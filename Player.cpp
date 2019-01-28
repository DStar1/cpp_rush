/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasmith <hasmith@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 17:23:42 by lhernand          #+#    #+#             */
/*   Updated: 2019/01/27 19:23:53 by hasmith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Game.hpp"
#include "Player.hpp"
// #include "Enemy.hpp"

Player::Player(void) :
numberOfMissiles(20)
{
	std::cout << "You have: " << numberOfMissiles << " missiles" << std::endl;
	this->missile = new Missile[this->numberOfMissiles];
	this->currMissile = 0;
	x = 20;
	y = 20;
	return ;
}
// Player::Player(void) :
// x(10),
// y(20),
// numberOfMissiles(20)
// {
// 	std::cout << "You have: " << numberOfMissiles << " missiles" << std::endl;
// 	this->missile = new Missile[this->numberOfMissiles];
// 	this->currMissile = 0;
// 	return ;
// }
Player::Player(int numberOfMissiles) :
x(25),
y(25),
numberOfMissiles(numberOfMissiles)
{
	std::cout << numberOfMissiles << std::endl;
	this->missile = new Missile[numberOfMissiles];
	currMissile = 0;
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
// int 		Player::getMapX(void)
// {
// 	return this->mapX;
// }
// int 		Player::getMapY(void)
// {
// 	return this->mapY;
// }
// void 		Player::setMapX(int x)
// {
// 	this->mapX = x;
// }
// void 		Player::setMapY(int y)
// {
// 	this->mapY = y;
// }
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

int 		Player::missilesCollisions(int ex, int ey)
{
	// usleep(5000);
	for (int i = 0; i < this->numberOfMissiles; i++)
	{
		std::string s = std::to_string(this->missile[this->currMissile-1].getX()) + " " + std::to_string(this->missile[this->currMissile-1].getY());
		mvwprintw(stdscr, 2, 2, s.c_str());
		if (this->missile->missileCollision(ex, ey))
		{
			// std::cout << "coords" << std::endl;
			return 1;
			// enemy.killEnemy();// maybe just 
		}
	}
	return 0;
}

void		Player::setGame(Game *game)
{
	this->game = game;
	// std::cout << this->game->getMapY() << ", " << this->game->getMapX() << std::endl;
	this->setX(this->game->getMapX()/2);
	this->setY(this->game->getMapY()-4);

}

void 		Player::drawMissiles(void)
{
	for (int i = 0; i < this->numberOfMissiles; i++){
		if (this->missile[i].getN() > 0)
		{
			this->missile[i].drawMissile(this->game);
		}
	}
}

void 		Player::getInput(char c, Game *game)
{
	if (c == 27)
		exit(0);
	if ((c == '4') && (this->getX() > 2))
		moveLeft();
	else if ((c == '6') && (this->getX() < game->getMapX() + 2))
		moveRight();
	else if (c == ' ')
	{
		this->missile[currMissile].setX(this->getX());
		this->missile[currMissile].setY(this->getY());
		this->missile[currMissile].setN(1);//health is 3?
		// missile->drawMissile(game); // implementation of projectiles here 
		currMissile++;
		currMissile %= this->numberOfMissiles;
	}   
	// drawPlayer();
}
