#include<iostream>
#include<cassert>

#include"raylib.h"
#include"Utils.h"
#include"Vec2.h"
#include"Vec4.h"
#include"Mat3.h"
#include"Mat4.h"

#include"Player.h"
#include"PTurret.h"



int main()
{
	//


	// vector addition
	Vec2 v2a(13.5f, -48.23f), v2b(5, 3.99f), v2c;
	v2c = v2a + v2b;
	Vec3 v3a(13.5f, -48.23f, 862), v3b(5, 3.99f, -12), v3c;
	v3c = v3a + v3b;
	Vec4 v4a(13.5f, -48.23f, 862, 0), v4b(5, 3.99f, -12, 1), v4c;
	v4c = v4a + v4b;

	TEST("Vec2 addition", v2c, Vec2(18.5f, -44.24f));
	TEST("Vec3 addition", v3c, Vec3(18.5f, -44.24f, 850));
	TEST("Vec4 addition", v4c, Vec4(18.5f, -44.24f, 850, 1));

	// vector subtraction
	v2a = Vec2(13.5f, -48.23f);
	v2b = Vec2(5, 3.99f);
	v2c = v2a - v2b;
	v3a = Vec3(13.5f, -48.23f, 862);
	v3b = Vec3(5, 3.99f, -12);
	v3c = v3a - v3b;
	v4a = Vec4(13.5f, -48.23f, 862, 0);
	v4b = Vec4(5, 3.99f, -12, 1);
	v4c = v4a - v4b;

	TEST("Vec2 subtraction", v2c, Vec2(8.5f, -52.22f));
	TEST("Vec3 subtraction", v3c, Vec3(8.5f, -52.22f, 874));
	TEST("Vec4 subtraction", v4c, Vec4(8.5f, -52.22f, 874, -1));

	// vector post-scale
	v2a = Vec2(13.5f, -48.23f);
	v2c = v2a * 2.482f;
	v3a = Vec3(13.5f, -48.23f, 862);
	v3c = v3a * 0.256f;
	v4a = Vec4(13.5f, -48.23f, 862, 0);
	v4c = v4a * 4.89f;

	TEST("Vec2 post-scale", v2c, Vec2(33.5069999695f, -119.706863403f));
	TEST("Vec3 post-scale", v3c, Vec3(3.45600008965f, -12.3468809128f, 220.672012329f));
	TEST("Vec4 post-scale", v4c, Vec4(66.0149993896f, -235.844696045f, 4215.1796875f, 0));

	// vector pre-scale
	v2a = Vec2(13.5f, -48.23f);
	v2c = 2.482f * v2a;
	v3a = Vec3(13.5f, -48.23f, 862);
	v3c = 0.256f * v3a;
	v4a = Vec4(13.5f, -48.23f, 862, 0);
	v4c = 4.89f * v4a;

	TEST("Vec2 pre-scale", v2c, Vec2(33.5069999695f, -119.706863403f));
	TEST("Vec3 pre-scale", v3c, Vec3(3.45600008965f, -12.3468809128f, 220.672012329f));
	TEST("Vec4 pre-scale", v4c, Vec4(66.0149993896f, -235.844696045f, 4215.1796875f, 0));

	// vector dot product
	v2a = Vec2(13.5f, -48.23f);
	v2b = Vec2(5, 3.99f);
	float dot2 = v2a.dot(v2b);
	v3a = Vec3(13.5f, -48.23f, 862);
	v3b = Vec3(5, 3.99f, -12);
	float dot3 = v3a.dot(v3b);
	v4a = Vec4(13.5f, -48.23f, 862, 0);
	v4b = Vec4(5, 3.99f, -12, 1);
	float dot4 = v4a.dot(v4b);

	TEST("Vec2 dot", dot2, -124.937698364f);
	TEST("Vec3 dot", dot3, -10468.9375f);
	TEST("Vec4 dot", dot4, -10468.9375f);

	// vector cross product
	v3a = Vec3(13.5f, -48.23f, 862);
	v3b = Vec3(5, 3.99f, -12);
	v3c = v3a.cross(v3b);
	v4a = Vec4(13.5f, -48.23f, 862, 0);
	v4b = Vec4(5, 3.99f, -12, 1);
	v4c = v4a.cross(v4b);

	TEST("Vec3 cross", v3c, Vec3(-2860.62011719f, 4472.00000000f, 295.01498413f));
	TEST("Vec4 cross", v4c, Vec4(-2860.62011719f, 4472.00000000f, 295.01498413f, 0));

	// vector magnitude
	v2a = Vec2(13.5f, -48.23f);
	float mag2 = v2a.length();
	v3a = Vec3(13.5f, -48.23f, 862);
	float mag3 = v3a.length();
	v4a = Vec4(13.5f, -48.23f, 862, 0);
	float mag4 = v4a.length();

	TEST("Vec2 magnitude", mag2, 50.0837593079f);
	TEST("Vec3 magnitude", mag3, 863.453735352f);
	TEST("Vec4 magnitude", mag4, 863.453735352f);

	// vector normalize
	v2a = Vec2(-13.5f, -48.23f);
	v2a.normalize();
	v3a = Vec3(13.5f, -48.23f, 862);
	v3a.normalize();
	v4a = Vec4(243, -48.23f, 862, 0);
	v4a.normalize();

	TEST("Vec2 normalize", v2a, Vec2(-0.269548f, -0.962987f));
	TEST("Vec3 normalize", v3a, Vec3(0.0156349f, -0.0558571f, 0.998316f));
	TEST("Vec4 normalize", v4a, Vec4(0.270935f, -0.0537745f, 0.961094f, 0));

	// matrix rotation
	Mat3 m3a, m3b, m3c, m3d;
	Mat4 m4a, m4b, m4c, m4d;
	m3a.setRotationX(3.98f);
	m4a.setRotationX(4.5f);
	m3b.setRotationY(1.76f);
	m4b.setRotationY(-2.6f);
	m3c.setRotationZ(9.62f);
	m4c.setRotationZ(0.72f);

	TEST("Mat3 set rotate", m3a, Mat3(1, 0, 0, 0, -0.668648f, -0.743579f, 0, 0.743579f, -0.668648f));
	TEST("Mat3 set rotate", m3b, Mat3(-0.188077f, 0, -0.982154f, 0, 1, 0, 0.982154f, 0, -0.188077f));
	TEST("Mat3 set rotate", m3c, Mat3(-0.981005f, -0.193984f, 0, 0.193984f, -0.981005f, 0, 0, 0, 1));
	TEST("Mat4 set rotate", m4a, Mat4(1, 0, 0, 0, 0, -0.210796f, -0.97753f, 0, 0, 0.97753f, -0.210796f, 0, 0, 0, 0, 1));
	TEST("Mat4 set rotate", m4b, Mat4(-0.856889f, 0, 0.515501f, 0, 0, 1, 0, 0, -0.515501f, 0, -0.856889f, 0, 0, 0, 0, 1));
	TEST("Mat4 set rotate", m4c, Mat4(0.751806f, 0.659385f, 0, 0, -0.659385f, 0.751806f, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1));

	// vector transform
	v2a = Vec2(13.5f, -48.23f);
	v3a = Vec3(13.5f, -48.23f, 862);
	v3b = m3b * v3a;
	v3c = m3c * v3a;
	v4a = Vec4(13.5f, -48.23f, 862, 0);
	v4b = m4b * v4a;
	v4c = m4c * v4a;

	TEST("Vec3 matrix transform", v3b, Vec3(844.077941895f, -48.2299995422f, -175.38130188f));
	TEST("Vec3 matrix transform", v3c, Vec3(-22.5994224548f, 44.6950683594f, 862));
	TEST("Vec4 matrix transform", v4b, Vec4(-455.930236816f, -48.2299995422f, -731.678771973f, 0));
	TEST("Vec4 matrix transform", v4c, Vec4(41.951499939f, -27.3578968048f, 862, 0));

	// matrix multiply
	m3d = m3a * m3c;
	m4d = m4c * m4b;

	TEST("Mat3 multiply", m3d, Mat3(-0.981004655361f, 0.129707172513f, 0.14424264431f, 0.193984255195f, 0.655946731567f, 0.729454636574f, 0, 0.743579149246f, -0.668647944927f));
	TEST("Mat4 multiply", m4d, Mat4(-0.644213855267f, -0.565019249916f, 0.515501439571f, 0, -0.659384667873f, 0.751805722713f, 0, 0, -0.387556940317f, -0.339913755655f, -0.856888711452f, 0, 0, 0, 0, 1));

	// homogeneous point translation
	m3b = Mat3(1, 0, 0,
		0, 1, 0,
		0, 0, 1);
	m3b[2] = Vec3(55, 44, 1);
	m3c.setRotationZ(2.2f);
	m3c[2] = Vec3(55, 44, 1);
	m4b = Mat4(1, 0, 0, 0,
		0, 1, 0, 0,
		0, 0, 1, 0,
		0, 0, 0, 1);
	m4b[3] = Vec4(55, 44, 99, 1);
	m4c.setRotationZ(2.2f);
	m4c[3] = Vec4(55, 44, 99, 1);

	v3a = Vec3(13.5f, -48.23f, 1);
	v3b = m3b * v3a;
	v3c = m3c * v3a;
	v4a = Vec4(13.5f, -48.23f, -54, 1);
	v4b = m4b * v4a;
	v4c = m4c * v4a;

	TEST("Vec3 matrix translation A", v3b, Vec3(68.5f, -4.23f, 1));
	TEST("Vec3 matrix translation B", v3c, Vec3(86.0490112305f, 83.2981109619f, 1));
	TEST("Vec4 matrix translation A", v4b, Vec4(68.5f, -4.23f, 45, 1));
	TEST("Vec4 matrix translation B", v4c, Vec4(86.0490112305f, 83.2981109619f, 45, 1));

	// homogeneous vector translation
	m3b = Mat3(1, 0, 0,
		0, 1, 0,
		0, 0, 1);
	m3b[2] = Vec3(55, 44, 1);
	m3c.setRotationZ(2.2f);
	m3c[2] = Vec3(55, 44, 1);
	m4b = Mat4(1, 0, 0, 0,
		0, 1, 0, 0,
		0, 0, 1, 0,
		0, 0, 0, 1);
	m4b[3] = Vec4(55, 44, 99, 1);
	m4c.setRotationZ(2.2f);
	m4c[3] = Vec4(55, 44, 99, 1);

	v3a = Vec3(13.5f, -48.23f, 0);
	v3b = m3b * v3a;
	v3c = m3c * v3a;
	v4a = Vec4(13.5f, -48.23f, -54, 0);
	v4b = m4b * v4a;
	v4c = m4c * v4a;

	TEST("Vec3 matrix translation C", v3b, Vec3(13.5f, -48.23f, 0));
	TEST("Vec3 matrix translation D", v3c, Vec3(31.0490131378f, 39.2981109619f, 0));
	TEST("Vec4 matrix translation C", v4b, Vec4(13.5f, -48.23f, -54, 0));
	TEST("Vec4 matrix translation D", v4c, Vec4(31.0490131378f, 39.2981109619f, -54, 0));


	//------------------------------------------------------------------
	//-------------------------DEMO APPLICATION-------------------------
	//------------------------------------------------------------------

	int screenW = 1920;
	int screenH = 1080;

	InitWindow(screenW, screenH, "LibTest");

	ToggleFullscreen();

	Vec2 aC = { 00, 00 };
	Vec2 bC = { (float)screenW, 00 };
	Vec2 cC = { (float)screenW, (float)screenH };
	Vec2 dC = { 00, (float)screenH };

	Vec2 aD = { 00, 00 };
	Vec2 bD = { (float)screenW, 00 };
	Vec2 cD = { (float)screenW, (float)screenH };
	Vec2 dD = { 00, (float)screenH };

	Vec2 a = { 00, 00 };
	Vec2 b = { (float)screenW, 00 };
	Vec2 c = { (float)screenW, (float)screenH };
	Vec2 d = { 00, (float)screenH };

	float t = 0;

	float timer = 0;

	Player player;
	PTurret turret1(&player.transform, Vec2{ 10, 10 });
	PTurret turret2(&player.transform, Vec2{ -10, 10 });

	while (!WindowShouldClose())
	{
		if (timer < 1)
		{
			timer += 0.0003f;
		}
		else
		{
			aC = aD;
			bC = bD;
			cC = cD;
			dC = dD;

			aD = Vec2{ (float)(GetRandomValue(0, screenW)), (float)(GetRandomValue(0, screenH)) };
			bD = Vec2{ (float)(GetRandomValue(0, screenW)), (float)(GetRandomValue(0, screenH)) };
			cD = Vec2{ (float)(GetRandomValue(0, screenW)), (float)(GetRandomValue(0, screenH)) };
			dD = Vec2{ (float)(GetRandomValue(0, screenW)), (float)(GetRandomValue(0, screenH)) };

			timer -= 1;
		}

		a = lerp(aC, aD, timer);
		b = lerp(bC, bD, timer);
		c = lerp(cC, cD, timer);
		d = lerp(dC, dD, timer);

		player.Update(GetFrameTime());
		turret1.Update(GetFrameTime());
		turret2.Update(GetFrameTime());

		BeginDrawing();
		ClearBackground(BLACK);

		

		for (int i = 0; i < 20; i++)
		{
			Vec2 hold1 = lerp(a, b, i * 0.05f);
			Vec2 hold2 = lerp(b, c, i * 0.05f);
			Vec2 hold3 = lerp(c, d, i * 0.05f);
			Vec2 hold5 = lerp(hold2, hold3, i * 0.05f);
			Vec2 hold4 = lerp(hold1, hold2, i * 0.05f);
			Vec2 hold6 = lerp(hold4, hold5, i * 0.05f);
			DrawCircle(hold1.x, hold1.y, 3, GREEN); 
			DrawCircle(hold2.x, hold2.y, 3, GREEN);
			DrawCircle(hold3.x, hold3.y, 3, GREEN);
			DrawLine(hold1.x, hold1.y, hold2.x, hold2.y, GREEN);
			DrawLine(hold2.x, hold2.y, hold3.x, hold3.y, GREEN);
			DrawCircle(hold4.x, hold4.y, 3, BLUE);
			DrawCircle(hold5.x, hold5.y, 3, BLUE);
			DrawLine(hold4.x, hold4.y, hold5.x, hold5.y, BLUE);
			DrawCircle(hold6.x, hold6.y, 3, YELLOW);
		}
		DrawCircle(a.x, a.y, 3, RED);
		DrawCircle(b.x, b.y, 3, RED);
		DrawCircle(c.x, c.y, 3, RED);
		DrawCircle(d.x, d.y, 3, RED);

		DrawLine(a.x, a.y, b.x, b.y, RED);
		DrawLine(b.x, b.y, c.x, c.y, RED);
		DrawLine(c.x, c.y, d.x, d.y, RED);

		while (t < 1)
		{
			Vec2 p0 = cubicBezier<Vec2>(a, b, c, d, t);
			Vec2 p1 = cubicBezier<Vec2>(a, b, c, d, t + 0.05f);
			DrawLineV(Vector2{ p0.x, p0.y }, Vector2{ p1.x, p1.y }, YELLOW);
			t += 0.05f;
		}
		t = 0;

		player.Draw();
		turret1.Draw();
		turret2.Draw();

		EndDrawing();
	}
	CloseWindow();
	return 0;
}