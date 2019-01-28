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

// #include "Enemy.hpp"
// #include "Missile.hpp"
// #include "GameEntity.hpp"

#include "Game.hpp"
#include "Player.hpp"
#include "Enemy.hpp"
int	main() {
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

	init_ncurses();
	Game *game = new Game(); // creates an instance of game
	Player *player = new Player();  // creates the movable player
	Missile *missile = new Missile();
	Enemy enemies[30]; // number of enemies on the stack.
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
	player->drawPlayer();
	int i = 0;
	while (1)
	{
		// missile->drawMissile(game);
		if ((c = getch()) != ERR)
		{
			player->getInput(c, game, missile);
		}
		while (i < number)
		{
			enemies[i++].drawEnemy(game); //loop that crreates all the enemies
			missile->drawMissile(game);
		}
		i = 0;
	}
	endwin();
	delete player; //delete player on the heap
	delete game; // delete the game on the heap
	return (0);
}
