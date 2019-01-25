#include "Player.h"
#include "raylib.h"


Player::Player()
{}


Player::~Player()
{}


void Player::Update(float DeltaT)
{
	if (IsKeyDown(KEY_A))
	{
		transform.rotate(-120 * DeltaT);
	}
	if (IsKeyDown(KEY_D))
	{
		transform.rotate(120 * DeltaT);
	}
	if (IsKeyDown(KEY_W))
	{
		transform.translate(transform.forward() * 100 * DeltaT);
	}
	if (IsKeyDown(KEY_S))
	{
		transform.translate(transform.forward() * -100 * DeltaT);
	}
}

void Player::Draw()
{
	DrawText(FormatText("PosX: %.1f\nPosY: %.1f\nRot: %.3f\nSclX: %.1f\nSclY: %.1f", transform.getWorldTRS().m3, transform.getTRSMatrix().m6, transform.worldRotation(), transform.localScale.x, transform.localScale.y), 10, 10, 25, WHITE);
	DrawRectanglePro(Rectangle{ transform.worldPosition().x, transform.worldPosition().y, 50, 50 }, Vector2{ 25, 25 }, transform.worldRotation(), WHITE);
	//DrawRectangle(transform.worldPosition().x, transform.worldPosition().y, 50, 50, WHITE);
	DrawLine(transform.worldPosition().x, transform.worldPosition().y, transform.worldPosition().x + transform.forward().x * 100, transform.worldPosition().y + transform.forward().y * 100, RED);
}


