#include "GameManager.h"

Texture2D employee, table, block;



GameManager::GameManager()
{
	mCurrentFactory = 0;
	mFactories = {};
	mIsInFactory = true;
	mIsInUpgrade = false;
}

GameManager::~GameManager()
{
}

void GameManager::Load()
{
	employee = LoadTexture("Sprites/EmployeeSprite1.png");
	table = LoadTexture("Sprites/TableSprite.png");
	block = LoadTexture("Sprites/BlockSprite.png");
}

void GameManager::Start()
{
	mFactories = { Factory(1000, 0, "Factory1", employee, table, block), Factory(2000, 1, "kjlghdiluhaslisaug", employee, table, block)};
}

void GameManager::Update()
{
	if (mIsInUpgrade) {
		mFactories[mCurrentFactory].UpdateButtons();
	}
}

void GameManager::Draw()
{
	mFactories[mCurrentFactory].Draw();
	if (mIsInUpgrade) {
		DrawRectangle(0, 0, 1080, 720, Color{ 0, 0, 0, 100 });
		mFactories[mCurrentFactory].DrawButtons();
	}

}

void GameManager::Unload()
{
	UnloadTexture(employee);
	UnloadTexture(table);
	UnloadTexture(block);
}

int GameManager::GetFactoryLength()
{
	return mFactories.size();
}

void GameManager::ChangeFactory(int direction)
{
	mCurrentFactory += direction;
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