//  Module:             Gameplay Programming
//  Assignment1:        LET IT RAIN
//  Student Name:       Timothy Chua
//  Student Number:     10165581F

#include "spawner.h"

Spawner::Spawner()
{
}

bool Spawner::initialize(int stage)
{
	clear();
	bool isInitialized = true;
	try {
		if (stage == 1)
			loadStage1();
		else if (stage == 2)
			loadStage2();
		else if (stage == 3)
			loadStage3();
		else
			return !isInitialized; // invalid stage
	}
	catch (...)
	{
		isInitialized = !isInitialized;
	}
	return isInitialized;
}

void Spawner::loadStage1()
{
	gruntSpawn.push(VECTOR2(GAME_WIDTH / 2, -2 * gruntShipNS::HEIGHT));
	gruntSpawn.push(VECTOR2(GAME_WIDTH / 2, gruntSpawn.back().y - gruntShipNS::HEIGHT));
	gruntSpawn.push(VECTOR2(GAME_WIDTH / 2, gruntSpawn.back().y - gruntShipNS::HEIGHT));
	gruntSpawn.push(VECTOR2(GAME_WIDTH / 2, gruntSpawn.back().y - gruntShipNS::HEIGHT));
	gruntSpawn.push(VECTOR2(GAME_WIDTH / 2, gruntSpawn.back().y - gruntShipNS::HEIGHT));

	gruntSpawn.push(VECTOR2(GAME_WIDTH / 4, gruntSpawn.back().y - 5 * gruntShipNS::HEIGHT));
	gruntSpawn.push(VECTOR2(GAME_WIDTH / 4, gruntSpawn.back().y - gruntShipNS::HEIGHT));
	gruntSpawn.push(VECTOR2(3 * GAME_WIDTH / 4, gruntSpawn.back().y + gruntShipNS::HEIGHT));
	gruntSpawn.push(VECTOR2(3 * GAME_WIDTH / 4, gruntSpawn.back().y - gruntShipNS::HEIGHT));

	gruntSpawn.push(VECTOR2(1 * GAME_WIDTH / 6, gruntSpawn.back().y - 5 * gruntShipNS::HEIGHT));
	gruntSpawn.push(VECTOR2(2 * GAME_WIDTH / 6, gruntSpawn.back().y + gruntShipNS::HEIGHT / 2));
	gruntSpawn.push(VECTOR2(3 * GAME_WIDTH / 6, gruntSpawn.back().y + gruntShipNS::HEIGHT / 2));
	gruntSpawn.push(VECTOR2(4 * GAME_WIDTH / 6, gruntSpawn.back().y - gruntShipNS::HEIGHT / 2));
	gruntSpawn.push(VECTOR2(5 * GAME_WIDTH / 6, gruntSpawn.back().y - gruntShipNS::HEIGHT / 2));

	gruntSpawn.push(VECTOR2(1 * GAME_WIDTH / 6, gruntSpawn.back().y - 5 * gruntShipNS::HEIGHT));
	gruntSpawn.push(VECTOR2(2 * GAME_WIDTH / 6, gruntSpawn.back().y - gruntShipNS::HEIGHT / 2));
	gruntSpawn.push(VECTOR2(3 * GAME_WIDTH / 6, gruntSpawn.back().y - gruntShipNS::HEIGHT / 2));
	gruntSpawn.push(VECTOR2(4 * GAME_WIDTH / 6, gruntSpawn.back().y - gruntShipNS::HEIGHT / 2));
	gruntSpawn.push(VECTOR2(5 * GAME_WIDTH / 6, gruntSpawn.back().y - gruntShipNS::HEIGHT / 2));

	gruntSpawn.push(VECTOR2(GAME_WIDTH / 6, gruntSpawn.back().y - 5 * gruntShipNS::HEIGHT));
	gruntSpawn.push(VECTOR2(2 * GAME_WIDTH / 6, gruntSpawn.back().y - gruntShipNS::HEIGHT / 2));
	gruntSpawn.push(VECTOR2(3 * GAME_WIDTH / 6, gruntSpawn.back().y - gruntShipNS::HEIGHT / 2));
	gruntSpawn.push(VECTOR2(4 * GAME_WIDTH / 6, gruntSpawn.back().y - gruntShipNS::HEIGHT / 2));
	gruntSpawn.push(VECTOR2(5 * GAME_WIDTH / 6, gruntSpawn.back().y - gruntShipNS::HEIGHT / 2));

}

