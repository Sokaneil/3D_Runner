
/*
 * E89 Pedagogical & Technical Lab
 * project:     runner
 * created on:  2023-03-08 - 14:28 +0100
 * 1st author:  sokaneil.sieng - sokaneil.sieng
 * description: draw map
 */

#include <lapin.h>
#include "runner.h"

void draw_map(void *data)
{
    struct display *ds;
    t_bunny_position pos;

    ds = data;
    pos.x = 0;
    pos.y = 0;
    while (pos.y < (ds->map.height * (ds->map.tile_size / 4))) {
        pos.x = 0;
        while (pos.x < (ds->map.width * (ds->map.tile_size / 4))) {
            if (ds->map.map[(pos.x / (ds->map.tile_size / 4)) +
                            ((pos.y / (ds->map.tile_size / 4))
                             * ds->map.width)] == 0) {
                stu_set_pixel(ds->ds_px, &pos, BLACK);
            } else if (ds->map.map[(pos.x / (ds->map.tile_size / 4)) +
                                   ((pos.y / (ds->map.tile_size / 4)) *
                                    ds->map.width)] == 2) {
                stu_set_pixel(ds->ds_px, &pos, RED);
            }
            pos.x += 1;
        }
        pos.y += 1;
    }
}
