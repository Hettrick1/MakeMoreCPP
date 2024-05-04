#include "Factory.h"

float timer = 0;
bool isPlayingHandAnim;

Factory::Factory(int firstLevelUpPrice, int index, std::string name, Texture2D& employeeTexture, Texture2D& tableTexture, Texture2D& matterTexture, Texture2D& handTexture, Texture2D& employeeTexture2, Texture2D& handTexture2)
{
	mText = name;
	mIndex = index;
	mLevel = 0;
	mMaxProductOnTables = 10;
	mLevelUpPrice = firstLevelUpPrice;
	mNbrOfEmployee = 0;
	mCanLevelUp = true;
	mClickLevel = 1;
	mTables = {
		Table(1, employeeTexture, tableTexture, matterTexture, handTexture, employeeTexture2, handTexture2, { 320, 72 }, { 350, 200 }, { 350, 130 }, { 320, 80 }),
		Table(1, employeeTexture, tableTexture, matterTexture, handTexture, employeeTexture2, handTexture2, { 570, 72 }, { 600, 200 }, { 600, 130 }, { 570, 80 }),
		Table(1, employeeTexture, tableTexture, matterTexture, handTexture, employeeTexture2, handTexture2, { 820, 72 }, { 850, 200 }, { 850, 130 }, { 820, 80 }),
		Table(1, employeeTexture, tableTexture, matterTexture, handTexture, employeeTexture2, handTexture2, { 320, 222 }, { 350, 350 }, { 350, 280 }, { 320, 230 }),
		Table(1, employeeTexture, tableTexture, matterTexture, handTexture, employeeTexture2, handTexture2, { 570, 222 }, { 600, 350 }, { 600, 280 }, { 570, 230 }),
		Table(1, employeeTexture, tableTexture, matterTexture, handTexture, employeeTexture2, handTexture2, { 820, 222 }, { 850, 350 }, { 850, 280 }, { 820, 230 }),
		Table(1, employeeTexture, tableTexture, matterTexture, handTexture, employeeTexture2, handTexture2, { 320, 372 }, { 350, 500 }, { 350, 430 }, { 320, 380 }),
		Table(1, employeeTexture, tableTexture, matterTexture, handTexture, employeeTexture2, handTexture2, { 570, 372 }, { 600, 500 }, { 600, 430 }, { 570, 380 }),
		Table(1, employeeTexture, tableTexture, matterTexture, handTexture, employeeTexture2, handTexture2, { 820, 372 }, { 850, 500 }, { 850, 430 }, { 820, 380 })
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
	mBossTexture1 = LoadTexture("Sprites/BossSprite1.png");
	mBossTexture2 = LoadTexture("Sprites/BossSprite2.png");
	mBossHandTexture = LoadTexture("Sprites/BossHandSprite.png");
	mHandFxTexture = LoadTexture("Sprites/handFxSprite.png");
	mCurrentBossTexture = mBossTexture1;
	mHandPos = { 40, 200 };
	mPopUpPos = { 90, 310 };
	mHandSpeed = 120;
	mHandFxSize = 4;
	mHandFxColor = BLANK;
}

Factory::~Factory()
{
}

void Factory::Load()
{
	mBossBtn.SetHoveredColor(BLANK);
	mBossBtn.SetClickedColor(BLANK);
	mBossBtn.SetOutlineColor(BLANK);
	mFactoryUpgradeBtn.SetText(TextFormat("%i", mLevelUpPrice));
}

void Factory::Update()
{
	for (Table& table : mTables) {
		table.Update();
	}
	AnimBossHand();
	if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
		for (Table& table : mTables) {
			if (table.GetIsActive()) {
				table.AddFabricationProgression(mClickLevel * 10);
			}
		}
		if (!isPlayingHandAnim) {
			isPlayingHandAnim = true;
			mHandSpeed = 120;
			mHandPos = { 40, 200 };
		}
		PopUp newPopUp;

		newPopUp.position = PopUpRandomSpawn();
		newPopUp.speedY = 100.0f;
		newPopUp.speedX = (float)(GetRandomValue(-20, 20) * 2.0);
		newPopUp.text = TextFormat("%i", mClickLevel);
		newPopUp.time = 0.0f;
		newPopUp.alpha = 255;
		mPopUpText.push_back(newPopUp);
	}
	for (PopUp& popUp : mPopUpText) {
		popUp.time += GetFrameTime();
		popUp.position.x += popUp.speedX * GetFrameTime();
		popUp.position.y -= popUp.speedY * GetFrameTime();
		if (popUp.time > 1.2) {
			mPopUpText.erase(begin(mPopUpText));
		}
	}
}

