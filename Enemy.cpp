/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhernand <lhernand@student.42.us.or>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/27 00:33:43 by lhernand          #+#    #+#             */
/*   Updated: 2019/01/27 00:33:47 by lhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Enemy.hpp"

Enemy::Enemy(void) :

l(1),
r(0)
{
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
	// mvaddch(getY() - 1, getX() + 1, ' ');
	// mvaddch(getY() - 1, getX() - 1, ' ');
	refresh();
}
void 		Enemy::killEnemy(void)
{
	this->clearEnemy();
	this->setN(0);
}
void 		Enemy::moveRight(void)
{
	this->clearEnemy();
	mvaddch(getY(), getX(), ' ');
	mvaddch(getY() - 1, getX() + 1, ' ');
	mvaddch(getY() - 1, getX() - 1, ' ');
	this->setX(x + 1);

}
void 		Enemy::moveLeft(void)
{
	this->clearEnemy();
	mvaddch(getY(), getX(), ' ');
	mvaddch(getY() - 1, getX() + 1, ' ');
	mvaddch(getY() - 1, getX() - 1, ' ');
	this->setX(x - 1);
}
void 		Enemy::drawEnemy(Game *game)//game instance is passed to know the map size;
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
	attron(COLOR_PAIR(2));
	mvaddch(this->getY() - 1, getX() + 1, '#');
	mvaddch(this->getY() - 1, getX() - 1, '#');
	mvaddch(this->getY(), this->getX(), '#');
	attroff(COLOR_PAIR(2));
	box(stdscr, 0, 0);
	refresh();
	usleep(1000); // creates small delay for the enemies as they move left to right and back.
}
