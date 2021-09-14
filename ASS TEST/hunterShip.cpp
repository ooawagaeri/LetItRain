//  Module:             Gameplay Programming
//  Assignment1:        LET IT RAIN
//  Student Name:       Timothy Chua
//  Student Number:     10165581F

#include "hunterShip.h"

HunterShip::HunterShip() : EnemyShip()
{
	health = hunterShipNS::HEALTH;
	spriteData.width = hunterShipNS::WIDTH;           // size of Ship1
	spriteData.height = hunterShipNS::HEIGHT;
	spriteData.x = hunterShipNS::X;                   // location on screen
	spriteData.y = hunterShipNS::Y;
	spriteData.rect.bottom = hunterShipNS::HEIGHT;    // rectangle to select parts of an image
	spriteData.rect.right = hunterShipNS::WIDTH;
	spriteData.angle = hunterShipNS::ROTATION;
	spriteData.scale = hunterShipNS::SCALE;
	velocity.x = 0;                             // velocity X
	velocity.y = hunterShipNS::SPEED;                             // velocity Y
	frameDelay = hunterShipNS::ANIMATION_DELAY;
	startFrame = hunterShipNS::START_FRAME;     // first frame of ship animation
	endFrame = hunterShipNS::END_FRAME;     // last frame of ship animation
	currentFrame = startFrame;
	bulletOn = false;
	explosionOn = false;
	damagedOn = false;
	mass = hunterShipNS::MASS;
	edge = RECT{ (long)(-hunterShipNS::WIDTH*hunterShipNS::SCALE / 2), (long)(-hunterShipNS::HEIGHT*hunterShipNS::SCALE / 2), (long)(hunterShipNS::WIDTH*hunterShipNS::SCALE / 2), (long)(hunterShipNS::HEIGHT*hunterShipNS::SCALE / 2) };
	collisionType = entityNS::ROTATED_BOX;
}

bool HunterShip::initialize(Game *gamePtr, int width, int height, int ncols,
	TextureManager *textureM)
{
	explosion.initialize(gamePtr->getGraphics(), explosionNS::WIDTH, explosionNS::HEIGHT, explosionNS::TEXTURE_COLS, textureM);
	explosion.setScale(hunterShipNS::EXPLOSION_SCALE);
	explosion.setFrames(explosionNS::START_FRAME, explosionNS::END_FRAME);
	explosion.setCurrentFrame(explosionNS::START_FRAME);
	explosion.setFrameDelay(explosionNS::ANIMATION_DELAY);
	explosion.setLoop(false);                  // do not loop animation

	damaged.initialize(gamePtr->getGraphics(), hunterShipNS::WIDTH, hunterShipNS::HEIGHT, hunterShipNS::DAMAGE_TEXTURE_COLS, textureM);
	damaged.setScale(hunterShipNS::SCALE);
	damaged.setFrames(hunterShipNS::DAMAGE_START_FRAME, hunterShipNS::DAMAGE_END_FRAME);
	damaged.setCurrentFrame(hunterShipNS::DAMAGE_START_FRAME);
	damaged.setFrameDelay(hunterShipNS::DAMAGE_ANIMATION_DELAY);
	damaged.setLoop(false);                  // do not loop animation
	return(Entity::initialize(gamePtr, width, height, ncols, textureM));
}

void HunterShip::update(float frameTime)
{
	EnemyShip::update(frameTime);

	if (!bulletOn)
	{
		// When in game window, bullet can fire
		if (getCenterY() > 0 && getCenterY() < GAME_HEIGHT)
		{
			bulletOn = !bulletOn;
			timer = GetTickCount();
		}
	}
	else if (getY() + hunterShipNS::HEIGHT*hunterShipNS::SCALE < 0)
	{
		alive = false;
		active = false;
		outOfBound = true;
	}
}