/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Board.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdiaz <jdiaz@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 23:48:56 by jdiaz             #+#    #+#             */
/*   Updated: 2019/01/27 20:20:55 by ztisnes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Board.hpp"
#include "../includes/Display.hpp"

Board::Board(void) : _board(NULL), _yMax(0), _xMax(0) {
	Display::pew("sounds/rs.mp3");
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
    printw("Created new board");
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

bool Board::handleCollision(Display *a, Display *b) {
    if (a->getType() == 'p' || b->getType() == 'p')
        clear();
    if (a->getType() == 'p' || b->getType() == 'p') {
        return true;
    }
    else {
        delete a;
        delete b;
    }
    return false;
}

/*
** In this function we update the coordinates of all the objects on the board.
** We begin by updating all the shooter objects while checking if they collide with any enemies.
** Then we update all the enemy objects and check if they collide with the player of with shooters
** If there is a collision, we delete both objects from the board
** If the player collides with an enemy, we return true and the game is over
*/
bool Board::update(int yMax, int xMax, Player *player, int key) {
    bool result;

    this->updateShooters(yMax, xMax);
    result = this->updateEnemies(yMax, xMax);
    if (!result)
        result = this->updatePlayer(yMax, xMax, key, player);
    return result;
}

bool Board::updatePlayer(int yMax, int xMax, int key, Player* player) {
    int player_x, player_y;

    player_x = player->getXCord();
    player_y = player->getYCord();
    player->direction(key, yMax, xMax);
    printw("player move: (%d, %d) -> (%d, %d)\n",
        player_y, player_x, player->getYCord(), player->getXCord());
    if (this->_board[player->getYCord()][player->getXCord()] &&
        this->_board[player->getYCord()][player->getXCord()]->getType() != 'p')
        return (true);
    this->_board[player_y][player_x] = NULL;
    this->_board[player->getYCord()][player->getXCord()] = player;
    return false;
}

/*
** Here we move each enemy object one step to the left. If they collide with a shooter, we delete both.
** If it collides with the player then the game is over and we return true.
** If the enemy is at the beginning of the board, we delete it.
*/
bool Board::updateEnemies(int yMax, int xMax) {
    printw("Updating enemies\n");
    for (int i = 0; i < xMax; i++) {
        for (int j = 0; j < yMax; j++) {
            if (this->_board[j][i] && this->_board[j][i]->getType() == 'e') {
                if (i == 0) {
                    delete this->_board[j][i];
                    printw("Enemy got to end of board, deleted enemy\n");
                }
                else if (this->_board[j][i - 1]) {
                    if (this->handleCollision(this->_board[j][i], this->_board[j][i - 1]))
                        return true;
                    this->_board[j][i - 1] = NULL;
                    printw("Collision at: y: %d, x: %d between shooter and enemy\n", j, i - 1);
                }
                else {
                    this->_board[j][i]->update();
                    this->_board[j][i - 1] = this->_board[j][i];
                    printw("enemy move: (%d, %d) -> (%d, %d)\n",
                        j, i, j, i - 1);

                }
                this->_board[j][i] = NULL;
            }
        }
    }
    return false;
}

/*
** Here we move each shooter object one step to the right. If they collide with an Enemy, we delete both.
** If the shooter is at the end of the board (xMax - 1), we delete it.
*/
void Board::updateShooters(int yMax, int xMax) {
    printw("Updating shooters\n");
    for (int i = xMax - 2; i >= 0; i--) {
        for (int j = 0; j < yMax - 1; j++) {
            if (this->_board[j][i] && this->_board[j][i]->getType() == 's') {
                if (i == xMax - 2) {
                    printw("shooter got to end of board, deleted shooter\n");
                }
                else if (this->_board[j][i + 1] && this->_board[j][i + 1]->getType() == 'e') {
                    this->handleCollision(this->_board[j][i], this->_board[j][i + 1]);
                    this->_board[j][i + 1] = NULL;
                    printw("Collision at: y: %d, x: %d between shooter and enemy\n", j, i + 1);
                }
                else {
                    this->_board[j][i]->update();
                    this->_board[j][i + 1] = this->_board[j][i];
                    printw("shooter move: (%d, %d) -> (%d, %d)\n",
                        j, i, j, i + 1);}
                this->_board[j][i] = NULL;
            }
        }
    }
}

void Board::draw(WINDOW *win) const {
    for (int i = 0; i < this->_yMax - 1; i++) {
        for (int j = 0; j < this->_xMax - 1; j++) {
            if (this->_board[i][j]) {
                mvprintw(i, j, "%c", this->_board[i][j]->getType());
            }
        }
    }
    (void)win;
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
