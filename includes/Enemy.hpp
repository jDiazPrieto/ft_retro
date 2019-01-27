/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 15:17:01 by jdiaz             #+#    #+#             */
/*   Updated: 2019/01/26 15:17:05 by jdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENEMY_HPP
# define ENEMY_HPP

#include "Display.hpp"

class Enemy : public Display {

public:
    //constructors
    Enemy(void);
    Enemy(int yPos, int xPos);
    Enemy(Enemy & src);
    ~Enemy(void);
};

#endif