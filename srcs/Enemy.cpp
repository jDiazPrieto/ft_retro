/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdiaz <jdiaz@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 16:55:40 by jdiaz             #+#    #+#             */
/*   Updated: 2019/01/27 09:18:34 by ztisnes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Enemy.hpp"

//constructors
Enemy::Enemy(void) : Display() {
    return;
}

Enemy::Enemy(int yPos, int xPos) : Display(yPos, xPos, 0, -1) {

    printw("Creater new enemy at y: %d x: %d\n", yPos, xPos);
    return;
}

Enemy::Enemy(Enemy & src) : Display(src) {
    *this = src;
    return;
}

Enemy::~Enemy(void) {
    return;
}

//operator overloads
Enemy & Enemy::operator=(Enemy const & rhs) {
    this->_yCord = rhs.getYCord();
    this->_xCord = rhs.getXCord();
    this->_yDirection = rhs.getYDirection();
    this->_xDirection = rhs.getXDirection();
    return *this;
}

char Enemy::getType(void) const {
    return ('e');
}
