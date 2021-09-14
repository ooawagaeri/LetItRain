//  Module:             Gameplay Programming
//  Assignment1:        LET IT RAIN
//  Student Name:       Zhuang Yuteng
//  Student Number:     10163964C
#include "laserManager.h"

LaserManager::LaserManager()
{
	Tick = GetTickCount();
}

bool LaserManager::initialize(Game *gamePtr, int width, int height, int ncols,
	TextureManager *textureM, float X, float Y, Lasership lship)
{
	bool is_initialised = true;		//this verifies if all ships are successfully generated
	Laser *it = laser_collection.back();

	is_initialised = (it)->initialize(gamePtr, width, height, ncols, textureM, lship.getAttLevel());
	(it)->setFrames(laserNS::LASER_START_FRAME, laserNS::LASER_END_FRAME);
	(it)->setCurrentFrame(laserNS::LASER_START_FRAME);
	(it)->setVelocity(VECTOR2(laserNS::LASER_SPEED, laserNS::LASER_SPEED));
	(it)->setX(X);
	(it)->setY(Y);
	
	if (!is_initialised)
		return is_initialised;

	return is_initialised;
}

void LaserManager::update(float frameTime, Input *input, Game *gamePtr, int width, int height, int ncols,
	TextureManager *textureM, float X, float Y, Lasership lship)
{
	int tickCheck = 500 / lship.getSpeLevel();
	if (input->isKeyDown(FIRE_LASER_KEY) && lship.getActive())
	{
		if (GetTickCount() - Tick> tickCheck)
		{
			Tick = GetTickCount();
			laser_collection.push_back(new Laser());
			initialize(gamePtr, width, height, ncols, textureM, X, Y, lship);

		}


	}
	for (std::vector<Laser *>::iterator it = laser_collection.begin(); it < laser_collection.end(); ++it)
	{

		(*it)->update(frameTime);
	}


}

void LaserManager::ai() {}

void LaserManager::collisions(EnemyManager *enemyList) {
	VECTOR2 collisionVector;
	GRUNTSHIP *gruntCollection = enemyList->getGrunts();
	HUNTERSHIP *hunterCollection = enemyList->getHunters();
	CarrierShip *boss = enemyList->getCarrier();

	std::vector<Laser *>::iterator it = laser_collection.begin();
	while ( it != laser_collection.end())
	{
		for (GRUNTSHIP::iterator grunt = (gruntCollection->begin()); grunt != gruntCollection->end(); grunt++)
		{
			if ((*grunt)->collidesWith(**it, collisionVector))
			{
				(*grunt)->damage(LASER);
				(*it)->setVisible(false);
				(*it)->setActive(false);
				break;
			}
		}
		for (HUNTERSHIP::iterator hunter = (hunterCollection->begin()); hunter != hunterCollection->end(); hunter++)
		{
			if ((*hunter)->collidesWith(**it, collisionVector))
			{
				(*hunter)->damage(LASER);
				(*it)->setVisible(false);
				(*it)->setActive(false);
				break;
			}
		}

		if (boss->collidesWith(**it, collisionVector))
		{
			boss->damage(LASER);
			(*it)->setVisible(false);
			(*it)->setActive(false);
			break;
		}

		if (!(*it)->getActive())
			it = laser_collection.erase(it);
		else
			it++;
	}
}

void LaserManager::render()
{

	for (std::vector<Laser *>::iterator it = laser_collection.begin(); it < laser_collection.end(); ++it)
	{

		(*it)->draw();

	}
}