/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Missile.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasmith <hasmith@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 19:49:55 by hasmith           #+#    #+#             */
/*   Updated: 2019/01/21 21:05:05 by hasmith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MISSILE_H_
# define MISSILE_H_

#include <string>
#include <iostream>
// #include "Enemy.hpp"
// #include "Missile.hpp"
#include "GameEntity.hpp"

class Missile : public GameEntity
{
    public:
        Missile(std::string n);
        Missile(Missile &ninj);
        Missile(void);
        ~Missile(void);
        Missile &operator=(Missile const &r);

};


#endif