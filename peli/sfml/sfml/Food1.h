#ifndef FOOD1_H
#define FOOD1_H
#include <SFML/Graphics.hpp>
#include <SFML/Window/Event.hpp>
#include <string>
#include <iostream>

namespace sf {
	class Texture;
}


namespace game{
	class Food1 :public sf::Drawable
	{
	public:
		Food1(const sf::Texture& foodTexture);
		virtual ~Food1();
		virtual void draw(sf::RenderTarget& targetF, sf::RenderStates statesF) const;
		sf::RectangleShape fRect;
		float left, right, top, bottom;

		Food1(sf::Vector2f fPosition, sf::Vector2f fSize, sf::Color color)
		{
			fRect.setPosition(fPosition);
			fRect.setSize(fSize);
		}

		void Update()
		{
			left = fRect.getPosition().x;
			right = fRect.getPosition().x + fRect.getSize().x;
			top = fRect.getPosition().y;
		}
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
		sf::Sprite fSprite;

	};
}
#endif
