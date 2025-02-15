#pragma once

#include "Table.h"
#include "Datas.h"
#include "raylib.h"
#include "Buttons.h"
#include "PopUpText.h"

#include <cmath>
#include <iostream>
#include <vector>

class Factory
{
private:
	std::string mText;
	int mIndex;
	int mLevel;
	int mMaxProductOnTables;
	int mLevelUpPrice;
	int mNbrOfEmployee;
	int mClickLevel;
	int mClickMultiplierCost;
	bool mCanLevelUp;
	std::vector<Table> mTables;
	std::vector<Buttons> mBuyEmployeeBtn;
	std::vector<Buttons> mUpgradeEmployeeBtn;
	Buttons mBossBtn = Buttons(Rectangle{ 40, 185, 250, 350 }, BLANK, "Boss", BLANK, 25);
	Buttons mFactoryUpgradeBtn = Buttons(Rectangle{ 93, 260, 150, 50 }, ORANGE, "", WHITE, 25);
	Texture2D mBossTexture1, mBossTexture2, mBossHandTexture, mCurrentBossTexture, mHandFxTexture;
	Vector2 mHandPos, mPopUpPos;
	float mHandSpeed;
	float mHandFxSize;
	Color mHandFxColor;
	std::vector<PopUp> mPopUpText;

public:
	Factory(int firstLevelUpPrice, int index, std::string name, Texture2D& employeeTexture, Texture2D& tableTexture, Texture2D& matterTexture, Texture2D& handTexture, Texture2D& employeeTexture2, Texture2D& handTexture2);
	~Factory();
	void Load();
	void Update();
	void UpdateButtons();
	void Draw();
	void DrawButtons();
	void Unload();
	void LevelUp();
	std::string GetFactoryName();
	int GetIndex();
	int GetFactoryLevel();
	int GetMaxProductOnTables();
	int GetLevelUpPrice();
	int GetNbrOfEmployee();
	bool GetCanLevelUp();
	Table& GetTable(int index);
	void UpgradeTable(int index);
	void ClickOnBoss();
	bool GetHasSomethingOnTable();
	void AnimBossHand();
	Vector2 PopUpRandomSpawn();
	void ClearPopUpVector();
	int GetClickLevel();
	int GetClickUpgradePrice();
	void UpgradeClick();
};

