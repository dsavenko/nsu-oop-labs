
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

    if (has_colors() == FALSE) {
        endwin();
        std::cerr << "Your terminal does not support color\n";
        exit(1);
    }
    start_color();

    const int main_color_pair = 1;
    const int player_color_pair = 2;
    const int bullet_color_pair = 3;

    // colors are COLOR_BLACK, COLOR_RED, COLOR_GREEN, COLOR_YELLOW, COLOR_BLUE, COLOR_MAGENTA, COLOR_CYAN, COLOR_WHITE
    init_pair(main_color_pair, COLOR_WHITE, COLOR_BLACK);
    init_pair(player_color_pair, COLOR_YELLOW, COLOR_BLUE);
    init_pair(bullet_color_pair, COLOR_RED, COLOR_BLACK);

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
        attron(COLOR_PAIR(bullet_color_pair));
        for (Bullet& b : bullets) {
            if ((now() - b.last_time) / 1ms > 300) {
                b.h--;
                b.last_time = now();
            }
            out(b.h, b.w, "*");
        }
        attroff(COLOR_PAIR(bullet_color_pair));
        bullets.erase(
            std::remove_if(bullets.begin(), bullets.end(), [](const Bullet& b) { return b.h < 2; }),
            bullets.end()
        );
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

        switch(c) {
        case KEY_LEFT: --w; break;
        case KEY_RIGHT: ++w; break;
        case KEY_UP: --h; break;
        case KEY_DOWN: ++h; break;
        case ' ': bullets.push_back(Bullet{w, h, now()}); break;
        }
        flushinp();
        w = std::clamp(w, 1, w1-2);
        h = std::clamp(h, 1, h1-2);
        attron(COLOR_PAIR(player_color_pair));
        out(h, w, "M");
        attroff(COLOR_PAIR(player_color_pair));
        refresh();
    }

    endwin();

    return 0;
}
