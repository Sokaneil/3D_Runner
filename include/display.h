/*
 * E89 Pedagogical & Technical Lab
 * project:     runner
 * created on:  2023-03-06 - 09:36 +0100
 * 1st author:  sokaneil.sieng - sokaneil.sieng
 * description: display
 */

#include <lapin.h>
#include "map.h"
#include "player.h"

#ifndef DISPLAY_H_
#define DISPLAY_H_

struct display {
    t_bunny_window *ds_win;
    t_bunny_pixelarray *ds_px;
    struct player player;
    struct map map;
};

#endif
