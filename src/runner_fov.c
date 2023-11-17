/*
 * E89 Pedagogical & Technical Lab
 * project:     runner
 * created on:  2023-03-16 - 16:28 +0100
 * 1st author:  sokaneil.sieng - sokaneil.sieng
 * description: runner fov
 */

#include "runner.h"

static void create_wall(struct display *ds, int distance, int x)
{
    t_bunny_position pos;
    int n;

    n = 0;
    pos.x = x;
    pos.y = (ds->map.win_height / 2) - (distance / 2);
    while (n != distance) {
        stu_set_pixel(ds->ds_px, &pos, ds->map.wall);
        n += 1;
        pos.y += 1;
    }
}

static double distance(struct display *ds, t_bunny_position pos)
{
    double d;

    d = sqrt(((double)(ds->player.pos.x - pos.x) *
              (double)(ds->player.pos.x - pos.x)) +
             ((double)(ds->player.pos.y - pos.y) *
              (double)(ds->player.pos.y - pos.y)));
    return d;
}

static void draw_wall(struct display *ds,
                      t_accurate_pos res,
                      int wall_px)
{
    t_bunny_position pos;
    double wall;
    int true_wall;

    pos = pos_from_accurate(&res);
    wall = ((ds->map.win_height * 25) / (distance(ds, pos)));
    true_wall = wall;
    if (true_wall > ds->ds_px->clipable.clip_height) {
        true_wall = ds->ds_px->clipable.clip_height - 1;
    }
    create_wall(ds, true_wall, wall_px);
}

void runner_fov(struct display *ds)
{
    double ratio_fov;
    double angle;
    t_accurate_pos res;
    int wall_px;

    wall_px = 0;
    angle = ds->player.angle - 35.0;
    ratio_fov = 70.0 / (double)ds->map.win_width;
    while (wall_px != ds->map.win_width) {
        res = send_ray(ds, &ds->player.pos, angle);
        draw_wall(ds, res, wall_px);
        angle += ratio_fov;
        wall_px += 1;
    }
}
