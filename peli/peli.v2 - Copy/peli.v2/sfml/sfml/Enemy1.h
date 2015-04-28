#ifndef ENEMY1_H
#define ENEMY1_H
#include <Box2D/Box2D.h>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/System/Vector2.hpp>
#include <string>
#include <iostream>


	class Enemy1
	{
	public:
		Enemy1(const sf::Vector2u& renderDimensions);
		~Enemy1();
		void draw(sf::RenderWindow& window);
		void moveMent();
		void eCollisionCheck(const sf::Time& elapsedTime);




	private:
		b2World _physicsWorld;
		b2Body* _ground;
		b2Body* enemyBox;
		const sf::Vector2i _frameSize;
		const sf::Vector2i _frameCount;
		sf::Clock clock;
		sf::Texture eTexture;
		sf::Sprite	eSprite;
		sf::Vector2i _currentFrame;
		float _frameDuration;
		float _animationTime;
		float dirSwitch;
		float time1;
		float framespeed;
		float movement;
	};



#endif


	