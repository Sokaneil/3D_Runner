/*
 * E89 Pedagogical & Technical Lab
 * project:     TP laser
 * created on:  2023-01-18 - 09:38 +0100
 * 1st author:  sokaneil.sieng - sokaneil.sieng
 * description: structure
 */

#include "runner.h"

#ifndef _PLAYER_H_
#define _PLAYER_H_

typedef t_bunny_accurate_position t_accurate_pos;

struct player {
    double angle;
    t_accurate_pos pos;
};

#endif
