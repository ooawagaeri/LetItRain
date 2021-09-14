//  Module:             Gameplay Programming
//  Assignment1:        LET IT RAIN
//  Student Name:       Zhuang Yuteng
//  Student Number:     10163964C
#include "bulletManager.h"

BulletManager::BulletManager()
{
	Tick = GetTickCount();
}

bool BulletManager::initialize(Game *gamePtr, int width, int height, int ncols,
	TextureManager *textureM,float X, float Y, float xVelocity, int frame)
{
	bool is_initialised = true;		//this verifies if all ships are successfully generated
	Bullet *it = bullet_collection.back();
	
	is_initialised=(it)->initialize(gamePtr, width, height, ncols, textureM);
	(it)->setFrames(bulletNS::BULLET_START_FRAME, bulletNS::BULLET_END_FRAME);
	(it)->setCurrentFrame(frame);
	(it)->setVelocity(VECTOR2(bulletNS::BULLET_X_SPEED*xVelocity, bulletNS::BULLET_SPEED));
	(it)->setX(X);
	(it)->setY(Y);
	if (!is_initialised)
		return is_initialised;
	return is_initialised;
}

void BulletManager::update(float frameTime,Input *input, Game *gamePtr, int width, int height, int ncols,
	TextureManager *textureM, float X, float Y, Bulletship bship)
{	
	int tickCheck = 500 / bship.getSpeLevel();
	if (input->isKeyDown(FIRE_BULLET_KEY) && bship.getActive())
	{
		if (GetTickCount() - Tick > tickCheck)
		{
			Tick = GetTickCount();
			bullet_collection.push_back(new Bullet());
			initialize(gamePtr, width, height, ncols, textureM, X, Y, 0, bulletNS::BULLET_FRAME_STRAIGHT);
			if (bship.getAttLevel() >= 2) {
				bullet_collection.push_back(new Bullet());
				initialize(gamePtr, width, height, ncols, textureM, X, Y, bulletNS::BULLET_P1_LEFT, bulletNS::BULLET_FRAME_P1_LEFT);
				bullet_collection.push_back(new Bullet());
				initialize(gamePtr, width, height, ncols, textureM, X, Y, bulletNS::BULLET_P1_RIGHT, bulletNS::BULLET_FRAME_P1_RIGHT);
			}
			if (bship.getAttLevel() >= 3) {
				bullet_collection.push_back(new Bullet());
				initialize(gamePtr, width, height, ncols, textureM, X, Y, bulletNS::BULLET_P2_LEFT, bulletNS::BULLET_FRAME_P2_LEFT);
				bullet_collection.push_back(new Bullet());
				initialize(gamePtr, width, height, ncols, textureM, X, Y, bulletNS::BULLET_P2_RIGHT, bulletNS::BULLET_FRAME_P2_RIGHT);
			}
		}		
	}
	for (std::vector<Bullet *>::iterator it = bullet_collection.begin(); it < bullet_collection.end(); ++it)
	{
		(*it)->update(frameTime);
	}
}

void BulletManager::ai() {}


void BulletManager::collisions(EnemyManager *enemyList)
{
	VECTOR2 collisionVector;
	GRUNTSHIP *gruntCollection = enemyList->getGrunts();
	HUNTERSHIP *hunterCollection = enemyList->getHunters();
	CarrierShip *boss = enemyList->getCarrier();

	BULLETLIST::iterator it = bullet_collection.begin();
	while (it != bullet_collection.end())
	{
		for (GRUNTSHIP::iterator grunt = (gruntCollection->begin()); grunt != gruntCollection->end(); grunt++)
		{
			if ((*grunt)->collidesWith(**it, collisionVector))
			{
				(*grunt)->damage(BULLET);
				(*it)->setVisible(false);
				(*it)->setActive(false);
				break;
			}
		}
		for (HUNTERSHIP::iterator hunter = (hunterCollection->begin()); hunter != hunterCollection->end(); hunter++)
		{
			if ((*hunter)->collidesWith(**it, collisionVector))
			{
				(*hunter)->damage(BULLET);
				(*it)->setVisible(false);
				(*it)->setActive(false);
				break;
			}
		}

		if (boss->collidesWith(**it, collisionVector))
		{
			boss->damage(BULLET);
			(*it)->setVisible(false);
			(*it)->setActive(false);
			break;
		}

		if (!(*it)->getActive())
			it = bullet_collection.erase(it);
		else
			it++;
	}
}


void BulletManager::render()
{
	
	for (std::vector<Bullet *>::iterator it = bullet_collection.begin(); it < bullet_collection.end(); ++it)
	{
		
			(*it)->draw();		
		
	}
}