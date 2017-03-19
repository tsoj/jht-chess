#include "picture.hpp"

extern int CHESS_FIELD_WIDTH;
extern int CHESS_FIELD_HEIGHT;



const unsigned char knight[] =  { "  ___'    /   o\\   \\   \\_>  /___\\            " };

const unsigned char bishop[] =  { "    o       ( )      / \\     /___\\           " };

const unsigned char rook[] =  { "  ^-^-^    \\   /    |   |    |___|           " };

const unsigned char queen[] =  { "  ooooo     \\ /      ( )      / \\     /___\\  " };

const unsigned char king[] =  { "    +       \\ /      / \\      \\ /      /_\\   " };

const unsigned char pawn[] =  { "             o       ( )      |_|            " };




Picture::Picture(){
	width_ = COLS;
	height_ = LINES;
	picture_b_piece = new unsigned char[width_*height_];
	picture_w_piece = new unsigned char[width_*height_];
	picture_mouse = new unsigned char[width_*height_];
	for(int i = 0; i < height_; i++){
		for(int j = 0 ; j < width_; j++){
			picture_b_piece[width_*i+j] = ' ';
			picture_w_piece[width_*i+j] = ' ';
			picture_mouse[width_*i+j] = ' ';
		}
	}
}

Picture::~Picture(){
}

void Picture::add_b_pixel(int width, int height, unsigned char c){
	picture_b_piece[width_*height+width] = c;
}

void Picture::add_w_pixel(int width, int height, unsigned char c){
	picture_w_piece[width_*height+width] = c;
}

void Picture::add_mouse_pixel(int width, int height, unsigned char c){
	picture_mouse[width_*height+width] = c;
}

