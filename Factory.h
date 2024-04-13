#pragma once

#include "Table.h"
#include "raylib.h"

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
	bool mCanLevelUp;
	std::vector<Table> mTables;

public:
	Factory(int firstLevelUpPrice, int index, std::string name, Texture2D employeeTexture, Texture2D tableTexture, Texture2D matterTexture);
	~Factory();
	void Load();
	void Update();
	void Draw();
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
};

