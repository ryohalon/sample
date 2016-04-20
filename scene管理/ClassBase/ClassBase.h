#pragma once
#include "../Singleton/sin_gamepad.h"

class ClassBase
{
private:

protected:

public:

	ClassBase() = default;
	virtual ~ClassBase() = default;

	virtual void Setup() = 0;
	virtual void Update() = 0;
	virtual void Draw() = 0;
};