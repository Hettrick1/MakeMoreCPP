#include "Product.h"

Product::Product(int price, float fabricationTime, Color cubeColor, Texture2D productTexture)
{
    mPrice = price;
    mFabricationTime = fabricationTime;
    mCubeColor = cubeColor;
    mProductTexture = productTexture;
}

Product::~Product()
{
}

int Product::GetPrice()
{
    return mPrice;
}

float Product::GetFabricationTime()
{
    return mFabricationTime;
}

Color Product::GetCubeColor()
{
    return mCubeColor;
}

Texture2D Product::GetProductTexture()
{
    return mProductTexture;
}
