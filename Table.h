#pragma once

#include "raylib.h"
class Table
{
private:
	int mLevel;
	int mProductAmount;
	Texture2D mEmployeeTexture;
	float mFabricationProgression;
	float mTimeTofabric;
public:
	Table();
	Table(int level, Texture2D employeeTexture);
	~Table();
	int GetLevel();
	int GetProductAmount();
	Texture2D GetEmployeeSprite();
	float GetFabricationProgression();
	float GetTimeToFabric();
};

