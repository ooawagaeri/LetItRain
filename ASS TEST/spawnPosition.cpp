//  Module:             Gameplay Programming
//  Assignment1:        LET IT RAIN
//  Student Name:       Timothy Chua
//  Student Number:     10165581F

#include "spawnPosition.h"

SpawnPosition::SpawnPosition()
{
	loadStage1(gruntSpawn);
	loadHunters(hunterSpawn);
}

SpawnPosition::SpawnPosition(int type) {
	if (type == 1) {
		loadPowerUpValues(powerupSpawn);
	}
}
void SpawnPosition::loadGrunts(float grunt[][GRUNT_SPAWN_AXIS]) {
	grunt[0][0] = GAME_WIDTH / 2 - gruntShipNS::WIDTH / 2; grunt[0][1] = -gruntShipNS::HEIGHT;
	grunt[1][0] = GAME_WIDTH / 2 - gruntShipNS::WIDTH / 2; grunt[1][1] = grunt[0][1] - gruntShipNS::HEIGHT;
	grunt[2][0] = GAME_WIDTH / 2 - gruntShipNS::WIDTH / 2; grunt[2][1] = grunt[1][1] - gruntShipNS::HEIGHT;
	grunt[3][0] = GAME_WIDTH / 2 - gruntShipNS::WIDTH / 2; grunt[3][1] = grunt[2][1] - gruntShipNS::HEIGHT;
	grunt[4][0] = GAME_WIDTH / 2 - gruntShipNS::WIDTH / 2; grunt[4][1] = grunt[3][1] - gruntShipNS::HEIGHT;

	grunt[5][0] = GAME_WIDTH / 5 - gruntShipNS::WIDTH / 2; grunt[5][1] = grunt[3][1] - 2 * gruntShipNS::HEIGHT;
	grunt[6][0] = GAME_WIDTH / 5 - gruntShipNS::WIDTH / 2; grunt[6][1] = grunt[3][1] - 3 * gruntShipNS::HEIGHT;

	grunt[7][0] = 4 * GAME_WIDTH / 5 - gruntShipNS::WIDTH / 2; grunt[7][1] = grunt[3][1] - 2 * gruntShipNS::HEIGHT;
	grunt[8][0] = 4 * GAME_WIDTH / 5 - gruntShipNS::WIDTH / 2; grunt[8][1] = grunt[3][1] - 3 * gruntShipNS::HEIGHT;
	/*
	grunt[9][0] = GAME_WIDTH / 2 - gruntShipNS::WIDTH / 2; grunt[13][1] = -2 * gruntShipNS::HEIGHT;
	grunt[10][0] = GAME_WIDTH / 2 - gruntShipNS::WIDTH / 2; grunt[10][1] = -3 * gruntShipNS::HEIGHT;
	grunt[11][0] = GAME_WIDTH / 2 - gruntShipNS::WIDTH / 2; grunt[11][1] = -4 * gruntShipNS::HEIGHT;
	grunt[13][0] = GAME_WIDTH / 2 - gruntShipNS::WIDTH / 2; grunt[13][1] = -2 * gruntShipNS::HEIGHT;
	grunt[13][0] = GAME_WIDTH / 2 - gruntShipNS::WIDTH / 2; grunt[13][1] = -2 * gruntShipNS::HEIGHT;
	/*
	grunt[14][0] = GAME_WIDTH / 2 - gruntShipNS::WIDTH / 2; grunt[14][1] = -3 * gruntShipNS::HEIGHT;
	grunt[15][0] = GAME_WIDTH / 2 - gruntShipNS::WIDTH / 2; grunt[15][1] = -4 * gruntShipNS::HEIGHT;
	grunt[16][0] = GAME_WIDTH / 2 - gruntShipNS::WIDTH / 2; grunt[13][1] = -2 * gruntShipNS::HEIGHT;
	grunt[17][0] = GAME_WIDTH / 2 - gruntShipNS::WIDTH / 2; grunt[14][1] = -3 * gruntShipNS::HEIGHT;
	grunt[18][0] = GAME_WIDTH / 2 - gruntShipNS::WIDTH / 2; grunt[15][1] = -4 * gruntShipNS::HEIGHT;
	/*
	grunt[19][0] = GAME_WIDTH / 2 - gruntShipNS::WIDTH / 2; grunt[5][1] = -2 * gruntShipNS::HEIGHT;
	grunt[20][0] = GAME_WIDTH / 2 - gruntShipNS::WIDTH / 2; grunt[6][1] = -3 * gruntShipNS::HEIGHT;
	/*
	grunt[21][0] = GAME_WIDTH / 2 - gruntShipNS::WIDTH / 2; grunt[7][1] = -4 * gruntShipNS::HEIGHT;
	grunt[22][0] = GAME_WIDTH / 2 - gruntShipNS::WIDTH / 2; grunt[8][1] = -gruntShipNS::HEIGHT;
	/*
	grunt[23][0] = GAME_WIDTH / 2 - gruntShipNS::WIDTH / 2; grunt[5][1] = -2 * gruntShipNS::HEIGHT;
	grunt[24][0] = GAME_WIDTH / 2 - gruntShipNS::WIDTH / 2; grunt[6][1] = -3 * gruntShipNS::HEIGHT;
	/*
	grunt[25][0] = GAME_WIDTH / 2 - gruntShipNS::WIDTH / 2; grunt[7][1] = -4 * gruntShipNS::HEIGHT;
	grunt[26][0] = GAME_WIDTH / 2 - gruntShipNS::WIDTH / 2; grunt[8][1] = -gruntShipNS::HEIGHT;
	/*
	grunt[27][0] = GAME_WIDTH / 2 - gruntShipNS::WIDTH / 2; grunt[14][1] = -3 * gruntShipNS::HEIGHT;
	grunt[28][0] = GAME_WIDTH / 2 - gruntShipNS::WIDTH / 2; grunt[15][1] = -4 * gruntShipNS::HEIGHT;
	grunt[29][0] = GAME_WIDTH / 2 - gruntShipNS::WIDTH / 2; grunt[13][1] = -2 * gruntShipNS::HEIGHT;
	grunt[30][0] = GAME_WIDTH / 2 - gruntShipNS::WIDTH / 2; grunt[14][1] = -3 * gruntShipNS::HEIGHT;
	grunt[31][0] = GAME_WIDTH / 2 - gruntShipNS::WIDTH / 2; grunt[15][1] = -4 * gruntShipNS::HEIGHT;
	/*
	grunt[32][0] = GAME_WIDTH / 2 - gruntShipNS::WIDTH / 2; grunt[14][1] = -3 * gruntShipNS::HEIGHT;
	grunt[33][0] = GAME_WIDTH / 2 - gruntShipNS::WIDTH / 2; grunt[15][1] = -4 * gruntShipNS::HEIGHT;
	grunt[34][0] = GAME_WIDTH / 2 - gruntShipNS::WIDTH / 2; grunt[13][1] = -2 * gruntShipNS::HEIGHT;
	grunt[35][0] = GAME_WIDTH / 2 - gruntShipNS::WIDTH / 2; grunt[14][1] = -3 * gruntShipNS::HEIGHT;
	*/
}

