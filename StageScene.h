#pragma once
#include "IScene.h"
#include "Player.h"
#include "Boss.h"
#include <Novice.h>
#include <memory>
class StageScene : public IScene
{
public:

	void Initialize() override;

	void Finalize() override;

	void Update(char keys[256], char preKeys[256]) override;

	void Draw()override;

private:

	std::unique_ptr<Player> player_;
	std::unique_ptr<Boss> boss_;

};

