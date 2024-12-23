#include "StageScene.h"
#include "SceneManager.h"
void StageScene::Initialize()
{
	player_ = std::make_unique<Player>();
	player_->Initialize();

	boss_ = std::make_unique<Boss>();
	boss_->Initialize();
}

void StageScene::Finalize()
{
}

void StageScene::Update(char keys[256], char preKeys[256])
{

	player_->Update(keys,preKeys);

	boss_->Update();

    float bossRadius = boss_->GetRadius();
    Vector2 bossPos = boss_->GetPos();

    for (const auto& bullet : player_->GetBullets()) {
        Vector2 bulletPos = bullet->GetPos();
        float bulletRadius = bullet->GetRadius();

        // 敵と弾の距離
        float dx = bossPos.x - bulletPos.x;
        float dy = bossPos.y - bulletPos.y;
        float distanceSquared = dx * dx + dy * dy;

        // 当たり判定のチェック
        if (distanceSquared <= (bossRadius + bulletRadius) * (bossRadius + bulletRadius)) {
            // シーン切り替え
            SceneManager::GetInstance()->ChangeScene("CLEAR");
            return;
        }
    }
}

void StageScene::Draw()
{
	player_->Draw();

	boss_->Draw();
}
