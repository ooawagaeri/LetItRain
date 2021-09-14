//  Module:             Gameplay Programming
//  Assignment1:        LET IT RAIN
//  Student Name:       Zhuang Yuteng
//  Student Number:     10163964C
#ifndef _LASERSHIP_H                 // Pdamage(WEAPON weapon)revent multiple definitions if this 
#define _LASERSHIP_H                 // file is included in more than one place
#define WIN32_LEAN_AND_MEAN

#include "entity.h"
#include "constants.h"

namespace lasershipNS
{
	const int WIDTH = 141;                   // image width
	const int HEIGHT = 100;                  // image height
	const int X = GAME_WIDTH / 2 - WIDTH / 2;   // location on screen
	const int Y = GAME_HEIGHT / 2 - HEIGHT / 2;
	const float SPEED = 200;                // 100 pixels per second
	const int   TEXTURE_COLS = 1;           // texture has 8 columns
	const int   SHIP_START_FRAME = 0;      // ship1 starts at frame 0
	const int   SHIP_END_FRAME = 0;        // ship1 end at frame 0
	const float SHIP_ANIMATION_DELAY = 0.2f;    // time between frames
	const int SHIELD_WIDTH = 143;
	const int SHIELD_HEIGHT = 108;
	const int SHIELD_COL = 1;
	const int SHIELD_FRAME = 1;
	const int TEXT_WIDTH = 64;
	const int TEXT_HEIGHT = 32;
	const int TEXT_TEXTURE_COLS = 3;
	const int TEXT_POWERUP_ATT = 3;
	const int TEXT_POWERUP_SPE = 4;
	const int TEXT_POWERUP_HP = 6;
	const int TEXT_POWERUP_SHIELD = 7;
	const int TEXT_POWERUP_SLOWMO = 5;
}

// inherits from Entity class
class Lasership : public Entity
{
private:
	int attLevel;
	int speLevel;
	bool shieldOn;
	Image shield;
	bool explosionOn;
	Image text;
	bool addText;
	DWORD Tick;
public:
	// constructor
	Lasership();

	// inherited member functions
	virtual void draw(Image explosion);
	virtual bool initialize(Game *gamePtr, int width, int height, int ncols,
		TextureManager *shipTextureM, TextureManager *powerupTextureM);
	void update(float frameTime, Image explosion);
	void writePowerUpText(int i);
	void damage();
	void damage(WEAPON weapon);
	int getAttLevel() { return attLevel; }
	void setAttLevel(int a) { attLevel = a; }
	int getSpeLevel() { return speLevel; }
	void setSpeLevel(int s) { speLevel = s; }
	bool getShieldOn() { return shieldOn; }
	void setShieldOn(bool s) { shieldOn = s; }
};
#endif



