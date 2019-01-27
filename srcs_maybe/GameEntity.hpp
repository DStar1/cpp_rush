/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GameEntity.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasmith <hasmith@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 19:49:55 by hasmith           #+#    #+#             */
/*   Updated: 2019/01/21 21:05:05 by hasmith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAMEENTITY_H_
# define GAMEENTITY_H_

#include <string>
#include <iostream>

class GameEntity {
    public:
        GameEntity(std::string n);
        GameEntity(GameEntity &clp);
        GameEntity(void);
        ~GameEntity(void);

        void rangedAttack(std::string const & target);
        void meleeAttack(std::string const & target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);

        GameEntity &operator=(GameEntity const &r);
        std::string name;
        int dead(void);

        void setStats(int hP, int maxHP, int eP, int maxEP, int level, std::string name, int meleeAD, int rangedAD, int armorDR);

        int getHP(void);
        int getMHP(void);
        int getEP(void);
        int getMaxEP(void);
        int getLev(void);
        int getMeleeAD(void);
        int getRangeAD(void);
        int getArmDamRed(void);

        void setHP(int hitPoints);
        void setMHP(int maxHitPoints);
        void setEP(int energyPoints);
        void setMaxEP(int maxEnergyPoints);
        void setLev(int level);
        void setMeleeAD(int meleeAttackDamage);
        void setRangeAD(int rangedAttackDamage);
        void setArmDamRed(int armorDamageReduction);

    private:
        int hitPoints;
        int maxHitPoints;
        int energyPoints;
        int maxEnergyPoints;
        int level;
        int meleeAttackDamage;
        int rangedAttackDamage;
        int armorDamageReduction;

};


#endif