/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasmith <hasmith@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 19:49:50 by hasmith           #+#    #+#             */
/*   Updated: 2019/01/26 16:22:16 by hasmith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Game.hpp"

Game::Game(void) :
mapx(100),
mapy(100)
{
    srand(time(0));
}

Game::Game(int col, int row) :
mapx(row),
mapy(col)
{
    srand(time(0));
}

Game::~Game(void)
{
    return;
}

Game::Game(Game const & src)
{
	(*this) = src;
}
Game		&Game::operator=(Game const & rhs)
{
	if (this == &rhs)
		return (*this);
	this->mapx = rhs.getMapX();
	this->mapy = rhs.getMapY();
	return (*this);
}
int Game::getMapX(void) const
{
	return (this->mapx);
}
int Game::getMapY(void) const
{
	return (this->mapy);
}
//non-member function
void  init_ncurses() {
	int col = 0;
	int row = 0;
	int c = 0;

	getmaxyx(stdscr, col, row);
	keypad(stdscr, TRUE);// Keys on numberpad
	nodelay(stdscr, TRUE);//

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
	// game->drawPlayer();
	refresh();

	// return (game);
}
// Game &Game::operator=(Game const &r){
//     if (this != &r){
//         x = r.x;
//         y = r.y;
//         mapx = r.mapx;
//         // hitPoints = r.hitPoints;
//         // maxHitPoints = r.maxHitPoints;
//     }
//     return (*this);
// }

// void		Game::getInput(int c) {
// 	if (c == 27) {
// 		// setEndgame(0);
//         exit(0);
// 	}
// 	// if (c == ' ')
// 	// 	playerBullet();
// 	if (c == KEY_RIGHT || c == KEY_LEFT || c == '6' || c == '4'
// 		|| c == '1' || c == '3') {
// 		mvaddch(getY(), getX(), ' ');
// 		mvaddch(getY() + 1, getX() + 1, ' ');
// 		mvaddch(getY() + 1, getX() - 1, ' ');
// 	}
// 	if ((c == KEY_RIGHT || c == '6') && getX() < mapx - 1)
// 		moveRight();
// 	if ((c == KEY_LEFT || c == '4' ) && getX() > 2)
// 		moveLeft();
// 	if ((c == '3') && getX() < mapx - 1)
// 	{
// 		// playerBullet();
// 		moveRight();
// 	}
// 	if ((c == '1') && getX() > 2)
// 	{
// 		// playerBullet();
// 		moveLeft();
// 	}
// 	drawPlayer();
// }
//
// void	Game::drawPlayer(void) {
// 	attron(COLOR_PAIR(1));
// 	mvaddch(getY(), getX(), '^');
// 	mvaddch(getY() + 1, getX() + 1, '^');
// 	mvaddch(getY() + 1, getX() - 1, '^');
// 	attroff(COLOR_PAIR(1));
// 	// drawEnemy();
// 	box(stdscr, 0, 0);
// 	refresh();
// }

// int Game::getX(void) {
//     return x;
// }
//
// int Game::getY(void) {
//     return y;
// }
// void Game::moveRight(){
//     x++;
// }
// void Game::moveLeft(){
//     x--;
// }
