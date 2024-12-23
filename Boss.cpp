#include "Boss.h"

void Boss::Initialize()
{
	texHandle_ = Novice::LoadTexture("./NoviceResources/white1x1.png");

	pos_ = { 640.0f,100.0f };
	scale_ = { 30.0f,30.0f };
}

void Boss::Update()
{
}

void Boss::Draw()
{
	Novice::DrawSprite(static_cast<int>(pos_.x), static_cast<int>(pos_.y), texHandle_, scale_.x, scale_.y, 0.0f, 0xFFFFFFFF);
}
