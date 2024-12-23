#pragma once

class SceneManager;

class IScene
{
public:

	virtual ~IScene() = default;

	virtual void Initialize() = 0;

	virtual void Finalize() = 0;

	virtual void Update(char keys[256], char preKeys[256]) = 0;

	virtual void Draw() = 0;

	virtual void SetSceneManager(SceneManager* sceneManager) { sceneManager_ = sceneManager; }

private:

	// シーンマネージャー（借りてくる）
	SceneManager* sceneManager_ = nullptr;

};

