#include "EventSystem.h"

ButtonListener::ButtonListener()
{
}

ButtonListener::~ButtonListener()
{
}

void ButtonListener::onButtonHovered()
{
	SetMouseCursor(MOUSE_CURSOR_POINTING_HAND);
}

void ButtonListener::onButtonUnhovered()
{
	SetMouseCursor(MOUSE_CURSOR_DEFAULT);
}

void ButtonListener::onClick()
{
}

Button1::Button1()
{
}

Button1::~Button1()
{
}

void Button1::onButtonHovered()
{
	ButtonListener::onButtonHovered();
}

void Button1::onButtonUnhovered()
{
	ButtonListener::onButtonUnhovered();
}

void Button1::onClick()
{
}
