/*
 * E89 Pedagogical & Technical Lab
 * project:     TP Laser
 * created on:  2023-01-18 - 09:36 +0100
 * 1st author:  sokaneil.sieng - sokaneil.sieng
 * description: send ray
 */

#include <lapin.h>
#include "runner.h"
#include <stdio.h>

t_accurate_pos send_ray(struct display *map,
                        const t_accurate_pos *start,
                        double angle)
{
    t_accurate_pos a_pos;
    t_bunny_position pos;

    a_pos.x = start->x;
    a_pos.y = start->y;
    angle = deg_to_rads(angle);
    while (a_pos.x > 0 && a_pos.x / map->map.tile_size < map->map.width
           && a_pos.y > 0 && a_pos.y / map->map.tile_size < map->map.height) {
        a_pos = move_forward(&a_pos, angle, 0.5);
        pos = pos_from_accurate(&a_pos);
        if (map->map.map[(pos.x / map->map.tile_size)
                         + ((pos.y / map->map.tile_size)
                            * map->map.width)] == 1) {
            return(a_pos);
        }
    }
    return(a_pos);
}
