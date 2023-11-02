
#include <iostream>

#include <stdio.h>
#include <curses.h>

#include <chrono>
#include <vector>
#include <algorithm>

using namespace std::chrono_literals;

using steady_clock_t = std::chrono::time_point<std::chrono::steady_clock>;

void out(int y, int x, const std::string& s) {
    wmove(stdscr, y, x);
    wprintw(stdscr, "%s", s.c_str());
}

steady_clock_t now() {
    return std::chrono::steady_clock::now();
}

int main() {
    // On Linux/Mac this enables Unicode support in terminal and allows you to use fancy Unicode characters
    // like box drawing, etc. Unfortunately, it doesn't work on Windows, leaving you with the boring ASCII set.
    setlocale(LC_ALL, "");

    // The library we're using for terminal manipulation is called 'curses' or 'ncurses'.
    // 'pdcurses' is a port for Windows (on Linux and Mac the lib is supported natively).
    // Google 'curses' or 'ncurses' for a lot of documentation and guides on how to use it.

    // init curses
    initscr();
    // disable buffering
    cbreak();
    // disable input character echo
    noecho();
    // disable cursor
    curs_set(FALSE);
    // enable function keys as single character values, like KEY_LEFT, etc.
    keypad(stdscr, TRUE);
    // set a very small delay in milliseconds for getch/wgetch to wait for input. Without it, getch/wgetch would block.
    timeout(50);

    if (has_colors() == FALSE) {
        endwin();
        std::cerr << "Your terminal does not support color\n";
        exit(1);
    }

    // init colors
    start_color();
    const int main_color_pair = 1;
    const int player_color_pair = 2;
    const int bullet_color_pair = 3;
    // colors are COLOR_BLACK, COLOR_RED, COLOR_GREEN, COLOR_YELLOW, COLOR_BLUE, COLOR_MAGENTA, COLOR_CYAN, COLOR_WHITE
    init_pair(main_color_pair, COLOR_WHITE, COLOR_BLACK);
    init_pair(player_color_pair, COLOR_YELLOW, COLOR_BLUE);
    init_pair(bullet_color_pair, COLOR_RED, COLOR_BLACK);

    int h1;
    int w1;
    // get console dimensions
    getmaxyx(stdscr, h1, w1);
    int h = h1/2;
    int w = w1/2;

    struct Bullet {
        int w;
        int h;
        steady_clock_t last_time;
    };
    std::vector<Bullet> bullets;

    const char* title_format_str = "The terminal game template. Bullets: %lu";

    int c;
    // Main loop of the game. The game scene is rendered each iteration of this loop. 
    // An iteration of this loop happens either when the user press a key or when getch()'s timeout expires (which is set to 50ms).
    // This means our game's frame rate (fps) is 20 if user doesn't press anything.
    while ('q' != (c = getch())) {
        // clear the screen
        clear();

        // print title
        ssize_t title_size = snprintf(NULL, 0, title_format_str, bullets.size());
        wmove(stdscr, 1, (w1-title_size)/2);
        wprintw(stdscr, title_format_str, bullets.size());

        // display bullets
        attron(COLOR_PAIR(bullet_color_pair));
        for (Bullet& b : bullets) {
            if ((now() - b.last_time) / 1ms > 300) {
                b.h--;
                b.last_time = now();
            }
            out(b.h, b.w, "*");
        }
        attroff(COLOR_PAIR(bullet_color_pair));

        // remove bullets reached the screen border
        bullets.erase(
            std::remove_if(bullets.begin(), bullets.end(), [](const Bullet& b) { return b.h < 2; }),
            bullets.end()
        );

        // display the border
        for (int i = 1; i < w1; ++i) {
            out(0, i, "-");
            out(h1-1, i, "-");
        }
        for (int i = 1; i < h1-1; ++i) {
            out(i, 0, "|");
            out(i, w1-1, "|");
        }
        out(0, 0, "+");
        out(0, w1-1, "+");
        out(h1-1, 0, "+");
        out(h1-1, w1-1, "+");

        // handle user input
        switch(c) {
        case KEY_LEFT: --w; break;
        case KEY_RIGHT: ++w; break;
        case KEY_UP: --h; break;
        case KEY_DOWN: ++h; break;
        case ' ': bullets.push_back(Bullet{w, h, now()}); break;
        }

        // discards user input that we haven't handled yet. MAY NOT BE WHAT YOU WANT!
        flushinp();

        // display the player
        w = std::clamp(w, 1, w1-2);
        h = std::clamp(h, 1, h1-2);
        attron(COLOR_PAIR(player_color_pair));
        out(h, w, "M");
        attroff(COLOR_PAIR(player_color_pair));

        // don't forget to call refresh/wrefresh to make your changes visible
        refresh();
    }

    // returns terminal to its normal state. DO NOT FORGET TO CALL ON EXIT!
    endwin();

    return 0;
}
