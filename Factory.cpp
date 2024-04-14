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
	mBuyEmployeeBtn = {
		Buttons(Rectangle{ 423, 170, 50, 50}, ORANGE, "+" , WHITE, 60),
		Buttons(Rectangle{ 673, 170, 50, 50}, ORANGE, "+" , WHITE, 60),
		Buttons(Rectangle{ 923, 170, 50, 50}, ORANGE, "+" , WHITE, 60),
		Buttons(Rectangle{ 423, 320, 50, 50}, ORANGE, "+" , WHITE, 60),
		Buttons(Rectangle{ 673, 320, 50, 50}, ORANGE, "+" , WHITE, 60),
		Buttons(Rectangle{ 923, 320, 50, 50}, ORANGE, "+" , WHITE, 60),
		Buttons(Rectangle{ 423, 470, 50, 50}, ORANGE, "+" , WHITE, 60),
		Buttons(Rectangle{ 673, 470, 50, 50}, ORANGE, "+" , WHITE, 60),
		Buttons(Rectangle{ 923, 470, 50, 50}, ORANGE, "+" , WHITE, 60),
	};
	mUpgradeEmployeeBtn = {
		Buttons(Rectangle{ 373, 170, 150, 50 }, ORANGE, TextFormat("%i", mTables[0].GetUpgradePrice()) , WHITE, 25),
		Buttons(Rectangle{ 623, 170, 150, 50 }, ORANGE, TextFormat("%i", mTables[1].GetUpgradePrice()) , WHITE, 25),
		Buttons(Rectangle{ 873, 170, 150, 50 }, ORANGE, TextFormat("%i", mTables[2].GetUpgradePrice()) , WHITE, 25),
		Buttons(Rectangle{ 373, 320, 150, 50 }, ORANGE, TextFormat("%i", mTables[3].GetUpgradePrice()) , WHITE, 25),
		Buttons(Rectangle{ 623, 320, 150, 50 }, ORANGE, TextFormat("%i", mTables[4].GetUpgradePrice()) , WHITE, 25),
		Buttons(Rectangle{ 873, 320, 150, 50 }, ORANGE, TextFormat("%i", mTables[5].GetUpgradePrice()) , WHITE, 25),
		Buttons(Rectangle{ 373, 470, 150, 50 }, ORANGE, TextFormat("%i", mTables[6].GetUpgradePrice()) , WHITE, 25),
		Buttons(Rectangle{ 623, 470, 150, 50 }, ORANGE, TextFormat("%i", mTables[7].GetUpgradePrice()) , WHITE, 25),
		Buttons(Rectangle{ 873, 470, 150, 50 }, ORANGE, TextFormat("%i", mTables[8].GetUpgradePrice()) , WHITE, 25),
	};
	for (Buttons& upgradeButton : mUpgradeEmployeeBtn) {
		upgradeButton.SetActive(false);
	}
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

void Factory::UpdateButtons()
{
	for (int i = 0; i < mBuyEmployeeBtn.size(); i++) {
		if (mTables[i].GetIsActive()) {
			mUpgradeEmployeeBtn[i].Update();
		}
		else {
			mBuyEmployeeBtn[i].Update();
		}
		if (mBuyEmployeeBtn[i].GetClickedBool()) {
			mBuyEmployeeBtn[i].SetActive(false);
			mUpgradeEmployeeBtn[i].SetActive(true);
			mTables[i].SetActive(true);
		}
	}
}

void Factory::Draw()
{
	for (Table& table : mTables) {
		table.Draw();
	}
}

void Factory::DrawButtons()
{
	for (Buttons& buyButton : mBuyEmployeeBtn) {
		buyButton.Draw();
	}
	for (Buttons& upgradeButton : mUpgradeEmployeeBtn) {
		upgradeButton.Draw();
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
