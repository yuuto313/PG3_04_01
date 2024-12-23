#pragma once
#include "IScene.h"
#include <Novice.h>
class ClearScene : public IScene
{
public:

	void Initialize() override;

	void Finalize() override;

	void Update(char keys[256], char preKeys[256]) override;

	void Draw() override;

private:

	int texHandle_;

};

