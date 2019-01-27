/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Board.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdiaz <jdiaz@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 23:48:56 by jdiaz             #+#    #+#             */
/*   Updated: 2019/01/27 09:18:48 by ztisnes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Board.hpp"
#include "../includes/Display.hpp"

Board::Board(void) : _board(NULL), _yMax(0), _xMax(0) {
    return;
}

Board::Board(int yMax, int xMax) : _board(NULL), _yMax(yMax), _xMax(xMax) {
    this->_board = new Display** [yMax];
    for (int i = 0; i < yMax; i++) {
        this->_board[i] = new Display* [xMax];
        for (int j = 0; j < xMax; j++) {
            this->_board[i][j] = NULL;
        }
    }
    return;
}

Board::Board(Board const & src) {
    *this = src;
    return;
}

Board::~Board(void) {
    //NEED TO FREE EVERYTHING THAT WAS ALLOCATED DYNAMICALLY
    return;
}

Board & Board::operator=(Board const & src) {
    this->_board = src.getBoard();
    this->_yMax = src.getYMax();
    this->_xMax = src.getXMax();
    return *this;;
}

void Board::addDisplay(Display* const display) {
    int y, x;
    y = display->getYCord();
    x = display->getXCord();
    this->_board[y][x] = display;
}

/*
** In this function we update the coordinates of all the objects on the board.
** We begin by updating all the shooter objects while checking if they collide with any enemies.
** Then we update all the enemy objects and check if they collide with the player of with shooters
** If there is a collision, we delete both objects from the board
** If the player collides with an enemy, we return true and the game is over
*/
bool Board::update(int yMax, int xMax) {
    updateShooters(yMax, xMax);
    updateEnemies(yMax, xMax);
    return false;
}

void Board::draw(void) const {
    return;
}

//getter functions
Display*** Board::getBoard(void) const {
    return this->_board;
}

int Board::getYMax(void) const {
    return this->_yMax;
}

int Board::getXMax(void) const {
    return this->_xMax;
}
