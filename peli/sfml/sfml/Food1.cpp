#include "Food1.h"


//enemy position
namespace game{
	Food1::Food1(const sf::Texture& foodImage) :
		fSprite(foodImage)
	{
		fSprite.setPosition(300, 400);
		fSprite.setScale(1.5f, 1.5f);
	}

	Food1::~Food1() {}

	void Food1::draw(sf::RenderTarget& targetF, sf::RenderStates statesF) const{
		targetF.draw(fSprite, statesF);
	}
		void fCollisioncheck()
		{

		}

}




