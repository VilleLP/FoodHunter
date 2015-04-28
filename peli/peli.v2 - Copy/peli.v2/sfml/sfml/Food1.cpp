#include "Food1.h"
#include "Enemy1.h"
#include <cassert>



	
Food1::Food1(const sf::Vector2u& renderDimensions)
	: _physicsWorld(b2Vec2(0.0f,10.0f)),
	foodBox(nullptr),
	_frameSize(40, 40),
	_frameCount(1, 1),
	_currentFrame(0, 0),
	_frameDuration(1.0f / 5.0f),
	_animationTime(0.0f)
	{
	const bool result = fTexture.loadFromFile("Food.png");
	assert(result);
	//Ensimmäisen food objektin sijoitus
	fSprite.setOrigin(0.5f * _frameSize.x, 0.5f * _frameSize.y);
	fSprite.setPosition(0.5f * renderDimensions.x, 0.7f * renderDimensions.y);
	fSprite.setTexture(fTexture);
	//Toisen food objektin sijoitus
	f2Sprite.setOrigin(0.5f * _frameSize.x, 0.5f * _frameSize.y);
	f2Sprite.setPosition(0.6f * renderDimensions.x, 0.7f * renderDimensions.y);
	f2Sprite.setTexture(fTexture);

	//ground
	b2BodyDef groundbodyDefinition;
	groundbodyDefinition.position.Set(2.0f, 3.0f);
	_ground = _physicsWorld.CreateBody(&groundbodyDefinition);
	b2PolygonShape groundShape;
	groundShape.SetAsBox(4.0f, 0.5f);
	_ground->CreateFixture(&groundShape, 0.0f);


	//Food objektin törmäys laatikon luominen
	b2BodyDef BoxBodyDefinition;
	BoxBodyDefinition.position.Set(2.0f, 1.0f);
	BoxBodyDefinition.type = b2_dynamicBody;
	foodBox = _physicsWorld.CreateBody(&BoxBodyDefinition);
	b2PolygonShape boxShape;
	boxShape.SetAsBox(0.25f, 0.25f);
	b2FixtureDef boxFixtureDefinition;
	boxFixtureDefinition.density = 1.0f;
	boxFixtureDefinition.friction = 0.3f;
	boxFixtureDefinition.restitution = 0.0f;
	boxFixtureDefinition.shape = &boxShape;
	foodBox->CreateFixture(&boxFixtureDefinition);

	//foodBox->SetLinearVelocity(b2Vec2(2.0f, -2.0f));
	//foodBox->SetAngularVelocity(-10.0f);
	}

	Food1::~Food1() {}

	//Food objektin piirtäminen
	void Food1::draw(sf::RenderWindow& window)
	{
		window.draw(f2Sprite);
		window.draw(fSprite);
	}
	//Food objektin törmäys tarkistus
	void Food1::foodCollisionCheck(const sf::Time& elapsedTime)
	{
		const float elapsedSeconds = elapsedTime.asSeconds();

		_physicsWorld.Step(elapsedSeconds, 8, 3);

		const b2Vec2 boxPosition = foodBox->GetPosition();
		
		


	}





