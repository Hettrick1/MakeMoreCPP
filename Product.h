#pragma once

#include "raylib.h"

class Product
{
private:
	int mPrice;
	float mFabricationTime;
	Color mCubeColor;
	Texture2D mProductTexture;
public:
	Product(int price, float fabricationTime, Color cubeColor, Texture2D productTexture);
	~Product();
	int GetPrice();
	float GetFabricationTime();
	Color GetCubeColor();
	Texture2D GetProductTexture();
};

