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
	mFactoryName = gm.GetCurrentFactory().GetFactoryName();
	if (factoryIndex != gm.GetCurrentFactory().GetIndex()) {
		buttons[4].SetButtonPosition(Vector2{ factoryTextPos.x - MeasureText(mFactoryName.c_str(), 40)/2 - 15, factoryTextPos.y });
		buttons[5].SetButtonPosition(Vector2{ factoryTextPos.x + MeasureText(mFactoryName.c_str(), 40) / 2 + 15, factoryTextPos.y });
	}
	for (Buttons& button : buttons)
	{
		button.Update();
	}
}

void Menus::Draw()
{
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
}
