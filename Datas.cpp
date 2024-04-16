#include "Datas.h"

extern int money = 10000;
extern Vector2 moneyPos = {800, 40};

Vector2 GetMoneyPos() {
	return moneyPos;
}

int GetMoney()
{
	return money;
}

void AddMoney(int amount)
{
	money += amount;
}
