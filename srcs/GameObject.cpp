/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GameObject.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 22:25:15 by jdiaz             #+#    #+#             */
/*   Updated: 2019/01/26 22:25:33 by jdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/GameObject.hpp"

GameObject::GameObject(void) : _player(NULL), _board(NULL), _score(0), _done(false) {
    return;
}

GameObject::GameObject(int yMax, int xMax) {
    this->_player = new Player(xMax, yMax);
    this->_board = new Board(yMax, xMax);
    this->_score = 0;
    this->_done = false;
    return;
}

GameObject::GameObject(GameObject const & src) {
    *this = src;
    return;
}

GameObject::~GameObject(void) {
    //Need to delete all dynamically allocated objects
    //delete this->_player;
    delete this->_board;
    return;
}

GameObject & GameObject::operator=(GameObject const & rhs) {
    this->_player = rhs.getPlayer();
    this->_board = rhs.getBoard();
    this->_score = rhs.getScore();
    this->_done = rhs.isDone();
    return (*this);
}

// Creates a new enemy in position y, x
// Call boards's addDisplay function to add the new enemy to the board
void GameObject::createEnemy(void) {
    int y;
    int x;

    y = rand() % this->_board->getYMax();
    x = this->_board->getXMax();
    Enemy *enemy = new Enemy(y, x);
    this->_board->addDisplay(enemy);
    return;
}

// Call the player's createShooter function to ge the new missile
// add the new missile to the board using the board's addDisplay function
void GameObject::createShooter(void) {
    int x, y;
    Shoot *shooter = this->_player->shootMissile();
    y = shooter->getYCord();
    x = shooter->getXCord();
    // We only add a shooter if the spot is empty
    if (this->_board->getBoard()[y][x] == NULL)
        this->_board->addDisplay(shooter);
    else
        delete shooter;
    return;
}

/*
** In this function we will move all the entities on the board and check collisions
** If the user presses the space bar, we create a new missile and add it to the board
** If the user moves the player, we update the player's direction variables
** After taking the user's input, we call the board's update function 
*/
void GameObject::update(int key) {
    this->_player->direction(key);
    this->_done = this->_board->update();
    if (key == (int)' ')
        this->createShooter();
    this->createEnemy();
    return;
}

// check if game is over, if not we call the board's draw function
void GameObject::draw(void) const {
    if (this->_done) {
        //DRAW GAME OVER
    }
    else {
        this->_board->draw();
    }
    return;
}

//getter functions
bool GameObject::isDone(void) const {
    return this->_done;
}

Player* GameObject::getPlayer(void) const {
    return this->_player;
}

Board* GameObject::getBoard(void) const {
    return this->_board;
}

int GameObject::getScore(void) const {
    return this->_score;
}


