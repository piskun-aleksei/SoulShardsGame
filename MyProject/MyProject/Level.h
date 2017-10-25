#pragma once
#ifndef __LEVEL_H__
#define __LEVEL_H__
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

using namespace sf;

const int H = 29;
const int W = 150;

float offsetX=0, offsetY=0;

String TileMap[H] = {
"000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000",
"0                       0                                                                                                               D            0",
"0                       0                                                                                                               D     WWW    0",
"0                       0                                                                                                               D            0",
"000000000000            0      0000000000000000000000000000000000000000000000000000000000000000000000       000000000000000000000000000000000000000000",
"0                       0                0                                                                                                           0",
"0                       0        s       0                                                                                                           0",
"0              000000000000000000        0                                                                                                           0",
"0                       0                0                                        00000000000000000000000000000000000000000000000000000000000000000000",
"0           s           0                0                                                                                                           0",
"000000000000            0                0          s            ss            s                                                                     0",
"0                       000000000        0           00000000000000000000000000                                                                      0",
"0                       0                0                                                                                                           0",
"0              0000000000                0                                                                                                           0",
"0                       0                0                                                                                                           0",
"0                       0           0000000000000                                        s                             s  s                          0",
"0                       0                                                                 00000000000000000000000000000    000000000000000000000000000",
"000000000000            0                                                                                                                            0",
"0                       0                       s                s                        s                                                          0",
"0                       0           000000000000000000000000000000000000000000000000       00000000000000000000000000000000000000000000000000000000000",
"0                       0                0                                                                  000000000000000000000000000000000000000000",
"0              0000000000                0                                                                  000000000000000000000000000000000000000000",
"0                       0                0                                         s                        000000000000000000000000000000000000000000",
"000000000000            000000000        0                                          000000000000000000000000000000000000000000000000000000000000000000",
"0                                        0                                                  0000000000000000000000000000000000000000000000000000000000",
"0                                        0                                                  0000000000000000000000000000000000000000000000000000000000",
"0                                        0                     ss                           0000000000000000000000000000000000000000000000000000000000",
"GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG",
"GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG",
}; 

class Level
{
public:
	Level(){};
	void update(Sprite & tile, RenderWindow * window,int score)
	{
		for(int i = 0; i < H; i++)
				{
					for(int j = 0; j < W; j++)
					{
						if (TileMap[i][j] == 'G')
						{
							tile.setTextureRect( IntRect(32,192,32,32) );
						}
						if (TileMap[i][j] == 'k')
						{
							tile.setTextureRect( IntRect(32,192,32,32) );
						}
						if (TileMap[i][j] == ' ')
						{
							tile.setTextureRect( IntRect(0,192,32,32) );
						}
						if (TileMap[i][j] == 's')
						{
							tile.setTextureRect( IntRect(0,192,32,32) );
						}
						if(TileMap[i][j] == '0')
						{
							tile.setTextureRect( IntRect(32,192,32,32) );
						}
						if(TileMap[i][j] == 'D')
						{
							if(score < 13)
							{
								tile.setTextureRect( IntRect(62,128,32,32) );
							}
							else
							{
								tile.setTextureRect( IntRect(0,192,32,32) );
							}
						}	
						if(TileMap[i][j] == 'W')
						{
							tile.setTextureRect( IntRect(64,0,32,32) );
						}
  						tile.setPosition(j*32-offsetX,i*32 - offsetY) ; 

					    window->draw(tile);
					}
				}
	}

};

#endif