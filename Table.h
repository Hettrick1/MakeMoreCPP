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
	Texture2D mHandTexture;
	Texture2D mEmployeeTexture2;
	Texture2D mCurrentEmployeeTexture;
	Texture2D mHandTexture2;
	Vector2 mEmployeePos;
	Vector2 mTablePos;
	Vector2 mMatterpos;
	Vector2 mHandPos;
	Vector2 mMoneyPopUpPos;
	float mFabricationProgression;
	float mTimeTofabric;
	int mMaxProductOnTable;
	bool mIsActive;
	bool mPlayMoneyAnim;
	bool mPlayHandAnim;
	int mUpgradePrice;
	int mBuyPrice;
	int mMoneyPopUpAmount;
	float mMinDest;
	float mMaxDest;
	bool mHandGoRight;
	int mDirectionX;
	int mDirectionY;
public:
	Table();
	Table(int level, Texture2D& employeeTexture, Texture2D& tableTexture, Texture2D& matterTexture, Texture2D& handTexture, Texture2D& employeeTexture2, Texture2D& handTexture2, Vector2 employeePos, Vector2 tablePos, Vector2 matterPos, Vector2 handPos);
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
	void SetPlayHandAnim(bool handAnim);
};

