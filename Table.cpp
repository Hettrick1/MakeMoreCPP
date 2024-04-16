#include "Table.h"

float timer = 0;

Table::Table()
{
	mLevel = 0;
	mProductAmount = 0;
	mEmployeeTexture = Texture2D();
	mTableTexture = Texture2D();
	mMatterTexture = Texture2D();
	mEmployeePos = Vector2();
	mTablePos = Vector2();
	mMatterpos = Vector2();
	mMoneyPopUpPos = Vector2();
	mMoneyPopUpAmount = 0;
	mFabricationProgression = 0;
	mMaxProductOnTable = 0;
	mIsActive = false;
	mPlayAnim = false;
	mTimeTofabric = 0;
	mUpgradePrice = 1000;
	mBuyPrice = 1000;
}

Table::Table(int level, Texture2D employeeTexture, Texture2D tableTexture, Texture2D matterTexture, Vector2 employeePos, Vector2 tablePos, Vector2 matterPos)
{
	mLevel = level;
	mProductAmount = 0;
	mEmployeeTexture = employeeTexture;
	mTableTexture = tableTexture;
	mMatterTexture = matterTexture;
	mEmployeePos = employeePos;
	mTablePos = tablePos;
	mMatterpos = matterPos;
	mMoneyPopUpPos = tablePos;
	mMoneyPopUpAmount = 0;
	mFabricationProgression = 0;
	mMaxProductOnTable = 10;
	mIsActive = false;
	mPlayAnim = false;
	mTimeTofabric = 5; //time to fabric c'est une incrémentation pour atteindre le montant qu'il faut dans le produit
	mUpgradePrice = 1000;
	mBuyPrice = 1000;
}

Table::~Table()
{
}

void Table::Update()
{
	if (mIsActive) {
		if (mFabricationProgression < 1000 && mProductAmount < mMaxProductOnTable) {
			mFabricationProgression += mTimeTofabric;
		}
		else if(mProductAmount < mMaxProductOnTable){
			mFabricationProgression = 0;
			mProductAmount += 1;
		}
		if (mPlayAnim) {
			timer += GetFrameTime();
			int directionX = GetMoneyPos().x + 30 - mMoneyPopUpPos.x;
			int directionY = GetMoneyPos().y - 5 - mMoneyPopUpPos.y;
			if (directionX != 0 && directionY != 0) {
				mMoneyPopUpPos.x += directionX * GetFrameTime();
				mMoneyPopUpPos.y += directionY * GetFrameTime();
			}
			if(timer > 30){
				mPlayAnim = false;
			}
		}
	}
}

void Table::Draw()
{
	if (mIsActive) {
		DrawTextureEx(mTableTexture, mTablePos, 0, 3, WHITE);
		DrawTextureEx(mMatterTexture, mMatterpos, 0, 2.5, WHITE);
		DrawTextureEx(mEmployeeTexture, mEmployeePos, 0, 4, WHITE);
		DrawText(TextFormat("%i", mProductAmount), mTablePos.x + 150, mTablePos.y + 10, 30, WHITE);
		if (mPlayAnim) {
			DrawText(TextFormat("%i", mMoneyPopUpAmount), mMoneyPopUpPos.x, mMoneyPopUpPos.y, 30, YELLOW);
		}
	}
}

void Table::SetActive(bool active)
{
	mIsActive = active;
}

bool Table::GetIsActive()
{
	return mIsActive;
}

int& Table::GetLevel()
{
	return mLevel;
}

int& Table::GetProductAmount()
{
	return mProductAmount;
}

Texture2D Table::GetEmployeeSprite()
{
	return mEmployeeTexture;
}

float& Table::GetFabricationProgression()
{
	return mFabricationProgression;
}

float& Table::GetTimeToFabric()
{
	return mTimeTofabric;
}

int& Table::GetUpgradePrice()
{
	return mUpgradePrice;
}

int& Table::GetBuyPrice()
{
	return mBuyPrice;
}

void Table::LevelUp()
{
	mLevel += 1;
	mUpgradePrice *= 2;
	mTimeTofabric = 5 * ((mLevel + 1)/2);
}

void Table::SetMaxProductOnTable(int maxProductOnTable)
{
	mMaxProductOnTable = maxProductOnTable;
}

void Table::AddFabricationProgression(int amount)
{
	mFabricationProgression += amount;
}

void Table::PlayMoneyAnimation()
{
	timer = 0;
	mMoneyPopUpPos = mTablePos;
	mMoneyPopUpAmount = 100 * mProductAmount;
	AddMoney(mMoneyPopUpAmount);
	mProductAmount = 0;
	mPlayAnim = true;
}
