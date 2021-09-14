//  Module:             Gameplay Programming
//  Assignment1:        LET IT RAIN
//  Student Name:       Timothy Chua
//  Student Number:     10165581F

#include "enemyManager.h"

EnemyManager::EnemyManager()
{
	spawner = new Spawner();
//	spawn = new SpawnPosition();
	boss = new CarrierShip();
	boss->setAlive(false);
}

bool EnemyManager::initialize(Game *gamePtr, TextureManager *textureM, int *stageNo, textManager *score, Bulletship *ship1, Lasership *ship2)
{
	bool isInitialised = true;		//this verifies if all ships are successfully generated
	spawner->clear();
	spawner->initialize(*stageNo);
	bulletShip = ship1;
	laserShip = ship2;
	scoring = score;
	stage = *stageNo;

	// Grunt List initialization
	VECTOR2 positionGrunt;
	gruntSize = spawner->gruntSize();
	for (int i = 0; i <= gruntSize; i++)
	{
		if (!spawner->gruntEmpty())
		{
			positionGrunt = spawner->getGrunt();
			gruntCollection.emplace_back(new GruntShip());
			isInitialised = gruntCollection.back()->initialize(gamePtr, gruntShipNS::WIDTH, gruntShipNS::HEIGHT, gruntShipNS::TEXTURE_COLS, textureM);
			gruntCollection.back()->setX(positionGrunt.x - gruntShipNS::WIDTH*gruntShipNS::SCALE / 2);
			gruntCollection.back()->setY(positionGrunt.y);
			if (!isInitialised)
				return !isInitialised;
		}
	}

	// Hunter List initialization
	d4Hunter positionHunter;
	hunterSize = spawner->hunterSize();
	for (int i = 0; i <= hunterSize; i++)
	{
		if (!spawner->hunterEmpty())
		{
			positionHunter = spawner->getHunter();
			hunterCollection.emplace_back(new HunterShip());
			isInitialised = hunterCollection.back()->initialize(gamePtr, hunterShipNS::WIDTH, hunterShipNS::HEIGHT, hunterShipNS::TEXTURE_COLS, textureM);
			hunterCollection.back()->setX(positionHunter.x - hunterShipNS::WIDTH*hunterShipNS::SCALE / 2);
			hunterCollection.back()->setY(positionHunter.y);
			hunterCollection.back()->setRadians(positionHunter.rotation);
			hunterCollection.back()->setVelocity(VECTOR2(positionHunter.x_speed, positionHunter.y_speed));
			if (!isInitialised)
				return !isInitialised;
		}
	}

	if (stage == 3 && !boss->getActive())
	{
		gamePtr->getAudio()->stopCue(INTRO);
		gamePtr->getAudio()->playCue(BEATDOWN);
		boss->setAlive(true);
		boss->initialize(gamePtr, carrierShipNS::WIDTH, carrierShipNS::HEIGHT, carrierShipNS::TEXTURE_COLS, textureM);
	}

	hunterCollection.emplace_back(new HunterShip());
	isInitialised = hunterCollection.back()->initialize(gamePtr, hunterShipNS::WIDTH, hunterShipNS::HEIGHT, hunterShipNS::TEXTURE_COLS, textureM);
	hunterCollection.back()->setX(GAME_WIDTH / 2 - hunterShipNS::WIDTH*hunterShipNS::SCALE / 2);
	hunterCollection.back()->setY(GAME_HEIGHT / 2);
	hunterCollection.back()->setEdge(RECT{ (long)(-300), (long)(-400), (long)(300), (long)(400) });
	hunterCollection.back()->setVelocity(VECTOR2(0, 0));

	return isInitialised;
}

void EnemyManager::update(float frameTime, Game *gamePtr, TextureManager *textureM, int *stage)
{
	int gruntCount = 0;
	int hunterCount = 0;

	for (grunt = gruntCollection.begin(); grunt != gruntCollection.end(); grunt++)
	{
		if ((*grunt)->getAlive())
		{
			gruntCount++;
			(*grunt)->update(frameTime);
		}
	}
	for (hunter = hunterCollection.begin(); hunter != hunterCollection.end(); hunter++)
	{
		if ((*hunter)->getAlive())
		{
			hunterCount++;
			(*hunter)->update(frameTime);
		}
	}

	if (boss->getAlive())
		boss->update(frameTime);
	else if (gruntCount == 0 && hunterCount == 0  && *stage < 3)
	{
		*stage = *stage + 1;
		initialize(gamePtr, textureM, stage, scoring, bulletShip, laserShip);
	}
}

void EnemyManager::ai()
{
	if (boss->getAlive())
		boss->ai(bulletShip, laserShip);

	for (hunter = hunterCollection.begin(); hunter != hunterCollection.end(); hunter++)
	{
		if ((*hunter)->getAlive())
			(*hunter)->ai(*bulletShip, *laserShip);
	}
}

void EnemyManager::collisions()
{
	VECTOR2 collisionVector;
	grunt = gruntCollection.begin();
	while ( grunt != gruntCollection.end())
	{
		if ((*grunt)->getAlive()) {
			if ((*grunt)->collidesWith(*bulletShip, collisionVector))
			{
				(*grunt)->damage(SHIP);
				bulletShip->damage(SHIP);
			}
			if ((*grunt)->collidesWith(*laserShip, collisionVector))
			{
				(*grunt)->damage(SHIP);
				laserShip->damage(SHIP);
			}
			grunt++;
		}
		else
		{
			if (!(*grunt)->getOutOfBound())
				scoring->incrementScore(100);
			grunt = gruntCollection.erase(grunt);
		}
	}

	hunter = hunterCollection.begin();
	while (hunter != hunterCollection.end())
	{
		if ((*hunter)->getAlive()) {
			if ((*hunter)->collidesWith(*bulletShip, collisionVector))
			{
				(*hunter)->damage(SHIP);
				bulletShip->damage(SHIP);
			}
			if ((*hunter)->collidesWith(*laserShip, collisionVector))
			{
				(*hunter)->damage(SHIP);
				laserShip->damage(SHIP);
			}
			hunter++;
		}
		else
		{
			if (!(*hunter)->getOutOfBound())
				scoring->incrementScore(1000);
			hunter = hunterCollection.erase(hunter);
		}
	}

	if (!boss->getAlive() && !(boss->getHealth() <= 0) && !boss->getActive() && stage == 3)
	{
		scoring->incrementScore(10000);
		boss->setActive(true);
	}
}

void EnemyManager::render()
{
	for (grunt = gruntCollection.begin(); grunt != gruntCollection.end(); grunt++)
	{
		if ((*grunt)->getAlive())
			(*grunt)->draw();
	}

	for (hunter = hunterCollection.begin(); hunter != hunterCollection.end(); hunter++)
	{
		if ((*hunter)->getAlive())
 			(*hunter)->draw();
	}

	if (boss->getAlive())
		boss->draw();
}