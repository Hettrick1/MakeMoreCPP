#pragma once
#include "Factory.h"
#include <vector>
class GameManager
{
private:
	int mCurrentFactory;
	std::vector<Factory> mFactories;
	bool mIsInUpgrade, mIsInFactory;
public:
	GameManager();
	~GameManager();
	void Load();
	void Start();
	void Update();
	void Draw();
	void Unload();
	int GetFactoryLength();
	void ChangeFactory(int direction);
	void SetInUpgrade(bool inUpgrade);
	Factory& GetCurrentFactory();
};

