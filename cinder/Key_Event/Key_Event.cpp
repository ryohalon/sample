#include "Key_Event.h"


struct Key_Event::KeyStatus
{
	std::set<int> push_key;
	std::set<int> press_key;
	std::set<int> pull_key;
};



Key_Event::Key_Event()
{
	key_status = std::make_unique<KeyStatus>();
}

Key_Event::~Key_Event()
{

}

void Key_Event::PushKey(KeyEvent& key_event)
{
	if (key_status->press_key.find(key_event.getCode()) == key_status->press_key.cend())
	{
		key_status->push_key.insert(key_event.getCode());
	}

	if (key_status->press_key.find(key_event.getCode()) == key_status->press_key.cend())
		key_status->press_key.insert(key_event.getCode());
}

void Key_Event::PullKey(KeyEvent& key_event)
{
	key_status->press_key.erase(key_event.getCode());
	key_status->pull_key.insert(key_event.getCode());
}

void Key_Event::FlushInput()
{
	key_status->push_key.clear();
	key_status->pull_key.clear();
}

bool Key_Event::IsPushKey(int key)
{
	return key_status->push_key.find(key) != key_status->push_key.cend();
}

bool Key_Event::IsPressKey(int key)
{
	return key_status->press_key.find(key) != key_status->press_key.cend();
}

bool Key_Event::IsPullKey(int key)
{
	return key_status->pull_key.find(key) != key_status->pull_key.cend();
}