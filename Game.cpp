/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasmith <hasmith@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 19:49:50 by hasmith           #+#    #+#             */
/*   Updated: 2019/01/26 17:13:01 by hasmith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Game.hpp"
#include "Missile.hpp"
#include <ctime>


// Game::Game(void) :
//         x(20),
//         y(5),
//         mapx(100),
//         mapy(100)
// {
//     srand(time(0));
// }

Game::Game(int col, int row) :
        mapy(col),
        mapx(row),
        px((row-2)/2),
        py(col-1)
{
    srand(time(0));
}


Game::~Game(void){
    return;
}

void		Game::getInput(int c) {
	if (c == 27) {
		// setEndgame(0);
        exit(0);
	}
	if (c == ' ')
		missile();
	if (c == KEY_RIGHT || c == KEY_LEFT || c == '6' || c == '4'
		|| c == '1' || c == '3') {
		mvaddch(getY(), getX(), ' ');
		mvaddch(getY() + 1, getX() + 1, ' ');
		mvaddch(getY() + 1, getX() - 1, ' ');
	}
	if ((c == KEY_RIGHT || c == '6') && getX() < mapx - 1)
		moveRight();
	if ((c == KEY_LEFT || c == '4' ) && getX() > 2)
		moveLeft();
	if ((c == '3') && getX() < mapx - 1)
	{
		// missile();
		moveRight();
	}
	if ((c == '1') && getX() > 2)
	{
		// missile();
		moveLeft();
	}
	drawPlayer();
}

void	Game::drawPlayer(void) {
	attron(COLOR_PAIR(1));
	mvaddch(getY(), getX(), '^');
	mvaddch(getY() + 1, getX() + 1, '^');
	mvaddch(getY() + 1, getX() - 1, '^');
	attroff(COLOR_PAIR(1));
	// drawEnemy();
	box(stdscr, 0, 0);
	refresh();
}

int Game::getX(void) {
    return px;
}

int Game::getY(void) {
    return py;
}

void Game::moveRight(){
    px++;
}
void Game::moveLeft(void){
    px--;
}
void Game::missile(void){
    Missile *newMissile = new Missile(getX(), getY());
    missiles.push_back(newMissile);
    if (bx == -1)
        bx = px;
    if (bx)
    by++;
}