#include "Factory.h"

Factory::Factory(int firstLevelUpPrice, int index)
{
	mText = "Factory";
	mIndex = index;
	mLevel = 0;
	mMaxProductOnTables = 0;
	mLevelUpPrice = firstLevelUpPrice;
	mNbrOfEmployee = 0;
	mCanLevelUp = true;
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
