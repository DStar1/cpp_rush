/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Missile.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasmith <hasmith@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 19:49:55 by hasmith           #+#    #+#             */
/*   Updated: 2019/01/26 17:17:25 by hasmith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MISSILE_H_
# define MISSILE_H_

#include "Game.hpp"

class Missile {
    public:
        Missile(int x, int y);
        ~Missile(void);

        int getBX(void);
        int getBY(void);

        void moveUp(void);
        void drawMissile(void);

    private:
        int bx;
        int by;
        // int player_enemy;

};

#endif