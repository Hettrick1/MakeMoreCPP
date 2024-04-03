#pragma once
class Factory
{
private:
	int level;
	int nbrOfEmployee;

public:
	Factory();
	~Factory();
	void Load();
	void Update();
	void Draw();
	void Unload();
};

