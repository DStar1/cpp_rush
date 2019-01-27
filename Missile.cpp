/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Missile.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasmith <hasmith@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 19:49:55 by hasmith           #+#    #+#             */
/*   Updated: 2019/01/26 17:12:56 by hasmith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Game.hpp"
#include "Missile.hpp"

Missile::Missile(int x, int y) :
        by(y),
        bx(x)
{
    return;
}

Missile::~Missile(void){
    return;
}

void Missile::drawMissile(void){
    return;
}

Missile::~Missile(void){
    return;
}

int Missile::getBX(void) {
    return bx;
}

int Missile::getBY(void) {
    return by;
}

void Missile::moveUp() {
    by++;
}
