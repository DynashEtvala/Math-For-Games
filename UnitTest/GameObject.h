#pragma once
#include "Transform2D.h"
class GameObject
{
public:
	GameObject();
	~GameObject();
	Transform2D transform;
	virtual void Update(float gameTime) = 0;
	virtual void Draw() = 0;
};

