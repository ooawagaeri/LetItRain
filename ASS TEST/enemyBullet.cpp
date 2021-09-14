//  Module:             Gameplay Programming
//  Assignment1:        LET IT RAIN
//  Student Name:       Timothy Chua
//  Student Number:     10165581F

#include "enemyBullet.h"

//=============================================================================
// default constructor
//=============================================================================
EnemyBullet::EnemyBullet() : Bullet()
{
	spriteData.width = enemyBulletNS::WIDTH;           // size of Ship1
	spriteData.height = enemyBulletNS::HEIGHT;
	spriteData.x = enemyBulletNS::X;                   // location on screen
	spriteData.y = enemyBulletNS::Y;
	spriteData.rect.bottom = enemyBulletNS::HEIGHT;    // rectangle to select parts of an image
	spriteData.rect.right = enemyBulletNS::WIDTH;
	velocity.x = 0;                             // velocity X
	velocity.y = enemyBulletNS::SPEED;                             // velocity Y
	frameDelay = enemyBulletNS::ANIMATION_DELAY;
	startFrame = enemyBulletNS::START_FRAME;     // first frame of ship animation
	endFrame = enemyBulletNS::END_FRAME;     // last frame of ship animation
	currentFrame = startFrame;
	radius = enemyBulletNS::WIDTH / 2.0;
	collisionType = entityNS::CIRCLE;
}