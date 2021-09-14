//  Module:             Gameplay Programming
//  Assignment1:        LET IT RAIN
//  Student Name:       Timothy Chua
//  Student Number:     10165581F

#include "carrierShip.h"

CarrierShip::CarrierShip() : EnemyShip()
{
	movementSet = 1;
	movementTimer = GetTickCount();
	health = carrierShipNS::HEALTH;
	originalHealth = carrierShipNS::HEALTH;
	spriteData.width = carrierShipNS::WIDTH;           // size of Ship1
	spriteData.height = carrierShipNS::HEIGHT;
	spriteData.x = carrierShipNS::X;                   // location on screen
	spriteData.y = carrierShipNS::Y;
	spriteData.rect.bottom = carrierShipNS::HEIGHT;    // rectangle to select parts of an image
	spriteData.rect.right = carrierShipNS::WIDTH;
	spriteData.angle = carrierShipNS::ROTATION;
	spriteData.scale = carrierShipNS::SCALE;
	velocity.x = 0;                             // velocity X
	velocity.y = carrierShipNS::SPEED;                             // velocity Y
	frameDelay = carrierShipNS::ANIMATION_DELAY;
	startFrame = carrierShipNS::START_FRAME;     // first frame of ship animation
	endFrame = carrierShipNS::END_FRAME;     // last frame of ship animation
	currentFrame = startFrame;
	bulletOn = false;
	missileOn = false;
	rotation = 0.0f;
	spiralOn = false;
	explosionOn = false;
	damagedOn = false;
	active = false;
	healthOn = false;
	mass = carrierShipNS::MASS;
	edge = RECT{ (long)(-carrierShipNS::WIDTH * carrierShipNS::SCALE / 2), (long)(-carrierShipNS::HEIGHT * carrierShipNS::SCALE / 2), (long)(carrierShipNS::WIDTH * carrierShipNS::SCALE / 2), (long)(carrierShipNS::HEIGHT * carrierShipNS::SCALE / 2) };
	collisionType = entityNS::BOX;
}

bool CarrierShip::initialize(Game *gamePtr, int width, int height, int ncols,
	TextureManager *textureM)
{
	explosion.initialize(gamePtr->getGraphics(), explosionNS::WIDTH, explosionNS::HEIGHT, explosionNS::TEXTURE_COLS, textureM);
	explosion.setScale(carrierShipNS::EXPLOSION_SCALE);
	explosion.setFrames(explosionNS::START_FRAME, explosionNS::END_FRAME);
	explosion.setCurrentFrame(explosionNS::START_FRAME);
	explosion.setFrameDelay(explosionNS::ANIMATION_DELAY);
	explosion.setLoop(false);                  // do not loop animation

	damaged.initialize(gamePtr->getGraphics(), carrierShipNS::WIDTH, carrierShipNS::HEIGHT, carrierShipNS::DAMAGE_TEXTURE_COLS, textureM);
	damaged.setScale(carrierShipNS::SCALE);
	damaged.setFrames(carrierShipNS::DAMAGE_START_FRAME, carrierShipNS::DAMAGE_END_FRAME);
	damaged.setCurrentFrame(carrierShipNS::DAMAGE_START_FRAME);
	damaged.setFrameDelay(carrierShipNS::DAMAGE_ANIMATION_DELAY);
	damaged.setLoop(false);                  // do not loop animation

	healthBar.initialize(gamePtr->getGraphics(), textureM, carrierShipNS::HEALTHBAR_X, carrierShipNS::HEALTHBAR_Y, 1.0f, carrierShipNS::HEALTH);

	healthBoarder.initialize(gamePtr->getGraphics(), healthBoarderNS::WIDTH, healthBoarderNS::HEIGHT, healthBoarderNS::TEXTURE_COLS, textureM);
	healthBoarder.setCurrentFrame(healthBoarderNS::FRAME);
	healthBoarder.setX(carrierShipNS::HEALTHBAR_X - healthBoarderNS::WIDTH / 2);
	healthBoarder.setY(carrierShipNS::HEALTHBAR_Y);

	return(Entity::initialize(gamePtr, width, height, ncols, textureM));
}

void CarrierShip::draw()
{
	EnemyShip::draw();
	if (healthOn)
	{
		healthBar.setSize(health);
		if (!getActive())
		{
			healthBar.draw(graphicsNS::GRAY);
		}
		else
		{
			healthBar.draw(graphicsNS::RED);
		}
		healthBoarder.draw();
	}
}

void CarrierShip::ai(Entity *ship1, Entity *ship2)
{
	if (health == originalHealth / 2 && !spiralOn)
		movementSet = 4;

	// Basic movement from start
	if (movementSet == 1)
	{
		if(GetTickCount() - movementTimer > 16000 && getY() + 3 * carrierShipNS::HEIGHT / 5 >= 0 )
		{
			healthOn = true;
			active = true;
			if (getVelocity().y < 0) 
			{
				setVelocity(VECTOR2(0, 0));
				movementSet++;
			}
			else
			{
				setVelocity(-getVelocity());
			}
			movementTimer = GetTickCount();
		}
	}
	else if (movementSet == 2)
	{
		if (!bulletOn && !spiralOn)
		{
			bulletOn = !bulletOn;
			timer = GetTickCount();
		}
		if (GetTickCount() - movementTimer > 3000)
		{
			setVelocity(VECTOR2(-carrierShipNS::X_SPEED, 0));
			movementTimer = GetTickCount();
			movementSet++;
		}
	}
	else if (movementSet == 3)
	{
		if (GetTickCount() - movementTimer > 8000)
		{
			setVelocity(-getVelocity());
			movementTimer = GetTickCount();
			movementSet -= 2;
		}
	}
	// Agro movement
	else if (movementSet == 4)
	{
		active = false;
		bulletOn = false;
		setVelocity(VECTOR2(0, -carrierShipNS::SPEED * 1.5f));
		if (getY() + carrierShipNS::HEIGHT * carrierShipNS::SCALE < 0)
		{
			setX(carrierShipNS::X);
			setVelocity(VECTOR2(0, carrierShipNS::SPEED));
			active = true;
			spiralOn = !spiralOn;
			movementSet -= 3;
		}
	}
}

void CarrierShip::damage(WEAPON weapon)
{
	if (weapon != SHIP)
	{
		if (weapon == BULLET)
			health -= 2;
		else if (weapon == LASER)
			health -= 5;
		else if (weapon == MISSILE)
			health -= 25;

		if (health <= 0 && !explosionOn)
		{
			audio->playCue(BIGEXP);
			explosionOn = true;
		}
		else
			damagedOn = true;
	}
}