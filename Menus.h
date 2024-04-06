#pragma once

#include "Buttons.h"
#include "EventSystem.h"
#include <vector>

class Menus
{
private:
	std::vector<Buttons> buttons;
public:
	void Load();
	void Start();
	void Update();
	void Draw();
	void Unload();
};

