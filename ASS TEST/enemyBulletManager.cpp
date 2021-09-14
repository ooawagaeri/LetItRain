//  Module:             Gameplay Programming
//  Assignment1:        LET IT RAIN
//  Student Name:       Timothy Chua
//  Student Number:     10165581F

#include "enemyBulletManager.h"

EnemyBulletManager::EnemyBulletManager()
{
}

bool EnemyBulletManager::initialize(EnemyManager *enemyList, Bulletship *ship1, Lasership *ship2)
{
	try
	{
		hunterCollection = enemyList->getHunters();
		boss = enemyList->getCarrier();
		bulletShip = ship1;
		laserShip = ship2;
		return true;
	}
	catch (...)
	{
		return false;
	}
}

bool EnemyBulletManager::initialize(Game *gamePtr, TextureManager *textureM, EnemyShip *enemy)
{
	bool isInitialised = true;		//this verifies if all ships are successfully generated

	if (HunterShip * hunterEnemy = dynamic_cast<HunterShip*>(enemy))
	{
		EnemyBullet *it = hunterBullets.back();
		isInitialised = it->initialize(gamePtr, enemyBulletNS::WIDTH, enemyBulletNS::HEIGHT, enemyBulletNS::TEXTURE_COLS, textureM);
		it->setFrames(enemyBulletNS::START_FRAME, enemyBulletNS::END_FRAME);
		it->setCurrentFrame(enemyBulletNS::START_FRAME);
		hunterEnemy->ai(*bulletShip, *laserShip);
		it->setVelocity(*(hunterEnemy->getTarget()));
		it->setX(hunterEnemy->getCenterX() - enemyBulletNS::WIDTH / 2);
		it->setY(hunterEnemy->getCenterY() - enemyBulletNS::HEIGHT / 2);
	}

	if (!isInitialised)
		return !isInitialised;

	return isInitialised;
}

bool EnemyBulletManager::initialize(Game *gamePtr, TextureManager *textureM, EnemyShip *enemy, int x)
{
	bool isInitialised = true;		//this verifies if all ships are successfully generated

	if (CarrierShip * carrierEnemy = dynamic_cast<CarrierShip*>(enemy))
	{
		EnemyBullet *it = carrierBullets.back();
		isInitialised = it->initialize(gamePtr, enemyBulletNS::WIDTH, enemyBulletNS::HEIGHT, enemyBulletNS::TEXTURE_COLS, textureM);
		it->setFrames(enemyBulletNS::START_FRAME, enemyBulletNS::END_FRAME);
		it->setCurrentFrame(enemyBulletNS::START_FRAME);
		it->setX(carrierEnemy->getCenterX() - x - enemyBulletNS::WIDTH / 2);
		it->setY(carrierEnemy->getCenterY() + carrierShipNS::HEIGHT / 2);
		it->setVelocity(VECTOR2(sin(carrierEnemy->getRadian())*-enemyBulletNS::SPEED, cos(carrierEnemy->getRadian())*-enemyBulletNS::SPEED));
	}

	if (!isInitialised)
		return !isInitialised;

	return isInitialised;
}

void EnemyBulletManager::update(float frameTime, Game *gamePtr, TextureManager *textureM)
{
	for (hunter = hunterCollection->begin(); hunter != hunterCollection->end(); hunter++)
	{
		if ((*hunter)->getBullet() && (GetTickCount() - (*hunter)->getTimer() > hunterShipNS::FIRE_RATE) && (*hunter)->getAlive())
		{
			(*hunter)->setTimer(GetTickCount());
			hunterBullets.push_back(new EnemyBullet());
			initialize(gamePtr, textureM, *hunter);
		}
	}

	if (boss->getBullet() && (GetTickCount() - boss->getTimer() > carrierShipNS::FIRE_RATE) && boss->getAlive())
	{
		boss->setTimer(GetTickCount());
		carrierBullets.push_back(new EnemyBullet());
		initialize(gamePtr, textureM, boss, 2 * boss->getWidth()*boss->getScale() / 7);
		carrierBullets.push_back(new EnemyBullet());
		initialize(gamePtr, textureM, boss, 2 * -boss->getWidth()*boss->getScale() / 7);
	}
	else if (boss->getSpiral() && (GetTickCount() - boss->getTimer() > carrierShipNS::FIRE_RATE) && boss->getAlive())
	{
		boss->setTimer(GetTickCount());
		for (int i = 0; i < 8; i++)
		{
			carrierBullets.push_back(new EnemyBullet());
			initialize(gamePtr, textureM, boss, 0);
			boss->setRotation(boss->getRotation() + 45);
		}
		boss->setRotation(boss->getRotation() + 10);
	}

	for (bullet = hunterBullets.begin(); bullet != hunterBullets.end(); bullet++)
	{
		(*bullet)->update(frameTime);
	}
	for (bullet = carrierBullets.begin(); bullet != carrierBullets.end(); bullet++)
	{
		(*bullet)->update(frameTime);
	}
}

void EnemyBulletManager::ai() {}


void EnemyBulletManager::collisions()
{
	VECTOR2 collisionVector;
	bullet = hunterBullets.begin();
	while (bullet != hunterBullets.end())
	{
		if ((bulletShip)->collidesWith(**bullet, collisionVector))
		{
			//(bulletShip)->damage(BULLET);
			(*bullet)->setVisible(false);
			(*bullet)->setActive(false);
		}
		else if ((laserShip)->collidesWith(**bullet, collisionVector))
		{
			//(laserShip)->damage(BULLET);
			(*bullet)->setVisible(false);
			(*bullet)->setActive(false);
		}
		if (!(*bullet)->getActive())
			bullet = hunterBullets.erase(bullet);
		else
			bullet++;
	}

	bullet = carrierBullets.begin();
	while (bullet != carrierBullets.end())
	{
		if ((bulletShip)->collidesWith(**bullet, collisionVector))
		{
			//(bulletShip)->damage(BULLET);
			(*bullet)->setVisible(false);
			(*bullet)->setActive(false);
		}
		else if ((laserShip)->collidesWith(**bullet, collisionVector))
		{
			//(laserShip)->damage(BULLET);
			(*bullet)->setVisible(false);
			(*bullet)->setActive(false);
		}
		if (!(*bullet)->getActive())
			bullet = carrierBullets.erase(bullet);
		else
			bullet++;
	}
}

void EnemyBulletManager::render()
{
	for (bullet = hunterBullets.begin(); bullet != hunterBullets.end(); bullet++)
	{
		(*bullet)->draw();
	}
	for (bullet = carrierBullets.begin(); bullet != carrierBullets.end(); bullet++)
	{
		(*bullet)->draw();
	}
}