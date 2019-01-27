/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdiaz <jdiaz@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 17:58:47 by jdiaz             #+#    #+#             */
/*   Updated: 2019/01/27 11:49:20 by ztisnes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/GameObject.hpp"
#include <ncurses.h>
#include <unistd.h>

void	beginGame(WINDOW *win, GameObject game, int yMax, int xMax)
{
	int key_pressed;

	while (!game.isDone()) {
		//wait for user to press a key
		key_pressed = getch();

		// update all entities on board (move missiles, enemies, player or create new entities)
		game.update(key_pressed, yMax, xMax);

		//Once all the characters are updated, we can re draw the board
		clear();
		game.draw(win);
		refresh();
	}

	return;
}

int	main(void)
{
	int yMax, xMax;

	//inititate ncurses
	initscr();
	cbreak();
	noecho();
	//get window dimensions
	getmaxyx(stdscr, yMax, xMax);

	//initiate gameobject
	GameObject game(yMax, xMax);

	//create window
	WINDOW * win = newwin(yMax - 1 , xMax - 1, 0, 0);
	//get arrow inputs
	keypad(win, true);

	beginGame(win, game, yMax, xMax);

	//game is over
	getch();
	endwin();
	return (0);
}
