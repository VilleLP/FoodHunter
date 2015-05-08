#include "Player.h"
#include "cassert"

enum Direction { Down, Left, Right, Up };

Player::Player(const sf::Vector2u& renderDimensions)
	: _physicsWorld(b2Vec2(0.0f, 10.0f)),
	playerBox(nullptr),
	_frameSize(40, 40),
	_frameCount(1, 1),
	_currentFrame(0, 0),
	_frameDuration(1.0f / 5.0f),
	_animationTime(0.0f),
	dirSwitch(950),
	//e_contacting(0),
	time1(0),
	framespeed(500),
	//Liikkumisnopeus
	movement(1.5f),
	source(1, Down),
	canJump(true)


{
	const bool result = pTexture.loadFromFile("Player.png");
	assert(result);
	//pSprite.setOrigin(0.5f * _frameSize.x, 0.5f * _frameSize.y);
	//pSprite.setPosition(0.1f * renderDimensions.x, 0.1f * renderDimensions.y);
	pSprite.setTexture(pTexture);
	//view.reset(sf::FloatRect(0, 0, renderDimensions.x, renderDimensions.y));
	//view.setViewport(sf::FloatRect(0, 0, 1.0f, 1.0f));
	
	//ground
	b2BodyDef groundbodyDefinition;
	groundbodyDefinition.position.Set(2.0f, 2.99f);
	_ground = _physicsWorld.CreateBody(&groundbodyDefinition);
	b2PolygonShape groundShape;
	groundShape.SetAsBox(4.0f, 0.5f);
	_ground->CreateFixture(&groundShape, 0.0f);
	//groundShape.SetFillColor(sf::Color(165.0f, 42.0f, 42.0f));


	b2BodyDef BoxBodyDefinition;
	BoxBodyDefinition.position.Set(2.0f, 1.0f);
	BoxBodyDefinition.type = b2_dynamicBody;
	playerBox = _physicsWorld.CreateBody(&BoxBodyDefinition);
	b2PolygonShape boxShape;
	boxShape.SetAsBox(0.25f, 0.25f);
	b2FixtureDef boxFixtureDefinition;
	boxFixtureDefinition.density = 1.0f;
	boxFixtureDefinition.friction = 0.3f;
	boxFixtureDefinition.restitution = 0.0f;
	boxFixtureDefinition.shape = &boxShape;
	playerBox->CreateFixture(&boxFixtureDefinition);

	//BoxBodyDefinition.position.x = pSprite.getPosition().x + 10 - (renderDimensions.x / 2);
	//BoxBodyDefinition.position.y = pSprite.getPosition().y + 10 - (renderDimensions.y / 2);

	//if (BoxBodyDefinition.position.x < 0)
	//	BoxBodyDefinition.position.x = 0;
	//if (BoxBodyDefinition.position.y < 0)
	//	BoxBodyDefinition.position.y = 0;

	//view.reset(sf::FloatRect(BoxBodyDefinition.position.x, BoxBodyDefinition.position.y,
	//	renderDimensions.x, renderDimensions.y));
}


Player::~Player()
{
}


void Player::draw(sf::RenderWindow& window)
{
	window.draw(pSprite);

	sf::View view;
	sf::Vector2f screenDimension(800, 600);

	/*view.reset(sf::FloatRect(0, 0, screenDimension.x, screenDimension.y));*/
	view.setViewport(sf::FloatRect(0, 0, 1.0f, 1.0f));
	sf::Vector2f position(pSprite.getPosition());

	position.x = pSprite.getPosition().x + 10 - (screenDimension.x / 2);
	position.y =/* pSprite.getPosition().y + 10 - */(screenDimension.y /32);

	if (position.x < 0)
		position.x = 0;
	if (position.y < 0)
		position.y = 0;

	view.reset(sf::FloatRect(position.x, position.y, screenDimension.x, screenDimension.y));
	window.setView(view);
}


void Player::pUpdate(const sf::Time& elapsedTime)
{
	const float elapsedSeconds = elapsedTime.asSeconds();

	_physicsWorld.Step(elapsedSeconds, 8, 3);

	const b2Vec2 boxPosition = playerBox->GetPosition();
	pSprite.setPosition(100.0f * boxPosition.x, 180.0f * boxPosition.y);
	
	//Camera

	/*pSprite.getPosition.x = pSprite.getPosition().x + 10 - (renderDimensions.x / 2);
	pSprite.getPosition.y = pSprite.getPosition().y + 10 - (renderDimensions.y / 2);

	if (pSprite.getPosition.x < 0)
		pSprite.getPosition.x = 0;
	if (pSprite.getPosition.y < 0)
		pSprite.getPosition.y = 0;

	view.reset(sf::FloatRect(pSprite.getPosition.x, pSprite.getPosition.y,
		renderDimensions.x, renderDimensions.y));
		*/
	}

void Player::pMovement()
{
	enum Direction { Down, Left, Right, Up };
	sf::Vector2i source(1, Down);
	b2Vec2 velocity = playerBox->GetLinearVelocity();
	

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		source.y = Right;
		playerBox->SetLinearVelocity(b2Vec2(movement, velocity.y));
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		source.y = Left;
		playerBox->SetLinearVelocity(b2Vec2(-movement, velocity.y));
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && canJump == true)
	{
		canJump = false;
		source.y = Up;
		playerBox->SetLinearVelocity(b2Vec2(0, -4));
		
	}
	if (velocity.y == 0)
	{
		canJump = true;
	}

}