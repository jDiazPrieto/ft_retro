/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Display.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdiaz <jdiaz@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 17:04:38 by jdiaz             #+#    #+#             */
/*   Updated: 2019/01/27 20:12:35 by ztisnes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Display.hpp"

//constructors
Display::Display(void) : _yCord(0), _xCord(0), _yDirection(0), _xDirection(0){
    return;
}

Display::Display(int yCord, int xCord, int yDirection, int xDirection) :
    _yCord(yCord), _xCord(xCord), _yDirection(yDirection), _xDirection(xDirection) {
    return;
}

Display::Display(Display & src) {
    *this = src;
    return;
}

Display::~Display(void) {
    return;
}

//operator overloads
Display & Display::operator=(Display const & src) {
    this->_yCord = src.getYCord();
    this->_xCord = src.getXCord();
    this->_yDirection = src.getYDirection();
    this->_xDirection = src.getXDirection();
    return *this;
}

//setter functions
void Display::setYCord(int y) {
	this->_yCord = y;
}

void Display::setXCord(int x) {
	this->_xCord = x;
}

//getter functions
int Display::getYCord(void) const {
    return this->_yCord;
}

int Display::getXCord(void) const {
    return this->_xCord;
}

int Display::getYDirection(void) const {
    return this->_yDirection;
}

int Display::getXDirection(void) const {
    return this->_xDirection;
}

void Display::pew(std::string soundFile)
{
	std::string command = "afplay " + soundFile + " &";
	std::system(command.c_str());
	return ;
}

void Display::update(void) {
    this->_xCord += this->_xDirection;
    this->_yCord += this->_yDirection;
}

void Display::draw(void) const {
    return;
}
