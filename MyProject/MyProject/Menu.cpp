#include "Menu.h"

using namespace sf;

Menu::Menu(RenderWindow* newWindow)
{
	restart = false;
	isDead = true;
	window = newWindow;
	startGameTexture.loadFromFile("startGame.png");
	startGameSprite.setTexture(startGameTexture);
	endGameTexture.loadFromFile("endGame.png");
	endGameSprite.setTexture(endGameTexture);
	winTexture.loadFromFile("win.png");
	winSprite.setTexture(winTexture);
	startGameSprite.setOrigin(0,0);
	startGameSprite.setPosition(0,0);
	endGameSprite.setOrigin(0,0);
	endGameSprite.setPosition(0,0);
	winSprite.setOrigin(0,0);
	winSprite.setPosition(0,0);
	sprite = 0;
	endGame = false;
}

Menu::~Menu()
{
}
bool Menu::update(bool life)
{
	
	if(life == false)
	{
		if (Keyboard::isKeyPressed(Keyboard::Space))
		{
			restart = true;
			isDead = false;
			return false;
		}
		if (Keyboard::isKeyPressed(Keyboard::Escape))
		{
			endGame = true;
		}
		isDead = true;
		return true;
	}
	return false;
}

void Menu::draw()
{
	if(sprite == 0)
	{
		window->draw(startGameSprite);
	}
	if(sprite == 1)
	{
		window->draw(endGameSprite);
	}
	if(sprite == 2)
	{
		window->draw(winSprite);
	}
}

void Menu::setSprite(int number)
{
	sprite = number;
}

void Menu::starting()
{
	if (Keyboard::isKeyPressed(Keyboard::Space))
	{
		isDead = false;
	}
	if (Keyboard::isKeyPressed(Keyboard::Escape))
	{
		isDead = true;
		endGame = true;
	}
}

int Menu::getSprite()
{
	return sprite;
}
