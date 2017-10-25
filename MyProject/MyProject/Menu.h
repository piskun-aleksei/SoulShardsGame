#ifndef __MENU_H__
#define __MENU_H__

#include <SFML/Graphics.hpp>

class Menu
{
private:
	sf::RenderWindow * window;
	int sprite;
	sf::Texture startGameTexture;
	sf::Sprite startGameSprite;
	sf::Texture endGameTexture;
	sf::Sprite endGameSprite;
	sf::Texture winTexture;
	sf::Sprite winSprite;
	bool start;
	
public:
	bool restart;
	bool isDead;
	bool endGame;
	void setSprite(int number);
	int getSprite();
	Menu(sf::RenderWindow * newWindow);
	~Menu();
	bool update(bool life);
	void starting();
	void draw();
};

#endif
