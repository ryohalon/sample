#pragma once
#include "cinder/app/MouseEvent.h"
#include <set>
#include <memory>

using namespace ci;
using namespace ci::app;

#define MOUSE Mouse_Event::Get()


class Mouse_Event
{
private:

	struct MouseStatus;

	std::unique_ptr<MouseStatus> mouse_status;

public:

	Mouse_Event();
	~Mouse_Event();

	static Mouse_Event& Get()
	{
		static Mouse_Event mouse_event;

		return mouse_event;
	}

	//マウスの座標を取得
	Vec2i GetMousePosition();

	//入力情報の削除
	void FlushInput();

	void UpdateMousePosition(MouseEvent& mouse_event);
	void PushButton(MouseEvent& mouse_event);
	void PullButton(MouseEvent& mouse_event);

	bool IsPushButton(int button);
	bool IsPressButton(int button);
	bool IsPullButton(int button);
};