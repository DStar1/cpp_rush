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
#include "Game.hpp"
#include <unistd.h> // library for usleep
Enemy::Enemy(void) :
x(2),
y(2),
N(1),
l(1),
r(0)
{
	return ;
}
Enemy::Enemy(int startCol, int startRow, int number) :
x(startCol),
y(startRow),
N(number),
l(0),
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
int			Enemy::getX(void) const
{
	return (this->x);
}
int 			Enemy::getY(void) const
{
	return (this->y);
}
int 			Enemy::getN(void) const
{
	return (this->N);
}
void 		Enemy::setX(int x)
{
	this->x = x;
}
void 		Enemy::setY(int y)
{
	this->y = y;
}
void 		Enemy::setN(int number)
{
	this->N = number;
}
void 		Enemy::moveRight(void)
{
	mvaddch(getY(), getX(), ' ');
	mvaddch(getY() - 1, getX() + 1, ' ');
	mvaddch(getY() - 1, getX() - 1, ' ');
	this->setX(x + 1);

}
void 		Enemy::moveLeft(void)
{
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
// void 		Enemy::getInput(char c, Game *game) //game instance is passed to know the map size;
// {
// 	if (c == 27)
// 		exit(0);
// 	if ((c == '4') && (this->getX() > 2))
// 		moveLeft();
// 	else if ((c == '6') && (this->getX() < game->getMapX() + 2))
// 		moveRight();
// 	// else if (c == ' ')
// 	// 	EnemyBullet();
// 	drawEnemy(game);
// }
