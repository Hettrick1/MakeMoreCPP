#pragma once

#include "raylib.h"
#include "Datas.h"

class ButtonListener {
public:
    ButtonListener();
    ~ButtonListener();
    virtual void onButtonHovered();
    virtual void onButtonUnhovered();
    virtual void onClick();
};

class Button1 : public ButtonListener {

public:
    Button1();
    ~Button1();
    void onButtonHovered() override;
    void onButtonUnhovered() override;
    void onClick() override;
};

