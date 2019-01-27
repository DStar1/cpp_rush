/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Missile.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasmith <hasmith@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 19:49:50 by hasmith           #+#    #+#             */
/*   Updated: 2019/01/21 21:05:02 by hasmith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Enemy.hpp"
#include "Missile.hpp"
#include "GameEntity.hpp"
#include <ctime>

Missile::Missile(std::string n)
{
    srand(time(0));
    GameEntity::setStats(60, 60, 120, 120, 1, n, 60, 5, 0);
    std::cout << "N1NJ-TP <" << this->name << "> contructor called!!!" << std::endl;
}

Missile::Missile(void)
{
    srand(time(0));
    GameEntity::setStats(60, 60, 120, 120, 1, "No name", 60, 5, 0);
    std::cout << "N1NJ-TP <" << "No name" << "> contructor called!!!" << std::endl;
}

Missile::Missile(Missile &ninj)
{
    srand(time(0));
    *this = ninj;
    std::cout << "N1NJ-TP <" << this->name << "> copy contructor called!!!" << std::endl;
}


Missile::~Missile(void){
    std::cout << "N1NJ-TP <" << this->name << "> destructor called!!!" << std::endl;
}

Missile &Missile::operator=(Missile const &r){
    if (this != &r){
        GameEntity::operator=(r);
        std::cout << "N1NJ-TP <" << this->name << "> assigninging operator!!!" << std::endl;
    } 
    return (*this);
}
