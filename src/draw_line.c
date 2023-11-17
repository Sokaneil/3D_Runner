/*
 * E89 Pedagogical & Technical Lab
 * project:     tp runner
 * created on:  2023-02-20 - 14:31 +0100
 * 1st author:  sokaneil.sieng - sokaneil.sieng
 * description: draw line
 */

#include <lapin.h> // For all bunny_ things
#include "runner.h"

static void check_larger(t_bunny_position *pos,
                         t_bunny_position *b_pos)
{
    int tmp;

    if (pos->x > b_pos->x) {
        tmp = pos->x;
        pos->x = b_pos->x;
        b_pos->x = tmp;
    }
    if (pos->y > b_pos->y) {
        tmp = pos->y;
        pos->y = b_pos->y;
        b_pos->y = tmp;
    }
}

void stu_draw_line(t_bunny_pixelarray *px,
                   t_bunny_position *pos_a,
                   t_bunny_position *pos_b,
                   unsigned int color)
{
    t_bunny_position pos;
    t_bunny_position b_pos;

    pos.x = pos_a->x;
    pos.y = pos_a->y;
    b_pos.x = pos_b->x;
    b_pos.y = pos_b->y;
    check_larger(&pos, &b_pos);
    if ((b_pos.x - pos.x) >= (b_pos.y - pos.y)) {
        while(pos.x < b_pos.x) {
            pos.y = get_value(pos_a->y, pos_b->y,
                              get_ratio(pos_a->x, pos_b->x, pos.x));
            stu_set_pixel(px, &pos, color);
            pos.x += 1;
        }
    } else if ((b_pos.y - pos.y) > (b_pos.x - pos.x)){
        while(pos.y < b_pos.y) {
            pos.x = get_value(pos_a->x, pos_b->x,
                              get_ratio(pos_a->y, pos_b->y, pos.y));
            stu_set_pixel(px, &pos, color);
            pos.y += 1;
        }
    }
}
