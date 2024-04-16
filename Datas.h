#pragma once

#include "raylib.h"

extern int money;
extern Vector2 moneyPos;

Vector2 GetMoneyPos();
int GetMoney();
void AddMoney(int amount);
