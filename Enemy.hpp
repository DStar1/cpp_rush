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

#ifndef Enemy_HPP
# define Enemy_HPP
# include "Game.hpp"
# include <unistd.h>

class Enemy
{
	public:
		Enemy(void);
		Enemy(int startCol, int startRow, int number);
		~Enemy(void);
		Enemy(Enemy const & src);
		Enemy &operator=(Enemy const & rhs);

		int 			getX(void) const;
		int			getY(void) const;
		int 			getN(void) const;

		void 		setN(int number);
		void 		setX(int x);
		void 		setY(int y);

		//methods for movements
		void 		moveRight(void);
		void 		moveLeft(void);

		//methods for game mechanics using ncursus
		void 		drawEnemy(Game *game);
		// void 		getInput(char c, Game *game); // don't think  we need this
	private:
		int			x;
		int			y;
		int			health; // health indicator
		int 			l; // has it collided on the left? 1 yes 0 no
		int 			r; // has it collided on the right? 1 yes 0 no
};

#endif
