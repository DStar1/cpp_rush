/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasmith <hasmith@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 17:23:48 by lhernand          #+#    #+#             */
/*   Updated: 2019/01/27 14:48:48 by hasmith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_HPP
# define PLAYER_HPP
# include "Game.hpp"
# include "Missile.hpp"

class Player
{
	public:
		Player(void);
		Player(int numberOfMissiles);
		~Player(void);
		Player(Player const & src);
		Player &operator=(Player const & rhs);

		int 			getX(void) const;
		int			getY(void) const;
		// int getMapX(void);
		// int getMapY(void);

		void 		setX(int x);
		void 		setY(int y);
		// void 		setMapX(int x);
		// void 		setMapY(int y);

		//methods for movements
		void 		moveRight(void);
		void 		moveLeft(void);

		//methods for game mechanics using ncursus
		void 		drawPlayer(void);
		void 		getInput(char c, Game *game);
		void		setGame(Game *game);
		void 		drawMissiles(void);
		int			currMissile;
	private:
		int			x;
		int			y;
		// int			mapX;
		// int			mapY;
		int 			numberOfMissiles;
		Missile		*missile;
		Game		*game;
};
#endif
