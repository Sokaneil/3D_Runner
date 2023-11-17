/*
 * E89 Pedagogical & Technical Lab
 * project:     runner
 * created on:  2023-03-06 - 09:33 +0100
 * 1st author:  sokaneil.sieng - sokaneil.sieng
 * description: key_event
 */

#include "runner.h"

t_bunny_response my_key_event(t_bunny_event_state state,
                           t_bunny_keysym keycode,
                           void *data)
{
    (void) data;
    if (state == GO_UP) {
        return (GO_ON);
    }
    if (keycode == BKS_ESCAPE) {
        return (EXIT_ON_SUCCESS);
    }
    return (GO_ON);
}
