#pragma once

#include "Table.h"
#include "Datas.h"
#include "raylib.h"
#include "Buttons.h"

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
	bool mCanLevelUp;
	std::vector<Table> mTables;
	std::vector<Buttons> mBuyEmployeeBtn;
	std::vector<Buttons> mUpgradeEmployeeBtn;

public:
	Factory(int firstLevelUpPrice, int index, std::string name, Texture2D employeeTexture, Texture2D tableTexture, Texture2D matterTexture);
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
};

