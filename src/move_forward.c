/*
 * E89 Pedagogical & Technical Lab
 * project:     TP Laser
 * created on:  2023-01-16 - 10:50 +0100
 * 1st author:  sokaneil.sieng - sokaneil.sieng
 * description: moving forward
 */

#include <lapin.h>
#include <math.h>

typedef t_bunny_accurate_position t_accurate_pos;

t_accurate_pos move_forward(const t_accurate_pos *start,
                            double angle,
                            double len)
{
    t_accurate_pos pos;

    pos.x = (cos(angle) * len) + start->x;
    pos.y = (sin(angle) * len) + start->y;
    return(pos);
}
