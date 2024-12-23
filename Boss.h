#pragma once
#include <Novice.h>
#include "Vector2.h"
class Boss
{
public:

	void Initialize();

	void Update();

	void Draw();

	float GetRadius() { return radius_; }

	Vector2 GetPos() { return pos_; }

private:

	int texHandle_;

	Vector2 pos_;
	Vector2 scale_;

	float radius_ = 20.0f;

};

