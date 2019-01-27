/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Shoot.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 18:26:23 by jdiaz             #+#    #+#             */
/*   Updated: 2019/01/26 18:26:24 by jdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Shoot.hpp"

Shoot::Shoot(void) : Display() {
    return;
}

Shoot::Shoot(int yCord, int xCord) : Display(yCord, xCord, 0, 1) {
    return;
}

Shoot::Shoot(Shoot & src) : Display(src) {
    *this = src;
    return;
}

Shoot::~Shoot(void) {
    return;
}

Shoot & Shoot::operator=(Shoot const & rhs) {
    this->_yCord = rhs.getYCord();
    this->_xCord = rhs.getXCord();
    this->_yDirection = rhs.getYDirection();
    this->_xDirection = rhs.getXDirection();
    return *this;
}

char Shoot::getType(void) const {
    return 'o';
}