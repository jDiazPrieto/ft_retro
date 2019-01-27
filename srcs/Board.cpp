/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Board.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 23:48:56 by jdiaz             #+#    #+#             */
/*   Updated: 2019/01/26 23:49:13 by jdiaz            ###   ########.fr       */
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

void addDisplay(Display* const display) {
    
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