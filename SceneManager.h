#pragma once
#include <memory>
#include <Novice.h>
#include <string>
#include "IScene.h"
#include "AbstractSceneFactory.h"

class SceneManager
{
public:

	void Finalize();

	void Update(char keys[256], char preKeys[256]);

	void Draw();

	/// <summary>
	/// 次のシーン予約
	/// </summary>
	/// <param name="sceneName"></param>
	void ChangeScene(const std::string& sceneName);

	/// <summary>
	/// シーンファクトリーのセッター
	/// </summary>
	/// <param name="sceneFactory"></param>
	void SetSceneFactory(AbstractSceneFactory* sceneFactory) { sceneFactory_ = sceneFactory; }

private:

	// 現在のシーン
	std::unique_ptr<IScene> scene_;

	// 次のシーン
	std::unique_ptr<IScene> nextScene_;

	// シーンファクトリー（借りてくる）
	AbstractSceneFactory* sceneFactory_ = nullptr;

private:// シングルトン設計

	static SceneManager* instance;

	/// <summary>
	/// コンストラクタ、デストラクタの隠蔽
	/// </summary>
	SceneManager() = default;
	~SceneManager() = default;

	/// <summary>
	/// コピーコンストラクタの封印
	/// </summary>
	/// <param name=""></param>
	SceneManager(SceneManager&) = delete;

	/// <summary>
	/// コピー代入演算の封印
	/// </summary>
	/// <param name=""></param>
	/// <returns></returns>
	SceneManager& operator=(SceneManager&) = delete;

public:

	/// <summary>
	///	シングルトンインスタンスの取得
	/// </summary>
	/// <returns></returns>
	static SceneManager* GetInstance();
};

