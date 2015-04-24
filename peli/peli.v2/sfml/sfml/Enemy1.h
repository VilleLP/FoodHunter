#ifndef ENEMY1_H
#define ENEMY1_H
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
		Enemy1();
		Enemy1(const sf::Vector2u& renderDimensions);
		~Enemy1();
		void draw(sf::RenderWindow& window);

		void moveMent();

		//RectangleShape rect;
		//Enemy1(Vector2f position, Vector2f size, Color color){}

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
		//Liikkumisnopeus
		float movement;
	};
//}


#endif
