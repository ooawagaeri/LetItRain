//  Module:             Gameplay Programming
//  Assignment1:        LET IT RAIN
//  Student Name:       Daniel Lee
//  Student Number:     10162739H
#include "powerup.h"


PowerUp::PowerUp() : Entity()
{
	collisionType = entityNS::CIRCLE;
	type = getCurrentFrame();

}

bool PowerUp::initialize(Game *gamePtr, int width, int height, int ncols, TextureManager *textureM) {

	return(Entity::initialize(gamePtr, width, height, ncols, textureM));

}

//=============================================================================
// update
// typically called once per frame
// frameTime is used to regulate the speed of movement and animation
//=============================================================================
bool IsPointInCircle(float xa, float ya, float xc, float yc, float r)
{
	return ((xa - xc)*(xa - xc) + (ya - yc)*(ya - yc)) < r*r;
}

float distFromShipToPowerup(float xa, float ya, float xc, float yc, float r)
{
	return (((xa - xc)*(xa - xc) + (ya - yc)*(ya - yc))/r);
}

/*
void PowerUp::update(float frameTime, Bulletship bship)
{
	if (IsPointInCircle(spriteData.x, spriteData.y, bship.getX(), bship.getY(), powerupNS::MAGNET_RADIUS)) {
		if (spriteData.x < bship.getX()) {
			spriteData.x += frameTime * velocity.x;
		}
		else if (spriteData.x > bship.getY()) {
			spriteData.x -= frameTime * velocity.x;
		}
		if (spriteData.y < bship.getY()) {
			spriteData.y += frameTime * velocity.y;
		}
		else if (spriteData.y > bship.getY()) {
			spriteData.y -= frameTime * velocity.y;
		}
		velocity.x++;
		velocity.y++;
	}
}
*/

void PowerUp::update(float frameTime, Bulletship bship, Lasership lship) {
// check both below 100, execute the one that is nearer,
	spriteData.y += frameTime * velocity.y;
	float bshipdist = distFromShipToPowerup(spriteData.x, spriteData.y, bship.getX(), bship.getY(), powerupNS::MAGNET_RADIUS);
	float lshipdist = distFromShipToPowerup(spriteData.x, spriteData.y, lship.getX(), lship.getY(), powerupNS::MAGNET_RADIUS);
	if (bshipdist > lshipdist && lshipdist < powerupNS::MAGNET_RADIUS) {
		if (spriteData.x < lship.getX()) {
			spriteData.x += frameTime * velocity.x;
		}
		else if (spriteData.x > lship.getY()) {
			spriteData.x -= frameTime * velocity.x;
		}
		if (spriteData.y < lship.getY()) {
			spriteData.y += frameTime * velocity.y;
		}
		else if (spriteData.y > lship.getY()) {
			spriteData.y -= frameTime * velocity.y;
		}
		velocity.x++;
		velocity.y++;
	}
	else if (bshipdist < lshipdist && bshipdist < powerupNS::MAGNET_RADIUS){
		if (spriteData.x < bship.getX()) {
			spriteData.x += frameTime * velocity.x;
		}
		else if (spriteData.x > bship.getY()) {
			spriteData.x -= frameTime * velocity.x;
		}
		if (spriteData.y < bship.getY()) {
			spriteData.y += frameTime * velocity.y;
		}
		else if (spriteData.y > bship.getY()) {
			spriteData.y -= frameTime * velocity.y;
		}
		velocity.x++;
		velocity.y++;
	}
}

void PowerUp::displayText(int type, Game *gamePtr, TextureManager *textureM) {
	initialize(gamePtr, 64, 32, 3, textureM);
	currentFrame = 4;
	draw(spriteData);
}
void PowerUp::hideIcon() {
	this->setVisible(true);
}

/*
// draw the ship
//=============================================================================
void PowerUp::draw()
{
	Image::draw();              // draw ship

}
*/