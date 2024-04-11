#include "GameManager.h"

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
}

void GameManager::Start()
{
	mFactories = { Factory(1000, 0) };
}

void GameManager::Update()
{
}

void GameManager::Draw()
{
}

void GameManager::Unload()
{
}

Factory& GameManager::GetCurrentFactory()
{
	return mFactories[mCurrentFactory];
}
