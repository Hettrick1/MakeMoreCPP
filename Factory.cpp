#include "Factory.h"

Factory::Factory(int firstLevelUpPrice, int index, std::string name, Texture2D employeeTexture, Texture2D tableTexture, Texture2D matterTexture)
{
	mText = name;
	mIndex = index;
	mLevel = 0;
	mMaxProductOnTables = 0;
	mLevelUpPrice = firstLevelUpPrice;
	mNbrOfEmployee = 0;
	mCanLevelUp = true;
	mTables = {
		Table(1, employeeTexture, tableTexture, matterTexture, { 320, 72 }, { 350, 200 }, { 350, 130 }),
		Table(1, employeeTexture, tableTexture, matterTexture, { 570, 72 }, { 600, 200 }, { 600, 130 }),
		Table(1, employeeTexture, tableTexture, matterTexture, { 820, 72 }, { 850, 200 }, { 850, 130 }),
		Table(1, employeeTexture, tableTexture, matterTexture, { 320, 222 }, { 350, 350 }, { 350, 280 }),
		Table(1, employeeTexture, tableTexture, matterTexture, { 570, 222 }, { 600, 350 }, { 600, 280 }),
		Table(1, employeeTexture, tableTexture, matterTexture, { 820, 222 }, { 850, 350 }, { 850, 280 }),
		Table(1, employeeTexture, tableTexture, matterTexture, { 320, 372 }, { 350, 500 }, { 350, 430 }),
		Table(1, employeeTexture, tableTexture, matterTexture, { 570, 372 }, { 600, 500 }, { 600, 430 }),
		Table(1, employeeTexture, tableTexture, matterTexture, { 820, 372 }, { 850, 500 }, { 850, 430 })
	};
}

Factory::~Factory()
{
}

void Factory::Load()
{
}

void Factory::Update()
{
}

void Factory::Draw()
{
	for (Table& table : mTables) {
		table.Draw();
	}
}

void Factory::Unload()
{
}

void Factory::LevelUp()
{
	mLevel += 1;
	if (mLevel <= 10) {
		mMaxProductOnTables += 10;
		mLevelUpPrice *= 2;
	}
	if (mLevel == 11) {
		mMaxProductOnTables += 100;
		float transi = mLevelUpPrice / 1000000;
		mLevelUpPrice = std::ceil(transi) * 1000000;
	}
	if (mLevel > 11 && mLevel <= 20) {
		mMaxProductOnTables += 100;
		mLevelUpPrice += 1000000;
		if (mLevel == 20) {
			mCanLevelUp = false;
		}
	}
}

std::string Factory::GetFactoryName()
{
	return mText;
}

int Factory::GetIndex()
{
	return mIndex;
}

int Factory::GetFactoryLevel()
{
	return mLevel;
}

int Factory::GetMaxProductOnTables()
{
	return mMaxProductOnTables;
}

int Factory::GetLevelUpPrice()
{
	return mLevelUpPrice;
}

int Factory::GetNbrOfEmployee()
{
	return mNbrOfEmployee;
}

bool Factory::GetCanLevelUp()
{
	return mCanLevelUp;
}

Table& Factory::GetTable(int index)
{
	return mTables[index];
}
