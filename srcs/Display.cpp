/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Display.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 17:04:38 by jdiaz             #+#    #+#             */
/*   Updated: 2019/01/26 17:04:47 by jdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Display.hpp"

Display::Display(void) : _yCord(0), _xCord(0), _yDirection(0), _xDirection(0){
    return;
}

Display::Display(int yCord, int xCord, int yDirection, int xDirection) :
    _yCord(yCord), _xCord(xCord), _yDirection(yDirection), _xDirection(0) {
    return;
}

Display::Display(Display & src) {
    *this = src;
    return;
}

Display::~Display(void) {
    return;
}

