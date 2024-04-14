#include "Datas.h"

extern int money = 10000;

int GetMoney()
{
	return money;
}

void AddMoney(int amount)
{
	money += amount;
}
