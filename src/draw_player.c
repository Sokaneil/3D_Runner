/*
 * E89 Pedagogical & Technical Lab
 * project:     runner
 * created on:  2023-03-15 - 10:58 +0100
 * 1st author:  sokaneil.sieng - sokaneil.sieng
 * description: draw player
 */

#include "runner.h"

void draw_player(t_accurate_pos *opos, struct display *ds)
{
    t_bunny_position pos;

    if (ds->map.map[((int) ds->player.pos.x / ds->map.tile_size) +
                    ((int) (ds->player.pos.y / ds->map.tile_size)
                     * ds->map.width)] == 1) {
        ds->player.pos = *opos;
    }
    pos = pos_from_accurate(&ds->player.pos);
    draw_map(ds);
    pos.x /= 4;
    pos.y /= 4;
    stu_set_pixel(ds->ds_px, &pos, RED);
    blit_at_origin(ds);
}
