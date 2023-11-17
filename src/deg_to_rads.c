/*
 * E89 Pedagogical & Technical Lab
 * project:     tp_sphere
 * created on:  2023-01-12 - 15:03 +0100
 * 1st author:  sokaneil.sieng - sokaneil.sieng
 * description: degs to rads
 */

#include <lapin.h>

double deg_to_rads(double degrees)
{
    double radian;

    radian = degrees * ((double)M_PI / 180.0);
    return (radian);
}
