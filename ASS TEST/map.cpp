//  Module:             Gameplay Programming
//  Assignment1:        LET IT RAIN
//  Student Name:       Daniel Lee
//  Student Number:     10162739H

#include "map.h"


bool Map::initialize(Game *gamePtr, int width, int height, int ncols,
	TextureManager *textureM, int stage)
{
	return(Entity::initialize(gamePtr, width, height, ncols, textureM));
}
//=============================================================================
// update
// typically called once per frame
// frameTime is used to regulate the speed of movement and animation
//=============================================================================
void Map::update(float frameTime, Game *gamePtr, int stage)
{
	if (stage == 3) {
		velocity.y = 0;
	}
	else if (spriteData.y >= GAME_HEIGHT) {
		spriteData.y = -(float)GAME_HEIGHT - spriteData.height + 369 + 184;
	}
	spriteData.y += frameTime * velocity.y; 
}


