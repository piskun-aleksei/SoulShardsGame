#pragma once
#ifndef __PLAYER_H__
#define __PLAYER_H__

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <sstream>
#include "Level.h"

using namespace sf;


class Player
{
private:
	int score;
public:
	float dx,dy;
	FloatRect borders;
	bool onGround;
	Sprite texture;
	float currentFrame;
	bool life;
	bool won;
	Font font;
	Text outputScore;
	RenderWindow * window;

    Player(Texture &image,RenderWindow * newWindow)
	{
		score = 0;
		window = newWindow;
		texture.setTexture(image);
		borders = FloatRect(430,100,30,58);
		dx = dy = 0.1;
		currentFrame = 0;
		life = true;
		won = false;
		font.loadFromFile("sansation.ttf");
		outputScore.setFont(font);
		std::ostringstream scoreString;
		scoreString << score;
		outputScore.setString(scoreString.str());
		outputScore.setCharacterSize(68);
		outputScore.setPosition(730,25);
		outputScore.setColor(sf::Color(210,10,50,255));
	}

	void update(float time)
	{	
		
		borders.left += dx * time;	

		Collision(0);

		if ( !onGround )
		{
			dy = dy+0.0005*time;
		}

		borders.top += dy*time;

		onGround = false;

		Collision(1);

		currentFrame += time*0.005;

		if (currentFrame > 8)
		{
			currentFrame -= 8;
		}
		if (dx > 0)
		{
			texture.setTextureRect(IntRect(15+64*int(currentFrame),198,30,58));
		}
		if (dx < 0)
		{
			texture.setTextureRect(IntRect(15+64*int(currentFrame),70,30,58));
		}
		if((borders.top > 0 && borders.top < 128) && (borders.left > 4550 && borders.left < 4800))
		{
			won = true;
		}
		texture.setPosition(borders.left - offsetX, borders.top - offsetY);
	  
		dx = 0;
		std::ostringstream scoreString;
		scoreString << score;
		outputScore.setString("Killed: " + scoreString.str());
	
	}

	void Collision(int num)
	{
	
		for (int i = borders.top/32 ; i < (borders.top+borders.height)/32; i++)
		{
			for (int j = borders.left/32; j < (borders.left+borders.width)/32; j++)
			{
				if ((TileMap[i][j]=='G') || (TileMap[i][j]=='0') || ((TileMap[i][j]=='D') && score <13))
				{ 
					if (dy > 0 && num == 1)
					{
						borders.top =   i*32 -  borders.height;
						dy=0;
						onGround=true;
					}
					if (dy < 0 && num == 1)
					{
						borders.top = i*32 + 32;
						dy=0;
					}
					if (dx > 0 && num == 0)
					{
						borders.left =  j*32 -  borders.width;
					}
					if (dx < 0 && num == 0)
					{
						borders.left =  j*32 +32;
					}
				}

			}
		}
	}

	void scoreUp()
	{
		score ++;
	}

	int getScore()
	{
		return score;
	}

	void setScore(int number)
	{
		score = number;
	}

	void drawScore()
	{
		window->draw(outputScore);
	}
};

#endif