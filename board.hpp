#ifndef _board_hpp_
#define _board_hpp_


#include "pieces.hpp"

class Board{
public:
	Board();

	~Board();

	int get_field(int x, int y);

	int get_vboard_field(int i);

	int move(int x1, int y1, int x2, int y2);

	void add_to_rboard(int x, int y, int i);	

	void vboard_to_rboard();

	void rboard_to_vboard();

	int *get_vboard();

	void flip_board();

	void set_vboard_field(int i, int content);

	void undo();

private:
	int vboard[120]={      //x=0 x=1 x=2 x=3 x=4 x=5 x=6 x=7 x=8 x=9
				-3, -3, -1, -1, -3, -1, -1, -1, -1, -1, //y=0
				-3, -3, -1, -1, -1, -1, -1, -1, -1, -1, //y=1
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

	int vboard1[120]={      //x=0 x=1 x=2 x=3 x=4 x=5 x=6 x=7 x=8 x=9
				-3, -3, -1, -1, -3, -1, -1, -1, -1, -1, //y=0
				-3, -3, -1, -1, -1, -1, -1, -1, -1, -1, //y=1
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
	int vboard2[120]={      //x=0 x=1 x=2 x=3 x=4 x=5 x=6 x=7 x=8 x=9
				-3, -3, -1, -1, -3, -1, -1, -1, -1, -1, //y=0
				-3, -3, -1, -1, -1, -1, -1, -1, -1, -1, //y=1
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

	int rboard[64];
};

#endif
