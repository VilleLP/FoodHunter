#include "Enemy1.h"
#include "Food1.h"
#include <cassert>


Enemy1::Enemy1(const sf::Vector2u& renderDimensions)
	: _physicsWorld(b2Vec2(0.0f, 10.0f)),
	enemyBox(nullptr),
	_frameSize(40, 40),
	_frameCount(1, 1),
	_currentFrame(0, 0),
	_frameDuration(1.0f / 5.0f),
	_animationTime(0.0f),
	dirSwitch(950),
	e_contacting(0),
	time1(0),
	framespeed(500),
	//Liikkumisnopeus
	movement(0.02f),
	m_imIt(false)
	{
		const bool result = eTexture.loadFromFile("Enemybox.png");
		assert(result);
		eSprite.setOrigin(0.5f * _frameSize.x, 0.5f * _frameSize.y);
		eSprite.setPosition(0.4f * renderDimensions.x, 0.7f * renderDimensions.y);
		eSprite.setTexture(eTexture);

		b2BodyDef BoxBodyDefinition;
		BoxBodyDefinition.position.Set(2.0f, 1.0f);
		BoxBodyDefinition.type = b2_dynamicBody;
		enemyBox = _physicsWorld.CreateBody(&BoxBodyDefinition);
		b2PolygonShape boxShape;
		boxShape.SetAsBox(0.25f, 0.25f);
		b2FixtureDef boxFixtureDefinition;
		boxFixtureDefinition.density = 1.0f;
		boxFixtureDefinition.friction = 0.3f;
		boxFixtureDefinition.restitution = 0.0f;
		boxFixtureDefinition.shape = &boxShape;
		enemyBox->CreateFixture(&boxFixtureDefinition);

		//enemyBox->SetLinearVelocity(b2Vec2(2.0f, -2.0f));
		//enemyBox->SetAngularVelocity(-10.0f);

		enemyBox->SetUserData(this);

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

	void Enemy1::startContact()
	{
		e_contacting++;
	}

	void Enemy1::endContact()
	{
		e_contacting--;
	}

	//Enemy objektin törmäyksen tarkistus
	void Enemy1::eCollisionCheck(const sf::Time& elapsedTime)
	{
		//const float elapsedSeconds = elapsedTime.asSeconds();

		//_physicsWorld.Step(elapsedSeconds, 8, 3);

		//const b2Vec2 boxPosition = enemyBox->GetPosition();
		


		if (e_contacting > 0)
		{
			movement = movement + 0.04f;
		}
		else
		{
			movement = movement;
		}
	}


//}
