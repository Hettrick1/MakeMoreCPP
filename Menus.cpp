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
	}
	if (buttons[1].GetClickedBool()) {
		buttons[1].SetClickedBool(false);
		gm.SetInUpgrade(true);
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
