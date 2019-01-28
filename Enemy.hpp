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
# include "Junk.hpp"
# include <unistd.h>

class Enemy : public Junk
{
	public:
		Enemy(void);
		~Enemy(void);
		Enemy(Enemy const & src);
		Enemy &operator=(Enemy const & rhs);
		//methods for movements
		void 		moveRight(void);
		void 		moveLeft(void);
		//methods for game mechanics using ncursus
		void 		drawEnemy(Game *game);
		void 		clearEnemy(void);
		void 		killEnemy(void);
	private:
		int 			l; // has it collided on the left? 1 yes 0 no
		int 			r; // has it collided on the right? 1 yes 0 no
};

#endif
