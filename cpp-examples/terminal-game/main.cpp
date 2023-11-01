
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
    wprintw(stdscr, s.c_str());
}

steady_clock_t now() {
    return std::chrono::steady_clock::now();
}

int main() {
    setlocale(LC_ALL, "");

    initscr();
    raw();
    noecho();
    curs_set(FALSE);
    keypad(stdscr, TRUE);
    nodelay(stdscr, TRUE);

    //set_escdelay(0);

    int h1, w1;
    getmaxyx(stdscr, h1, w1);
    int h = h1/2;
    int w = w1/2;

    struct Bullet {
        int w;
        int h;
        steady_clock_t last_time;
    };
    std::vector<Bullet> bullets;

    int c;
    int z = 0;
    while ('q' != (c = getch())) {
        clear();
        for (Bullet& b : bullets) {
            if ((now() - b.last_time) / 1ms > 300) {
                b.h--;
                b.last_time = now();
            }
            out(b.h, b.w, "\u25cf");
        }
        bullets.erase(
            std::remove_if(bullets.begin(), bullets.end(), [](const Bullet& b) { return b.h < 2; }),
            bullets.end()
        );
        for (int i = 1; i < w1; ++i) {
            out(0, i, "\u2501");
            out(h1-1, i, "\u2501");
        }
        for (int i = 1; i < h1-1; ++i) {
            out(i, 0, "\u2503");
            out(i, w1-1, "\u2503");
        }
        out(0, 0, "\u250f");
        out(0, w1-1, "\u2513");
        out(h1-1, 0, "\u2517");
        out(h1-1, w1-1, "\u251b");

        switch(c) {
        case KEY_LEFT: --w; break;
        case KEY_RIGHT: ++w; break;
        case KEY_UP: --h; break;
        case KEY_DOWN: ++h; break;
        case ' ': bullets.push_back(Bullet{w, h, now()}); break;
        }
        flushinp();
        out(h, w, "\u2588");
        refresh();
    }

    endwin();

    return 0;
}
