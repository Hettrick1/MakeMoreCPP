#include "Table.h"

float moneyTimer = 0;
float spriteTimer = 0;
Table::Table()
{
	mLevel = 0;
	mProductAmount = 0;
	mEmployeeTexture = Texture2D();
	mTableTexture = Texture2D();
	mMatterTexture = Texture2D();
	mEmployeeTexture2 = Texture2D();
	mCurrentEmployeeTexture = Texture2D();
	mHandTexture2 = Texture2D();
	mHandTexture = Texture2D();
	mEmployeePos = Vector2();
	mTablePos = Vector2();
	mMatterpos = Vector2();
	mMoneyPopUpPos = Vector2();
	mHandPos = Vector2();
	mMoneyPopUpAmount = 0;
	mFabricationProgression = 0;
	mMaxProductOnTable = 0;
	mIsActive = false;
	mPlayHandAnim = false;
	mPlayMoneyAnim = false;
	mTimeTofabric = 0;
	mUpgradePrice = 1000;
	mBuyPrice = 1000;
	mMinDest = 0;
	mMaxDest = 0;
	mHandGoRight = false;
	mDirectionX = 0;
	mDirectionY = 0;
}

Table::Table(int level, Texture2D& employeeTexture, Texture2D& tableTexture, Texture2D& matterTexture, Texture2D& handTexture, Texture2D& employeeTexture2, Texture2D& handTexture2,Vector2 employeePos, Vector2 tablePos, Vector2 matterPos, Vector2 handPos)
{
	mLevel = level;
	mProductAmount = 0;
	mEmployeeTexture = employeeTexture;
	mTableTexture = tableTexture;
	mMatterTexture = matterTexture;
	mHandTexture = handTexture;
	mEmployeeTexture2 = employeeTexture2;
	mCurrentEmployeeTexture = mEmployeeTexture;
	mHandTexture2 = handTexture2;
	mEmployeePos = employeePos;
	mTablePos = tablePos;
	mMatterpos = matterPos;
	mHandPos = handPos;
	mMoneyPopUpPos = tablePos;
	mMoneyPopUpAmount = 0;
	mFabricationProgression = 0;
	mMaxProductOnTable = 10;
	mIsActive = false;
	mPlayMoneyAnim = false;
	mPlayHandAnim = true;
	mTimeTofabric = 5; //time to fabric c'est une incrémentation pour atteindre le montant qu'il faut dans le produit
	mUpgradePrice = 1000;
	mBuyPrice = 1000;
	mMinDest = mHandPos.x - 20;
	mMaxDest = mHandPos.x + 10;
	mHandGoRight = false;
	mDirectionX = GetMoneyPos().x + 30 - mMoneyPopUpPos.x;
	mDirectionY = GetMoneyPos().y - 5 - mMoneyPopUpPos.y;
}

Table::~Table()
{
}

void Table::Update()
{
	if (mIsActive) {
		if (mFabricationProgression < 100 && mProductAmount < mMaxProductOnTable) {
			mFabricationProgression += mTimeTofabric * GetFrameTime();
		}
		else if(mProductAmount < mMaxProductOnTable){
			mPlayHandAnim = false;
			spriteTimer += GetFrameTime();
			mCurrentEmployeeTexture = mEmployeeTexture2;
			if (spriteTimer > 0.2) {
				mPlayHandAnim = true;
				mCurrentEmployeeTexture = mEmployeeTexture;
				mFabricationProgression = 0;
				mProductAmount += 1;
				spriteTimer = 0;
			}
		}
		if (mPlayMoneyAnim) {
			moneyTimer += GetFrameTime();
			
			if (mDirectionX != 0 && mDirectionY != 0) {
				mMoneyPopUpPos.x += mDirectionX * GetFrameTime();
				mMoneyPopUpPos.y += mDirectionY * GetFrameTime();
			}
			if (mMoneyPopUpPos.x > GetMoneyPos().x + 20 && mMoneyPopUpPos.y < GetMoneyPos().y + 5) {
				mPlayMoneyAnim = false;
			}
			if(moneyTimer > 30){
				mPlayMoneyAnim = false;
			}
		}
		if (mPlayHandAnim && mProductAmount < mMaxProductOnTable) {
			Vector2 speed{ -50 * mLevel, 50 * mLevel};
			if (mHandPos.x > mMinDest && !mHandGoRight) {
				mHandPos.x += speed.x * GetFrameTime();
				mHandPos.y += speed.y * GetFrameTime();
			}
			else mHandGoRight = true;
			if (mHandPos.x < mMaxDest && mHandGoRight) {
				mHandPos.x -= speed.x * GetFrameTime();
				mHandPos.y -= speed.y * GetFrameTime();
			}
			else mHandGoRight = false;
		}
	}
}

void Table::Draw()
{
	if (mIsActive) {
		DrawTextureEx(mTableTexture, mTablePos, 0, 3, WHITE);
		DrawTextureEx(mMatterTexture, mMatterpos, 0, 2.5, WHITE);
		DrawTextureEx(mCurrentEmployeeTexture, mEmployeePos, 0, 4, WHITE);
		DrawTextureEx(mHandTexture, mHandPos, 0, 4, WHITE);
		DrawTextureEx(mHandTexture2, { mEmployeePos.x + 45, mEmployeePos.y + 95 }, 0, 4, WHITE);
		DrawText(TextFormat("%i", mProductAmount), mTablePos.x + 150, mTablePos.y + 10, 30, WHITE);
		DrawRectangle(mTablePos.x + 75, mTablePos.y +15, 50, 20, GRAY);
		float sizeRect = mFabricationProgression / 100 * 50;
		if (sizeRect > 50) sizeRect = 50;
		DrawRectangle(mTablePos.x + 75, mTablePos.y + 15, sizeRect, 20, GREEN);
		DrawRectangleLinesEx({ mTablePos.x + 75, mTablePos.y + 15, 50, 20 }, 3, BLACK);
		if (mPlayMoneyAnim) {
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
	mTimeTofabric += 5;
}

void Table::SetMaxProductOnTable(int maxProductOnTable)
{
	mMaxProductOnTable = maxProductOnTable;
}

void Table::AddFabricationProgression(int amount)
{
	if (mProductAmount < mMaxProductOnTable) {
		mFabricationProgression += amount;
	}
}

void Table::PlayMoneyAnimation()
{
	moneyTimer = 0;
	mMoneyPopUpPos = mTablePos;
	mMoneyPopUpAmount = 100 * mProductAmount;
	AddMoney(mMoneyPopUpAmount);
	mProductAmount = 0;
	mPlayMoneyAnim = true;
}

void Table::SetPlayHandAnim(bool handAnim)
{
	mPlayHandAnim = handAnim;
}
