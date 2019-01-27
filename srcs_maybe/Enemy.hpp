/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasmith <hasmith@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 19:49:55 by hasmith           #+#    #+#             */
/*   Updated: 2019/01/21 21:05:05 by hasmith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Enemy_H_
# define Enemy_H_

#include <string>
#include <iostream>
// #include "Missile.hpp"
// #include "Enemy.hpp"
#include "GameEntity.hpp"

class Enemy : public GameEntity
{
    public:
        Enemy(std::string n);
        Enemy(Enemy &obj);
        Enemy(void);
        ~Enemy(void);
        Enemy &operator=(Enemy const &r);

};


#endif