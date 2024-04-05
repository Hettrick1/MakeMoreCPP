#pragma once

#include "Factory.h"

#include <vector>

extern std::vector<Factory> allFactories;

void LoadDatas();
void UnloadDatas();
Factory& GetFactory(int index);

