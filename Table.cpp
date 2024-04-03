#include "Table.h"

Table::Table()
{
	mLevel = 0;
	mProductAmount = 0;
	mEmployeeTexture = Texture2D();
	mFabricationProgression = 0;
	mTimeTofabric = 0;
}

Table::Table(int level, Texture2D employeeTexture)
{
	mLevel = level;
	mProductAmount = 0;
	mEmployeeTexture = employeeTexture;
	mFabricationProgression = 0;
	mTimeTofabric = 5 * level; //time to fabric c'est une incrémentation pour atteindre le montant qu'il faut dans le produit
}

Table::~Table()
{
}

int Table::GetLevel()
{
	return mLevel;
}

int Table::GetProductAmount()
{
	return mProductAmount;
}

Texture2D Table::GetEmployeeSprite()
{
	return mEmployeeTexture;
}

float Table::GetFabricationProgression()
{
	return mFabricationProgression;
}

float Table::GetTimeToFabric()
{
	return mTimeTofabric;
}
