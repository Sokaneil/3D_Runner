/*
 * E89 Pedagogical & Technical Lab
 * project:     TP Event
 * created on:  2023-01-20 - 16:16 +0100
 * 1st author:  sokaneil.sieng - sokaneil.sieng
 * description: put pixel
 */

#include <lapin.h> // For all bunny_ things

void stu_set_pixel(t_bunny_pixelarray *px,
                   t_bunny_position *pos,
                   unsigned int color)
{
    int width;
    int height;
    int total;
    int i;
    unsigned int *tmp;

    width = px->clipable.clip_width;
    height = px->clipable.clip_height;
    total = width * height;
    tmp = (unsigned int *)px -> pixels;
    i = (width * pos->y) + pos->x;
    if (i > 0 && i < total) {
        tmp[i] = color;
    }
}

