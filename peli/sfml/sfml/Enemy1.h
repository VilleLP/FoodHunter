#ifndef ENEMY1_H
#define ENEMY1_H
#include <SFML/Graphics.hpp>
#include <SFML/Window/Event.hpp>
#include <string>
#include <iostream>


namespace sf{
	class Texture;
}


namespace game{
	class Enemy1 : public sf::Drawable 
	{
	public:
		Enemy1();
		Enemy1(const sf::Texture& enemyTexture);
		virtual ~Enemy1();
		virtual void draw(sf::RenderTarget& targetE, sf::RenderStates statesE) const;

		//RectangleShape rect;
		//Enemy1(Vector2f position, Vector2f size, Color color){}

		void moveMent();


		void eCollisionCheck();


		// Enemy törmäys
		/*Enemy1(Vector2f position, Vector2f size, Color color)
		{
		rect.setPosition(position);
		rect.setSize(size);
		rect.setFillColor(color);
		}
		*/
		/*void upDate()
		{
		bottom = rect.getPosition().y + rect.getSize().y;
		left = rect.getPosition().x;
		right = rect.getPosition().x + rect.getSize().x;
		up = rect.getPosition().y;
		}
		*/

		/*bool Collosion(Enemy1 e)
		{
		if (right < e.left || left > e.right ||
		up > e.bottom || bottom < e.up)
		{
		return false;
		}
		return true;
		}
		*/



	private:
		//enemy sprite
		sf::Sprite eSprite;
	};
}


#endif
