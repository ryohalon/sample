#pragma once
#include "cinder/app/KeyEvent.h"
#include <set>
#include <memory>

using namespace ci;
using namespace ci::app;

#define KEY Key_Event::Get()


class Key_Event
{
private:

	struct KeyStatus;

	std::unique_ptr<KeyStatus> key_status;

public:

	Key_Event();
	~Key_Event();

	static Key_Event& Get()
	{
		static Key_Event key_event;

		return key_event;
	}

	void PushKey(KeyEvent& key_event);
	void PullKey(KeyEvent& key_event);

	void FlushInput();

	bool IsPushKey(int key);
	bool IsPressKey(int key);
	bool IsPullKey(int key);
};