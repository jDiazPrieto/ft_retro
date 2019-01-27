/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 16:55:40 by jdiaz             #+#    #+#             */
/*   Updated: 2019/01/26 16:55:51 by jdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Enemy.hpp"

Enemy::Enemy(void) : Display() {
    //generate random position here
    return;
}

Enemy::Enemy(int yPos, int xPos) : Display(yPos, xPos, 0, -1) {
    //generate random position here
    return;
}

Enemy::Enemy(Enemy & src) : Display(src) {
    *this = src;
    return;
}

Enemy::~Enemy(void) {
    return;
}
