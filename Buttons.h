#pragma once

#include "raylib.h"
#include <iostream>

class Buttons
{
private:
    Vector2 mPosition;
    Vector2 mSize;
    Color mButtonColor;
    Color mTextColor;
    std::string mText;
    int mFontSize;
    bool mIsHovered;
    bool mIsClicked;
    bool mEnable;
    bool mIsActive;
    bool mClickBool;
    float mTimer;
    Color mPressedColor;
    Color mHoveredColor;
    Color mDisableColor;
public:
    Buttons(Vector2 position, Vector2 size, Color buttonColor, std::string text, Color textColor, int fontSize);
    Buttons(Rectangle rectangle, Color buttonColor, std::string text, Color textColor, int fontSize);
    ~Buttons();
    void SetButtonColor(Color color);
    void SetHoveredColor(Color color);
    void SetClickedColor(Color color);
    void SetDisableColor(Color color);
    void SetEnable(bool enable);
    void SetActive(bool isActive);
    bool GetClickedBool();
    void SetClickedBool(bool click);
    void Update();
    void Draw();
};

