#pragma once
#include <Novice.h>
#include "Vector2.h"
#include "PlayerBullet.h"
#include <memory>
#include <list>
class Player
{
public:

	void Initialize();

	void Update(char keys[256],char preKeys[256]);

	void Draw();

	void Attack(char keys[256],char preKeys[256]);

	const std::list<std::unique_ptr<PlayerBullet>>& GetBullets() const {
		return bullets_;
	}
	Vector2 GetBulletPos();
	float GetBulletRadius();

private:

	std::list<std::unique_ptr<PlayerBullet>> bullets_;

	int texHandle_;

	Vector2 pos_;
	Vector2 scale_;
	float speed_;

};

