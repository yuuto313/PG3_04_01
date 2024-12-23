#include "PlayerBullet.h"

void PlayerBullet::Initialize(const Vector2& pos)
{
	this->pos_ = pos;
	speed_ = 4.0f;
	scale_ = { 20.0f,20.0f };

	texHandle_ = Novice::LoadTexture("./NoviceResources/white1x1.png");

}

void PlayerBullet::Update()
{
	pos_.y -= speed_;
}

void PlayerBullet::Draw()
{
	Novice::DrawSprite(static_cast<int>(pos_.x), static_cast<int>(pos_.y), texHandle_, scale_.x, scale_.y, 0.0f, 0xFFFFFFFF);
}
