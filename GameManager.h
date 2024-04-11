#pragma once
#include "Factory.h"
#include <vector>
class GameManager
{
private:
	int mCurrentFactory;
	std::vector<Factory> mFactories;
public:
	GameManager();
	~GameManager();
	void Load();
	void Start();
	void Update();
	void Draw();
	void Unload();
	Factory& GetCurrentFactory();
};

