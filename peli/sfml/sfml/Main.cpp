#include "Enemy1.h"
#include "Food1.h"



int main()
{
	using std::cout;
	using std::endl;
	using std::cerr;

	sf::Clock clock;
	enum Direction { Down, Left, Up, Right };
	sf::Vector2i source(1, Down);


	sf::RenderWindow Window(sf::VideoMode(800, 600), "Food hunting");
	sf::Event event;
	Window.setKeyRepeatEnabled(false);
	/*
	//enemy texturen lataaminen
	sf::Texture enemyTexture;
	if (!enemyTexture.loadFromFile("Enemybox.png")) {
		std::cerr << "Texture Error" << std::endl;
	}
	game::Enemy1 enemyImage(enemyTexture);

	*/

	//food texturen lataaminen
	sf::Texture foodTexture;
	if (!foodTexture.loadFromFile("Food.png")){
		std::cerr << "Food Texture Error" << std::endl;
	}
	game::Food1 foodImage(foodTexture);

	//game::Food1 (game::Food1(sf::Vector2f(10, 10), sf::Vector2f(20, 20));

	while (Window.isOpen())
	{
		while (Window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				Window.close();
				break;
			}

		}

		foodImage.Update();

		/*if (foodImage.fCollisioncheck())
		{
			std::cout << "Collision!" << std::endl;
		}
		*/
		//Kellon resettaus
		clock.restart();
		//Window.draw(enemyImage);
		Window.draw(foodImage);
		Window.display();
		Window.clear();

	}
};


		//collision
		//https://www.youtube.com/watch?v=n0U-NBmLj78&index=32&list=PLHJE4y54mpC5j_x90UkuoMZOdmmL9-_rg
			
		//hyödyllistä
		//http://stackoverflow.com/questions/19143402/how-to-make-my-own-classes-with-c-and-sfml
		//http://www.gamefromscratch.com/page/Game-From-Scratch-CPP-Edition-Part-5.aspx
		//http://facepunch.com/showthread.php?t=798675