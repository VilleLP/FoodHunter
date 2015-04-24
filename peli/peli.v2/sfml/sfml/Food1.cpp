#include "Food1.h"
#include <cassert>

	
Food1::Food1(const sf::Vector2u& renderDimensions)
	: _frameSize(40, 40),
	_frameCount(1, 1),
	_currentFrame(0, 0),
	_frameDuration(1.0f / 5.0f),
	_animationTime(0.0f)
	{
	const bool result = fTexture.loadFromFile("Food.png");
	assert(result);
	fSprite.setOrigin(0.5f * _frameSize.x, 0.5f * _frameSize.y);
	fSprite.setPosition(0.5f * renderDimensions.x, 0.7f * renderDimensions.y);
	fSprite.setTexture(fTexture);
	}

	Food1::~Food1() {}

	void Food1::draw(sf::RenderWindow& window)
	{
	
		window.draw(fSprite);
	}

	void fCollisioncheck()
	{

	}






