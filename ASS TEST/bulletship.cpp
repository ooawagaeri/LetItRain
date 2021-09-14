//  Module:             Gameplay Programming
//  Assignment1:        LET IT RAIN
//  Student Name:       Zhuang Yuteng
//  Student Number:     10163964C
#include "bulletship.h"

//=============================================================================
// default constructor
//=============================================================================
Bulletship::Bulletship() : Entity()
{
	spriteData.width = bulletshipNS::WIDTH;           // size of Ship1
	spriteData.height = bulletshipNS::HEIGHT;
	spriteData.x = bulletshipNS::X;                   // location on screen
	spriteData.y = bulletshipNS::Y;
	spriteData.rect.bottom = bulletshipNS::HEIGHT;    // rectangle to select parts of an image
	spriteData.rect.right = bulletshipNS::WIDTH;
	velocity.x = 0;                             // velocity X
	velocity.y = 0;                             // velocity Y
	frameDelay = bulletshipNS::SHIP_ANIMATION_DELAY;
	startFrame = bulletshipNS::SHIP_START_FRAME;     // first frame of ship animation
	endFrame = bulletshipNS::SHIP_END_FRAME;     // last frame of ship animation
	currentFrame = startFrame+ 4;
	radius = bulletshipNS::WIDTH / 2.0;
	collisionType = entityNS::CIRCLE;
	speLevel = 1;
	attLevel = 1;
	shieldOn = false;
	health = 3;
	explosionOn = false;
	addText = false;
}

//=============================================================================
// Initialize the Ship.
// Post: returns true if successful, false if failed
//=============================================================================
bool Bulletship::initialize(Game *gamePtr, int width, int height, int ncols,
	TextureManager *shipTextureM, TextureManager *powerupTextureM)
{
	// main game textures

	shield.initialize(gamePtr->getGraphics(),106, 106, 2, shipTextureM);
	shield.setCurrentFrame(1);
	text.initialize(gamePtr->getGraphics(), bulletshipNS::TEXT_WIDTH, bulletshipNS::TEXT_HEIGHT, bulletshipNS::TEXT_TEXTURE_COLS, powerupTextureM);
	
	return(Entity::initialize(gamePtr, width, height, ncols, shipTextureM));
}

//=============================================================================
// draw the ship
//=============================================================================
void Bulletship::draw(Image explosion)
{
	Image::draw();              // draw ship
	if (shieldOn)
		shield.draw(spriteData, graphicsNS::ALPHA50 & colorFilter);
	if (explosionOn) {
		explosion.draw(explosion.getSpriteInfo(), colorFilter);
	}
	if (addText) {
		text.draw();
		if (GetTickCount() - Tick > 3000) {
			addText = false;
		}
	}
}

void Bulletship::writePowerUpText(int i) {
	Tick = GetTickCount();
	if (i == 0) {
		text.setCurrentFrame(bulletshipNS::TEXT_POWERUP_ATT);
	}
	else if (i == 1) {
		text.setCurrentFrame(bulletshipNS::TEXT_POWERUP_SPE);
	}
	else if (i == 2) {
		text.setCurrentFrame(bulletshipNS::TEXT_POWERUP_HP);
	}
	else if (i == 3){
		text.setCurrentFrame(bulletshipNS::TEXT_POWERUP_SHIELD);
	}
	else if (i == 4) {
		text.setCurrentFrame(bulletshipNS::TEXT_POWERUP_SLOWMO);
	}
	else {
		text.setVisible(false);
	}
	addText = true;
}

void Bulletship::damage(WEAPON weapon)
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
void Bulletship::update(float frameTime, Image explosion)
{
	Entity::update(frameTime);

	if (input->isKeyDown(BULLETSHIP_RIGHT_KEY))
	{
		spriteData.x += frameTime * velocity.x;         // move ship along X 
	}

	else if (input->isKeyDown(BULLETSHIP_LEFT_KEY))
	{
		spriteData.x += frameTime * (-velocity.x);         // move ship along X 
	}

	else if (input->isKeyDown(BULLETSHIP_FORWARD_KEY))
	{
		spriteData.y += frameTime * (-velocity.y);         // move ship along X 
	}

	else if (input->isKeyDown(BULLETSHIP_BACKWARD_KEY))
	{
		spriteData.y += frameTime * velocity.y;         // move ship along X 
	}
	
	if (spriteData.x > GAME_WIDTH - bulletshipNS::WIDTH*getScale())
	{
		spriteData.x = GAME_WIDTH - bulletshipNS::WIDTH*getScale();
	}

	else if (spriteData.x < 0)
	{
		spriteData.x = 0;
	}

	else if (spriteData.y > GAME_HEIGHT - bulletshipNS::HEIGHT*getScale())
	{
		spriteData.y = GAME_HEIGHT - bulletshipNS::HEIGHT*getScale();
	}

	else if (spriteData.y < 0)
	{
		spriteData.y = 0;
	}
	if (explosionOn) {
		setVisible(false);
		setActive(false);
		explosion.update(frameTime);
		if (explosion.getAnimationComplete()) {
			explosionOn = false;
			explosion.setAnimationComplete(false);
		}
	}
	if (addText) {
		text.setY(spriteData.y - 20);
		text.setX(spriteData.x);
	}
}



