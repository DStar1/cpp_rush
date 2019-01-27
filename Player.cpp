/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhernand <lhernand@student.42.us.or>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 17:23:42 by lhernand          #+#    #+#             */
/*   Updated: 2019/01/26 17:23:44 by lhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Game.hpp"
#include "Player.hpp"

Player::Player(void) :
x(25),
y(25),
numberOfMissiles(100)
{
	std::cout << "You have: " << numberOfMissiles << " missiles" << std::endl;
	this->missile = new Missile[100];
	return ;
}
Player::Player(int numberOfMissiles) :
x(25),
y(25),
numberOfMissiles(numberOfMissiles)
{
	std::cout << numberOfMissiles << std::endl;
	this->missile = new Missile[numberOfMissiles];
	return ;
}
Player::~Player(void)
{
	std::cout << "Player Destroyed" << std::endl;
}
Player::Player(Player const & src)
{
	*this = src;
}
Player 		&Player::operator=(Player const & rhs)
{
	if (this == &rhs)
		return (*this);
	this->x = rhs.getX();
	this->y = rhs.getY();
	return (*this);
}
int			Player::getX(void) const
{
	return (this->x);
}
int 			Player::getY(void) const
{
	return (this->y);
}
void 		Player::setX(int x)
{
	this->x = x;
}
void 		Player::setY(int y)
{
	this->y = y;
}
void 		Player::moveRight(void)
{
	mvaddch(getY(), getX(), ' ');
	mvaddch(getY() + 1, getX() + 1, ' ');
	mvaddch(getY() + 1, getX() - 1, ' ');
	this->setX(x + 1);

}
void 		Player::moveLeft(void)
{
	mvaddch(getY(), getX(), ' ');
	mvaddch(getY() + 1, getX() + 1, ' ');
	mvaddch(getY() + 1, getX() - 1, ' ');
	this->setX(x - 1);
}
void 		Player::drawPlayer(void)
{
	attron(COLOR_PAIR(1));
	mvaddch(this->getY(), this->getX(), '^');
	mvaddch(this->getY() + 1, getX() + 1, '^');
	mvaddch(this->getY() + 1, getX() - 1, '^');
	attroff(COLOR_PAIR(1));
	box(stdscr, 0, 0);
	refresh();
}
void 		Player::getInput(char c, Game *game, Missile *missile)
{
	if (c == 27)
		exit(0);
	if ((c == '4') && (this->getX() > 2))
		moveLeft();
	else if ((c == '6') && (this->getX() < game->getMapX() + 2))
		moveRight();
	else if (c == ' ')
	{
		missile->setX(this->getX());
		missile->setY(this->getY() - 1);
		missile->drawMissile(game); // implementation of projectiles here
	}
	drawPlayer();

}
