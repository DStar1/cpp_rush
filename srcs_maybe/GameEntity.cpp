/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GameEntity.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasmith <hasmith@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 19:49:50 by hasmith           #+#    #+#             */
/*   Updated: 2019/01/21 21:05:02 by hasmith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "GameEntity.hpp"
// #include "Enemy.hpp"
#include <ctime>

GameEntity::GameEntity(std::string n) :
        name(n),
        hitPoints(100),
        maxHitPoints(100),
        energyPoints(100),
        maxEnergyPoints(100),
        level(1),
        meleeAttackDamage(30),
        rangedAttackDamage(20),
        armorDamageReduction(5) 
{
    srand(time(0));
    std::cout << "CL4P-TP <" << name << "> constructor called!!!" << std::endl;
}

GameEntity::GameEntity(void) :
        name("No name"),
        hitPoints(100),
        maxHitPoints(100),
        energyPoints(100),
        maxEnergyPoints(100),
        level(1),
        meleeAttackDamage(30),
        rangedAttackDamage(20),
        armorDamageReduction(5) 
{
    srand(time(0));
    std::cout << "CL4P-TP <" << name << "> constructor called!!!" << std::endl;
}


GameEntity::~GameEntity(void){
    std::cout << "CL4P-TP <" << name << "> destructor called!!!" << std::endl;
}

GameEntity::GameEntity(GameEntity &clp)
{
    srand(time(0));
    *this = clp;
    std::cout << "CL4P-TP <" << this->name << "> copy contructor called!!!" << std::endl;
}

GameEntity &GameEntity::operator=(GameEntity const &r){
    if (this != &r){
        hitPoints = r.hitPoints;
        maxHitPoints = r.maxHitPoints;
        energyPoints = r.energyPoints;
        maxEnergyPoints = r.maxEnergyPoints;
        level = r.level;
        name =r.name;
        meleeAttackDamage = r.meleeAttackDamage;
        rangedAttackDamage = r.rangedAttackDamage;
        armorDamageReduction = r.armorDamageReduction;
    }
    return (*this);
}

void GameEntity::rangedAttack(std::string const & target){
    if (dead())
        return;
    int damage = (rangedAttackDamage - armorDamageReduction);
    std::cout << "CL4P-TP <" << name << ">attacks <" << target << "> at range, causing <" << damage << "> points of damage !" << std::endl;
}

void GameEntity::meleeAttack(std::string const & target){
    if (dead())
        return;
    int damage = (meleeAttackDamage - armorDamageReduction);
    std::cout << "CL4P-TP <" << name << ">attacks <" << target << "> at range, causing <" << damage << "> points of damage !" << std::endl;
}

void GameEntity::takeDamage(unsigned int amount){
    if (dead())
        return;
    hitPoints -= amount;
    if (hitPoints <= 0)
    {
        hitPoints = 0;
        std::cout << "CL4P-TP <" << name << "> is DEAD!!!" << std::endl;
    }
}

void GameEntity::beRepaired(unsigned int amount){
    if (hitPoints < maxHitPoints)
    {
        hitPoints += amount;
        if (hitPoints > maxHitPoints)
            hitPoints = maxHitPoints;
        std::cout << "CL4P-TP <" << name << "> new health is " << hitPoints << std::endl;
    }
}

int GameEntity::dead(void){
    if (hitPoints <= 0){
        std::cout << "CL4P-TP <" << name << "> is already dead" << std::endl;
        return 1;//already dead
    }
    return 0;
}

void GameEntity::setStats(int hP, int maxHP, int eP, int maxEP, int level, std::string name, int meleeAD, int rangedAD, int armorDR){
    this->hitPoints = hP;
    this->maxHitPoints = maxHP;
    this->energyPoints = eP;
    this->maxEnergyPoints = maxEP;
    this->level = level;
    this->name = name;
    this->meleeAttackDamage = meleeAD;
    this->rangedAttackDamage = rangedAD;
    this->armorDamageReduction = armorDR;
}

int GameEntity::getHP(void) {
    return (this->hitPoints); 
}

int GameEntity::getMHP(void) {
    return (this->maxHitPoints);   
}

int GameEntity::getEP(void) {
    return (this->energyPoints);  
}

int GameEntity::getMaxEP(void) {
    return (this->maxEnergyPoints);  
}

int GameEntity::getLev(void) {
    return (this->level);    
}

int GameEntity::getMeleeAD(void) {
    return (this->meleeAttackDamage);   
}

int GameEntity::getRangeAD(void) {
    return (this->rangedAttackDamage);    
}

int GameEntity::getArmDamRed(void) {
    return (this->armorDamageReduction); 
}


void GameEntity::setHP(int i) {
    this->hitPoints = i;    
}

void GameEntity::setMHP(int i) {
    this->maxHitPoints = i;    
}

void GameEntity::setEP(int i) {
    this->energyPoints = i;    
}

void GameEntity::setMaxEP(int i) {
    this->maxEnergyPoints = i;    
}

void GameEntity::setLev(int i) {
    this->level = i;    
}

void GameEntity::setMeleeAD(int i) {
    this->meleeAttackDamage = i;    
}

void GameEntity::setRangeAD(int i) {
    this->rangedAttackDamage = i;    
}

void GameEntity::setArmDamRed(int i) {
    this->armorDamageReduction = i;    
}
