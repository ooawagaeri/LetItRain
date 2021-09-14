//  Module:             Gameplay Programming
//  Assignment1:        LET IT RAIN
//  Student Name:       Timothy Chua
//  Student Number:     10165581F

#include "enemyShip.h"

EnemyShip::EnemyShip() : Entity()
{
	alive = true;
	outOfBound = false;
}

bool EnemyShip::initialize(Game *gamePtr, int width, int height, int ncols,
	TextureManager *textureM)
{
	//explosion.initialize(gamePtr->getGraphics(), explosionNS::WIDTH, explosionNS::HEIGHT, explosionNS::TEXTURE_COLS, textureM);
	//explosion.setFrames(explosionNS::START_FRAME, explosionNS::END_FRAME);
	//explosion.setCurrentFrame(explosionNS::START_FRAME);
	//explosion.setFrameDelay(explosionNS::ANIMATION_DELAY);
	//explosion.setLoop(false);                  // do not loop animation
	return(Entity::initialize(gamePtr, width, height, ncols, textureM));
}

void EnemyShip::update(float frameTime)
{
	Entity::update(frameTime);
	spriteData.x -= frameTime * velocity.x;
	spriteData.y -= frameTime * velocity.y;

	if (explosionOn)
	{
		visible = false;
		active = false;

		explosion.update(frameTime);
		if (explosion.getAnimationComplete())
		{
			alive = false;
			explosionOn = false;
			explosion.setAnimationComplete(false);
			return;
		}
	}

	else if (damagedOn)
	{
		damaged.update(frameTime);
		if (damaged.getAnimationComplete())
		{
			damagedOn = false;
			damaged.setAnimationComplete(false);
		}
	}

	if ((health <= 0 && explosionOn == false) || (getY() > GAME_HEIGHT + getHeight()*getScale()))
	{
		if (getY() > GAME_HEIGHT + getHeight()*getScale())
			outOfBound = true;
		alive = false;
		active = false;
	}
}

// To find closest ship vector position
void EnemyShip::ai(Entity &ship1, Entity &ship2)
{
	VECTOR2 ship1Pos = *getCenter() - *ship1.getCenter();
	VECTOR2 ship2Pos = *getCenter() - *ship2.getCenter();
	VECTOR2 *target;

	if (D3DXVec2Length(&ship1Pos) < D3DXVec2Length(&ship2Pos)) 
	{ 
		target = D3DXVec2Normalize(&ship1Pos, &ship1Pos);
		*target = VECTOR2(target->x * enemyBulletNS::SPEED, target->y * enemyBulletNS::SPEED);
	}
	else
	{
		target = D3DXVec2Normalize(&ship2Pos, &ship2Pos);
		*target = VECTOR2(target->x * enemyBulletNS::SPEED, target->y * enemyBulletNS::SPEED);
	}
	nearestTarget = *target;
}

void EnemyShip::draw()
{
	Image::draw();              // draw ship
	if (explosionOn)
		explosion.draw(spriteData, colorFilter);
	if (damagedOn)
		damaged.draw(spriteData, colorFilter);
}

void EnemyShip::damage(WEAPON weapon)
{
	if (weapon != SHIP)
	{
		if (weapon == BULLET)
			health -= 3;
		else if (weapon == LASER)
			health -= 5;
		else if (weapon == MISSILE)
			health -= 25;

		if (health <= 0 && !explosionOn)
		{
			audio->playCue(SMALLEXP);
			explosionOn = true;
		}
		else
			damagedOn = true;
	}
	else if (!explosionOn)
	{
		audio->playCue(SMALLEXP);
		health = 0;
		explosionOn = true;
	}
}