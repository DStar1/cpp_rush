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
numberOfMissiles(100)
{
	std::cout << "You have: " << numberOfMissiles << " missiles" << std::endl;
	this->missile = new Missile[100];
	this->currMissile = 0;
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
		// missile->setX(this->getX());
		// missile->setY(this->getY() - 1);
		// missile->drawMissile(game); // implementation of projectiles here
		this->missile[currMissile].setX(this->getX());
		this->missile[currMissile].setY(this->getY());
		this->missile[currMissile].setN(1);//health is 3?
		// missile->drawMissile(game); // implementation of projectiles here
		currMissile++;
		currMissile %= this->numberOfMissiles;
	}
	// drawPlayer();

}
