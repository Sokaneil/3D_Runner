/*
 * E89 Pedagogical & Technical Lab
 * project:     TP Laser
 * created on:  2023-01-19 - 15:02 +0100
 * 1st author:  sokaneil.sieng - sokaneil.sieng
 * description: get ratio
 */

float get_ratio(int a, int b, int x)
{
    float ratio;

    ratio = ((float) x - a) / ((float) b - a);
    return ratio;
}
