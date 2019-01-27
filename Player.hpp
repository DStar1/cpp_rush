/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhernand <lhernand@student.42.us.or>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 17:23:48 by lhernand          #+#    #+#             */
/*   Updated: 2019/01/26 17:23:49 by lhernand         ###   ########.fr       */
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

		void 		setX(int x);
		void 		setY(int y);

		//methods for movements
		void 		moveRight(void);
		void 		moveLeft(void);

		//methods for game mechanics using ncursus
		void 		drawPlayer(void);
		void 		getInput(char c, Game *game, Missile *missile);
	private:
		int			x;
		int			y;
		int 			numberOfMissiles;
		Missile		*missile;
};
#endif
