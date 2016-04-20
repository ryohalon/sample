#pragma once
#include "../SceneBase/SceneBase.h"

class Result : public SceneBase
{
private:

	Font font;

public:

	Result() :
		font(Font("res/jadhei01m.ttf"))
	{
		font.size(64);
		next_scene_name = SceneName::TITLE;
	}

	~Result() = default;

	void Setup() {}
	void Update()
	{
		if (App::Get().isPushKey(GLFW_KEY_ENTER))
			is_finish = true;
	}
	void Draw()
	{
		font.draw("Result", -font.drawSize("Result") / 2, Color::red);
	}
};