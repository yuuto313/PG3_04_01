#include "ClearScene.h"
#include "SceneManager.h"
void ClearScene::Initialize()
{
	texHandle_ = Novice::LoadTexture("./NoviceResources/clear.png");
}

void ClearScene::Finalize()
{
}

void ClearScene::Update(char keys[256], char preKeys[256])
{
	if (!preKeys[DIK_RETURN] && keys[DIK_RETURN]) {
		// シーン切り替え
		SceneManager::GetInstance()->ChangeScene("TITLE");
	}
}

void ClearScene::Draw()
{
	Novice::DrawSprite(0, 0, texHandle_, 1.0f, 1.0f, 0.0f, 0xFFFFFFFF);
}
