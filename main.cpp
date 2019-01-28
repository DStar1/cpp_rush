/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasmith <hasmith@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 19:54:34 by hasmith           #+#    #+#             */
/*   Updated: 2019/01/26 16:18:19 by hasmith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Game.hpp"
#include "Player.hpp"
#include "Enemy.hpp"
#include <curses.h>
int	main(void)
{
	int c = 0;
	int startX; // initial x value for the enemies
	int x;
	int y;
	int number; // number of enemies to spawn

	startX = x = 10;
	y = 2;
	number = 30;
	srand(time(NULL));

	initscr();//creates std screen
	cbreak();//enter raw modal
	noecho();
	curs_set(0);

	Game *game = new Game(); // creates an instance of game
	mvprintw(game->getMapY()/4 - 9, game->getMapX()/2,  "      `/hdho` +dho+dddy \n");
	mvprintw(game->getMapY()/4 - 8, game->getMapX()/2,  "    `+dMNh:   oh: +MMMd \n");
	mvprintw(game->getMapY()/4 - 7, game->getMapX()/2,  "  .+mMNy-     ` `:dMMd/ \n");
	mvprintw(game->getMapY()/4 - 6, game->getMapX()/2,  ".omMNy-`      `/dMMh/`  \n");
	mvprintw(game->getMapY()/4 - 5, game->getMapX()/2,  "dMMMNdddddddo oMMMh` -o \n");
	mvprintw(game->getMapY()/4 - 4, game->getMapX()/2,  "hdddddddNMMMy sMMMy:hNd \n");
	mvprintw(game->getMapY()/4 - 3, game->getMapX()/2,  "````````sMMMy .---..--. \n");
	mvprintw(game->getMapY()/4 - 2, game->getMapX()/2,  "        +dddo           \n");
	mvprintw(game->getMapY()/4 - 1, game->getMapX()/2,  "                        \n");

	mvprintw(game->getMapY()/4 + 1, game->getMapX()/2,  "       `-/+++++/-`       \n");
	mvprintw(game->getMapY()/4 + 2, game->getMapX()/2,  "     -oysyyyyyyyyy+-     \n");
	mvprintw(game->getMapY()/4 + 3, game->getMapX()/2,  "   `+yyy.`-+syyyyyyy+`   \n");
	mvprintw(game->getMapY()/4 + 4, game->getMapX()/2,  "   oyyyy.   `./oyyyyyo   \n");
	mvprintw(game->getMapY()/4 + 5, game->getMapX()/2,  "  .yyyyy.       .:oyyy.  \n");
	mvprintw(game->getMapY()/4 + 6, game->getMapX()/2,  "  .yyyyy.      `.:+yyy.  \n");
	mvprintw(game->getMapY()/4 + 7, game->getMapX()/2,  "   oyyyy.  `.:+syyyyyo   \n");
	mvprintw(game->getMapY()/4 + 8, game->getMapX()/2,  "   `+yyy::osyyyyyyyy+`   \n");
	mvprintw(game->getMapY()/4 + 9, game->getMapX()/2,  "     -+yyyyyyyyyyy+-     \n");
	mvprintw(game->getMapY()/4 + 10, game->getMapX()/2,  "       `-/+++++:-`       \n");


	getch();
	clear();
	game->init_ncurses();
	Player *player = new Player();  // creates the movable player
	Enemy *enemies = new Enemy[number]; // number of enemies on the stack.

	for (int i = 0; i < number; i++)
	{

		enemies[i].setX(x += 5); //spawns enemies at varying x + 5 offsets
		if (i % 10 == 0)
		{
			enemies[i].setY(y += 5); // will increase the height.
			enemies[i].setX(x = startX); // returns to the original startX val
		}
		enemies[i].setY(y);
		enemies[i].setN(1);

	}
	std::string s = std::to_string(enemies[number-1].getX()) + " " + std::to_string(enemies[number-1].getY());
	mvwprintw(stdscr, 3, 2, s.c_str());
	player->setGame(game);
	player->drawPlayer();
	int i = 0;
	int kills = 0;
	int flag = 1;
	while (flag == 1)
	{
		if ((c = getch()) != ERR)
		{
			player->getInput(c, game);
		}

		while (i < number)
		{

			if (player->missilesCollisions(enemies[i].getX(), enemies[i].getY()))
			{
				enemies[i].killEnemy();
				kills++;
			} //checks collisions and should render enemy and missile invisible if true
			enemies[i++].drawEnemy(); //loop that crreates all the enemies
		}
		player->drawMissiles();
		player->drawPlayer();
		if (win(enemies, game, number))
			flag = 0;
		if (kills == 10)
			flag = 2;
		i = 0;
	}
	if (flag == 0)
	{
		printw("You lose\nPress any key to exit.\n");
		getch();
	}
	else if (flag == 2)
	{
		printw("You win.\nPress any key to exit.\n");
		getch();
	}
	endwin();
	delete player; //delete player on the heap
	delete game; // delete the game on the heap
	return (0);
}
