/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasmith <hasmith@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/27 00:33:43 by lhernand          #+#    #+#             */
/*   Updated: 2019/01/27 21:46:13 by hasmith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Enemy.hpp"

Enemy::Enemy(void)
:
l(1),
r(0)
{
	this->setN(0);
	return ;
}
Enemy::~Enemy(void)
{
	std::cout << "Enemy Destroyed" << std::endl;
}
Enemy::Enemy(Enemy const & src)
{
	*this = src;
}
Enemy 		&Enemy::operator=(Enemy const & rhs)
{
	if (this == &rhs)
		return (*this);
	this->x = rhs.getX();
	this->y = rhs.getY();
	this->N = rhs.getN();
	return (*this);
}
void 		Enemy::clearEnemy(void)
{
	mvaddch(getY(), getX(), ' ');
	mvaddch(getY() - 1, getX() + 1, ' ');
	mvaddch(getY() - 1, getX() - 1, ' ');
	refresh();
}
void 		Enemy::killEnemy(void)
{
	this->clearEnemy();
	this->setN(0);
	this->setX(0);
	this->setY(0);
}
void 		Enemy::moveRight(void)
{
	this->clearEnemy();
	this->setX(x + 1);

}
void 		Enemy::moveLeft(void)
{
	this->clearEnemy();
	this->setX(x - 1);
}
void 		Enemy::moveDown(void)
{
	this->clearEnemy();
	this->setY(y - 1);
}
void 		Enemy::drawEnemy(Game *game)//game instance is passed to know the map size;
{
	// (void)game;
	if (this->getN())
	{
		if (l)
		{
			this->moveLeft();
			if (this->getX() == 2)
			{
				this->r = 1;
				this->l = 0;
			}
		}
		else if (r)
		{
			this->moveRight();
			if (this->getX() == game->getMapX() - 2)
			{
				this->r = 0;
				this->l = 1;
			}
		}
		// this->setY(this->getY() - 3);
		// this->moveDown();
		attron(COLOR_PAIR(2));
		mvaddch(this->getY() - 1, getX() + 1, '#');
		mvaddch(this->getY() - 1, getX() - 1, '#');
		mvaddch(this->getY(), this->getX(), '#');
		attroff(COLOR_PAIR(2));
		box(stdscr, 0, 0);
		refresh();
		usleep(1000); // creates small delay for the enemies as they move left to right and back.
	}
}
