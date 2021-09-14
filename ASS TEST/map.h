//  Module:             Gameplay Programming
//  Assignment1:        LET IT RAIN
//  Student Name:       Daniel Lee
//  Student Number:     10162739H
#ifndef _MAP_H                 // Prevent multiple definitions if this 
#define _MAP_H                 // file is included in more than one place
#define WIN32_LEAN_AND_MEAN

#include "entity.h"
#include "constants.h"
// inherits from Entity class

namespace mapNS
{
	const float SPEED =30;
	const int   TEXTURE_COLS = 1;
}
class Map : public Entity
{
private:

public:
	virtual bool initialize(Game *gamePtr, int width, int height, int ncols,
		TextureManager *textureM, int stage);
	void update(float frameTime, Game *gamePtr, int stage);
};
#endif
