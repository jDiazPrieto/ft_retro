#include <ncurses.h>

int main(int argc, char **argv) {
	
	initscr();
	cbreak();
	noecho();

	int y, x;

	// get y, x of cursor on terminal
	// getyx(stdscr, y, x);
	
	getmaxyx(stdscr, y, x);

	// Create a pointer to a WINDOW object
	WINDOW * win = newwin(y , x, 0, 0);
	// make border around our window
	box(win, 0, 0);
	refresh();
	wrefresh(win, true);

	keypad(win)

	// customize border
	mvwprintw(win, 2, 3, "y: %d x: %d", y, x);

	// refreshes a specific window
	wrefresh(win);

	// waits for user input, returns int value of that key
	getch();

	// deallocates memory and ends ncurses
	endwin();
	
	return 0;
}
