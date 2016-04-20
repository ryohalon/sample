#pragma once
#include "../Scene/Title/Title.h"
#include "../Scene/GameMain/GameMain.h"
#include "../Scene/Result/Result.h"

class SceneManager : public ClassBase
{
private:

	SceneBase* now_scene;

	void Setup()
	{
		now_scene->Setup();
	}

	void Update()
	{
		now_scene->Update();
	}

	void Draw()
	{
		now_scene->Draw();
	}

	void ChangeScene()
	{
		if (now_scene->GetIsFinish() != true)
			return;

		std::function<void()> CreateScene[] = {
			[&]() {
			delete now_scene;
			now_scene = new Title();
		},
			[&]() {
			delete now_scene;
			now_scene = new GameMain();
		},
			[&]() {
			delete now_scene;
			now_scene = new Result();
		}
		};

		CreateScene[static_cast<int>(now_scene->GetNextSceneName())]();
		
		Setup();
	}

public:

	SceneManager()
	{
		now_scene = new Title();
	}

	~SceneManager()
	{
		delete now_scene;
	}

	void MainLoop()
	{
		while (App::Get().isOpen())
		{
			if (!App::Get().isOpen())
				break;

			Update();

			App::Get().begin();

			Draw();

			App::Get().end();

			ChangeScene();
		}

	}
};