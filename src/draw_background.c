/*
 * E89 Pedagogical & Technical Lab
 * project:     Runner
 * created on:  2023-04-18 - 09:34 +0200
 * 1st author:  Sokaneil SIeng - sokaneil
 * description: draw background
 */

#include "runner.h"

void draw_background(struct display *ds)
{
    int screen;
    int total;
    unsigned int *screen_point;

    total = ds->map.win_width * ds->map.win_height;
    if (total <= 0) {
        return;
    }
    screen_point = (unsigned int *)ds->ds_px -> pixels;
    screen = 0;
    while (screen <= (total / 2)) {
        screen_point[screen] = ds->map.sky;
        screen += 1;
    }
    while (screen <= total) {
        screen_point[screen] = ds->map.floor;
        screen += 1;
    }
}
