#ifndef _main_hpp_
#define _main_hpp_

#include <iostream>
#include <chrono>
#include <thread>
#include <pthread.h>
#include <cstdarg>
//#include <string>
#include "picture.hpp"
#include <sstream> 
#include "ai.hpp"
#include "pieces.hpp"
/*extern{
	#include "board.hpp"
}*/
/*	white	black

pawn	100	-100

knight	275	-275

bishop	325	-325

rook	465	-465

queen	900	-900

king	13840	-13840
*/
int SEC_DEEPNESS=1;

int NOPSD = 17;
int NOMSD = 24;

int CHESS_FIELD_WIDTH = 9;
int CHESS_FIELD_HEIGHT = 5;

struct move{
	int old_field;
	int new_field;
};

struct chess_data{
	int pos_mov[150][120];
	int num;
	int deepness;
	int *value;
};

int stored_boards[3][120];

int WHOSE_MOVE;

int HORIZON_DEEPNESS;

int COLOR_R = 400;
int COLOR_G = 400;
int COLOR_B = 400;



int vboard[120]={      //x=0 x=1 x=2 x=3 x=4 x=5 x=6 x=7 x=8 x=9
				-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, //y=0
				-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, //y=1
				-1,  B_ROOK,  B_KNIGHT,  B_BISHOP,  B_QUEEN,  B_KING,  B_BISHOP,  B_KNIGHT,  B_ROOK, -1, //y=2
				-1,  B_PAWN,  B_PAWN,  B_PAWN,  B_PAWN,  B_PAWN,  B_PAWN,  B_PAWN,  B_PAWN, -1, //y=3
				-1,  0,  0,  0,  0,  0,  0,  0,  0, -1, //y=4
				-1,  0,  0,  0,  0,  0,  0,  0,  0, -1, //y=5
				-1,  0,  0,  0,  0,  0,  0,  0,  0, -1, //y=6
				-1,  0,  0,  0,  0,  0,  0,  0,  0, -1, //y=7
				-1,  W_PAWN,  W_PAWN,  W_PAWN,  W_PAWN,  W_PAWN,  W_PAWN,  W_PAWN,  W_PAWN, -1, //y=8
				-1,  W_ROOK,  W_KNIGHT,  W_BISHOP,  W_QUEEN,  W_KING,  W_BISHOP,  W_KNIGHT,  W_ROOK, -1, //y=9
				-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, //y=10
				-1, -1, -1, -1, -1, -1, -1, -1, -1, -1  //y=11
			};
int wboard[120]={      //x=0 x=1 x=2 x=3 x=4 x=5 x=6 x=7 x=8 x=9
				-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, //y=0
				-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, //y=1
				-1,  B_ROOK,  B_KNIGHT,  B_BISHOP,  B_QUEEN,  B_KING,  B_BISHOP,  B_KNIGHT,  B_ROOK, -1, //y=2
				-1,  B_PAWN,  B_PAWN,  B_PAWN,  B_PAWN,  B_PAWN,  B_PAWN,  B_PAWN,  B_PAWN, -1, //y=3
				-1,  0,  0,  0,  0,  0,  0,  0,  0, -1, //y=4
				-1,  0,  0,  0,  0,  0,  0,  0,  0, -1, //y=5
				-1,  0,  0,  0,  0,  0,  0,  0,  0, -1, //y=6
				-1,  0,  0,  0,  0,  0,  0,  0,  0, -1, //y=7
				-1,  W_PAWN,  W_PAWN,  W_PAWN,  W_PAWN,  W_PAWN,  W_PAWN,  W_PAWN,  W_PAWN, -1, //y=8
				-1,  W_ROOK,  W_KNIGHT,  W_BISHOP,  W_QUEEN,  W_KING,  W_BISHOP,  W_KNIGHT,  W_ROOK, -1, //y=9
				-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, //y=10
				-1, -1, -1, -1, -1, -1, -1, -1, -1, -1  //y=11
			};
int xboard[120]={      //x=0 x=1 x=2 x=3 x=4 x=5 x=6 x=7 x=8 x=9
				-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, //y=0
				-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, //y=1
				-1,  B_ROOK,  B_KNIGHT,  B_BISHOP,  B_QUEEN,  B_KING,  B_BISHOP,  B_KNIGHT,  B_ROOK, -1, //y=2
				-1,  B_PAWN,  B_PAWN,  B_PAWN,  B_PAWN,  B_PAWN,  B_PAWN,  B_PAWN,  B_PAWN, -1, //y=3
				-1,  0,  0,  0,  0,  0,  0,  0,  0, -1, //y=4
				-1,  0,  0,  0,  0,  0,  0,  0,  0, -1, //y=5
				-1,  0,  0,  0,  0,  0,  0,  0,  0, -1, //y=6
				-1,  0,  0,  0,  0,  0,  0,  0,  0, -1, //y=7
				-1,  W_PAWN,  W_PAWN,  W_PAWN,  W_PAWN,  W_PAWN,  W_PAWN,  W_PAWN,  W_PAWN, -1, //y=8
				-1,  W_ROOK,  W_KNIGHT,  W_BISHOP,  W_QUEEN,  W_KING,  W_BISHOP,  W_KNIGHT,  W_ROOK, -1, //y=9
				-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, //y=10
				-1, -1, -1, -1, -1, -1, -1, -1, -1, -1  //y=11
			};

/*int board_equal(int a[120], int b[120]){
	for(int i = 0; i<0; i++){
		if(a[i]!=b[i]){
			return 0;
		}
	}
	return 1;
}*/

#endif
