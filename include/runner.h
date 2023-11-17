/*
 * E89 Pedagogical & Technical Lab
 * project:     TP laser
 * created on:  2023-01-18 - 09:39 +0100
 * 1st author:  sokaneil.sieng - sokaneil.sieng
 * description: header files
 */

#ifndef RUNNER_H_
#define RUNNER_H_
#include "display.h"
#include <unistd.h>
#include <assert.h>
#include <lapin.h>
#include <math.h>
#include <stdlib.h>

typedef t_bunny_accurate_position t_accurate_pos;

double deg_to_rads(double degrees);
t_accurate_pos move_forward(const t_accurate_pos *start,
                            double angle,
                            double len);
t_bunny_position pos_from_accurate(const t_accurate_pos *);
t_accurate_pos send_ray(struct display *map,
                        const t_accurate_pos *start,
                        double angle);
void draw_impact(struct display *map,
                 t_bunny_pixelarray *pxa,
                 const t_accurate_pos *start,
                 double angle) ;
void stu_set_pixel(t_bunny_pixelarray *px,
                   t_bunny_position *pos,
                   unsigned int color);
void clear_pixelarray(t_bunny_pixelarray *pxa,
                      unsigned int color);
void stu_draw_line(t_bunny_pixelarray *px,
                   t_bunny_position *pos_a,
                   t_bunny_position *pos_b,
                   unsigned int color);
int get_value(int a, int b, float ratio);
float get_ratio(int a, int b, int x);
t_bunny_response my_key_event(t_bunny_event_state state,
                              t_bunny_keysym keycode,
                              void *data);
void blit_at_origin(struct display *ds);
unsigned int mk_colour(unsigned char r,
                       unsigned char g,
                       unsigned char b,
                       unsigned char a);
void draw_map(void *data);
void draw_player(t_accurate_pos *opos, struct display *ds);
t_bunny_response loop(void *data);
void runner_fov(struct display *ds);
void draw_background(struct display *ds);

#endif
