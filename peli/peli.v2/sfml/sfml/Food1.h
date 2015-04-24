#ifndef FOOD1_H
#define FOOD1_H
#include <SFML/Graphics.hpp>
#include <SFML/Window/Event.hpp>
#include <string>
#include <iostream>


	class Food1 
	{
	public:
		Food1(const sf::Vector2u& renderDimensions);
		~Food1();
		void draw(sf::RenderWindow& window);


		//sf::RectangleShape fRect;
		//float left, right, top, bottom;

		/*
		Food1(sf::Vector2f fPosition, sf::Vector2f fSize, sf::Color color)
		{
			fRect.setPosition(fPosition);
			fRect.setSize(fSize);
		}
		*/
		/*
		void Update()
		{
			left = fRect.getPosition().x;
			right = fRect.getPosition().x + fRect.getSize().x;
			top = fRect.getPosition().y;
		}
		*/
		//törmäys
		/*
		bool fCollisioncheck(sf::Texture& foodTexture)
		{
			if (left < foodTexture.right || right > foodTexture.left 
				|| bottom < foodTexture.top)
			{
				return false;
			}
			return true;
		}
		*/
	private:
		const sf::Vector2i _frameSize;
		const sf::Vector2i _frameCount;

		sf::Texture fTexture;
		sf::Sprite	fSprite;
		sf::Vector2i _currentFrame;
		float _frameDuration;
		float _animationTime;

	};
#endif
