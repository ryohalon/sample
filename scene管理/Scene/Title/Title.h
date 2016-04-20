#pragma once
#include "../SceneBase/SceneBase.h"

class Title : public SceneBase
{
private:

	Font font;

public:

	Title() :
		font(Font("res/jadhei01m.ttf"))
	{
		font.size(64);
		next_scene_name = SceneName::GAMEMAIN;
	}

	~Title() = default;

	void Setup() {}
	void Update()
	{
		if (App::Get().isPushKey(GLFW_KEY_ENTER))
			is_finish = true;
	}
	void Draw()
	{
		font.draw("Title", -font.drawSize("Title") / 2, Color::white);
	}
};