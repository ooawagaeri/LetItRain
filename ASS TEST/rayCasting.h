//  Module:             Gameplay Programming
//  Assignment1:        LET IT RAIN
//  Student Name:       Timothy Chua
//  Student Number:     10165581F

#ifndef _RAY_H
#define _RAY_H
#define WIN32_LEAN_AND_MEAN

#include <vector>
#include <queue>
#include <math.h>
#include "entity.h"
#include "constants.h"
#include "enemyManager.h"

class Ray
{
private:
	Input *mouse;
	float x;
	float y;
	VECTOR2 pos;
	VECTOR2 Ray::maxDist(VECTOR2 cast);
	float direction;
	float visibilityAngle;
	int viewDistance;
	std::queue<CUSTOMVERTEX> vision;

public:
	// constructor
	Ray(Input *input);
	// inherited member functions
	VECTOR2 CastRayVector(VECTOR2 target, const HUNTERSHIP &walls);
	void UpdateVision(const HUNTERSHIP &walls);
	void Render(Graphics *g);
};
#endif