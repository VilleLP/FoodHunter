#ifndef FOOD1_H
#define FOOD1_H
#include <Box2D/Box2D.h>
#include <SFML/Graphics.hpp>
#include <SFML/System/Time.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/System/Vector2.hpp>
#include <string>
#include <iostream>


	class Food1 
	{
	public:
		Food1(const sf::Vector2u& renderDimensions);
		~Food1();
		void draw(sf::RenderWindow& window);
		void foodCollisionCheck(const sf::Time& elapsedTime);
		void startContact();
		void endContact();
		void handleContact(Food1* f1, Food1* f2);

	private:
		b2Fixture* GetFixtureB();
		b2World _physicsWorld;
		b2Body* _ground;
		b2Body* foodBox;
		const sf::Vector2i _frameSize;
		const sf::Vector2i _frameCount;
		sf::Texture fTexture;
		sf::Sprite	fSprite, f2Sprite;
		sf::Vector2i _currentFrame;
		float _frameDuration;
		float _animationTime;
		int f_contacting;
		bool invisibleF1;
		bool m_imIt;
	};
#endif



