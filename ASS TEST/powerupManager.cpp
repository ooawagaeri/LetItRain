//  Module:             Gameplay Programming
//  Assignment1:        LET IT RAIN
//  Student Name:       Daniel Lee
//  Student Number:     10162739H

#include "powerupManager.h"

PowerupManager::PowerupManager()
{
	for (int i = 0; i < POWERUP_MAX_SIZE; i++)
	{
		powerupCollection.push_back(new PowerUp());
	}
	spawn = new SpawnPosition(1);
	slowMoThreadDone = false;
	bulletshipShieldDone = false;
	lasershipShieldDone = false;
	count = 0;
}

bool PowerupManager::initialize(Game *gamePtr, int width, int height, int ncols,
	TextureManager *textureM)
{
	bool okay = true;		//this verifies if all ships are successfully generated
	int count = 0;
	for (powerup = powerupCollection.begin(); powerup != powerupCollection.end(); powerup++)
	{
		okay = (*powerup)->initialize(gamePtr, width, height, ncols, textureM);
		(*powerup)->setFrames(powerupNS::POWERUP_START_FRAME, powerupNS::POWERUP_END_FRAME);
		(*powerup)->setVelocity(VECTOR2(0, powerupNS::VELOCITY));
		(*powerup)->setX(spawn->getPowerUp(count, 0));
		(*powerup)->setY(spawn->getPowerUp(count, 1));
		(*powerup)->setCurrentFrame(spawn->getPowerUp(count, 2));
		(*powerup)->setType(spawn->getPowerUp(count, 2));
		(*powerup)->setActive(true);
		count++;
		if (!okay)
			return okay;
	}
	return okay;
}

void PowerupManager::update(float frameTime, Bulletship bship, Lasership lship)
{
	for (powerup = powerupCollection.begin(); powerup != powerupCollection.end(); powerup++)
	{
		(*powerup)->update(frameTime, bship, lship);
	}
}

void PowerupManager::ai() {}

void PowerupManager::detachThread() {
	if (slowMoThreadDone == true) {
		slowMo.detach();
	}
	if (bulletshipShieldDone == true) {
		bulletshipShield.detach();
	}
	if (lasershipShieldDone == true) {
		lasershipShield.detach();
	}
}

void PowerupManager::powerupTimer(Game *gamePtr) {
	slowMoThreadDone = true;
	Sleep(5000);
	gamePtr->setTimeModifier(1);
	slowMo.detach();
	slowMoThreadDone = false;
}

void PowerupManager::powerupBulletshipShield(Bulletship *bship) {
	bulletshipShieldDone = true;
	Sleep(5000);
	bship->setShieldOn(false);
	bulletshipShield.detach();
	bulletshipShieldDone = false;
}


void PowerupManager::powerupLasershipShield(Lasership *lship) {
	lasershipShieldDone = true;
	Sleep(5000);
	lship->setShieldOn(false);
	lasershipShield.detach();
	lasershipShieldDone = false;
}

void PowerupManager::collisions(Bulletship *bship, Game *gamePtr, TextureManager *textureM)
{
	VECTOR2 collisionVector;
	for (powerup = powerupCollection.begin(); powerup != powerupCollection.end(); powerup++)
	{
		if ((*powerup)->collidesWith(*bship, collisionVector))
		{
			if ((*powerup)->getVisible() == true && (*powerup)->getActive() == true) {
				gamePtr->getAudio()->playCue(POWERUP);
				if ((*powerup)->getType() == 0) {
					if (bship->getAttLevel() < 3) {
						bship->setAttLevel(bship->getAttLevel() + 1);
					}
				}
				else if ((*powerup)->getType() == 1) {
					if (bship->getSpeLevel() < 3) {
						bship->setSpeLevel(bship->getSpeLevel() + 1);
					}
				}
				else if ((*powerup)->getType() == 2) {
					if (bship->getHealth() < 3) {
						bship->setHealth((float)bship->getHealth() + 1);
					}
				}
				else if ((*powerup)->getType() == 3) {
					bship->setShieldOn(true);
					if (bulletshipShieldDone == false) {
						bulletshipShield = std::thread(&PowerupManager::powerupBulletshipShield, this, bship);
					}
				}
				else if ((*powerup)->getType() == 4) {
					gamePtr->setTimeModifier(0.5);
					if (slowMoThreadDone == false) {
						slowMo = std::thread(&PowerupManager::powerupTimer, this, gamePtr);
					}
					
				}
			}
			(*powerup)->setVisible(false);
			if ((*powerup)->getActive() == true) {
				bship->writePowerUpText((*powerup)->getType());
			}
			if (slowMoThreadDone != true) {
				(*powerup)->setActive(false);
			}
		}
	}
}
void PowerupManager::collisions(Lasership *lship, Game *gamePtr)
{
	VECTOR2 collisionVector;
	for (powerup = powerupCollection.begin(); powerup != powerupCollection.end(); powerup++)
	{
		if ((*powerup)->collidesWith(*lship, collisionVector))
		{
			if ((*powerup)->getVisible() == true && (*powerup)->getActive() == true) {
				if ((*powerup)->getType() == 0) {
					if (lship->getAttLevel() < 3) {
						lship->setAttLevel(lship->getAttLevel() + 1);
					}
				}
				else if ((*powerup)->getType() == 1) {
					if (lship->getSpeLevel() < 3) {
						lship->setSpeLevel(lship->getSpeLevel() + 1);
					}
				}
				else if ((*powerup)->getType() == 2) {
					continue;
				}
				else if ((*powerup)->getType() == 3) {
					lship->setShieldOn(true);
					if (lasershipShieldDone == false) {
						lasershipShield = std::thread(&PowerupManager::powerupLasershipShield, this, lship);
					}
				}
				else if ((*powerup)->getType() == 4) {
					gamePtr->setTimeModifier(0.5);
					if (slowMoThreadDone == false) {
						slowMo = std::thread(&PowerupManager::powerupTimer, this, gamePtr);
					}
				}

			}
			(*powerup)->setVisible(false);
			if ((*powerup)->getActive() == true) {
				lship->writePowerUpText((*powerup)->getType());
			}
			if (slowMoThreadDone == true)
				(*powerup)->setActive(false);
		}
	}
}

void PowerupManager::render()
{
	for (powerup = powerupCollection.begin(); powerup != powerupCollection.end(); powerup++)
	{



		(*powerup)->draw();
	}
}