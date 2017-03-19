#ifndef _mouse_hpp_
#define _mouse_hpp_

#include "mice.h"

extern int MOUSE_X_POS;
extern int MOUSE_Y_POS;

extern int MOUSE_X_FIELD;
extern int MOUSE_Y_FIELD;

extern int MOUSE_L_BUTTON;
extern int MOUSE_M_BUTTON;
extern int MOUSE_R_BUTTON;

void mouse_update();

void mouse_open();

void mouse_close();

#endif