void Spawner::loadStage2()
{
	hunterSpawn.push(d4Hunter{ -hunterShipNS::WIDTH, GAME_HEIGHT, 1 * (float)PI / 5, hunterShipNS::SPEED*cos(1 * (float)PI / 5), -hunterShipNS::SPEED });
	hunterSpawn.push(d4Hunter{ GAME_WIDTH + hunterShipNS::WIDTH, GAME_HEIGHT, 2 * (float)PI - (float)PI / 5, -hunterShipNS::SPEED*cos(9 * (float)PI / 5), -hunterShipNS::SPEED });

	gruntSpawn.push(VECTOR2(GAME_WIDTH / 4, - 5 * gruntShipNS::HEIGHT));
	gruntSpawn.push(VECTOR2(GAME_WIDTH / 4, gruntSpawn.back().y - gruntShipNS::HEIGHT));
	gruntSpawn.push(VECTOR2(3 * GAME_WIDTH / 4, gruntSpawn.back().y + gruntShipNS::HEIGHT));
	gruntSpawn.push(VECTOR2(3 * GAME_WIDTH / 4, gruntSpawn.back().y - gruntShipNS::HEIGHT));

	gruntSpawn.push(VECTOR2(2 * GAME_WIDTH / 5, gruntSpawn.back().y - 5 * gruntShipNS::HEIGHT));
	gruntSpawn.push(VECTOR2(2 * GAME_WIDTH / 5, gruntSpawn.back().y - gruntShipNS::HEIGHT));
	gruntSpawn.push(VECTOR2(3 * GAME_WIDTH / 5, gruntSpawn.back().y + gruntShipNS::HEIGHT));
	gruntSpawn.push(VECTOR2(3 * GAME_WIDTH / 5, gruntSpawn.back().y - gruntShipNS::HEIGHT));

	gruntSpawn.push(VECTOR2(1 * GAME_WIDTH / 6, gruntSpawn.back().y - 6 * gruntShipNS::HEIGHT));
	gruntSpawn.push(VECTOR2(2 * GAME_WIDTH / 6, gruntSpawn.back().y + gruntShipNS::HEIGHT));
	gruntSpawn.push(VECTOR2(3 * GAME_WIDTH / 6, gruntSpawn.back().y + gruntShipNS::HEIGHT));
	gruntSpawn.push(VECTOR2(4 * GAME_WIDTH / 6, gruntSpawn.back().y - gruntShipNS::HEIGHT));
	gruntSpawn.push(VECTOR2(5 * GAME_WIDTH / 6, gruntSpawn.back().y - gruntShipNS::HEIGHT));

	hunterSpawn.push(d4Hunter{ 1 * GAME_WIDTH / 5, gruntSpawn.back().y / 3 - hunterShipNS::HEIGHT, (float)PI, 0, hunterShipNS::SPEED });
	hunterSpawn.push(d4Hunter{ 4 * GAME_WIDTH / 5, hunterSpawn.back().y, (float)PI , 0, hunterShipNS::SPEED });
	hunterSpawn.push(d4Hunter{ GAME_WIDTH + hunterShipNS::WIDTH,  hunterSpawn.back().y - 4 * hunterShipNS::HEIGHT, 1 * (float)PI / 5 + (float)PI, hunterShipNS::SPEED*cos(2 * (float)PI / 5 + (float)PI), hunterShipNS::SPEED });
	hunterSpawn.push(d4Hunter{ -hunterShipNS::WIDTH, hunterSpawn.back().y, 9 * (float)PI / 5 + (float)PI, -hunterShipNS::SPEED*cos(8 * (float)PI / 5 + (float)PI), hunterShipNS::SPEED });
}

void Spawner::loadStage3()
{
	hunterSpawn.push(d4Hunter{ GAME_WIDTH / 2 -hunterShipNS::WIDTH, GAME_HEIGHT/2, 0, 0, 0 });
	//hunterSpawn.push(d4Hunter{ GAME_WIDTH / 2 + hunterShipNS::WIDTH, GAME_HEIGHT / 2, 0, 0, 0 });
//	hunterSpawn.push(d4Hunter{ GAME_WIDTH + hunterShipNS::WIDTH, GAME_HEIGHT, 2 * (float)PI - (float)PI / 5, -hunterShipNS::SPEED*cos(9 * (float)PI / 5), -hunterShipNS::SPEED });

	//gruntSpawn.push(VECTOR2(2 * GAME_WIDTH / 6, - 12 * gruntShipNS::HEIGHT));
	//gruntSpawn.push(VECTOR2(3 * GAME_WIDTH / 6, gruntSpawn.back().y + gruntShipNS::HEIGHT / 2));
	//gruntSpawn.push(VECTOR2(4 * GAME_WIDTH / 6, gruntSpawn.back().y - gruntShipNS::HEIGHT / 2));

	//for (int i = 0; i < 9; i++)
	//{
	//	gruntSpawn.push(VECTOR2(rand() % 7 * GAME_WIDTH / 7, gruntSpawn.back().y - 10 * gruntShipNS::HEIGHT));
	//}
}

d4PowerUp Spawner::getValue()
{
	d4PowerUp pos = spawn.front();
	spawn.pop();
	return pos;
}
VECTOR2 Spawner::getGrunt()
{
	VECTOR2 pos = gruntSpawn.front();
	gruntSpawn.pop();
	return pos;
}
d4Hunter Spawner::getHunter()
{
	d4Hunter pos = hunterSpawn.front();
	hunterSpawn.pop();
	return pos;
}

void Spawner::clear()
{
	gruntSpawn = std::queue<VECTOR2>();
	hunterSpawn = std::queue<d4Hunter>();
	spawn = std::queue<d4PowerUp>();
}