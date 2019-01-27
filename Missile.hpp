/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Missile.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasmith <hasmith@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 19:49:55 by hasmith           #+#    #+#             */
/*   Updated: 2019/01/26 18:56:12 by hasmith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MISSILE_H_
# define MISSILE_H_

#include "Game.hpp"

class Missile {
    public:
        Missile(int x, int y);
        Missile(void);
        ~Missile(void);

        int getMX(void);
        int getMY(void);
        int getAlive(void);
        void setInfo(int x, int y, int life);
        // void setMX(int i);
        // void setMY(int i);
        // void setAlive(int i);

        void moveUp(void);
        void drawMissile(void);
        void clear(void);

    private:
        int mx;
        int my;
        int alive;
        // int player_enemy;

};

#endif