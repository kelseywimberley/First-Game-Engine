#pragma once

#include "GameObject.h"
#include "Transform.h"

class Collision
{
public:
	static bool AABBCollision(GameObject g1, GameObject g2);
	static bool WallCollision(GameObject g, Transform t);
};
