#include "TitleScene.h"
#include "SceneManager.h"

void TitleScene::Initialize()
{
	texHandle_ = Novice::LoadTexture("./NoviceResources/title.png");
}

void TitleScene::Finalize()
{
}

void TitleScene::Update(char keys[256], char preKeys[256])
{
	if (!preKeys[DIK_RETURN] && keys[DIK_RETURN]) {
		// シーン切り替え
		SceneManager::GetInstance()->ChangeScene("GAME");
	}
}

void TitleScene::Draw()
{
	Novice::DrawSprite(0, 0, texHandle_, 1.0f, 1.0f, 0.0f, 0xFFFFFFFF);
}
