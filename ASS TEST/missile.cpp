//  Module:             Gameplay Programming
//  Assignment1:        LET IT RAIN
//  Student Name:       Zhuang Yuteng
//  Student Number:     10163964C
#include "missile.h"

//=============================================================================
// default constructor
//=============================================================================
Missile::Missile() : Entity()
{
	spriteData.width = missileNS::WIDTH;           // size of Ship1
	spriteData.height = missileNS::HEIGHT;
	spriteData.x = missileNS::X;                   // location on screen
	spriteData.y = missileNS::Y;
	spriteData.rect.bottom = missileNS::HEIGHT;    // rectangle to select parts of an image
	spriteData.rect.right = missileNS::WIDTH;
	velocity.x = 0;                             // velocity X
	velocity.y = 0;                             // velocity Y
	frameDelay = missileNS::MISSILE_ANIMATION_DELAY;
	startFrame = missileNS::MISSILE_START_FRAME;     // first frame of ship animation
	endFrame = missileNS::MISSILE_END_FRAME;     // last frame of ship animation
	currentFrame = startFrame;
	radius = missileNS::WIDTH / 2.0;
	collisionType = entityNS::CIRCLE;
}

//=============================================================================
// Initialize the Ship.
// Post: returns true if successful, false if failed
//=============================================================================
bool Missile::initialize(Game *gamePtr, int width, int height, int ncols,
	TextureManager *textureM)
{

	return(Entity::initialize(gamePtr, width, height, ncols, textureM));
}

//=============================================================================
// draw the ship
//=============================================================================
void Missile::draw()
{
	Image::draw();              // draw ship

}

//=============================================================================
// update
// typically called once per frame
// frameTime is used to regulate the speed of movement and animation
//=============================================================================
void Missile::update(float frameTime,float xPosition,float yPosition)
{
	Entity::update(frameTime);
	
	direction = VECTOR2(xPosition - spriteData.x, yPosition - spriteData.y);
	current = VECTOR2(xPosition, yPosition);

	float x = xPosition - spriteData.x;
	float y = yPosition - spriteData.y;
	angle = atan(y / x);

	if(xPosition<spriteData.x)
		setRadians(3 * PI /2 + angle);
	
	else if(xPosition>spriteData.x)
		setRadians(PI / 2 + angle);

	spriteData.x += frameTime * direction.x;         // move ship along y
	spriteData.y += frameTime * direction.y;         // move ship along y	

	if (spriteData.x > GAME_WIDTH -missileNS::WIDTH*getScale())
	{
		spriteData.x = GAME_WIDTH - missileNS::WIDTH*getScale();
	}

	if (spriteData.x < 0)
	{
		spriteData.x = 0;
	}

	if (spriteData.y > GAME_HEIGHT - missileNS::HEIGHT*getScale())
	{
		spriteData.y = GAME_HEIGHT - missileNS::HEIGHT*getScale();
	}

	if (spriteData.y < 0)
	{
		spriteData.y = 0;
	}
}










