#include "PTurret.h"
#include "raylib.h"



PTurret::PTurret()
{}


PTurret::PTurret(Transform2D* newParent)
{
	transform.setParent(newParent);
}


PTurret::PTurret(Transform2D* newParent, Vec2 pos)
{
	transform.setParent(newParent);
	transform.localPos = pos;
}


PTurret::~PTurret()
{}


void PTurret::Update(float DeltaT)
{
	if (IsKeyDown(KEY_Q))
	{
		transform.rotate(-120 * DeltaT);
	}
	if (IsKeyDown(KEY_E))
	{
		transform.rotate(120 * DeltaT);
	}
}

void PTurret::Draw()
{
	DrawRectanglePro(Rectangle{ transform.worldPosition().x, transform.worldPosition().y, 50, 10 }, Vector2{ 5, 5 }, transform.worldRotation(), GRAY);
}