void Factory::UpdateButtons()
{
	for (int i = 0; i < mBuyEmployeeBtn.size(); i++) {
		if (mTables[i].GetIsActive()) {
			mUpgradeEmployeeBtn[i].Update();
			mUpgradeEmployeeBtn[i].SetText(TextFormat("%i", mTables[i].GetUpgradePrice()));
		}
		else {
			mBuyEmployeeBtn[i].Update();
		}
		if (mBuyEmployeeBtn[i].GetClickedBool() && GetMoney() >= mTables[i].GetBuyPrice()) {
			mBuyEmployeeBtn[i].SetClickedBool(false);
			mBuyEmployeeBtn[i].SetActive(false);
			mUpgradeEmployeeBtn[i].SetActive(true);
			mTables[i].SetActive(true);
			AddMoney(-mTables[i].GetBuyPrice());
		}
		if (mUpgradeEmployeeBtn[i].GetClickedBool() && GetMoney() >= mTables[i].GetUpgradePrice()) {
			mUpgradeEmployeeBtn[i].SetClickedBool(false);
			UpgradeTable(i);
		}
		mUpgradeEmployeeBtn[i].SetClickedBool(false);
	}
	mFactoryUpgradeBtn.Update();
	if (mFactoryUpgradeBtn.GetClickedBool() && GetMoney() >= mLevelUpPrice) {
		mFactoryUpgradeBtn.SetClickedBool(false);
		LevelUp();
	}
	mFactoryUpgradeBtn.SetClickedBool(false);
}

void Factory::Draw()
{
	for (Table& table : mTables) {
		table.Draw();
	}
	DrawTextureEx(mCurrentBossTexture, {40, 200}, 0, 4, WHITE);
	DrawTextureEx(mHandFxTexture, { mHandPos.x, mHandPos.y - 10 }, 0, mHandFxSize, mHandFxColor);
	DrawTextureEx(mHandFxTexture, { mHandPos.x + 136, mHandPos.y - 10}, 0, mHandFxSize, mHandFxColor);
	DrawTextureEx(mBossHandTexture, mHandPos, 0, 4, WHITE);
	mBossBtn.Draw();
	for (PopUp& popUp : mPopUpText) {
		DrawText(popUp.text.c_str(), popUp.position.x, popUp.position.y, 20, WHITE);
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
	mFactoryUpgradeBtn.Draw();
}

void Factory::Unload()
{
	UnloadTexture(mBossHandTexture);
	UnloadTexture(mBossTexture1);
	UnloadTexture(mBossTexture2);
	UnloadTexture(mCurrentBossTexture);
	UnloadTexture(mHandFxTexture);
}

void Factory::LevelUp()
{
	AddMoney(-mLevelUpPrice);
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
	for (Table& table : mTables) {
		table.SetMaxProductOnTable(mMaxProductOnTables);
	}
	mFactoryUpgradeBtn.SetText(TextFormat("%i", mLevelUpPrice));
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

void Factory::UpgradeTable(int index)
{
	AddMoney(-mTables[index].GetUpgradePrice());
	mTables[index].LevelUp();
}

void Factory::ClickOnBoss()
{
	timer += GetFrameTime();
	if (GetHasSomethingOnTable()) {
		mBossBtn.Update();
		if (mBossBtn.GetClickedBool()) {
			mBossBtn.SetClickedBool(false);
			timer = 0;
			mCurrentBossTexture = mBossTexture2;
			for (Table& table : mTables) {
				if (table.GetProductAmount() > 0) {
					table.PlayMoneyAnimation();
					mBossBtn.SetHoveredBool(false);
					SetMouseCursor(MOUSE_CURSOR_DEFAULT);
				}
			}
		}
	}
	if (timer > 2) {
		mCurrentBossTexture = mBossTexture1;
	}
}

bool Factory::GetHasSomethingOnTable()
{
	for (Table& table : mTables) {
		if (table.GetProductAmount() > 0) {
			return true;
			break;
		}
	}
	return false;
}

void Factory::AnimBossHand()
{
	if (isPlayingHandAnim) {
		mHandPos.y += mHandSpeed * GetFrameTime();
		if (mHandPos.y > 210) {
			mHandSpeed *= -1;
			mHandFxColor = WHITE;
		}
		if (mHandPos.y < 205) {
			mHandFxColor = BLANK;
		}
		if (mHandPos.y < 200) {
			isPlayingHandAnim = false;
		}
	}
}

Vector2 Factory::PopUpRandomSpawn()
{
	int left = GetRandomValue(0, 1);

	if (left == 0) {
		return { mPopUpPos.x + (float)GetRandomValue(-10, 10), mPopUpPos.y + 20 };
	}
	else {
		return { mPopUpPos.x + 136 + (float)GetRandomValue(-10, 10), mPopUpPos.y + 20 };
	}
}

void Factory::ClearPopUpVector()
{
	mPopUpText.clear();
}
