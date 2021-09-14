//  Module:             Gameplay Programming
//  Assignment1:        LET IT RAIN
//  Student Name:       Timothy Chua
//  Student Number:     10165581F

#include "gruntShip.h"

GruntShip::GruntShip() : EnemyShip()
{
	health = gruntShipNS::HEALTH;
	spriteData.width = gruntShipNS::WIDTH;           // size of Ship1
	spriteData.height = gruntShipNS::HEIGHT;
	spriteData.x = gruntShipNS::X;                   // location on screen
	spriteData.y = gruntShipNS::Y;
	spriteData.rect.bottom = gruntShipNS::HEIGHT;    // rectangle to select parts of an image
	spriteData.rect.right = gruntShipNS::WIDTH;
	spriteData.angle = gruntShipNS::ROTATION;
	spriteData.scale = gruntShipNS::SCALE;
	velocity.x = 0;                             // velocity X
	velocity.y = gruntShipNS::SPEED;                             // velocity Y
	frameDelay = gruntShipNS::ANIMATION_DELAY;
	startFrame = gruntShipNS::START_FRAME;     // first frame of ship animation
	endFrame = gruntShipNS::END_FRAME;     // last frame of ship animation
	currentFrame = startFrame;
	radius = gruntShipNS::WIDTH / 2.0 - 5;
	explosionOn = false;
	damagedOn = false;
	mass = gruntShipNS::MASS;
	collisionType = entityNS::CIRCLE;
}

bool GruntShip::initialize(Game *gamePtr, int width, int height, int ncols,
	TextureManager *textureM)
{
	explosion.initialize(gamePtr->getGraphics(), explosionNS::WIDTH, explosionNS::HEIGHT, explosionNS::TEXTURE_COLS, textureM);
	explosion.setScale(gruntShipNS::EXPLOSION_SCALE);
	explosion.setFrames(explosionNS::START_FRAME, explosionNS::END_FRAME);
	explosion.setCurrentFrame(explosionNS::START_FRAME);
	explosion.setFrameDelay(explosionNS::ANIMATION_DELAY);
	explosion.setLoop(false);                  // do not loop animation

	damaged.initialize(gamePtr->getGraphics(), gruntShipNS::WIDTH, gruntShipNS::HEIGHT, gruntShipNS::DAMAGE_TEXTURE_COLS, textureM);
	damaged.setScale(gruntShipNS::SCALE);
	damaged.setFrames(gruntShipNS::DAMAGE_START_FRAME, gruntShipNS::DAMAGE_END_FRAME);
	damaged.setCurrentFrame(gruntShipNS::DAMAGE_START_FRAME);
	damaged.setFrameDelay(gruntShipNS::DAMAGE_ANIMATION_DELAY);
	damaged.setLoop(false);                  // do not loop animation
	return(Entity::initialize(gamePtr, width, height, ncols, textureM));

}