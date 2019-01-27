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

int	main() {
	int c = 0;
	srand(time(NULL));

	initscr();//creates std screen
	cbreak();//enter raw modal
	noecho();
	curs_set(0);

	init_ncurses();
	Game *game = new Game();
	Player *player = new Player();
	player->drawPlayer();
	while (1)
	{
		if ((c = getch()) != ERR)
		{
		// game->getInput(c);
			player->getInput(c, game);
		}
	}
	delete player;
	delete game;
	return (0);
}
