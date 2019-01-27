/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Missile.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasmith <hasmith@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/27 00:33:43 by lhernand          #+#    #+#             */
/*   Updated: 2019/01/27 15:02:42 by hasmith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Missile.hpp"

Missile::Missile(void) :
x(25),
y(25),
N(0)
{
	return ;
}
Missile::Missile(int startCol, int startRow, int number) :
x(startCol),
y(startRow),
N(number)
{
	return ;
}
Missile::~Missile(void)
{
	std::cout << "Missile Destroyed" << std::endl;
}
Missile::Missile(Missile const & src)
{
	*this = src;
}
Missile 		&Missile::operator=(Missile const & rhs)
{
	if (this == &rhs)
		return (*this);
	this->x = rhs.getX();
	this->y = rhs.getY();
	this->N = rhs.getN();
	return (*this);
}
int			Missile::getX(void) const
{
	return (this->x);
}
int 			Missile::getY(void) const
{
	return (this->y);
}
int 			Missile::getN(void) const
{
	return (this->N);
}
void 		Missile::setX(int x)
{
	this->x = x;
}
void 		Missile::setY(int y)
{
	this->y = y;
}
void 		Missile::setN(int number)
{
	this->N = number;
}

void 		Missile::moveUp(void)
{
	mvaddch(this->getY(), this->getX(), ' ');
	this->setY(this->getY() - 1);
}
void 		Missile::drawMissile(Game *game)
{
	if (this->N > 0 && (this->getY() > 0 && this->getY() < game->getMapY() - 1))
	{
		this->moveUp();
		attron(COLOR_PAIR(3));
		mvaddch(this->getY() - 1, this->getX(), '|');
		attroff(COLOR_PAIR(3));
		box(stdscr, 0, 0);
		refresh();
		usleep(1000); // creates small delay for the enemies as they move left to right and back.
	}
	else
		this->N = 0;
}
// void 		Missile::getInput(char c, Game *game) //game instance is passed to know the map size;
// {
// 	if (c == 27)
// 		exit(0);
// 	if ((c == '4') && (this->getX() > 2))
// 		moveLeft();
// 	else if ((c == '6') && (this->getX() < game->getMapX() + 2))
// 		moveRight();
// 	// else if (c == ' ')
// 	// 	MissileBullet();
// 	drawMissile(game);
// }
