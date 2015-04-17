#include "Enemy1.h"



//enemy position
namespace game{

	Enemy1::Enemy1(){}
	Enemy1::Enemy1(const sf::Texture& enemyImage) :
		eSprite(enemyImage)
	{

		eSprite.setPosition(400, 400);
		eSprite.setScale(1.5f, 1.5f);
		
	}

	Enemy1::~Enemy1() {}

	void Enemy1::draw(sf::RenderTarget& targetE, sf::RenderStates statesE) const {
		targetE.draw(eSprite, statesE);
	}
	
	//liikkuminen
	void moveMent()
	{
		sf::Sprite eSprite;
		float dirSwitch = 1000;
		float time1 = 0;
		float framespeed = 500;
		//Liikkumisnopeus
		float movement = 0.02f;
		sf::Clock clock;


		time1 += framespeed*clock.restart().asSeconds();

		eSprite.move(movement, 0);


		if (time1 >= dirSwitch)
		{
			time1 = 0;
			movement *= -1;

		}

	}
	
	//Törmäyksen tarkistus
	void eCollisionCheck()
	{

	}
}
