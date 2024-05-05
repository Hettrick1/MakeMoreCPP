#include "Menus.h"

Texture2D factory;
Texture2D employees;
Texture2D upgrades;
Texture2D options;
Texture2D leftArrow;
Texture2D rightArrow;

GameManager gm;

int factoryIndex;
std::string mFactoryName;
Vector2 factoryTextPos = { 540, 60 };

bool isInUpgradePanel = false;

void Menus::Load()
{
	gm.Load();
	factory = LoadTexture("Sprites/factory-50.png");
	employees = LoadTexture("Sprites/man-50.png");
	upgrades = LoadTexture("Sprites/arrow-up-50.png");
	options = LoadTexture("Sprites/more-50.png");
	leftArrow = LoadTexture("Sprites/arrow-left-50.png");
	rightArrow = LoadTexture("Sprites/arrow-right-50.png");
}

void Menus::Start()
{
	gm.Start();
	factoryIndex = gm.GetCurrentFactory().GetIndex();
	mFactoryName = gm.GetCurrentFactory().GetFactoryName();
	buttons = { 
		Buttons(Rectangle{0, 650, 310, 70}, ORANGE, factory , 1),
		Buttons(Rectangle{310, 650, 310, 70}, ORANGE, employees, 1),
		Buttons(Rectangle{620, 650, 310, 70}, ORANGE, upgrades, 1),
		Buttons(Rectangle{930, 650, 150, 70}, ORANGE, options, 1),
		Buttons(Rectangle{factoryTextPos.x - MeasureText(mFactoryName.c_str(), 40)/2 - 70 - 15, 25, 70, 70}, ORANGE, leftArrow, 1),
		Buttons(Rectangle{factoryTextPos.x + MeasureText(mFactoryName.c_str(), 40)/2 + 15, 25, 70, 70}, ORANGE, rightArrow, 1),
	};
	upgradeFactoryButtons = {
		Buttons(Rectangle{620, 580, 310, 70}, ORANGE, TextFormat("Click multiplier : %i", gm.GetCurrentFactory().GetClickUpgradePrice()), WHITE, 20),
		Buttons(Rectangle{620, 510, 310, 70}, ORANGE, TextFormat("New Factory : %i", gm.GetNewFactoryPrice()), WHITE, 20),
	};
}

void Menus::Update()
{
	gm.Update();
	mFactoryName = gm.GetCurrentFactory().GetFactoryName();
	if (factoryIndex != gm.GetCurrentFactory().GetIndex()) {
		factoryIndex = gm.GetCurrentFactory().GetIndex();
		buttons[4].SetButtonPosition(Vector2{ factoryTextPos.x - MeasureText(mFactoryName.c_str(), 40)/2 -70 - 15, 25 });
		buttons[5].SetButtonPosition(Vector2{ factoryTextPos.x + MeasureText(mFactoryName.c_str(), 40) / 2 + 15, 25 });
	}
	if (factoryIndex == 0 && factoryIndex != gm.GetFactoryLength() - 1) {
		buttons[5].SetActive(true);
		buttons[4].SetActive(false);
	}
	else if (factoryIndex == 0 && factoryIndex == gm.GetFactoryLength() - 1) {
		buttons[4].SetActive(false);
		buttons[5].SetActive(false);
	}
	else if (factoryIndex != 0 && factoryIndex == gm.GetFactoryLength() - 1) {
		buttons[4].SetActive(true);
		buttons[5].SetActive(false);
	}
	else {
		buttons[4].SetActive(true);
		buttons[5].SetActive(true);
	}
	for (Buttons& button : buttons)
	{
		button.Update();
	}
	if (buttons[4].GetClickedBool()) {
		buttons[4].SetClickedBool(false);
		gm.ChangeFactory(-1);
	}
	else if (buttons[5].GetClickedBool()) {
		buttons[5].SetClickedBool(false);
		gm.ChangeFactory(1);
	}
	if (buttons[0].GetClickedBool()) {
		buttons[0].SetClickedBool(false);
		gm.SetInUpgrade(false);
		isInUpgradePanel = false;
	}
	if (buttons[1].GetClickedBool()) {
		buttons[1].SetClickedBool(false);
		gm.SetInUpgrade(true);
		isInUpgradePanel = false;
	}
	if (buttons[2].GetClickedBool()) {
		buttons[2].SetClickedBool(false);
		gm.SetInUpgrade(false);
		isInUpgradePanel = !isInUpgradePanel;
	}
	if (isInUpgradePanel) {
		if (GetMoney() < gm.GetCurrentFactory().GetClickUpgradePrice()) {
			upgradeFactoryButtons[0].SetClickedColor(BLANK);
			upgradeFactoryButtons[0].SetHoveredBool(false);
			upgradeFactoryButtons[0].SetEnable(false);
		}
		else {
			upgradeFactoryButtons[0].SetClickedColor({ 128, 128, 128, 255 });
			upgradeFactoryButtons[0].SetEnable(true);
		}
		if (GetMoney() < gm.GetNewFactoryPrice()) {
			upgradeFactoryButtons[1].SetClickedColor(BLANK);
			upgradeFactoryButtons[1].SetHoveredBool(false);
			upgradeFactoryButtons[1].SetEnable(false);
		}
		else {
			upgradeFactoryButtons[1].SetClickedColor({ 128, 128, 128, 255 });
			upgradeFactoryButtons[1].SetEnable(true);
		}
		for (Buttons& button : upgradeFactoryButtons) {
			button.Update();
		}
		if (upgradeFactoryButtons[0].GetClickedBool()) {
			upgradeFactoryButtons[0].SetClickedBool(false);
			gm.GetCurrentFactory().UpgradeClick();
			SetMouseCursor(MOUSE_CURSOR_DEFAULT);
			upgradeFactoryButtons[0].SetText(TextFormat("Click multiplier : %i", gm.GetCurrentFactory().GetClickUpgradePrice()));
		}
		if (upgradeFactoryButtons[1].GetClickedBool()) {
			upgradeFactoryButtons[1].SetClickedBool(false);
			gm.CreateNewFactory();
			SetMouseCursor(MOUSE_CURSOR_DEFAULT);
			upgradeFactoryButtons[1].SetText(TextFormat("New Factory : %i", gm.GetNewFactoryPrice()));
		}
	}
}

void Menus::Draw()
{
	gm.Draw();
	DrawText(TextFormat("money : %i", GetMoney()), GetMoneyPos().x, GetMoneyPos().y, 20, WHITE);
	for (Buttons& button : buttons)
	{
		button.Draw();
	}
	DrawRectangle(factoryTextPos.x - MeasureText(mFactoryName.c_str(), 40) / 2 - 15, factoryTextPos.y-25, MeasureText(mFactoryName.c_str(), 40) + 30, 50, WHITE);
	DrawText(mFactoryName.c_str(), factoryTextPos.x - MeasureText(mFactoryName.c_str(), 40) / 2, factoryTextPos.y - 20, 40, BLACK);
	if (isInUpgradePanel) {
		for (Buttons& button : upgradeFactoryButtons) {
			button.Draw();
		}
	}
}

void Menus::Unload()
{
	for (Buttons& button : buttons)
	{
		button.Unload();
	}
	UnloadTexture(factory);
	UnloadTexture(employees);
	UnloadTexture(upgrades);
	UnloadTexture(options);
	gm.Unload();
}
