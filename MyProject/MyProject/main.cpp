#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Player.h"
#include "Enemy.h"
#include "Menu.h"
#include <windows.h>

using namespace sf;

int main()
{
	ShowWindow(GetConsoleWindow(),SW_HIDE);
	RenderWindow window(VideoMode(1024, 500), "Soul Shards Game");

	Texture tileSet;
	tileSet.loadFromFile("tile.png");

	Texture playerTexture;
	playerTexture.loadFromFile("skeleton.png");
	Player player(playerTexture,&window);
	int color = 0;
	std::vector<Enemy> enemy;

	for(int i = 0; i < 13; i++)
	{
		enemy.push_back(playerTexture);
	}

	enemy[0].set(150,262);
	enemy[1].set(570,805);
	enemy[2].set(1900,549);
	enemy[3].set(1700,294);
	enemy[4].set(2200,294);
	enemy[5].set(3100,454);
	enemy[6].set(4200,454);
	enemy[7].set(3100,549);
	enemy[8].set(3700,549);
	enemy[9].set(2800,678);
	enemy[10].set(1700,805);
	enemy[11].set(2500,805);
	enemy[12].set(950,165);

	int enemiesAmount = 0;

	for(std::vector<Enemy>::iterator it = enemy.begin(); it < enemy.end(); it++)
	{
		enemiesAmount++;
	}

	Level level;
	Sprite tile(tileSet);
	SoundBuffer buffer;
	buffer.loadFromFile("Jump.ogg");
	Sound sound(buffer);
    Music music;
    music.openFromFile("main_theme.ogg");
	music.setLoop(true);
	music.setVolume(20);
    music.play();
	Menu menu(&window);

	Clock clock;

    while (window.isOpen())
    { 
		
		float time = clock.getElapsedTime().asMicroseconds();
		clock.restart();

		time = time/500;  // здесь регулируем скорость игры

		if (time > 20) time = 20; 

        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)      
                window.close();
		}
		if(menu.getSprite() == 0)
		{
			menu.draw();
			menu.starting();
		}
		if(menu.restart)
		{	
			for(int i = 0; i < enemiesAmount ; i++)
			{
				enemy[i].set(enemy[i].coordX,enemy[i].coordY);
				enemy[i].life = true;
			}
			player.borders = FloatRect(430,100,30,58);
			player.won = false;
			player.setScore(0);
			player.life = true;
			menu.restart = false;
			menu.isDead = false;
		}
		if(!menu.isDead)
		{
			if(player.won)
			{
				menu.setSprite(2);
				player.life = false;
			}
			else
			{
				menu.setSprite(1);
			}
			if(!menu.update(player.life))
			{
				if (Keyboard::isKeyPressed(Keyboard::Left))
				{
					player.dx = -0.15; 
				}

				if (Keyboard::isKeyPressed(Keyboard::Right))
				{
					player.dx = 0.15;
				}

			    if (Keyboard::isKeyPressed(Keyboard::Up))
				{
					if (player.onGround)
					{
						player.dy =- 0.4;
						player.onGround = false;
						sound.play();	
					}
				}

				player.update(time);

				for(int i = 0; i < enemiesAmount; i++)
				{
				 enemy[i].update(time);
				}
				for(int i = 0; i < enemiesAmount; i++)
				{
					if(player.borders.intersects( enemy[i].borders ) )
					{
						if (enemy[i].life)
						{
							if (player.dy > 0)
							{
								enemy[i].dx = 0;
								player.dy = -0.2;
								enemy[i].life = false;
								player.scoreUp();
							}
							else
							{
								player.life = false;
							}
						}
					}
				}

				if(player.borders.left > 400 && player.borders.left < 4175)
				{
					offsetX = player.borders.left-400;  
				}

				if(player.borders.top > 200 && player.borders.top < 628)
				{
					offsetY = player.borders.top-200; 
				}
				
				window.clear(Color(107,140,255));
				level.update(tile,&window,player.getScore());
				window.draw(player.texture);

				for(int i = 0; i < enemiesAmount; i++)
				{
					window.draw(enemy[i].texture);
				}
			}
			player.drawScore();
		}
		else
		{
			if(!menu.update(player.life))
			{
				player.life = true;
			}
			menu.draw();
		}
		if(menu.endGame == true )
		{
			return 0;
		}
		
		window.display();
	}
    return 0;
}



