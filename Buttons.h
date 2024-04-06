#pragma once

#include "raylib.h"
#include "EventSystem.h"
#include <iostream>

class Buttons
{
private:
    Vector2 mPosition;
    Vector2 mSize;
    Color mButtonColor;
    Color mTextColor;
    std::string mText;
    ButtonListener mListener;
    int mFontSize;
    bool mIsHovered;
public:
    Buttons(Vector2 position, Vector2 size, Color buttonColor, std::string text, Color textColor, int fontSize, ButtonListener& listener);
    Buttons(Rectangle rectangle, Color buttonColor, std::string text, Color textColor, int fontSize, ButtonListener& listener);
    ~Buttons();
    void SetListener(ButtonListener& listener);
    void SetColor(Color color);
    void Update();
    void Draw();
};

