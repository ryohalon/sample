#include "Mouse_Event.h"

struct Mouse_Event::MouseStatus
{
	std::set<int> push_mouse_button;
	std::set<int> press_mouse_button;
	std::set<int> pull_mouse_button;
	Vec2i mouse_pos;
};



Mouse_Event::Mouse_Event()
{
	mouse_status = std::make_unique<MouseStatus>();
	mouse_status->mouse_pos = Vec2i::zero();
}

Mouse_Event::~Mouse_Event()
{

}

Vec2i Mouse_Event::GetMousePosition()
{
	return mouse_status->mouse_pos;
}

void Mouse_Event::UpdateMousePosition(MouseEvent& mouse_event)
{
	mouse_status->mouse_pos = mouse_event.getPos();
}

void Mouse_Event::PushButton(MouseEvent& mouse_event)
{
	if (mouse_event.isLeftDown())
	{
		mouse_status->push_mouse_button.insert(MouseEvent::LEFT_DOWN);
		mouse_status->press_mouse_button.insert(MouseEvent::LEFT_DOWN);
	}

	if (mouse_event.isRightDown())
	{
		mouse_status->push_mouse_button.insert(MouseEvent::RIGHT_DOWN);
		mouse_status->press_mouse_button.insert(MouseEvent::RIGHT_DOWN);
	}
}

void Mouse_Event::PullButton(MouseEvent& mouse_event)
{
	if (mouse_event.isLeft())
	{
		mouse_status->press_mouse_button.erase(MouseEvent::LEFT_DOWN);
		mouse_status->pull_mouse_button.insert(MouseEvent::LEFT_DOWN);
	}

	if (mouse_event.isRight())
	{
		mouse_status->press_mouse_button.erase(MouseEvent::RIGHT_DOWN);
		mouse_status->pull_mouse_button.insert(MouseEvent::RIGHT_DOWN);
	}
}

void Mouse_Event::FlushInput()
{
	mouse_status->push_mouse_button.clear();
	mouse_status->pull_mouse_button.clear();
}

bool Mouse_Event::IsPushButton(int button)
{
	return mouse_status->push_mouse_button.find(button) != mouse_status->push_mouse_button.cend();
}

bool Mouse_Event::IsPressButton(int button)
{
	return mouse_status->press_mouse_button.find(button) != mouse_status->press_mouse_button.cend();
}

bool Mouse_Event::IsPullButton(int button)
{
	return mouse_status->pull_mouse_button.find(button) != mouse_status->pull_mouse_button.cend();
}
