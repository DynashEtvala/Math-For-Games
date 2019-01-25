#pragma once
#include "Transform2D.h"
class PTurret
{
public:
	Transform2D transform;
	PTurret();
	PTurret(Transform2D* newParent);
	PTurret(Transform2D* newParent, Vec2 pos);
	~PTurret();
	void Update(float DeltaT);
	void Draw();
};

