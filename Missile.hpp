/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhernand <lhernand@student.42.us.or>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 17:23:48 by lhernand          #+#    #+#             */
/*   Updated: 2019/01/26 17:23:49 by lhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MISSILE_HPP
# define MISSILE_HPP
# include "Game.hpp"
// # include "Player.cpp"
# include <unistd.h> // library for usleep
class Missile
{
	public:
		Missile(void);
		Missile(int startCol, int startRow, int number);
		~Missile(void);
		Missile(Missile const & src);
		Missile &operator=(Missile const & rhs);

		int 			getX(void) const;
		int			getY(void) const;
		int 			getN(void) const;

		void 		setN(int number);
		void 		setX(int x);
		void 		setY(int y);
		//methods for movement
		void 		moveUp(void);
		//methods for game mechanics using ncursus
		void 		drawMissile(Game *game);
		int			missileCollision(int x, int y);
		void 		clearMissile(void);
		void 		killMissile(void);
		// void 		getInput(char c, Game *game); // don't think  we need this

	private:
		int			x;
		int			y;
		int			N; // health indicator
		// int 			l; // has it collided on the left? 1 yes 0 no
		// int 			r; // has it collided on the right? 1 yes 0 no
};

#endif