void Picture::build_pic(Board board, int move_cont){

	for(int i = 0; i<8; i++){
		for(int j = 0; j<8; j++){
			for(int k = 0; k<CHESS_FIELD_WIDTH; k++){
				for(int l = 0; l<CHESS_FIELD_HEIGHT; l++){
					add_b_pixel( (k+j*CHESS_FIELD_WIDTH), (l+i*CHESS_FIELD_HEIGHT), ' ' );
					add_w_pixel( (k+j*CHESS_FIELD_WIDTH), (l+i*CHESS_FIELD_HEIGHT), ' ' );
				}
			}
			if(board.get_field(j, i)==W_KNIGHT){
				for(int k = 0; k<CHESS_FIELD_WIDTH; k++){
					for(int l = 0; l<CHESS_FIELD_HEIGHT; l++){
						add_w_pixel( (k+j*CHESS_FIELD_WIDTH), (l+i*CHESS_FIELD_HEIGHT), knight[k+l*CHESS_FIELD_WIDTH] );
					}
				}
			}
			else if(board.get_field(j, i)==B_KNIGHT){
				for(int k = 0; k<CHESS_FIELD_WIDTH; k++){
					for(int l = 0; l<CHESS_FIELD_HEIGHT; l++){
						add_b_pixel( (k+j*CHESS_FIELD_WIDTH), (l+i*CHESS_FIELD_HEIGHT), knight[k+l*CHESS_FIELD_WIDTH] );
					}
				}
			}
			else if(board.get_field(j, i)==W_BISHOP){
				for(int k = 0; k<CHESS_FIELD_WIDTH; k++){
					for(int l = 0; l<CHESS_FIELD_HEIGHT; l++){
						add_w_pixel( (k+j*CHESS_FIELD_WIDTH), (l+i*CHESS_FIELD_HEIGHT), bishop[k+l*CHESS_FIELD_WIDTH] );
					}
				}
			}
			else if(board.get_field(j, i)==B_BISHOP){
				for(int k = 0; k<CHESS_FIELD_WIDTH; k++){
					for(int l = 0; l<CHESS_FIELD_HEIGHT; l++){
						add_b_pixel( (k+j*CHESS_FIELD_WIDTH), (l+i*CHESS_FIELD_HEIGHT), bishop[k+l*CHESS_FIELD_WIDTH] );
					}
				}
			}
			else if(board.get_field(j, i)==W_ROOK){
				for(int k = 0; k<CHESS_FIELD_WIDTH; k++){
					for(int l = 0; l<CHESS_FIELD_HEIGHT; l++){
						add_w_pixel( (k+j*CHESS_FIELD_WIDTH), (l+i*CHESS_FIELD_HEIGHT), rook[k+l*CHESS_FIELD_WIDTH] );
					}
				}
			}
			else if(board.get_field(j, i)==B_ROOK){
				for(int k = 0; k<CHESS_FIELD_WIDTH; k++){
					for(int l = 0; l<CHESS_FIELD_HEIGHT; l++){
						add_b_pixel( (k+j*CHESS_FIELD_WIDTH), (l+i*CHESS_FIELD_HEIGHT), rook[k+l*CHESS_FIELD_WIDTH] );
					}
				}
			}
			else if(board.get_field(j, i)==W_QUEEN){
				for(int k = 0; k<CHESS_FIELD_WIDTH; k++){
					for(int l = 0; l<CHESS_FIELD_HEIGHT; l++){
						add_w_pixel( (k+j*CHESS_FIELD_WIDTH), (l+i*CHESS_FIELD_HEIGHT), queen[k+l*CHESS_FIELD_WIDTH] );
					}
				}
			}
			else if(board.get_field(j, i)==B_QUEEN){
				for(int k = 0; k<CHESS_FIELD_WIDTH; k++){
					for(int l = 0; l<CHESS_FIELD_HEIGHT; l++){
						add_b_pixel( (k+j*CHESS_FIELD_WIDTH), (l+i*CHESS_FIELD_HEIGHT), queen[k+l*CHESS_FIELD_WIDTH] );
					}
				}
			}
			else if(board.get_field(j, i)==W_KING){
				for(int k = 0; k<CHESS_FIELD_WIDTH; k++){
					for(int l = 0; l<CHESS_FIELD_HEIGHT; l++){
						add_w_pixel( (k+j*CHESS_FIELD_WIDTH), (l+i*CHESS_FIELD_HEIGHT), king[k+l*CHESS_FIELD_WIDTH] );
					}
				}
			}
			else if(board.get_field(j, i)==B_KING){
				for(int k = 0; k<CHESS_FIELD_WIDTH; k++){
					for(int l = 0; l<CHESS_FIELD_HEIGHT; l++){
						add_b_pixel( (k+j*CHESS_FIELD_WIDTH), (l+i*CHESS_FIELD_HEIGHT), king[k+l*CHESS_FIELD_WIDTH] );
					}
				}
			}
			else if(board.get_field(j, i)==W_PAWN){
				for(int k = 0; k<CHESS_FIELD_WIDTH; k++){
					for(int l = 0; l<CHESS_FIELD_HEIGHT; l++){
						add_w_pixel( (k+j*CHESS_FIELD_WIDTH), (l+i*CHESS_FIELD_HEIGHT), pawn[k+l*CHESS_FIELD_WIDTH] );
					}
				}
			}
			else if(board.get_field(j, i)==B_PAWN){
				for(int k = 0; k<CHESS_FIELD_WIDTH; k++){
					for(int l = 0; l<CHESS_FIELD_HEIGHT; l++){
						add_b_pixel( (k+j*CHESS_FIELD_WIDTH), (l+i*CHESS_FIELD_HEIGHT), pawn[k+l*CHESS_FIELD_WIDTH] );
					}
				}
			}
		}
	}
	
	if(move_cont==B_KNIGHT){
		for(int k = 0; k<CHESS_FIELD_WIDTH; k++){
			for(int l = 0; l<CHESS_FIELD_HEIGHT; l++){
				add_b_pixel( (k+MOUSE_X_FIELD*CHESS_FIELD_WIDTH), (l+MOUSE_Y_FIELD*CHESS_FIELD_HEIGHT), knight[k+l*CHESS_FIELD_WIDTH] );
				add_w_pixel( (k+MOUSE_X_FIELD*CHESS_FIELD_WIDTH), (l+MOUSE_Y_FIELD*CHESS_FIELD_HEIGHT), ' ' );
			}
		}
	}
	else if(move_cont==W_KNIGHT){
		for(int k = 0; k<CHESS_FIELD_WIDTH; k++){
			for(int l = 0; l<CHESS_FIELD_HEIGHT; l++){
				add_w_pixel( (k+MOUSE_X_FIELD*CHESS_FIELD_WIDTH), (l+MOUSE_Y_FIELD*CHESS_FIELD_HEIGHT), knight[k+l*CHESS_FIELD_WIDTH] );
				add_b_pixel( (k+MOUSE_X_FIELD*CHESS_FIELD_WIDTH), (l+MOUSE_Y_FIELD*CHESS_FIELD_HEIGHT), ' ' );
			}
		}
	}
	else if(move_cont==B_BISHOP){
		for(int k = 0; k<CHESS_FIELD_WIDTH; k++){
			for(int l = 0; l<CHESS_FIELD_HEIGHT; l++){
				add_b_pixel( (k+MOUSE_X_FIELD*CHESS_FIELD_WIDTH), (l+MOUSE_Y_FIELD*CHESS_FIELD_HEIGHT), bishop[k+l*CHESS_FIELD_WIDTH] );
				add_w_pixel( (k+MOUSE_X_FIELD*CHESS_FIELD_WIDTH), (l+MOUSE_Y_FIELD*CHESS_FIELD_HEIGHT), ' ' );
			}
		}
	}
	else if(move_cont==W_BISHOP){
		for(int k = 0; k<CHESS_FIELD_WIDTH; k++){
			for(int l = 0; l<CHESS_FIELD_HEIGHT; l++){
				add_w_pixel( (k+MOUSE_X_FIELD*CHESS_FIELD_WIDTH), (l+MOUSE_Y_FIELD*CHESS_FIELD_HEIGHT), bishop[k+l*CHESS_FIELD_WIDTH] );
				add_b_pixel( (k+MOUSE_X_FIELD*CHESS_FIELD_WIDTH), (l+MOUSE_Y_FIELD*CHESS_FIELD_HEIGHT), ' ' );
			}
		}
	}
	else if(move_cont==B_ROOK){
		for(int k = 0; k<CHESS_FIELD_WIDTH; k++){
			for(int l = 0; l<CHESS_FIELD_HEIGHT; l++){
				add_b_pixel( (k+MOUSE_X_FIELD*CHESS_FIELD_WIDTH), (l+MOUSE_Y_FIELD*CHESS_FIELD_HEIGHT), rook[k+l*CHESS_FIELD_WIDTH] );
				add_w_pixel( (k+MOUSE_X_FIELD*CHESS_FIELD_WIDTH), (l+MOUSE_Y_FIELD*CHESS_FIELD_HEIGHT), ' ' );
			}
		}
	}
	else if(move_cont==W_ROOK){
		for(int k = 0; k<CHESS_FIELD_WIDTH; k++){
			for(int l = 0; l<CHESS_FIELD_HEIGHT; l++){
				add_w_pixel( (k+MOUSE_X_FIELD*CHESS_FIELD_WIDTH), (l+MOUSE_Y_FIELD*CHESS_FIELD_HEIGHT), rook[k+l*CHESS_FIELD_WIDTH] );
				add_b_pixel( (k+MOUSE_X_FIELD*CHESS_FIELD_WIDTH), (l+MOUSE_Y_FIELD*CHESS_FIELD_HEIGHT), ' ' );
			}
		}
	}
	else if(move_cont==B_QUEEN){
		for(int k = 0; k<CHESS_FIELD_WIDTH; k++){
			for(int l = 0; l<CHESS_FIELD_HEIGHT; l++){
				add_b_pixel( (k+MOUSE_X_FIELD*CHESS_FIELD_WIDTH), (l+MOUSE_Y_FIELD*CHESS_FIELD_HEIGHT), queen[k+l*CHESS_FIELD_WIDTH] );
				add_w_pixel( (k+MOUSE_X_FIELD*CHESS_FIELD_WIDTH), (l+MOUSE_Y_FIELD*CHESS_FIELD_HEIGHT), ' ' );
			}
		}
	}
	else if(move_cont==W_QUEEN){
		for(int k = 0; k<CHESS_FIELD_WIDTH; k++){
			for(int l = 0; l<CHESS_FIELD_HEIGHT; l++){
				add_w_pixel( (k+MOUSE_X_FIELD*CHESS_FIELD_WIDTH), (l+MOUSE_Y_FIELD*CHESS_FIELD_HEIGHT), queen[k+l*CHESS_FIELD_WIDTH] );
				add_b_pixel( (k+MOUSE_X_FIELD*CHESS_FIELD_WIDTH), (l+MOUSE_Y_FIELD*CHESS_FIELD_HEIGHT), ' ' );
			}
		}
	}
	else if(move_cont==B_KING){
		for(int k = 0; k<CHESS_FIELD_WIDTH; k++){
			for(int l = 0; l<CHESS_FIELD_HEIGHT; l++){
				add_b_pixel( (k+MOUSE_X_FIELD*CHESS_FIELD_WIDTH), (l+MOUSE_Y_FIELD*CHESS_FIELD_HEIGHT), king[k+l*CHESS_FIELD_WIDTH] );
				add_w_pixel( (k+MOUSE_X_FIELD*CHESS_FIELD_WIDTH), (l+MOUSE_Y_FIELD*CHESS_FIELD_HEIGHT), ' ' );
			}
		}
	}
	else if(move_cont==W_KING){
		for(int k = 0; k<CHESS_FIELD_WIDTH; k++){
			for(int l = 0; l<CHESS_FIELD_HEIGHT; l++){
				add_w_pixel( (k+MOUSE_X_FIELD*CHESS_FIELD_WIDTH), (l+MOUSE_Y_FIELD*CHESS_FIELD_HEIGHT), king[k+l*CHESS_FIELD_WIDTH] );
				add_b_pixel( (k+MOUSE_X_FIELD*CHESS_FIELD_WIDTH), (l+MOUSE_Y_FIELD*CHESS_FIELD_HEIGHT), ' ' );
			}
		}
	}
	else if(move_cont==B_PAWN){
		for(int k = 0; k<CHESS_FIELD_WIDTH; k++){
			for(int l = 0; l<CHESS_FIELD_HEIGHT; l++){
				add_b_pixel( (k+MOUSE_X_FIELD*CHESS_FIELD_WIDTH), (l+MOUSE_Y_FIELD*CHESS_FIELD_HEIGHT), pawn[k+l*CHESS_FIELD_WIDTH] );
				add_w_pixel( (k+MOUSE_X_FIELD*CHESS_FIELD_WIDTH), (l+MOUSE_Y_FIELD*CHESS_FIELD_HEIGHT), ' ' );
			}
		}
	}
	if(move_cont==W_PAWN){
		for(int k = 0; k<CHESS_FIELD_WIDTH; k++){
			for(int l = 0; l<CHESS_FIELD_HEIGHT; l++){
				add_w_pixel( (k+MOUSE_X_FIELD*CHESS_FIELD_WIDTH), (l+MOUSE_Y_FIELD*CHESS_FIELD_HEIGHT), pawn[k+l*CHESS_FIELD_WIDTH] );
				add_b_pixel( (k+MOUSE_X_FIELD*CHESS_FIELD_WIDTH), (l+MOUSE_Y_FIELD*CHESS_FIELD_HEIGHT), ' ' );
			}
		}
	}


	init_pair(1, COLOR_BLACK, COLOR_RED); //black piece on red field
	init_pair(2, COLOR_BLACK, COLOR_WHITE); // black piece on grey field
	init_pair(3, COLOR_GREEN, COLOR_RED); //white piece on red field
	init_pair(4, COLOR_GREEN, COLOR_WHITE); // white piece on grey field
	init_pair(5, COLOR_GREEN, COLOR_BLUE); //rest, white on blue

	int wcol = 0;
	move(0,0);
	for(int i = 0; i<height_; i++){
		for(int j = 0; j<width_; j++){

			//check if there should be a red or a grey backgroundcolor
			if(i%(CHESS_FIELD_HEIGHT*2)<CHESS_FIELD_HEIGHT){
				if(j%(CHESS_FIELD_WIDTH*2)<CHESS_FIELD_WIDTH){
					wcol=2;
				}				
				else if(j%(CHESS_FIELD_WIDTH*2)>=CHESS_FIELD_WIDTH){
					wcol=1;
				}
			}
			else if(i%(CHESS_FIELD_HEIGHT*2)>=CHESS_FIELD_HEIGHT){
				if(j%(CHESS_FIELD_WIDTH*2)>=CHESS_FIELD_WIDTH){
					wcol=2;
				}
				else if(j%(CHESS_FIELD_WIDTH*2)<CHESS_FIELD_WIDTH){
					wcol=1;
				}
			}

			if(picture_mouse[i*width_+j] != ' '){
				if(i<CHESS_FIELD_HEIGHT*8 && j < CHESS_FIELD_WIDTH*8){
					attron(COLOR_PAIR(wcol+2));
				}
				else{
					attron(COLOR_PAIR(5));
				}
				printw("%c", picture_mouse[i*width_+j]);
			}
			else if(picture_b_piece[i*width_+j] != ' ' && i<CHESS_FIELD_HEIGHT*8 && j<CHESS_FIELD_WIDTH*8){
				attron(COLOR_PAIR(wcol));
				printw("%c", picture_b_piece[i*width_+j]);
			}
			else if(i<CHESS_FIELD_HEIGHT*8 && j < CHESS_FIELD_WIDTH*8){
				attron(COLOR_PAIR(wcol+2));
				printw("%c", picture_w_piece[i*width_+j]);
			}
			else{
				attron(COLOR_PAIR(5));
				printw("%c", picture_mouse[i*width_+j]);
			}
		}
	}
	refresh();
}
void Picture::build_pic_flipped(Board board, int move_cont){

	
	Board board_temp = board;

	board_temp.flip_board();

	for(int i = 0; i<8; i++){
		for(int j = 0; j<8; j++){
			for(int k = 0; k<CHESS_FIELD_WIDTH; k++){
				for(int l = 0; l<CHESS_FIELD_HEIGHT; l++){
					add_b_pixel( (k+j*CHESS_FIELD_WIDTH), (l+i*CHESS_FIELD_HEIGHT), ' ' );
					add_w_pixel( (k+j*CHESS_FIELD_WIDTH), (l+i*CHESS_FIELD_HEIGHT), ' ' );
				}
			}
			if(board_temp.get_field(j, i)==W_KNIGHT){
				for(int k = 0; k<CHESS_FIELD_WIDTH; k++){
					for(int l = 0; l<CHESS_FIELD_HEIGHT; l++){
						add_w_pixel( (k+j*CHESS_FIELD_WIDTH), (l+i*CHESS_FIELD_HEIGHT), knight[k+l*CHESS_FIELD_WIDTH] );
					}
				}
			}
			else if(board_temp.get_field(j, i)==B_KNIGHT){
				for(int k = 0; k<CHESS_FIELD_WIDTH; k++){
					for(int l = 0; l<CHESS_FIELD_HEIGHT; l++){
						add_b_pixel( (k+j*CHESS_FIELD_WIDTH), (l+i*CHESS_FIELD_HEIGHT), knight[k+l*CHESS_FIELD_WIDTH] );
					}
				}
			}
			else if(board_temp.get_field(j, i)==W_BISHOP){
				for(int k = 0; k<CHESS_FIELD_WIDTH; k++){
					for(int l = 0; l<CHESS_FIELD_HEIGHT; l++){
						add_w_pixel( (k+j*CHESS_FIELD_WIDTH), (l+i*CHESS_FIELD_HEIGHT), bishop[k+l*CHESS_FIELD_WIDTH] );
					}
				}
			}
			else if(board_temp.get_field(j, i)==B_BISHOP){
				for(int k = 0; k<CHESS_FIELD_WIDTH; k++){
					for(int l = 0; l<CHESS_FIELD_HEIGHT; l++){
						add_b_pixel( (k+j*CHESS_FIELD_WIDTH), (l+i*CHESS_FIELD_HEIGHT), bishop[k+l*CHESS_FIELD_WIDTH] );
					}
				}
			}
			else if(board_temp.get_field(j, i)==W_ROOK){
				for(int k = 0; k<CHESS_FIELD_WIDTH; k++){
					for(int l = 0; l<CHESS_FIELD_HEIGHT; l++){
						add_w_pixel( (k+j*CHESS_FIELD_WIDTH), (l+i*CHESS_FIELD_HEIGHT), rook[k+l*CHESS_FIELD_WIDTH] );
					}
				}
			}
			else if(board_temp.get_field(j, i)==B_ROOK){
				for(int k = 0; k<CHESS_FIELD_WIDTH; k++){
					for(int l = 0; l<CHESS_FIELD_HEIGHT; l++){
						add_b_pixel( (k+j*CHESS_FIELD_WIDTH), (l+i*CHESS_FIELD_HEIGHT), rook[k+l*CHESS_FIELD_WIDTH] );
					}
				}
			}
			else if(board_temp.get_field(j, i)==W_QUEEN){
				for(int k = 0; k<CHESS_FIELD_WIDTH; k++){
					for(int l = 0; l<CHESS_FIELD_HEIGHT; l++){
						add_w_pixel( (k+j*CHESS_FIELD_WIDTH), (l+i*CHESS_FIELD_HEIGHT), queen[k+l*CHESS_FIELD_WIDTH] );
					}
				}
			}
			else if(board_temp.get_field(j, i)==B_QUEEN){
				for(int k = 0; k<CHESS_FIELD_WIDTH; k++){
					for(int l = 0; l<CHESS_FIELD_HEIGHT; l++){
						add_b_pixel( (k+j*CHESS_FIELD_WIDTH), (l+i*CHESS_FIELD_HEIGHT), queen[k+l*CHESS_FIELD_WIDTH] );
					}
				}
			}
			else if(board_temp.get_field(j, i)==W_KING){
				for(int k = 0; k<CHESS_FIELD_WIDTH; k++){
					for(int l = 0; l<CHESS_FIELD_HEIGHT; l++){
						add_w_pixel( (k+j*CHESS_FIELD_WIDTH), (l+i*CHESS_FIELD_HEIGHT), king[k+l*CHESS_FIELD_WIDTH] );
					}
				}
			}
			else if(board_temp.get_field(j, i)==B_KING){
				for(int k = 0; k<CHESS_FIELD_WIDTH; k++){
					for(int l = 0; l<CHESS_FIELD_HEIGHT; l++){
						add_b_pixel( (k+j*CHESS_FIELD_WIDTH), (l+i*CHESS_FIELD_HEIGHT), king[k+l*CHESS_FIELD_WIDTH] );
					}
				}
			}
			else if(board_temp.get_field(j, i)==W_PAWN){
				for(int k = 0; k<CHESS_FIELD_WIDTH; k++){
					for(int l = 0; l<CHESS_FIELD_HEIGHT; l++){
						add_w_pixel( (k+j*CHESS_FIELD_WIDTH), (l+i*CHESS_FIELD_HEIGHT), pawn[k+l*CHESS_FIELD_WIDTH] );
					}
				}
			}
			else if(board_temp.get_field(j, i)==B_PAWN){
				for(int k = 0; k<CHESS_FIELD_WIDTH; k++){
					for(int l = 0; l<CHESS_FIELD_HEIGHT; l++){
						add_b_pixel( (k+j*CHESS_FIELD_WIDTH), (l+i*CHESS_FIELD_HEIGHT), pawn[k+l*CHESS_FIELD_WIDTH] );
					}
				}
			}
		}
	}
	
	if(move_cont==B_KNIGHT){
		for(int k = 0; k<CHESS_FIELD_WIDTH; k++){
			for(int l = 0; l<CHESS_FIELD_HEIGHT; l++){
				add_b_pixel( (k+MOUSE_X_FIELD*CHESS_FIELD_WIDTH), (l+MOUSE_Y_FIELD*CHESS_FIELD_HEIGHT), knight[k+l*CHESS_FIELD_WIDTH] );
				add_w_pixel( (k+MOUSE_X_FIELD*CHESS_FIELD_WIDTH), (l+MOUSE_Y_FIELD*CHESS_FIELD_HEIGHT), ' ' );
			}
		}
	}
	else if(move_cont==W_KNIGHT){
		for(int k = 0; k<CHESS_FIELD_WIDTH; k++){
			for(int l = 0; l<CHESS_FIELD_HEIGHT; l++){
				add_w_pixel( (k+MOUSE_X_FIELD*CHESS_FIELD_WIDTH), (l+MOUSE_Y_FIELD*CHESS_FIELD_HEIGHT), knight[k+l*CHESS_FIELD_WIDTH] );
				add_b_pixel( (k+MOUSE_X_FIELD*CHESS_FIELD_WIDTH), (l+MOUSE_Y_FIELD*CHESS_FIELD_HEIGHT), ' ' );
			}
		}
	}
	else if(move_cont==B_BISHOP){
		for(int k = 0; k<CHESS_FIELD_WIDTH; k++){
			for(int l = 0; l<CHESS_FIELD_HEIGHT; l++){
				add_b_pixel( (k+MOUSE_X_FIELD*CHESS_FIELD_WIDTH), (l+MOUSE_Y_FIELD*CHESS_FIELD_HEIGHT), bishop[k+l*CHESS_FIELD_WIDTH] );
				add_w_pixel( (k+MOUSE_X_FIELD*CHESS_FIELD_WIDTH), (l+MOUSE_Y_FIELD*CHESS_FIELD_HEIGHT), ' ' );
			}
		}
	}
	else if(move_cont==W_BISHOP){
		for(int k = 0; k<CHESS_FIELD_WIDTH; k++){
			for(int l = 0; l<CHESS_FIELD_HEIGHT; l++){
				add_w_pixel( (k+MOUSE_X_FIELD*CHESS_FIELD_WIDTH), (l+MOUSE_Y_FIELD*CHESS_FIELD_HEIGHT), bishop[k+l*CHESS_FIELD_WIDTH] );
				add_b_pixel( (k+MOUSE_X_FIELD*CHESS_FIELD_WIDTH), (l+MOUSE_Y_FIELD*CHESS_FIELD_HEIGHT), ' ' );
			}
		}
	}
	else if(move_cont==B_ROOK){
		for(int k = 0; k<CHESS_FIELD_WIDTH; k++){
			for(int l = 0; l<CHESS_FIELD_HEIGHT; l++){
				add_b_pixel( (k+MOUSE_X_FIELD*CHESS_FIELD_WIDTH), (l+MOUSE_Y_FIELD*CHESS_FIELD_HEIGHT), rook[k+l*CHESS_FIELD_WIDTH] );
				add_w_pixel( (k+MOUSE_X_FIELD*CHESS_FIELD_WIDTH), (l+MOUSE_Y_FIELD*CHESS_FIELD_HEIGHT), ' ' );
			}
		}
	}
	else if(move_cont==W_ROOK){
		for(int k = 0; k<CHESS_FIELD_WIDTH; k++){
			for(int l = 0; l<CHESS_FIELD_HEIGHT; l++){
				add_w_pixel( (k+MOUSE_X_FIELD*CHESS_FIELD_WIDTH), (l+MOUSE_Y_FIELD*CHESS_FIELD_HEIGHT), rook[k+l*CHESS_FIELD_WIDTH] );
				add_b_pixel( (k+MOUSE_X_FIELD*CHESS_FIELD_WIDTH), (l+MOUSE_Y_FIELD*CHESS_FIELD_HEIGHT), ' ' );
			}
		}
	}
	else if(move_cont==B_QUEEN){
		for(int k = 0; k<CHESS_FIELD_WIDTH; k++){
			for(int l = 0; l<CHESS_FIELD_HEIGHT; l++){
				add_b_pixel( (k+MOUSE_X_FIELD*CHESS_FIELD_WIDTH), (l+MOUSE_Y_FIELD*CHESS_FIELD_HEIGHT), queen[k+l*CHESS_FIELD_WIDTH] );
				add_w_pixel( (k+MOUSE_X_FIELD*CHESS_FIELD_WIDTH), (l+MOUSE_Y_FIELD*CHESS_FIELD_HEIGHT), ' ' );
			}
		}
	}
	else if(move_cont==W_QUEEN){
		for(int k = 0; k<CHESS_FIELD_WIDTH; k++){
			for(int l = 0; l<CHESS_FIELD_HEIGHT; l++){
				add_w_pixel( (k+MOUSE_X_FIELD*CHESS_FIELD_WIDTH), (l+MOUSE_Y_FIELD*CHESS_FIELD_HEIGHT), queen[k+l*CHESS_FIELD_WIDTH] );
				add_b_pixel( (k+MOUSE_X_FIELD*CHESS_FIELD_WIDTH), (l+MOUSE_Y_FIELD*CHESS_FIELD_HEIGHT), ' ' );
			}
		}
	}
	else if(move_cont==B_KING){
		for(int k = 0; k<CHESS_FIELD_WIDTH; k++){
			for(int l = 0; l<CHESS_FIELD_HEIGHT; l++){
				add_b_pixel( (k+MOUSE_X_FIELD*CHESS_FIELD_WIDTH), (l+MOUSE_Y_FIELD*CHESS_FIELD_HEIGHT), king[k+l*CHESS_FIELD_WIDTH] );
				add_w_pixel( (k+MOUSE_X_FIELD*CHESS_FIELD_WIDTH), (l+MOUSE_Y_FIELD*CHESS_FIELD_HEIGHT), ' ' );
			}
		}
	}
	else if(move_cont==W_KING){
		for(int k = 0; k<CHESS_FIELD_WIDTH; k++){
			for(int l = 0; l<CHESS_FIELD_HEIGHT; l++){
				add_w_pixel( (k+MOUSE_X_FIELD*CHESS_FIELD_WIDTH), (l+MOUSE_Y_FIELD*CHESS_FIELD_HEIGHT), king[k+l*CHESS_FIELD_WIDTH] );
				add_b_pixel( (k+MOUSE_X_FIELD*CHESS_FIELD_WIDTH), (l+MOUSE_Y_FIELD*CHESS_FIELD_HEIGHT), ' ' );
			}
		}
	}
	else if(move_cont==B_PAWN){
		for(int k = 0; k<CHESS_FIELD_WIDTH; k++){
			for(int l = 0; l<CHESS_FIELD_HEIGHT; l++){
				add_b_pixel( (k+MOUSE_X_FIELD*CHESS_FIELD_WIDTH), (l+MOUSE_Y_FIELD*CHESS_FIELD_HEIGHT), pawn[k+l*CHESS_FIELD_WIDTH] );
				add_w_pixel( (k+MOUSE_X_FIELD*CHESS_FIELD_WIDTH), (l+MOUSE_Y_FIELD*CHESS_FIELD_HEIGHT), ' ' );
			}
		}
	}
	if(move_cont==W_PAWN){
		for(int k = 0; k<CHESS_FIELD_WIDTH; k++){
			for(int l = 0; l<CHESS_FIELD_HEIGHT; l++){
				add_w_pixel( (k+MOUSE_X_FIELD*CHESS_FIELD_WIDTH), (l+MOUSE_Y_FIELD*CHESS_FIELD_HEIGHT), pawn[k+l*CHESS_FIELD_WIDTH] );
				add_b_pixel( (k+MOUSE_X_FIELD*CHESS_FIELD_WIDTH), (l+MOUSE_Y_FIELD*CHESS_FIELD_HEIGHT), ' ' );
			}
		}
	}


	init_pair(1, COLOR_BLACK, COLOR_RED); //black piece on red field
	init_pair(2, COLOR_BLACK, COLOR_WHITE); // black piece on grey field
	init_pair(3, COLOR_GREEN, COLOR_RED); //white piece on red field
	init_pair(4, COLOR_GREEN, COLOR_WHITE); // white piece on grey field
	init_pair(5, COLOR_GREEN, COLOR_BLUE); //rest, white on blue

	int wcol = 0;
	move(0,0);
	for(int i = 0; i<height_; i++){
		for(int j = 0; j<width_; j++){

			//check if there should be a red or a grey backgroundcolor
			if(i%(CHESS_FIELD_HEIGHT*2)<CHESS_FIELD_HEIGHT){
				if(j%(CHESS_FIELD_WIDTH*2)<CHESS_FIELD_WIDTH){
					wcol=2;
				}				
				else if(j%(CHESS_FIELD_WIDTH*2)>=CHESS_FIELD_WIDTH){
					wcol=1;
				}
			}
			else if(i%(CHESS_FIELD_HEIGHT*2)>=CHESS_FIELD_HEIGHT){
				if(j%(CHESS_FIELD_WIDTH*2)>=CHESS_FIELD_WIDTH){
					wcol=2;
				}
				else if(j%(CHESS_FIELD_WIDTH*2)<CHESS_FIELD_WIDTH){
					wcol=1;
				}
			}

			if(picture_mouse[i*width_+j] != ' '){
				if(i<CHESS_FIELD_HEIGHT*8 && j < CHESS_FIELD_WIDTH*8){
					attron(COLOR_PAIR(wcol+2));
				}
				else{
					attron(COLOR_PAIR(5));
				}
				printw("%c", picture_mouse[i*width_+j]);
			}
			else if(picture_b_piece[i*width_+j] != ' ' && i<CHESS_FIELD_HEIGHT*8 && j<CHESS_FIELD_WIDTH*8){
				attron(COLOR_PAIR(wcol));
				printw("%c", picture_b_piece[i*width_+j]);
			}
			else if(i<CHESS_FIELD_HEIGHT*8 && j < CHESS_FIELD_WIDTH*8){
				attron(COLOR_PAIR(wcol+2));
				printw("%c", picture_w_piece[i*width_+j]);
			}
			else{
				attron(COLOR_PAIR(5));
				printw("%c", picture_mouse[i*width_+j]);
			}
		}
	}
	refresh();
}

