#pragma once

#include <cmath>
#include <iostream>

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

public:
	Factory(int firstLevelUpPrice, int index);
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
};

