/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Board.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 22:18:46 by jdiaz             #+#    #+#             */
/*   Updated: 2019/01/26 22:23:53 by jdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BOARD_HPP
# define BOARD_HPP

#include <string>
#include "Display.hpp"
#include "Player.hpp"

class Board {

private:

	Display ***_board;
	int		_yMax;
	int		_xMax;

	//constructor
	Board(void);

	//update Display objects' coordinates
	void updateShooters(int yMax, int xMax);
    bool updateEnemies(int yMax, int xMax);
	bool updatePlayer(int yMax, int xMax, int key, Player* player);
	bool handleCollision(Display *a, Display * b);

public:
	
	//constructors
	Board(int yMax, int xMax);
	Board(Board const & src);
	~Board(void);
	
	// operator overloads
	Board & operator=(Board const & src);

	void addDisplay(Display* const display);
	bool update(int yMax, int xMax, Player *player, int key);
	void draw(void) const;

	// getter functions
	Display*** getBoard(void) const;
	int		getYMax(void) const;
	int		getXMax(void) const;
	
};

#endif
