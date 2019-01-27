/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Missile.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasmith <hasmith@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 19:49:55 by hasmith           #+#    #+#             */
/*   Updated: 2019/01/26 19:25:17 by hasmith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Game.hpp"
#include "Missile.hpp"
#include <iostream>

Missile::Missile(int x, int y) :
        mx(x),
        my(y),
        alive(1)
{
    return;
}

Missile::Missile(void)
{
    mx = 0;
    my = 0;
    alive = 0;
    return;
}

void Missile::drawMissile(void){
	attron(COLOR_PAIR(1));
	// mvprintw(my, mx, ".");
	mvprintw(10, 10, ".");
    // mvaddch(my, mx, '^');
	attroff(COLOR_PAIR(1));
    // refresh();
    return;
}

void Missile::clear(void){
    mvprintw(my, mx, " ");
    return;
}

Missile::~Missile(void){
    return;
}

int Missile::getMX(void) {
    return mx;
}

int Missile::getAlive(void) {
    return alive;
}

int Missile::getMY(void) {
    return my;
}

void Missile::setInfo(int x, int y, int life) {
    mx = x;
    my = y;
    life = life;
}

// void Missile::setMY(int i) {
//     my = i;
// }

// void Missile::setAlive(int i) {
//     alive = i;
// }


void Missile::moveUp() {
    my--;
    std::cout << "y bullets: " << my << std::endl;
}
