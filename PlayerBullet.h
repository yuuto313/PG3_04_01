#pragma once
#include <Novice.h>
#include "Vector2.h"
class PlayerBullet
{
public:

	void Initialize(const Vector2& pos);

	void Update();

	void Draw();

	float GetRadius() { return radius_; }

	Vector2 GetPos() { return pos_; }

private:

	Vector2 pos_ = {};
	Vector2 scale_;
	float speed_;

	float radius_ = 30.0f;

	int texHandle_;

};

