#pragma once
#include "../SceneBase/SceneBase.h"

class GameMain : public SceneBase
{
private:

	Font font;

public:

	GameMain() :
		font(Font("res/jadhei01m.ttf"))
	{
		font.size(64);
		next_scene_name = SceneName::RESULT;
	}

	~GameMain() = default;

	void Setup() {}
	void Update()
	{
		if (App::Get().isPushKey(GLFW_KEY_ENTER))
			is_finish = true;
	}

	void Draw()
	{
		font.draw("GameMain", -font.drawSize("GameMain") / 2, Color::blue);
	}
};