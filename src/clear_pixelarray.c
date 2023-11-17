/*
 * E89 Pedagogical & Technical Lab
 * project:     TP Event
 * created on:  2023-01-20 - 16:15 +0100
 * 1st author:  sokaneil.sieng - sokaneil.sieng
 * description: clear_pixelarray
 */

#include <lapin.h>

void clear_pixelarray(t_bunny_pixelarray *pxa,
                      unsigned int color)
{
    int width;
    int height;
    int total;
    unsigned int *tmp;
    int i;

    width = pxa->clipable.clip_height;
    height = pxa->clipable.clip_width;
    total = width * height;
    tmp = (unsigned int *)pxa -> pixels;
    i = 0;
    while (i <= total) {
        tmp [i] = color;
        i = i + 1;
    }
}
