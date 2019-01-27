/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasmith <hasmith@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 19:54:34 by hasmith           #+#    #+#             */
/*   Updated: 2019/01/26 18:38:31 by hasmith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "Enemy.hpp"
// #include "Missile.hpp"
// #include "GameEntity.hpp"

#include "Game.hpp"

using namespace std;

Game *init_ncurses() {
    int col = 0;
    int row = 0;
    getmaxyx(stdscr, col, row);

    Game *game = new Game(col - 2, row - 2);

    keypad(stdscr, TRUE);// Keys on numberpad
    nodelay(stdscr, TRUE);//

    int c;
	start_color();
	init_pair(1, COLOR_CYAN, COLOR_BLACK);
	init_pair(2, COLOR_RED, COLOR_BLACK);
	init_pair(3, COLOR_YELLOW, COLOR_BLACK);
	init_pair(4, COLOR_GREEN, COLOR_BLACK);
	init_pair(5, COLOR_MAGENTA, COLOR_BLACK);
	init_pair(6, COLOR_BLUE, COLOR_BLACK);
    refresh();

	// Draw box/start screen
	attron(COLOR_PAIR(4));
	mvaddch(0, 0, c);
	attroff(COLOR_PAIR(4));
	// drawEnemy();
	box(stdscr, 0, 0);
	game->drawPlayer();
	refresh();

	return (game);
}

int	main() {
	int c;
	srand(time(NULL));

	initscr();//creates std screen
	cbreak();//enter raw modal
	noecho();
	curs_set(0);

	Game *game = init_ncurses();

	while (1) {
        if ((c = getch()) != ERR)
            game->getInput(c);

		// if (end)
		// {
		// 	clear();
		// 	return (0);
		// };
	}
	
	return (0);
}