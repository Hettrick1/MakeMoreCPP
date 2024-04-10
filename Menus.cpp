#include "Menus.h"

void Menus::Load()
{
}

void Menus::Start()
{
	Button1 button1;
	buttons = { 
		Buttons(Rectangle{100, 100, 100, 100}, WHITE, "+", BLACK, 40),
		Buttons(Rectangle{300, 300, 100, 100}, WHITE, "Hello", BLACK, 40),
	};
}

void Menus::Update()
{
	for (Buttons& button : buttons)
	{
		button.Update();
	}
	if (buttons[0].GetClickedBool()) {
		buttons[0].SetClickedBool(false);
		std::cout << "iquhgfUJIHGFISDHGP";
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
