#include "SceneFactory.h"
#include "TitleScene.h"
#include "StageScene.h"
#include "ClearScene.h"

std::unique_ptr<IScene> SceneFactory::CreateScene(const std::string& sceneName)
{
	// 次のシーンを生成
	IScene* newScene = nullptr;

	if (sceneName == "TITLE") {
		newScene = new TitleScene();
	} else if (sceneName == "GAME") {
		newScene = new StageScene();
	} else if (sceneName == "CLEAR") {
		newScene = new ClearScene();
	}

	return std::unique_ptr<IScene>(newScene);
}
