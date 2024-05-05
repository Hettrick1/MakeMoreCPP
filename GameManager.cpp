#include "GameManager.h"

Texture2D employee, table, block, hand, employeeFabFinished, hand2, bossTableTexture;



GameManager::GameManager()
{
	mCurrentFactory = 0;
	mFactories = {};
	mIsInFactory = true;
	mIsInUpgrade = false;
	mNewFactoryPrice = 50000;
	mIndex = 1;
}

GameManager::~GameManager()
{
}

void GameManager::Load()
{
	employee = LoadTexture("Sprites/EmployeeSprite1.png");
	employeeFabFinished = LoadTexture("Sprites/EmployeeSprite3.png");
	table = LoadTexture("Sprites/TableSprite.png");
	block = LoadTexture("Sprites/BlockSprite.png");
	hand = LoadTexture("Sprites/EmployeeHandSprite.png");
	hand2 = LoadTexture("Sprites/HandSprite.png");
	bossTableTexture = LoadTexture("Sprites/BossTableSprite.png");
}

void GameManager::Start()
{
	mFactories = { Factory(1000, 0, "Factory 1", employee, table, block, hand, employeeFabFinished, hand2)};
	for (Factory& factory : mFactories) {
		factory.Load();
	}
}

void GameManager::Update()
{
	if (mIsInUpgrade) {
		mFactories[mCurrentFactory].UpdateButtons();
	}
	else {
		for (Factory& factory : mFactories) {
			factory.Update();
		}
		mFactories[mCurrentFactory].ClickOnBoss();
	}
}

void GameManager::Draw()
{
	mFactories[mCurrentFactory].Draw();
	if (mIsInUpgrade) {
		DrawRectangle(0, 0, 1080, 720, Color{ 0, 0, 0, 150 });
		DrawTextureEx(bossTableTexture, { 40, 200 }, 0, 4, WHITE);
		mFactories[mCurrentFactory].DrawButtons();
	}

}

void GameManager::Unload()
{
	UnloadTexture(employee);
	UnloadTexture(table);
	UnloadTexture(block);
	UnloadTexture(hand);
	UnloadTexture(employeeFabFinished);
	UnloadTexture(hand2);
	UnloadTexture(bossTableTexture);
	for (Factory& factory : mFactories) {
		factory.Unload();
	}
}

int GameManager::GetFactoryLength()
{
	return mFactories.size();
}

void GameManager::ChangeFactory(int direction)
{
	mCurrentFactory += direction;
	mFactories[mCurrentFactory].ClearPopUpVector();
}

Factory& GameManager::GetCurrentFactory()
{
	return mFactories[mCurrentFactory];
}

void GameManager::SetInUpgrade(bool inUpgrade)
{
	if (inUpgrade)
	{
		mIsInFactory = false;
		mIsInUpgrade = true;
	}
	else {
		mIsInFactory = true;
		mIsInUpgrade = false;
	}
}

int GameManager::GetNewFactoryPrice()
{
	return mNewFactoryPrice;
}

void GameManager::CreateNewFactory()
{
	AddMoney(-mNewFactoryPrice);
	mNewFactoryPrice *= 2;
	Factory newFactory = Factory(3000, mIndex, TextFormat("Factory %i", mIndex + 1), employee, table, block, hand, employeeFabFinished, hand2);
	newFactory.Load();
	mFactories.push_back(newFactory);
	mIndex += 1;
}

