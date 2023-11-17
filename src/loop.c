/*
 * E89 Pedagogical & Technical Lab
 * project:     runner
 * created on:  2023-03-15 - 10:07 +0100
 * 1st author:  sokaneil.sieng - sokaneil.sieng
 * description: manage keys
 */

#include "runner.h"

static void loop_arrow_keys(const bool *keys, struct display *ds)
{
    if (keys[BKS_LEFT]) {
        ds->player.angle -= 5;
    }
    if (keys[BKS_RIGHT]) {
        ds->player.angle += 5;
    }
    if (keys[BKS_UP]) {
        ds->player.pos = move_forward(&ds->player.pos,
                                      deg_to_rads(ds->player.angle),
                                      5);
    }
}

static void loop_keys(const bool *keys, struct display *ds)
{
    if (keys[BKS_W]) {
        ds->player.pos = move_forward(&ds->player.pos,
                                      deg_to_rads(ds->player.angle),
                                      1);
    }
    if (keys[BKS_A]) {
        ds->player.pos = move_forward(&ds->player.pos,
                                      deg_to_rads(ds->player.angle + 270),
                                      1);
    }
    if (keys[BKS_S]) {
        ds->player.pos = move_forward(&ds->player.pos,
                                      deg_to_rads(ds->player.angle + 180),
                                      1);
    }
    if (keys[BKS_D]) {
        ds->player.pos = move_forward(&ds->player.pos,
                                      deg_to_rads(ds->player.angle + 90),
                                      1);
    }
}

t_bunny_response loop(void *data)
{
    struct display *ds;
    t_accurate_pos opos;
    const bool *keys;

    ds = data;
    opos = ds->player.pos;
    keys = bunny_get_keyboard();
    loop_arrow_keys(keys, ds);
    loop_keys(keys, ds);
    if (ds->player.pos.x < 0 || ds->player.pos.y < 0 ||
        ds->map.map[((int)ds->player.pos.x / ds->map.tile_size)
                    + (((int)ds->player.pos.y / ds->map.tile_size)
                            * ds->map.width)] == 1) {
        ds->player.pos = opos;
    }
    if (ds->player.pos.x < 0 || ds->player.pos.y < 0 ||
        ds->map.map[((int)ds->player.pos.x / ds->map.tile_size)
                    + (((int)ds->player.pos.y / ds->map.tile_size)
                            * ds->map.width)] == 2) {
        return (EXIT_ON_SUCCESS);
    }
    draw_background(ds);
    runner_fov(ds);
    draw_player(&opos, ds);
    blit_at_origin(ds);
    return (GO_ON);
}

