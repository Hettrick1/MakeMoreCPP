#include "Menus.h"

void Menus::Load()
{
}

void Menus::Start()
{
	Button1 button1;
	buttons = { 
		Buttons(Rectangle{100, 100, 100, 100}, WHITE, "a", BLACK, 40, button1),
		Buttons(Rectangle{300, 300, 100, 100}, WHITE, "Hello", BLACK, 40, button1),
	};
}

void Menus::Update()
{
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
}

void Menus::Unload()
{
}
