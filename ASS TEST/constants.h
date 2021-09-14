// Programming 2D Games
// Copyright (c) 2011 by: 
// Charles Kelly
// Chapter 6 constants.h v1.0

#ifndef _CONSTANTS_H            // Prevent multiple definitions if this 
#define _CONSTANTS_H            // file is included in more than one place
#define WIN32_LEAN_AND_MEAN

#include <windows.h>

//-----------------------------------------------
// Useful macros
//-----------------------------------------------
// Safely delete pointer referenced item
#define SAFE_DELETE(ptr)       { if (ptr) { delete (ptr); (ptr)=NULL; } }
// Safely release pointer referenced item
#define SAFE_RELEASE(ptr)      { if(ptr) { (ptr)->Release(); (ptr)=NULL; } }
// Safely delete pointer referenced array
#define SAFE_DELETE_ARRAY(ptr) { if(ptr) { delete [](ptr); (ptr)=NULL; } }
// Safely call onLostDevice
#define SAFE_ON_LOST_DEVICE(ptr)    { if(ptr) { ptr->onLostDevice(); } }
// Safely call onResetDevice
#define SAFE_ON_RESET_DEVICE(ptr)   { if(ptr) { ptr->onResetDevice(); } }
#define TRANSCOLOR  SETCOLOR_ARGB(0,255,0,255)  // transparent color (magenta)

//-----------------------------------------------
//                  Constants
//-----------------------------------------------

// window
const char CLASS_NAME[] = "Letitrain";
const char GAME_TITLE[] = "LET IT RAIN";
const bool FULLSCREEN = false;              // windowed or fullscreen
const UINT GAME_WIDTH = 600;               // width of game in pixels
const UINT GAME_HEIGHT = 800;               // height of game in pixels

// game
const double PI = 3.14159265;
const float FRAME_RATE = 200.0f;                // the target frame rate (frames/sec)
const float MIN_FRAME_RATE = 10.0f;             // the minimum frame rate
const float MIN_FRAME_TIME = 1.0f/FRAME_RATE;   // minimum desired time for 1 frame
const float MAX_FRAME_TIME = 1.0f/MIN_FRAME_RATE; // maximum time used in calculations
const float GRAVITY = 6.67428e-11f;             // gravitational constant
const float MASS_PLANET = 1.0e14f;
const float MASS_SHIP = 5.0f;

// graphic images
const char MAP_IMAGE[] =   "..\\resources\\testbg4.png";     // photo source NASA/courtesy of nasaimages.org 
const char TEXTURES_IMAGE[] = "pictures\\textures.png";  // game textures
const char PW_IMAGE[] = "..\\resources\\pwtexturestext.png";
const char PLAYERSHIP_IMAGE[] = "pictures\\playership4.png";  //texture for playership
const char PLAYERSHIP2_IMAGE[] = "pictures\\playership2.png";  //texture for playership2 
const char WEAPON_IMAGE[] = "pictures\\bullets.png";
const char ENEMY_IMAGE[] = "..\\resources\\Example_ships\\enemyTextures.png";
const char HEART_IMAGE[] = "pictures\\heart.png"; // texture for hearts/lives
const char PAUSEICON_IMAGE[] = "pictures\\pauseicon.png";
const char MMBACKGROUND_IMAGE[] = "pictures\\MainMenuBackground.png";
const char STARTBUTTON_IMAGE[] = "pictures\\startButton.png";
const char EXITBUTTON_IMAGE[] = "pictures\\exitButton.png";
const char PAUSEBUTTON_IMAGE[] = "pictures\\PauseIcon.PNG";
																		// audio files required by audio.cpp
																		// WAVE_BANK must be location of .xwb file.
const char WAVE_BANK[] = "audio\\Win\\Wave Bank.xwb";
// SOUND_BANK must be location of .xsb file.
const char SOUND_BANK[] = "audio\\Win\\Sound Bank.xsb";

// audio cues
const char TITLE[] = "Title";
const char BEATDOWN[] = "Beatdown";
const char INTRO[] = "Intro";
const char POWERUP[] = "Powerup";
const char FINISH[] = "FIN";
const char HIT[] = "Hit";
const char PIANO[] = "Slow";

const char RESUMEBUTTON_IMAGE[] =	"pictures\\resumeButton.png";			// Texture for Resume Button
const char PAUSEMENU_IMAGE[]	=	"pictures\\pauseMenu.png";				// Texture for Pause Menu
const char CREDITSBUTTON_IMAGE[] =	"pictures\\creditsButton.png";			// Texture for Credit Button
const char LEADERBOARDBUTTON_IMAGE[] = "pictures\\leaderboardButton.png";	// Texture for Leaderboard Button
const char GREYBACKGROUND_IMAGE[] = "pictures\\greyBackground.png";			// Texture for Credit/Leaderboard background
const char CREDITSPAGE_IMAGE[] = "pictures\\creditPage.png";
const char MAINMENUBUTTON_IMAGE[] = "pictures\\mainMenuButton.png";
const char GAMEOVER_IMAGE[] = "pictures\\gameOver.png";
const char CONGRATULATIONS_IMAGE[] = "pictures\\congratulations.png";
const char SMALLEXP[] = "Small Exp";
const char BIGEXP[] = "Big Exp";

// key mappings
// In this game simple constants are used for key mappings. If variables were used
// it would be possible to save and restore key mappings from a data file.
const UCHAR ESC_KEY      = VK_ESCAPE;       // escape key
const UCHAR ALT_KEY      = VK_MENU;         // Alt key
const UCHAR ENTER_KEY    = VK_RETURN;       // Enter key


const UCHAR SHIP_RIGHT_KEY = 0x44;
const UCHAR SHIP_LEFT_KEY = 0x41;
const UCHAR SHIP_UP_KEY = 0x57;
const UCHAR SHIP_DOWN_KEY = 0x53;

//control key for player ship
const UCHAR BULLETSHIP_LEFT_KEY = 'A';
const UCHAR BULLETSHIP_RIGHT_KEY = 'D';
const UCHAR BULLETSHIP_FORWARD_KEY = 'W';
const UCHAR BULLETSHIP_BACKWARD_KEY = 'S';
const UCHAR FIRE_BULLET_KEY = 'F';
const UCHAR FIRE_LASER_KEY = VK_RETURN;
const UCHAR LASERSHIP_LEFT_KEY = VK_LEFT;
const UCHAR LASERSHIP_RIGHT_KEY = VK_RIGHT;
const UCHAR LASERSHIP_FORWARD_KEY = VK_UP;
const UCHAR LASERSHIP_BACKWARD_KEY = VK_DOWN;


// weapon types
enum WEAPON { BULLET, MISSILE, LASER, SHIP };

#endif
