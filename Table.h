#pragma once

#include "raylib.h"
class Table
{
private:
	int mLevel;
	int mProductAmount;
	Texture2D mEmployeeTexture;
	Texture2D mTableTexture;
	Texture2D mMatterTexture;
	Vector2 mEmployeePos;
	Vector2 mTablePos;
	Vector2 mMatterpos;
	float mFabricationProgression;
	float mTimeTofabric;
	bool mIsActive;
public:
	Table();
	Table(int level, Texture2D employeeTexture, Texture2D tableTexture, Texture2D matterTexture, Vector2 employeePos, Vector2 tablePos, Vector2 matterPos);
	~Table();
	void Update();
	void Draw();
	void SetActive(bool active);
	bool GetIsActive();
	int GetLevel();
	int GetProductAmount();
	Texture2D GetEmployeeSprite();
	float GetFabricationProgression();
	float GetTimeToFabric();
};

