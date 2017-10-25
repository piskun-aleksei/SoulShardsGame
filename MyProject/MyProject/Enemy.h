#pragma once
#ifndef __ENEMY_H__
#define __ENEMY_H__

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Level.h"

using namespace sf;

class Enemy
{
public:
	int coordX;
	int coordY;
	int reverseFlag;
	float dx,dy;
	FloatRect borders;
	Sprite texture;
	float currentFrame;
	bool life;
	int number;
	Enemy(Texture &image)
	{
		
		texture.setTexture(image);
		life = true;
	}
	void set(int x,int y)
	{
		reverseFlag = 0;
		texture.setColor(Color::Red);
		coordX = x;
		coordY = y;
		borders = FloatRect(x,y,30,58);
		dx = 0.05;
		currentFrame = 0;
	}
	void update(float time)
	{
		borders.left += dx * time;
		Collision();
		currentFrame += time * 0.005;
		if (currentFrame > 2)
			currentFrame -= 2;
		if(reverseFlag == 0)
			texture.setTextureRect(IntRect(15+64*int(currentFrame),198,30,58));
		if(reverseFlag == 1)
			texture.setTextureRect(IntRect(15+64*int(currentFrame),70,30,58));
		if (!life)
			texture.setTextureRect(IntRect(0, 0, 2,2));
		texture.setPosition(borders.left - offsetX, borders.top - offsetY);
	}
	
	void Collision()
	{
		for (int i = borders.top/32 ; i < (borders.top+borders.height)/32; i++)
		{
			for (int j = borders.left/32; j < (borders.left+borders.width)/32; j++)
			{
				if ((TileMap[i][j]=='G') || (TileMap[i][j]=='0') || (TileMap[i][j]=='s'))
				{
					if (dx > 0)
					{
						reverseFlag = 1;
						borders.left =  j*32 - borders.width;
						dx *= -1;
					}
					else if (dx < 0)
					{
						reverseFlag = 0;
						borders.left =  j*32 + 32;
						dx *= -1;
					}
				}
			}
		}
	}

};

#endif