void SpawnPosition::loadHunters(float hunter[][HUNTER_SPAWN_AXIS]) {
	// x position, y position , rotation (radian), x velocity, y velocity
	hunter[0][0] = -hunterShipNS::WIDTH; hunter[0][1] = GAME_HEIGHT + hunterShipNS::HEIGHT; hunter[0][2] = 1 * PI / 5; hunter[0][3] = hunterShipNS::SPEED*cos(hunter[0][2]); hunter[0][4] = -hunterShipNS::SPEED;
	hunter[1][0] = GAME_WIDTH; hunter[1][1] = GAME_HEIGHT + hunterShipNS::HEIGHT; hunter[1][2] = 9 * PI / 5; hunter[1][3] = -hunterShipNS::SPEED*cos(hunter[1][2]); hunter[1][4] = -hunterShipNS::SPEED;

	hunter[2][0] = GAME_WIDTH / 2; hunter[2][1] = GAME_HEIGHT / 2 - hunterShipNS::HEIGHT; hunter[2][2] = PI; hunter[2][3] = 0; hunter[2][4] = 0;
	/*	hunter[3][0] = GAME_WIDTH / 2 - hunterShipNS::WIDTH / 2; hunter[3][1] = -4 * hunterShipNS::HEIGHT;
	hunter[4][0] = GAME_WIDTH / 2 - hunterShipNS::WIDTH / 2; hunter[4][1] = -5 * hunterShipNS::HEIGHT;
	hunter[5][0] = GAME_WIDTH / 2 - hunterShipNS::WIDTH / 2; hunter[5][1] = -2 * hunterShipNS::HEIGHT;
	hunter[6][0] = GAME_WIDTH / 2 - hunterShipNS::WIDTH / 2; hunter[6][1] = -3 * hunterShipNS::HEIGHT;
	hunter[7][0] = GAME_WIDTH / 2 - hunterShipNS::WIDTH / 2; hunter[7][1] = -4 * hunterShipNS::HEIGHT;*/
}

float SpawnPosition::getGrunt(int no, int xy)
{
	return (gruntSpawn[no][xy]);
}

float SpawnPosition::getHunter(int no, int xy)
{
	return (hunterSpawn[no][xy]);
}

