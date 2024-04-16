#pragma once

#include "raylib.h"
#include "Datas.h"
#include <iostream>
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
	Vector2 mMoneyPopUpPos;
	float mFabricationProgression;
	float mTimeTofabric;
	int mMaxProductOnTable;
	bool mIsActive;
	bool mPlayAnim;
	int mUpgradePrice;
	int mBuyPrice;
	int mMoneyPopUpAmount;
public:
	Table();
	Table(int level, Texture2D employeeTexture, Texture2D tableTexture, Texture2D matterTexture, Vector2 employeePos, Vector2 tablePos, Vector2 matterPos);
	~Table();
	void Update();
	void Draw();
	void SetActive(bool active);
	bool GetIsActive();
	int& GetLevel();
	int& GetProductAmount();
	Texture2D GetEmployeeSprite();
	float& GetFabricationProgression();
	float& GetTimeToFabric();
	int& GetUpgradePrice();
	int& GetBuyPrice();
	void LevelUp();
	void SetMaxProductOnTable(int maxProductOnTable);
	void AddFabricationProgression(int amount);
	void PlayMoneyAnimation();
};

