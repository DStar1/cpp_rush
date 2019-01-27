/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasmith <hasmith@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 19:49:55 by hasmith           #+#    #+#             */
/*   Updated: 2019/01/26 16:00:55 by hasmith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H_
# define GAME_H_

#include <string>
#include <iostream>
# include <ncurses.h>
# include <curses.h>
# include <iostream>
# include <thread>
# include <chrono>

class Game {
    public:
        // Game(std::string n);
        Game(void);
        Game(int col, int row);
        ~Game(void);

        void getInput(int c);
        int getX(void);
        int getY(void);

        void moveRight();
        void moveLeft();
        void drawPlayer(void);

    private:
        int x;
        int y;
        int mapx;
        int mapy;

};


#endif