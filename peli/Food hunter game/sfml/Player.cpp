#include "Player.h"
#include "cassert"
#include "sstream"


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
	time1(0),
	framespeed(500),
	movement(1.5f),
	source(1, Down),
	canJump(true),
	reSpawnCheck(),
	life(3)

	


{
	const bool result = pTexture.loadFromFile("Player.png");
	const bool resultg = gTexture.loadFromFile("ground.png");
	const bool resultg2 = g2Texture.loadFromFile("ground.png");
	bool resultld = lifeTextured.loadFromFile("dead.png");
	bool resultl1 = lifeTexture1.loadFromFile("life1.png");
	bool resultl2 = lifeTexture2.loadFromFile("life2.png");
	bool resultl3 = lifeTexture3.loadFromFile("life3.png");
	fontti.loadFromFile("arial.ttf");
	font.loadFromFile("arial.ttf");
	assert(result);


	pSprite.setTexture(pTexture);
	gSprite.setTexture(gTexture);
	g2Sprite.setTexture(g2Texture);
	//groundien spriten sijoitus ja koon skaalaus
	gSprite.setPosition(0.0f * renderDimensions.x, 0.72f * renderDimensions.y);
	gSprite.setScale(1.2f, 1);

	g2Sprite.setPosition(0.9f * renderDimensions.x, 0.72f * renderDimensions.y);
	g2Sprite.setScale(1.2f, 1);

	//reSpawnboxin asettaminen, kun putoaa
	hit.setPosition(0.45f * renderDimensions.x, 1.0f * renderDimensions.y);
	hit.setScale(1600.0f, 1.0f);

	 

	//ground
	b2BodyDef groundbodyDefinition;
	groundbodyDefinition.position.Set(2.0f, 2.99f);
	_ground = _physicsWorld.CreateBody(&groundbodyDefinition);
	b2PolygonShape groundShape;
	groundShape.SetAsBox(4.0f, 0.5f);
	_ground->CreateFixture(&groundShape, 0.0f);
	// toinen ground
	groundbodyDefinition.position.Set(10.3f, 2.99f);
	_ground = _physicsWorld.CreateBody(&groundbodyDefinition);
	groundShape.SetAsBox(3.15f, 0.5f);
	_ground->CreateFixture(&groundShape, 0.3f);

	
	
	
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
	
	//putoamis check
	reSpawnCheck = hit.getPosition().y;

}


Player::~Player()
{
}




void Player::draw(sf::RenderWindow& window)
{
	float healthCheck1 = 3;
	float healthCheck2 = 2;
	float healthCheck3 = 1;
	float healthCheck4 = 0;

	if (life == 3)
	{
		lifeSprite3.setTexture(lifeTexture3);
		lifeSprite3.setPosition(pSprite.getPosition().x - 130.0f, 15.0f);
		window.draw(lifeSprite3);
	}
	else if (life == 2)
	{
		lifeSprite2.setTexture(lifeTexture2);
		lifeSprite2.setPosition(pSprite.getPosition().x - 130.0f, 15.0f);
		window.draw(lifeSprite2);
	}
	else if (life == 1)
	{
		lifeSprite1.setTexture(lifeTexture1);
		lifeSprite1.setPosition(pSprite.getPosition().x - 130.0f, 15.0f);
		window.draw(lifeSprite1);
	}
	else if(life == 0)
	{
		texti.setFont(fontti);
		texti.setString("Game over");
		texti.setCharacterSize(150);
		texti.setColor(sf::Color::Red);
		texti.setStyle(sf::Text::Bold);
		texti.setPosition(1, 200);

		window.draw(texti);

		movement = 0.0f;
		canJump = false;
		
	}
	text.setFont(font);


	text.setString("Lives:");


	text.setCharacterSize(24);


	text.setColor(sf::Color::Red);


	text.setStyle(sf::Text::Bold);


	text.setPosition(pSprite.getPosition().x - 200.0f, 15);

	window.draw(text);

	//piirt‰‰ pelaajan
	window.draw(pSprite);
	//piirt‰‰ maata
	window.draw(gSprite);
	window.draw(g2Sprite);

	//kamera seuraa pelaajaa
	sf::View view;
	sf::Vector2f screenDimension(800, 600);

	view.setViewport(sf::FloatRect(0, 0, 1.0f, 1.0f));
	sf::Vector2f position(pSprite.getPosition());

	position.x = pSprite.getPosition().x + 10 - (screenDimension.x / 2);
	position.y =(screenDimension.y /32);

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


}

// pelaajan liikkuminen
void Player::pMovement()
{
	enum Direction { Down, Left, Right, Up };
	sf::Vector2i source(1, Down);
	b2Vec2 velocity = playerBox->GetLinearVelocity();
	

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		source.y = Right;
		playerBox->SetLinearVelocity(b2Vec2(movement, velocity.y));
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		source.y = Left;
		playerBox->SetLinearVelocity(b2Vec2(-movement, velocity.y));
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && canJump == true || sf::Keyboard::isKeyPressed(sf::Keyboard::W) && canJump == true)
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

void Player::reSpawn()
{
	//jos putoaa respawn alkuun
	float playerFallPosCheck = pSprite.getPosition().y;

	if (playerFallPosCheck > reSpawnCheck)
	{

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

		pSprite.setPosition(100.0f, 180.0f);

		life--;
	}
}
