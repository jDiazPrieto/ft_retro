/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GameObject.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdiaz <jdiaz@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 15:23:50 by jdiaz             #+#    #+#             */
/*   Updated: 2019/01/27 11:32:20 by ztisnes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAMEOBJECT_HPP
# define GAMEOBJECT_HPP

#include <time.h>
#include "Display.hpp"
#include "Player.hpp"
#include "Enemy.hpp"
#include "Shoot.hpp"
#include <ncurses.h>
#include "Board.hpp"
#include <cstdlib>
#include <ncurses.h>

class GameObject {

private:

    Player  *_player;
    //Enemy   *_enemies;
    //Shoot   *_shooters;
    Board   *_board;
    int     _score;
    bool    _done;

    GameObject(void);

public:

    //constructors
    GameObject(int yMax, int xMax);
    GameObject(GameObject const & src);
    ~GameObject(void);

    //operator overloads
    GameObject & operator=(GameObject const & rhs);

    bool isDone(void) const;
    void createEnemy(void);
    void createShooter(void);
    void update(int key, int yMax, int xMax);
    void draw(WINDOW * win) const;

    //getter functions
    Player* getPlayer(void) const;
    Board*  getBoard(void) const;
    int     getScore(void) const;
};

#endif
