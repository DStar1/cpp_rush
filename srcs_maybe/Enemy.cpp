/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasmith <hasmith@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 19:49:50 by hasmith           #+#    #+#             */
/*   Updated: 2019/01/21 21:05:02 by hasmith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Enemy.hpp"
#include "GameEntity.hpp"
#include <ctime>

Enemy::Enemy(std::string n)
{
    srand(time(0));
    GameEntity::setStats(100, 100, 100, 100, 1, n, 30, 20, 5);
    std::cout << "FR4G-TP <" << this->name << "> contructor called!!!" << std::endl;
}

Enemy::Enemy(void)
{
    srand(time(0));
    GameEntity::setStats(100, 100, 100, 100, 1, "No name", 30, 20, 5);
    std::cout << "FR4G-TP <" << "No name" << "> contructor called!!!" << std::endl;
}

Enemy::Enemy(Enemy &frag)
{
    srand(time(0));
    *this = frag;
    std::cout << "FR4G-TP <" << this->name << "> copy contructor called!!!" << std::endl;
}


Enemy::~Enemy(void){
    std::cout << "FR4G-TP <" << this->name << "> destructor called!!!" << std::endl;
}

Enemy &Enemy::operator=(Enemy const &r){
    if (this != &r){
        GameEntity::operator=(r);
        std::cout << "FR4G-TP <" << this->name << "> assigninging operator!!!" << std::endl;
    } 
    return (*this);
}
