/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasmith <hasmith@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 19:49:50 by hasmith           #+#    #+#             */
/*   Updated: 2019/01/26 19:35:45 by hasmith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Game.hpp"
#include "Missile.hpp"
#include <ctime>
#include <iostream>

Game::Game(int col, int row)
{
    srand(time(0));
	mapy = col;
	mapx = row;
	px = ((row-2)/2);
	py = (col-1);
	numMissiles = 14;
	numMissilesShot = 0;
	missiles = new Missile[numMissiles];
}


Game::~Game(void){
	delete [] missiles;
    return;
}

void		Game::getInput(int c) {
	if (c == 27) {
		// setEndgame(0);
        exit(0);
	}
	if (c == ' ')
		shootMissile();
	if (c == KEY_RIGHT || c == KEY_LEFT || c == '6' || c == '4' || c == '1' || c == '3') {
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
		// shootMissile();
		moveRight();
	}
	if ((c == '1') && getX() > 2)
	{
		// shootMissile();
		moveLeft();
	}
	// std::cout << "Player" << std::endl;
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

void	Game::drawMissiles(void) {
	for (int i = 0; i < numMissiles; i++) {
		if (missiles[i].getAlive()){
			//clear
			missiles[i].clear();
			//moveUp
			missiles[i].moveUp();
			//draw
			missiles[i].drawMissile();
			//if y == 1 setAlive(0) clearMissile()
			if (missiles[i].getMY() == 1) {
				missiles[i].setInfo(0,0,0);
				missiles[i].clear();
			}
			//if hit == true do something
			
		}
	}
}

//Maybe not needed
void	Game::clearMissiles(void) {
	for (int i = 0; i < numMissiles; i++) {
		if (missiles[i].getAlive())
			missiles[i].clear();
	}
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
void Game::shootMissile(void){
    // Missile newshootMissile = Missile(getX(), getY());
	// // numshootMissiles++; //checking <
	// std::cout << "Shooting"  << std::endl;
    missiles[numMissilesShot].setInfo(getX(),getY() - 5, 1);
	// std::cout << "After shooting"  << std::endl;
	// // std::cout << "x: " << getX() << "y: " << getY() << std::endl;
	// missiles[numMissilesShot] = newshootMissile;
	numMissilesShot++;
	// missiles[numMissilesShot].clear();
	drawMissiles();//???
}