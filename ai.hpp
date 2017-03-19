#ifndef _ai_hpp_
#define _ai_hpp_

#include "move_gen.hpp"

extern int HORIZON_DEEPNESS;

int explore_one_move_for_white(int pos_mov[150][120], int num, int deepness, int *alpha);

int explore_one_move_for_black(int pos_mov[150][120], int num, int deepness, int *alpha);

int valuation(int vboard[120]);

#endif
