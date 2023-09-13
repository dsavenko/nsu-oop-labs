
#include <iostream>

#include <stdio.h>
#include <curses.h>

#include <chrono>
#include <thread>

int main() {

    initscr();
    raw();
    noecho();
    curs_set(FALSE);
    keypad(stdscr, TRUE);
    nodelay(stdscr, TRUE);

    //set_escdelay(0);

    int h1, w1;
    getmaxyx(stdscr, h1, w1);
    int h = h1, w = w1;

    wmove(stdscr, h / 2, w / 2);
    wprintw(stdscr, "hello from %s, rows %d, cols %d", "curses", h1, w1);

    int c;
    bool cont = false;
    while ('q' != (c = getch())) {  
        cont = false;      
        switch(c) {
        case KEY_LEFT: --w; break;
        case KEY_RIGHT: ++w; break;
        case KEY_UP: --h; break;
        case KEY_DOWN: ++h; break;
        default: cont = true; break;
        }
        flushinp();
        if (cont) {
            std::this_thread::sleep_for(std::chrono::nanoseconds(10000));
            continue;
        }
        if (0 >= h) {
            h = 1;
        }
        if (0 >= w) {
            w = 1;
        }
        if (w >= w1) {
            w = w1-1;
        }
        if (h >= h1) {
            h = h1-1;
        }
        clear();
        wmove(stdscr, h / 2, w / 2);
        wprintw(stdscr, "hello from %s, rows %d/%d, cols %d/%d", "curses", h, h1, w, w1);
        refresh();
    }

    endwin();

    return 0;
}
