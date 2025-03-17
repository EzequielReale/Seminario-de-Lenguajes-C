#ifndef AI_H
#define AI_H 2

#include "const.h"

t_bool has_free_spaces(char[][DIMF]);

t_bool out_of_range(short, short);

void player_move(char[][DIMF]);

void COM_move(char[][DIMF]);

char check_winner(char[][DIMF]);

#endif