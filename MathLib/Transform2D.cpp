#pragma once
#include "Transform2D.h"

Transform2D::Transform2D()
{
	localPos = Vec2{ 0,0 };
	localRot = 0;
	localScale = Vec2{ 1, 1 };
	parent = nullptr;
}

void Transform2D::translate(const Vec2 &offset)
{
	localPos += offset;
}
void Transform2D::rotate(const float angle)
{
	localRot += angle;
}

void Transform2D::lookAt(const Transform2D &target)
{
	Vec2 temp(target.localPos - localPos);
	localRot = temp.angleBetween(Vec2{ 1, 0 });
}
Vec2 Transform2D::forward() const
{
	Mat3 mat = getTRSMatrix();
	return Vec2{ cosf(localRot * (22.0f / 7.0f) / 180), sinf(localRot * (22.0f / 7.0f) / 180)};
}
Vec2 Transform2D::right() const
{
	Mat3 mat = getTRSMatrix();
	return Vec2{ asinf(localRot), cosf(localRot) };
}
void Transform2D::setForward(const Vec2 &newFwd)
{
	localRot = newFwd.angleBetween(Vec2{ 1, 0 });
}

Mat3 Transform2D::getTRSMatrix() const
{
	return Mat3::translation(localPos) * Mat3::rotation(localRot) * Mat3::scale(localScale);
}

Mat3 Transform2D::getWorldTRS() const
{
	if (parent == nullptr)
	{
		return getTRSMatrix();
	}
	else
	{
		return getTRSMatrix() * parent->getWorldTRS();
	}
}


Vec2 Transform2D::worldPosition() const
{
	if (parent == nullptr)
	{
		return localPos;
	}
	else
	{
		float A = atan2(localPos.x, localPos.y) + parent->worldRotation() * (22.0f / 7.0f) / 180;
		float B = localPos.length();
		Vec2 parPos = parent->worldPosition();
		return Vec2{ parPos.x + cosf(A) * B, parPos.y + sinf(A) * B };
	}
}
float Transform2D::worldRotation() const
{
	if (parent == nullptr)
	{
		return localRot;
	}
	else
	{
		return localRot + parent->worldRotation();
	}
}
Vec2 Transform2D::worldScale() const
{
	if (parent == nullptr)
	{
		return localScale;
	}
	else
	{
		return Vec2{ localScale.x * parent->worldScale().x, localScale.y * parent->worldScale().y };
	}
}

void Transform2D::setParent(Transform2D *_parent)
{
	parent = _parent;
	parent->children.push_back(this);
}
Transform2D* Transform2D::getParent()
{
	return parent;
}
Transform2D const * Transform2D::getParent() const
{
	return parent;
}

Transform2D * Transform2D::getChildren()
{
	return children[0];
}
Transform2D *const Transform2D::getChildren() const
{
	return children[0];
}
size_t Transform2D::getChildrenCount() const
{
	return children.size();
}



