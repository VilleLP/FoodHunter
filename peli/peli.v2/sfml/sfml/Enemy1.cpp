#include "Enemy1.h"
#include <cassert>


	Enemy1::Enemy1(const sf::Vector2u& renderDimensions)
		: _frameSize(40, 40),
		_frameCount(1, 1),
		_currentFrame(0, 0),
		_frameDuration(1.0f / 5.0f),
		_animationTime(0.0f),	
		dirSwitch(1000),
		time1(0),
		framespeed(500),
		//Liikkumisnopeus
		movement(0.02f)
	{
		const bool result = eTexture.loadFromFile("Enemybox.png");
		assert(result);
		eSprite.setOrigin(0.5f * _frameSize.x, 0.5f * _frameSize.y);
		eSprite.setPosition(0.5f * renderDimensions.x, 0.7f * renderDimensions.y);
		eSprite.setTexture(eTexture);


	}

	Enemy1::~Enemy1() {}
	
	void Enemy1::moveMent()
	{
		
		time1 += framespeed*clock.restart().asSeconds();

		eSprite.move(movement, 0);

		
		if (time1 >= dirSwitch)
		{
			time1 = 0;
			movement *= -1;

		}
		
	}
	

	void Enemy1::draw(sf::RenderWindow& window2)
	{

		window2.draw(eSprite);

	}
	
	//Törmäyksen tarkistus
	void eCollisionCheck()
	{

	}
//}
