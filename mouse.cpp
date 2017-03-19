#include "mouse.hpp"


int MOUSE_X_POS = 0;
int MOUSE_Y_POS = 0;
int MOUSE_X_POS_COUNTER = 0;
int MOUSE_Y_POS_COUNTER = 0;
int MOUSE_X_FIELD = 0;
int MOUSE_Y_FIELD = 0;
int MOUSE_L_BUTTON = 0;
int MOUSE_M_BUTTON = 0;
int MOUSE_R_BUTTON = 0;

#define MAX_COUNTER 3


void mouse_update(){
	get_mice();
	
	MOUSE_L_BUTTON = mice_data[0] & 0x1;
	MOUSE_R_BUTTON = mice_data[0] & 0x2;
	MOUSE_M_BUTTON = mice_data[0] & 0x4;

	if(mice_data[1]>1){
		mice_data[1]/=2;
	}
	if(mice_data[2]>1){
		mice_data[2]/=2;
	}

	MOUSE_X_POS_COUNTER+=mice_data[1];
	MOUSE_Y_POS_COUNTER-=mice_data[2];

	if(MOUSE_X_POS_COUNTER>=MAX_COUNTER){
		MOUSE_X_POS++;
		MOUSE_X_POS_COUNTER=0;
	}
	if(MOUSE_Y_POS_COUNTER>=MAX_COUNTER){
		MOUSE_Y_POS++;
		MOUSE_Y_POS_COUNTER=0;
	}
	if(MOUSE_X_POS_COUNTER<=-MAX_COUNTER){
		MOUSE_X_POS--;
		MOUSE_X_POS_COUNTER=0;
	}
	if(MOUSE_Y_POS_COUNTER<=-MAX_COUNTER){
		MOUSE_Y_POS--;
		MOUSE_Y_POS_COUNTER=0;
	}

	if(MOUSE_X_POS < 72){
		MOUSE_X_FIELD = MOUSE_X_POS/9;
	}
	else{
		MOUSE_X_FIELD = -1;
	}

	if(MOUSE_Y_POS < 40){
		MOUSE_Y_FIELD = MOUSE_Y_POS/5;
	}
	else{
		MOUSE_Y_FIELD = -1;
	}
}

void mouse_open(){
	open_mice();
}

void mouse_close(){
	close_mice();
}













