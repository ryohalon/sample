#pragma once
#include "../lib/framework.hpp"
#include <iostream>

enum WindowSize
{
	WIDTH = 786,
	HEIGHT = 512
};

class App
{
private:

public:

	static AppEnv& Get()
	{
		static AppEnv env(WindowSize::WIDTH, WindowSize::HEIGHT);

		return env;
	}
};