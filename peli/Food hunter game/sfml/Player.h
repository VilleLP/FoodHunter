#ifndef PLAYER_H
#define PLAYER_H
#include <Box2D/Box2D.h>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include "SFML\Graphics\Text.hpp"
#include "SFML\Graphics\\Font.hpp"
#include <SFML/Window/Event.hpp>
#include <SFML/System/Vector2.hpp>
#include <string>
#include <iostream>

class Player
{
public:
	Player(const sf::Vector2u& renderDimensions);
	~Player();
	void draw(sf::RenderWindow& window);
	void pUpdate(const sf::Time& elapsedTime);
	void pMovement();
	const b2Vec2 playerPos(b2Vec2){ return playerBox->GetPosition(); };
	void reSpawn();
	void hitPoints(sf::RenderWindow window);


private:
	
	b2World _physicsWorld;
	b2Body* _ground;
	b2Body* playerBox;
	b2Color setColor;
	const sf::Vector2i _frameSize;
	const sf::Vector2i _frameCount;
	sf::Clock clock;
	sf::Texture pTexture;
	sf::Sprite	pSprite;

	sf::Texture gTexture;
	sf::Sprite gSprite;

	sf::Texture g2Texture;
	sf::Sprite g2Sprite;

	sf::Sprite hit;

	sf::Texture lifeTexture3;
	sf::Sprite lifeSprite3;

	sf::Texture lifeTexture2;
	sf::Sprite lifeSprite2;

	sf::Texture lifeTexture1;
	sf::Sprite lifeSprite1;

	sf::Texture lifeTextured;
	sf::Sprite lifeSprited;

	sf::Vector2i _currentFrame;
	float _frameDuration;
	float _animationTime;
	float dirSwitch;
	float time1;
	float framespeed;
	float movement;
	sf::Vector2i source;
	float reSpawnCheck;
	bool canJump;
	sf::Text texti;
	sf::Font fontti;
	sf::Text text;
	sf::Font font;
	int life;
	
};


#endif
