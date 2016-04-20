#pragma once
#include "../../ClassBase/ClassBase.h"

enum class SceneName
{
	TITLE,
	GAMEMAIN,
	RESULT
};

class SceneBase : public ClassBase
{
private:

protected:

	bool is_finish;
	SceneName next_scene_name;

public:

	SceneBase() :
		is_finish(false)
	{ }
	virtual ~SceneBase() = default;

	bool GetIsFinish() const { return is_finish; }
	SceneName GetNextSceneName() const { return next_scene_name; }

	virtual void Setup(){}
	virtual void Update(){}
	virtual void Draw(){}
};