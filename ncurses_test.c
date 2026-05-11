//Practice with ncurses library
#include <stdio.h>
#include <ncurses.h>

int main(){
    initscr();
    start_color();

    // define your color pair here
    init_pair(1, COLOR_WHITE, COLOR_BLUE);
    // turn the color on
    attron(COLOR_PAIR(1));
    
    // print at position (5, 10)
     mvprintw(5, 10, "Hello, ncurses!");

    // turn the color off
    attroff(COLOR_PAIR(1));

    refresh();
    getch();
    endwin();
    return 0;
}