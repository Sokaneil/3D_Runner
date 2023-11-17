/*
 * E89 Pedagogical & Technical Lab
 * project:     TP laser
 * created on:  2023-01-18 - 09:38 +0100
 * 1st author:  sokaneil.sieng - sokaneil.sieng
 * description: structure
 */

#ifndef _MAP_H_
#define _MAP_H_

struct map {
    int tile_size;
    int width;
    int height;
    int win_width;
    int win_height;
    unsigned int sky;
    unsigned int floor;
    unsigned int wall;
    int *map;
};

#endif
