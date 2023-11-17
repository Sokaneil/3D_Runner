/*
 * E89 Pedagogical & Technical Lab
 * project:     TP Laser
 * created on:  2023-01-19 - 15:03 +0100
 * 1st author:  sokaneil.sieng - sokaneil.sieng
 * description: get value
 */

int get_value(int a, int b, float ratio)
{
    int value;

    value = ratio*((float) b - a) +(float) a;
    return (value);
}
