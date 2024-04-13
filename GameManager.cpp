#include "GameManager.h"

Texture2D employee, table, block;

GameManager::GameManager()
{
	mCurrentFactory = 0;
	mFactories = {};
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
	mFactories[0].GetTable(0).SetActive(true);
}

void GameManager::Update()
{
}

void GameManager::Draw()
{
	mFactories[mCurrentFactory].Draw();
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
