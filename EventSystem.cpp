#include "EventSystem.h"

ButtonListener::ButtonListener()
{
}

ButtonListener::~ButtonListener()
{
}

void ButtonListener::onButtonHovered()
{

}

void ButtonListener::onButtonUnhovered()
{

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
