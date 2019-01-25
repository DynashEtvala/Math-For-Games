#pragma once
#include "Vec2.h"
#include "Mat3.h"

struct Transform2D
{
public:
	Transform2D();

	Vec2 localPos;
	float localRot;
	Vec2 localScale;

	void translate(const Vec2 &offset);
	void rotate(const float angle);

	void lookAt(const Transform2D &target);
	Vec2 forward() const;
	Vec2 right() const;
	void setForward(const Vec2 &newFwd);

	Mat3 getTRSMatrix() const;
	Mat3 getWorldTRS() const;

	Vec2 worldPosition() const;
	float worldRotation() const;
	Vec2 worldScale() const;

	void setParent(Transform2D *parent);
	Transform2D *getParent();
	Transform2D const *getParent() const;

	Transform2D *getChildren();
	Transform2D *const getChildren() const;
	size_t getChildrenCount() const;

private:
	Transform2D * parent;
	std::vector<Transform2D *> children;
};