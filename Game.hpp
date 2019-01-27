/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasmith <hasmith@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 19:49:55 by hasmith           #+#    #+#             */
/*   Updated: 2019/01/26 18:19:43 by hasmith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H_
# define GAME_H_

#include <string>
#include <iostream>
# include <ncurses.h>
# include <curses.h>
# include <thread>
# include <chrono>
#include "Missile.hpp"
// #include <vector>

class Game {
    public:
        Game(int col, int row);
        ~Game(void);

        void getInput(int c);
        int getX(void);
        int getY(void);

        void moveRight();
        void moveLeft();
        void drawPlayer(void);
        void drawMissiles(void);

        void shootMissile(void);
        void clearMissiles(void);

    private:
        int px;
        int py;
        int mapx;
        int mapy;
        int score;

        int numMissiles;
        int numMissilesShot;
        Missile *missiles;


};


#endif