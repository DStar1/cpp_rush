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

Enemy::Enemy(void)

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
	refresh();
}
void 		Enemy::killEnemy(void)
{
	this->clearEnemy();
	this->setN(0);
}

void 		Enemy::moveDown(void)
{
	this->clearEnemy();
	mvaddch(getY(), getX(), ' ');
	mvaddch(getY() - 1, getX() + 1, ' ');
	mvaddch(getY() - 1, getX() - 1, ' ');
	this->setY(getY() + 2);
}
void 		Enemy::drawEnemy(void)//game instance is passed to know the map size;
{
	moveDown();
	attron(COLOR_PAIR(2));
	mvaddch(this->getY() - 1, getX() + 1, '#');
	mvaddch(this->getY() - 1, getX() - 1, '#');
	mvaddch(this->getY(), this->getX(), '#');
	attroff(COLOR_PAIR(2));
	box(stdscr, 0, 0);
	refresh();
	usleep(7000); // creates small delay for the enemies as they move left to right and back.
}
int 		win(Enemy *enemies, Game *game, int number)
{
	int i = 0;
	while (i < number)
	if (enemies[i++].getY() == game->getMapY() - 4)
	return (1);
	return (0);
}
