#pragma once

#include <cmath>

class Factory
{
private:
	int mLevel;
	int mMaxProductOnTables;
	int mLevelUpPrice;
	int mNbrOfEmployee;
	bool mCanLevelUp;

public:
	Factory(int firstLevelUpPrice);
	~Factory();
	void Load();
	void Update();
	void Draw();
	void Unload();
	void LevelUp();
	int GetFactoryLevel();
	int GetMaxProductOnTables();
	int GetLevelUpPrice();
	int GetNbrOfEmployee();
	bool GetCanLevelUp();
};

