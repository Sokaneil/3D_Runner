/*
 * E89 Pedagogical & Technical Lab
 * project:     runner
 * created on:  2023-03-06 - 09:40 +0100
 * 1st author:  sokaneil.sieng - sokaneil.sieng
 * description: main
 */

#include "runner.h"
#include <lapin.h>

int map[15 * 15] = {
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 0, 1, 1, 0, 1, 0, 0, 1, 0, 0, 0, 1, 0, 1,
        1, 0, 1, 1, 0, 1, 0, 1, 1, 0, 1, 0, 0, 0, 1,
        1, 0, 0, 0, 0, 1, 0, 1, 1, 0, 1, 0, 1, 0, 1,
        1, 1, 0, 1, 0, 1, 0, 0, 0, 0, 1, 0, 1, 0, 1,
        1, 1, 0, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1,
        1, 1, 0, 1, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1,
        1, 0, 0, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 1,
        1, 0, 1, 1, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1,
        1, 1, 1, 0, 0, 1, 1, 0, 1, 0, 1, 0, 1, 1, 1,
        1, 0, 0, 0, 1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1,
        1, 1, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1,
        1, 0, 0, 0, 1, 0, 0, 0, 1, 1, 1, 0, 1, 0, 1,
        1, 0, 1, 1, 1, 0, 1, 0, 0, 0, 1, 1, 1, 2, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    };

static void configuration(struct display *ds)
{
    ds->map.width     = 15;
    ds->map.height    = 15;
    ds->map.tile_size = 50;
    ds->map.win_width = ds->map.width * ds->map.tile_size;
    ds->map.win_height= ds->map.height * ds->map.tile_size;
    ds->map.sky       = mk_colour(0, 191, 255, 255);
    ds->map.floor     = mk_colour(98, 47, 34, 255);;
    ds->map.wall      = mk_colour(128, 128, 128, 255);
    ds->map.map       = &map[0];
    ds->player.pos.x  = 75;
    ds->player.pos.y  = 75;
    ds->player.angle  = 0;
}

int main(void)
{
    struct display ds;

    configuration(&ds);
    ds.ds_win    = bunny_start(ds.map.win_width,
                               ds.map.win_height,
                               false,
                               "fl: Projet Runner");
    ds.ds_px = bunny_new_pixelarray(ds.ds_win->buffer.width,
                                    ds.ds_win->buffer.height);
    bunny_set_key_response(my_key_event);
    bunny_set_loop_main_function(loop);
    blit_at_origin(&ds);
    bunny_loop(ds.ds_win, 60, &ds);
    bunny_delete_clipable(&ds.ds_px->clipable);
    bunny_stop(ds.ds_win);
    write(1, "YOU WON, CONGRATS!!!\n", 21);
    return (0);
}
