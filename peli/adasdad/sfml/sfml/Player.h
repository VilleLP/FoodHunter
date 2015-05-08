#ifndef PLAYER_H
#define PLAYER_H
#include <Box2D/Box2D.h>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
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
private:
	//b2Fixture* GetFixtureA();
	b2World _physicsWorld;
	b2Body* _ground;
	b2Body* playerBox;
	const sf::Vector2i _frameSize;
	const sf::Vector2i _frameCount;
	sf::Clock clock;
	sf::Texture pTexture;
	sf::Sprite	pSprite;
	sf::Vector2i _currentFrame;
	float _frameDuration;
	float _animationTime;
	float dirSwitch;
	float time1;
	float framespeed;
	float movement;
	sf::Vector2i source;
	bool canJump;
	//sf::View view;

};
#endif
