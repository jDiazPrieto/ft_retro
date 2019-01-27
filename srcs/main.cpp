/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 17:58:47 by jdiaz             #+#    #+#             */
/*   Updated: 2019/01/26 18:32:03 by jdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/GameObject.hpp"
#include <ncurses.h>
#include <unistd.h>

void	beginGame(WINDOW *win, GameObject game, int yMax, int Xmax)
{
	int key_pressed;

	while (!game.isDone()) {
		key_pressed = getch();
		game.update(key_pressed);
		game.draw();
	}
	return;
}

int	main(void)
{
	int yMax, xMax;
	WINDOW *win;

	initscr();
	cbreak();
	noecho();

	getmaxyx(stdscr, yMax, xMax);
	keypad(win, true);
	GameObject game(yMax, xMax);

	win = newwin(yMax - 1 , xMax - 1, 0, 0);
	beginGame(win, game, yMax, xMax);

	endwin();
}
