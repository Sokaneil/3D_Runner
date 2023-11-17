/*
 * E89 Pedagogical & Technical Lab
 * project:     TP laser
 * created on:  2023-01-16 - 15:38 +0100
 * 1st 1author:  sokaneil.sieng - sokaneil.sieng
 * description: convert t_bunny_accurate_position to t_bunny_position
 */

#include <lapin.h>

typedef t_bunny_accurate_position t_accurate_position;

t_bunny_position pos_from_accurate(const t_accurate_position *res)
{
    t_bunny_position convert;

    convert.x = (int) res->x;
    convert.y = (int) res->y;
    return(convert);
}
