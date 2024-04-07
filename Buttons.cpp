#include "Buttons.h"

float timer = 0;

Buttons::Buttons(Vector2 position, Vector2 size, Color buttonColor, std::string text, Color textColor, int fontSize, ButtonListener& listener)
{
	mPosition = position;
	mSize = size;
	mButtonColor = buttonColor;
	mTextColor = textColor;
	mText = text;
	mListener = listener;
	mFontSize = fontSize;
	mIsHovered = false;
	mIsClicked = false;
}

Buttons::Buttons(Rectangle rectangle, Color buttonColor, std::string text, Color textColor, int fontSize, ButtonListener& listener)
{
	mPosition = Vector2{ rectangle.x, rectangle.y };
	mSize = Vector2{ rectangle.width, rectangle.height };
	mButtonColor = buttonColor;
	mTextColor = textColor;
	mText = text;
	mListener = listener;
	mFontSize = fontSize;
	mIsHovered = false;
	mIsClicked = false;
}

Buttons::~Buttons()
{
}

void Buttons::SetListener(ButtonListener& listener)
{
	mListener = listener;
}

void Buttons::SetColor(Color color)
{
	mButtonColor = color;
}

void Buttons::Update()
{
	Rectangle rect = { mPosition.x, mPosition.y, mSize.x, mSize.y };
	if (CheckCollisionPointRec(GetMousePosition(), rect)) {
		if (!mIsHovered) {
			mIsHovered = true;
			mListener.onButtonHovered();
		}
		if (!mIsClicked && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
			mIsClicked = true;
			timer = 0;
			mListener.onClick();
		}
	}
	else if (mIsHovered) {
		mIsHovered = false;
		mListener.onButtonUnhovered();
	}
	if (mIsClicked) {
		
		float deltaTime = GetFrameTime();
		timer += deltaTime;
		if (timer > 0.5) {
			mIsClicked = false;
		}
	}
}

void Buttons::Draw()
{
	DrawRectangle(mPosition.x, mPosition.y, mSize.x, mSize.y, mButtonColor);
	DrawRectangleLines(mPosition.x, mPosition.y, mSize.x, mSize.y, BLACK);

	float textWidth = MeasureTextEx(GetFontDefault(), mText.c_str(), mFontSize, 3).x;
	float textHeight = MeasureTextEx(GetFontDefault(), mText.c_str(), mFontSize, 3).y;

	if (textWidth > mSize.x) {
		textWidth = mSize.x;
	}

	float textX = mPosition.x + (mSize.x - textWidth) / 2.0f;
	float textY = mPosition.y + (mSize.y - textHeight) / 2.0f;

	DrawTextEx(GetFontDefault(), mText.c_str(), Vector2{ textX, textY }, mFontSize, 3, mTextColor);
	if (mIsClicked) {
		SetColor(RED);
	}
	else {
		SetColor(WHITE);
	}
}
