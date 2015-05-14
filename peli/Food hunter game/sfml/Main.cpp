#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/System/Time.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/VideoMode.hpp>
#include "sstream"

#include "Enemy1.h"
#include "Food1.h"
#include "Player.h"


static void loop(sf::RenderWindow& window);

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "Food hunter");
	loop(window);
	

	return 0;
	


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
		player.reSpawn();
		window.display();

	}
}


