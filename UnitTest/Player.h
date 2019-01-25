#pragma once
#include"Transform2D.h"
class Player
{
public:
	Transform2D transform;
	Player();
	~Player();
	void Update(float deltaT);
	void Draw();
};

