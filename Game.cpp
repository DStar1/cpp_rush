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
#include <ctime>

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

int Game::getMapX(void) const
{
	return (this->mapx);
}
int Game::getMapY(void) const
{
	return (this->mapy);
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
