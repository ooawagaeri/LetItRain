//  Module:             Gameplay Programming
//  Assignment1:        LET IT RAIN
//  Student Name:       Zhuang Yuteng
//  Student Number:     10163964C
#include "lasership.h"

//=============================================================================
// default constructor
//=============================================================================
Lasership::Lasership() : Entity()
{
	spriteData.width = lasershipNS::WIDTH;           // size of Ship1
	spriteData.height = lasershipNS::HEIGHT;
	spriteData.x = lasershipNS::X;                   // location on screen
	spriteData.y = lasershipNS::Y;
	spriteData.rect.bottom = lasershipNS::HEIGHT;    // rectangle to select parts of an image
	spriteData.rect.right = lasershipNS::WIDTH;
	velocity.x = 0;                             // velocity X
	velocity.y = 0;                             // velocity Y
	frameDelay = lasershipNS::SHIP_ANIMATION_DELAY;
	startFrame = lasershipNS::SHIP_START_FRAME;     // first frame of ship animation
	endFrame = lasershipNS::SHIP_END_FRAME;     // last frame of ship animation
	currentFrame = startFrame;
	radius = lasershipNS::WIDTH / 2.0;
	collisionType = entityNS::CIRCLE;
	attLevel = 1;
	speLevel = 1;
	shieldOn = false;
	health = 3;
	explosionOn = false;
	addText = false;
}

//=============================================================================
// Initialize the Ship.
// Post: returns true if successful, false if failed
//=============================================================================
bool Lasership::initialize(Game *gamePtr, int width, int height, int ncols,
	TextureManager *shipTextureM, TextureManager *powerupTextureM)
{
	shield.initialize(gamePtr->getGraphics(), lasershipNS::SHIELD_WIDTH, lasershipNS::SHIELD_HEIGHT, lasershipNS::SHIELD_COL, shipTextureM);
	shield.setCurrentFrame(lasershipNS::SHIELD_FRAME);
	text.initialize(gamePtr->getGraphics(), lasershipNS::TEXT_WIDTH, lasershipNS::TEXT_HEIGHT, lasershipNS::TEXT_TEXTURE_COLS, powerupTextureM);


	return(Entity::initialize(gamePtr, width, height, ncols, shipTextureM));
}

//=============================================================================
// draw the ship
//=============================================================================
void Lasership::draw(Image explosion)
{
	Image::draw();              // draw ship
	if (shieldOn)
		// draw shield using colorFilter 50% alpha
		shield.draw(spriteData, graphicsNS::ALPHA50 & colorFilter);
	if (explosionOn)
		explosion.draw(explosion.getSpriteInfo(), colorFilter);
	if (addText) {
		text.draw();
		if (GetTickCount() - Tick > 3000) {
			addText = false;
		}
	}
}

void Lasership::writePowerUpText(int i) {
	Tick = GetTickCount();
	if (i == 0) {
		text.setCurrentFrame(lasershipNS::TEXT_POWERUP_ATT);
	}
	else if (i == 1) {
		text.setCurrentFrame(lasershipNS::TEXT_POWERUP_SPE);
	}
	else if (i == 2) {
		text.setCurrentFrame(lasershipNS::TEXT_POWERUP_HP);
	}
	else if (i == 3) {
		text.setCurrentFrame(lasershipNS::TEXT_POWERUP_SHIELD);
	}
	else if (i == 4) {
		text.setCurrentFrame(lasershipNS::TEXT_POWERUP_SLOWMO);
	}
	else {
		text.setVisible(false);
	}
	addText = true;
}

void Lasership::damage(WEAPON weapon) 
{
	if (!shieldOn)
	{
		health -= 1;
		audio->playCue(HIT);
		if (health <= 0) {
			explosionOn = true;
		}
	}
}

//=============================================================================
// update
// typically called once per frame
// frameTime is used to regulate the speed of movement and animation
//=============================================================================
void Lasership::update(float frameTime, Image explosion)
{
	Entity::update(frameTime);

	if (input->isKeyDown(LASERSHIP_RIGHT_KEY))
	{
		spriteData.x += frameTime * velocity.x;         // move ship along X 
	}

	else if (input->isKeyDown(LASERSHIP_LEFT_KEY))
	{
		spriteData.x += frameTime * (-velocity.x);         // move ship along X 
	}

	else if (input->isKeyDown(LASERSHIP_FORWARD_KEY))
	{
		spriteData.y += frameTime * (-velocity.y);         // move ship along X 
	}

	else if (input->isKeyDown(LASERSHIP_BACKWARD_KEY))
	{
		spriteData.y += frameTime * velocity.y;         // move ship along X 
	}
	
	if (spriteData.x > GAME_WIDTH - lasershipNS::WIDTH*getScale())
	{
		spriteData.x = GAME_WIDTH - lasershipNS::WIDTH*getScale();
	}

	else if (spriteData.x < 0)
	{
		spriteData.x = 0;
	}

	else if (spriteData.y > GAME_HEIGHT - lasershipNS::HEIGHT*getScale())
	{
		spriteData.y = GAME_HEIGHT - lasershipNS::HEIGHT*getScale();
	}

	else if (spriteData.y < 0)
	{
		spriteData.y = 0;
	}

	if (explosionOn)
	{
		setVisible(false);
		setActive(false);
		explosion.update(frameTime);
		if (explosion.getAnimationComplete()) {
			explosionOn = false;
			explosion.setAnimationComplete(false);
		}
	}
	if (addText) {
		text.setY(spriteData.y - 25);
		text.setX(spriteData.x);
	}
}