int Picture::get_width(){
	return width_;
}

int Picture::get_height(){
	return height_;
}

void Picture::print(std::string s){
	int j=1;
	int k=1;
	for(int i = 0; i<s.length(); i++){
		if(s[i]=='\n'){
			j++;
			i++;
			k=1;
		}
		else if(width_-(CHESS_FIELD_WIDTH*8+k)<1){
			j++;
			k=1;
		}
				
		add_mouse_pixel(CHESS_FIELD_WIDTH*8+k, j,  s[i]);
		k++;
	}
}

void Picture::clear_printed(){
	for(int i = 0; i<COLS; i++){
		for(int j = 0; j<LINES; j++){	
			add_mouse_pixel(i, j,  ' ');
		}
	}
}

int init_picture(int a, int b, int c){
	initscr();
	if(has_colors() == TRUE){	
		start_color();
		//init_color(COLOR_RED, 150, 300, 150);//nice green
		//init_color(COLOR_RED, 280, 380, 280);
		init_color(COLOR_RED, a, b, c);
		init_color(COLOR_WHITE, 500, 500, 500);
		init_color(COLOR_BLACK, 0, 0, 0);
		init_color(COLOR_BLUE, 0, 0, 0);
		init_color(COLOR_GREEN, 1000, 1000, 1000);
	}
	else{
		return -1;
	}

	timeout(0);
	return 0;
}
		






























