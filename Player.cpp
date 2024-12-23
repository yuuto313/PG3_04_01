#include "Player.h"

void Player::Initialize()
{
	pos_ = { 640.0f,600.0f };
	scale_ = { 60.0f,60.0f };
	speed_ = 7.0f;
	texHandle_ = Novice::LoadTexture("./NoviceResources/white1x1.png");
}

void Player::Update(char keys[256], char preKeys[256])
{
	if (keys[DIK_A]) {
		pos_.x -= speed_;
	}

	if (keys[DIK_D]) {
		pos_.x += speed_;
	}

	// プレイヤーのポジションが画面外に出ないように制限
	float halfWidth = scale_.x / 2.0f;

	if (pos_.x - halfWidth < 0.0f) {
		pos_.x = halfWidth;
	}

	if (pos_.x + halfWidth > 1280.0f) {
		pos_.x = 1280.0f - halfWidth;
	}
	
	Attack(keys,preKeys);

}

void Player::Draw()
{
	for (const auto& bullet : bullets_) {
		bullet->Draw();
	}

	Novice::DrawSprite(static_cast<int>(pos_.x), static_cast<int>(pos_.y), texHandle_, scale_.x, scale_.y, 0.0, 0xFFFFFFFF);
}

void Player::Attack(char keys[256], char preKeys[256])
{

	if (keys[DIK_SPACE] && !preKeys[DIK_SPACE]) {
		std::unique_ptr<PlayerBullet> bullet = std::make_unique<PlayerBullet>();
		bullet->Initialize(pos_);
		bullets_.push_back(std::move(bullet));
	}

	for (const auto& bullet : bullets_) {
		bullet->Update();
	}
}

Vector2 Player::GetBulletPos()
{
	if (!bullets_.empty()) {
		return bullets_.front()->GetPos();
	}
	return { -1.0f, -1.0f }; // 弾が存在しない場合のデフォルト値
}

float Player::GetBulletRadius()
{
	if (!bullets_.empty()) {
		return bullets_.front()->GetRadius();
	}
	return 0.0f; // 弾が存在しない場合のデフォルト値
}
