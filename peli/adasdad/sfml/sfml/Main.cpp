#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/System/Time.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/VideoMode.hpp>

#include "Enemy1.h"
#include "Food1.h"
#include "Player.h"


static void loop(sf::RenderWindow& window);

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "Food hunting");
	loop(window);
	

	return 0;
	

	//food texturen lataaminen
	//sf::Texture foodTexture;
	//if (!foodTexture.loadFromFile("Food.png")){
	//	std::cerr << "Food Texture Error" << std::endl;
	//}
	//game::Food1 foodImage(foodTexture);

	//game::Food1 (game::Food1(sf::Vector2f(10, 10), sf::Vector2f(20, 20));

	//foodImage.Update();

}

static void loop(sf::RenderWindow& window)
{
	sf::Clock clock;
	sf::Time elapsedTime;
	sf::Event event;
	Enemy1 enemy1(window.getSize());
	Food1 food1(window.getSize());
	Player player(window.getSize());

	while (window.isOpen())
	{
		elapsedTime = clock.restart();
		{
			while (window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
					window.close();
			}

		}

		
		//window.setView();
		window.clear(sf::Color(0, 0, 244, 255));
		clock.restart();
		food1.draw(window);
		food1.foodCollisionCheck(elapsedTime);
		enemy1.draw(window);
		enemy1.eCollisionCheck(elapsedTime);
		enemy1.moveMent();
		player.draw(window);
		player.pUpdate(elapsedTime);
		player.pMovement();
		window.display();
	}
}


		//collision
		//https://www.youtube.com/watch?v=n0U-NBmLj78&index=32&list=PLHJE4y54mpC5j_x90UkuoMZOdmmL9-_rg
			
		//hyödyllistä
		//http://stackoverflow.com/questions/19143402/how-to-make-my-own-classes-with-c-and-sfml
		//http://www.gamefromscratch.com/page/Game-From-Scratch-CPP-Edition-Part-5.aspx
		//http://facepunch.com/showthread.php?t=798675