void SpawnPosition::loadPowerUpValues(float p[][POWERUP_SPAWN_AXIS]) {
	p[0][0] = GAME_WIDTH / 2 - powerupNS::WIDTH / 2; p[0][1] = -13 * gruntShipNS::HEIGHT; p[0][2] = powerupNS::POWERUP_ATT;
	p[1][0] = GAME_WIDTH / 2 - powerupNS::WIDTH / 2; p[1][1] = -20 * gruntShipNS::HEIGHT; p[1][2] = powerupNS::POWERUP_SPE;
	p[2][0] = GAME_WIDTH / 2 - powerupNS::WIDTH / 2; p[2][1] = -25 * gruntShipNS::HEIGHT; p[2][2] = powerupNS::POWERUP_SHIELD;
	p[3][0] = GAME_WIDTH / 2 - powerupNS::WIDTH / 2; p[3][1] = -26 * gruntShipNS::HEIGHT; p[3][2] = powerupNS::POWERUP_SLOW;
	p[4][0] = GAME_WIDTH / 2 - powerupNS::WIDTH / 2; p[4][1] = -30 * gruntShipNS::HEIGHT; p[4][2] = powerupNS::POWERUP_HP;
	p[5][0] = 2 *GAME_WIDTH / 6 - powerupNS::WIDTH / 2; p[5][1] = -38 * gruntShipNS::HEIGHT; p[5][2] = powerupNS::POWERUP_SPE;
	p[6][0] = 4 * GAME_WIDTH / 6 - powerupNS::WIDTH / 2; p[6][1] = -38 * gruntShipNS::HEIGHT; p[6][2] = powerupNS::POWERUP_ATT;
	p[7][0] = GAME_WIDTH / 2 - powerupNS::WIDTH / 2; p[7][1] = -44 * gruntShipNS::HEIGHT; p[7][2] = powerupNS::POWERUP_SLOW;

}

float SpawnPosition::getPowerUp(int no, int xy)
{
	return (powerupSpawn[no][xy]);
}

void SpawnPosition::loadStage1(float grunt[][24])
{
	grunt[0][0] = GAME_WIDTH / 2; grunt[0][1] = -2 * gruntShipNS::HEIGHT;
	grunt[1][0] = GAME_WIDTH / 2; grunt[1][1] = grunt[0][1] - gruntShipNS::HEIGHT;
	grunt[2][0] = GAME_WIDTH / 2; grunt[2][1] = grunt[1][1] - gruntShipNS::HEIGHT;
	grunt[3][0] = GAME_WIDTH / 2; grunt[3][1] = grunt[2][1] - gruntShipNS::HEIGHT;
	grunt[4][0] = GAME_WIDTH / 2; grunt[4][1] = grunt[3][1] - gruntShipNS::HEIGHT;

	grunt[5][0] = 2 * GAME_WIDTH / 6; grunt[5][1] = grunt[3][1] - 3 * gruntShipNS::HEIGHT;
	grunt[6][0] = 2 * GAME_WIDTH / 6; grunt[6][1] = grunt[3][1] - 4 * gruntShipNS::HEIGHT;

	grunt[7][0] = 4 * GAME_WIDTH / 6; grunt[7][1] = grunt[3][1] - 3 * gruntShipNS::HEIGHT;
	grunt[8][0] = 4 * GAME_WIDTH / 6; grunt[8][1] = grunt[3][1] - 4 * gruntShipNS::HEIGHT;

	grunt[9][0] = GAME_WIDTH / 6; grunt[9][1] = grunt[8][1] - 3 * gruntShipNS::HEIGHT;
	grunt[10][0] = 2 * GAME_WIDTH / 6; grunt[10][1] = grunt[9][1] - gruntShipNS::HEIGHT / 2;
	grunt[11][0] = 3 * GAME_WIDTH / 6; grunt[11][1] = grunt[10][1] - gruntShipNS::HEIGHT / 2;
	grunt[12][0] = 4 * GAME_WIDTH / 6; grunt[12][1] = grunt[11][1] - gruntShipNS::HEIGHT / 2;
	grunt[13][0] = 5 * GAME_WIDTH / 6; grunt[13][1] = grunt[12][1] - gruntShipNS::HEIGHT / 2;

	grunt[9][0] = GAME_WIDTH / 6; grunt[9][1] = grunt[8][1] - 3 * gruntShipNS::HEIGHT;
	grunt[10][0] = 2 * GAME_WIDTH / 6; grunt[10][1] = grunt[9][1] - gruntShipNS::HEIGHT / 2;
	grunt[11][0] = 3 * GAME_WIDTH / 6; grunt[11][1] = grunt[10][1] - gruntShipNS::HEIGHT / 2;
	grunt[12][0] = 4 * GAME_WIDTH / 6; grunt[12][1] = grunt[11][1] - gruntShipNS::HEIGHT / 2;
	grunt[13][0] = 5 * GAME_WIDTH / 6; grunt[13][1] = grunt[12][1] - gruntShipNS::HEIGHT / 2;
}