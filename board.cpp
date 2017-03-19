#include "board.hpp"
#include <string.h>

Board::Board(){
	/*vboard={      //x=0 x=1 x=2 x=3 x=4 x=5 x=6 x=7 x=8 x=9
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
	vboard1={      //x=0 x=1 x=2 x=3 x=4 x=5 x=6 x=7 x=8 x=9
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
	vboard2={      //x=0 x=1 x=2 x=3 x=4 x=5 x=6 x=7 x=8 x=9
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
			};*/
	vboard_to_rboard();
}

Board::~Board(){

}
int Board::get_field(int x, int y){
	return rboard[y*8+x];
}

void Board::undo(){
	memcpy(vboard, vboard1, sizeof(int)*120);
	memcpy(vboard1, vboard2, sizeof(int)*120);
	vboard_to_rboard();
}
//-21, -19, -12, -8, +8, +12, +19, +21   -11, -9, +9, +11
int Board::move(int x1, int y1, int x2, int y2){

	memcpy(vboard2, vboard1, sizeof(int)*120);
	memcpy(vboard1, vboard, sizeof(int)*120);

	int en_passant=0;
	if(vboard[x2 + 21 + y2*10]==-2){
		en_passant=-2;
	}
	if(vboard[x2 + 21 + y2*10]==-5){
		en_passant=-5;
	}
	for(int i = 21; i<=98; i++){
		if(vboard[i]==-2 || vboard[i]==-5){
			vboard[i]=0;
		}
	}

	if(x1==x2 && y1==y2){
		vboard_to_rboard();
		return -1;
	}

	if(vboard[x1 + 21 + y1*10] == W_KNIGHT){
		if((x1 + 21 + y1*10 -21 == x2 + 21 + y2*10) || (x1 + 21 + y1*10 -19 == x2 + 21 + y2*10) || (x1 + 21 + y1*10 -12 == x2 + 21 + y2*10) || (x1 + 21 + y1*10 -8 == x2 + 21 + y2*10) || (x1 + 21 + y1*10 +21 == x2 + 21 + y2*10) || (x1 + 21 + y1*10 +19 == x2 + 21 + y2*10) || (x1 + 21 + y1*10 +12 == x2 + 21 + y2*10) || (x1 + 21 + y1*10 +8 == x2 + 21 + y2*10)){
			if(vboard[x2 + 21 + y2*10]==0 || vboard[x2 + 21 + y2*10]<-50){
				vboard[x2 + 21 + y2*10] = W_KNIGHT;
				vboard[x1 + 21 + y1*10] = 0;
				vboard_to_rboard();
				return 0;
			}
		}
	}

	if(vboard[x1 + 21 + y1*10] == B_KNIGHT){
		if((x1 + 21 + y1*10 -21 == x2 + 21 + y2*10) || (x1 + 21 + y1*10 -19 == x2 + 21 + y2*10) || (x1 + 21 + y1*10 -12 == x2 + 21 + y2*10) || (x1 + 21 + y1*10 -8 == x2 + 21 + y2*10) || (x1 + 21 + y1*10 +21 == x2 + 21 + y2*10) || (x1 + 21 + y1*10 +19 == x2 + 21 + y2*10) || (x1 + 21 + y1*10 +12 == x2 + 21 + y2*10) || (x1 + 21 + y1*10 +8 == x2 + 21 + y2*10)){
			if(vboard[x2 + 21 + y2*10]>=0){
				vboard[x2 + 21 + y2*10] = B_KNIGHT;
				vboard[x1 + 21 + y1*10] = 0;
				vboard_to_rboard();
				return 0;
			}
		}/*
		if((x1 + 21 + y1*10) - (x2 + 21 + y2*10)%21==0 || (x1 + 21 + y1*10) - (x2 + 21 + y2*10)%19==0 || (x1 + 21 + y1*10) - (x2 + 21 + y2*10)%12==0 || (x1 + 21 + y1*10) - (x2 + 21 + y2*10)%8==0){
			if(vboard[x2 + 21 + y2*10]==0 || vboard[x2 + 21 + y2*10]<-50){
				vboard[x2 + 21 + y2*10] = W_KNIGHT;
				vboard[x1 + 21 + y1*10] = 0;
				vboard_to_rboard();
				return 0;
			}
		}*/
	}

	if(vboard[x1 + 21 + y1*10] == W_BISHOP){
		if(((x1 + 21 + y1*10) - (x2 + 21 + y2*10))%11==0 || ((x1 + 21 + y1*10) - (x2 + 21 + y2*10))%9==0){
			int a = (x2 + 21 + y2*10) - (x1 + 21 + y1*10);
			int b;
			int c;
			if(a<0){
				b=-1;
			}
			else{
				b=1;
			}
			if(a%9==0){
				c=9;
			}
			else{
				c=11;
			}

			for(int i = c; i<a*b; i+=c){
				if(vboard[x1 + 21 + y1*10+i*b]!=0){
					vboard_to_rboard();
					return -1;
				}
			}
			if(vboard[x2 + 21 + y2*10]==0 || vboard[x2 + 21 + y2*10]<-50){
				vboard[x2 + 21 + y2*10] = W_BISHOP;
				vboard[x1 + 21 + y1*10] = 0;
				vboard_to_rboard();
				return 0;
			}
		}
	}

	if(vboard[x1 + 21 + y1*10] == B_BISHOP){
		if(((x1 + 21 + y1*10) - (x2 + 21 + y2*10))%11==0 || ((x1 + 21 + y1*10) - (x2 + 21 + y2*10))%9==0){
			int a = (x2 + 21 + y2*10) - (x1 + 21 + y1*10);
			int b;
			int c;
			if(a<0){
				b=-1;
			}
			else{
				b=1;
			}
			if(a%9==0){
				c=9;
			}
			else{
				c=11;
			}

			for(int i = c; i<a*b; i+=c){
				if(vboard[x1 + 21 + y1*10+i*b]!=0){
					vboard_to_rboard();
					return -1;
				}
			}
			if(vboard[x2 + 21 + y2*10]>=0){
				vboard[x2 + 21 + y2*10] = B_BISHOP;
				vboard[x1 + 21 + y1*10] = 0;
				vboard_to_rboard();
				return 0;
			}
		}
	}

	if(vboard[x1 + 21 + y1*10] == W_ROOK){
		if(((x1 + 21 + y1*10) - (x2 + 21 + y2*10))%10==0 || (((x1 + 21 + y1*10) - (x2 + 21 + y2*10))<=8 && ((x1 + 21 + y1*10) - (x2 + 21 + y2*10))>=-8)){
			int a = (x2 + 21 + y2*10) - (x1 + 21 + y1*10);
			int b;
			int c;
			if(a<0){
				b=-1;
			}
			else{
				b=1;
			}
			if(a%10==0){
				c=10;
			}
			else{
				c=1;
			}

			for(int i = c; i<a*b; i+=c){
				if(vboard[x1 + 21 + y1*10+i*b]!=0){
					vboard_to_rboard();
					return -1;
				}
			}
			if(vboard[x2 + 21 + y2*10]==0 || vboard[x2 + 21 + y2*10]<-50){
				vboard[x2 + 21 + y2*10] = W_ROOK;
				vboard[x1 + 21 + y1*10] = 0;
				vboard_to_rboard();
				if(x1 + 21 + y1*10==98){
					vboard[1]=-1;
				}
				else{
					vboard[11]=-1;
				}
				return 0;
			}
		}
	}

	if(vboard[x1 + 21 + y1*10] == B_ROOK){
		if(((x1 + 21 + y1*10) - (x2 + 21 + y2*10))%10==0 || (((x1 + 21 + y1*10) - (x2 + 21 + y2*10))<=8 && ((x1 + 21 + y1*10) - (x2 + 21 + y2*10))>=-8)){
			int a = (x2 + 21 + y2*10) - (x1 + 21 + y1*10);
			int b;
			int c;
			if(a<0){
				b=-1;
			}
			else{
				b=1;
			}
			if(a%10==0){
				c=10;
			}
			else{
				c=1;
			}

			for(int i = c; i<a*b; i+=c){
				if(vboard[x1 + 21 + y1*10+i*b]!=0){
					vboard_to_rboard();
					return -1;
				}
			}
			if(vboard[x2 + 21 + y2*10]>=0){
				vboard[x2 + 21 + y2*10] = B_ROOK;
				vboard[x1 + 21 + y1*10] = 0;
				vboard_to_rboard();
				if(x1 + 21 + y1*10==28){
					vboard[0]=-1;;
				}
				else{
					vboard[10]=-1;
				}
				return 0;
			}
		}
	}

	if(vboard[x1 + 21 + y1*10] == W_QUEEN){
		if(((x1 + 21 + y1*10) - (x2 + 21 + y2*10))%10==0 || (((x1 + 21 + y1*10) - (x2 + 21 + y2*10))<=8 && ((x1 + 21 + y1*10) - (x2 + 21 + y2*10))>=-8) || ((x1 + 21 + y1*10) - (x2 + 21 + y2*10))%11==0 || ((x1 + 21 + y1*10) - (x2 + 21 + y2*10))%9==0){
			int a = (x2 + 21 + y2*10) - (x1 + 21 + y1*10);
			int b;
			int c;
			if(a<0){
				b=-1;
			}
			else{
				b=1;
			}
			if(a%10==0){
				c=10;
			}
			else if(a%11==0){
				c=11;
			}
			else if(a%9==0){
				c=9;
			}
			else{
				c=1;
			}

			for(int i = c; i<a*b; i+=c){
				if(vboard[x1 + 21 + y1*10+i*b]!=0){
					vboard_to_rboard();
					return -1;
				}
			}
			if(vboard[x2 + 21 + y2*10]==0 || vboard[x2 + 21 + y2*10]<-50){
				vboard[x2 + 21 + y2*10] = W_QUEEN;
				vboard[x1 + 21 + y1*10] = 0;
				vboard_to_rboard();
				return 0;
			}
		}
	}

	if(vboard[x1 + 21 + y1*10] == B_QUEEN){
		if(((x1 + 21 + y1*10) - (x2 + 21 + y2*10))%10==0 || (((x1 + 21 + y1*10) - (x2 + 21 + y2*10))<=8 && ((x1 + 21 + y1*10) - (x2 + 21 + y2*10))>=-8) || ((x1 + 21 + y1*10) - (x2 + 21 + y2*10))%11==0 || ((x1 + 21 + y1*10) - (x2 + 21 + y2*10))%9==0){
			int a = (x2 + 21 + y2*10) - (x1 + 21 + y1*10);
			int b;
			int c;
			if(a<0){
				b=-1;
			}
			else{
				b=1;
			}
			if(a%10==0){
				c=10;
			}
			else if(a%11==0){
				c=11;
			}
			else if(a%9==0){
				c=9;
			}
			else{
				c=1;
			}

			for(int i = c; i<a*b; i+=c){
				if(vboard[x1 + 21 + y1*10+i*b]!=0){
					vboard_to_rboard();
					return -1;
				}
			}
			if(vboard[x2 + 21 + y2*10]>=0){
				vboard[x2 + 21 + y2*10] = B_QUEEN;
				vboard[x1 + 21 + y1*10] = 0;
				vboard_to_rboard();
				return 0;
			}
		}
	}

	if(vboard[x1 + 21 + y1*10] == W_KING){
		if((x1 + 21 + y1*10 -1 == x2 + 21 + y2*10) || (x1 + 21 + y1*10 -9 == x2 + 21 + y2*10) || (x1 + 21 + y1*10 -10 == x2 + 21 + y2*10) || (x1 + 21 + y1*10 -11 == x2 + 21 + y2*10) || (x1 + 21 + y1*10 +1 == x2 + 21 + y2*10) || (x1 + 21 + y1*10 +9 == x2 + 21 + y2*10) || (x1 + 21 + y1*10 +10 == x2 + 21 + y2*10) || (x1 + 21 + y1*10 +11 == x2 + 21 + y2*10)){
			if(vboard[x2 + 21 + y2*10]==0 || vboard[x2 + 21 + y2*10]<-50){
				vboard[x2 + 21 + y2*10] = W_KING;
				vboard[x1 + 21 + y1*10] = 0;
				vboard[1] = -1;
				vboard_to_rboard();
				vboard[11]=-1;
				vboard[1]=-1;
				return 0;
			}
		}

		if(vboard[1]==-3 && vboard[97]==0 && vboard[96]==0 && x2 + 21 + y2*10 == 97){
			vboard[98]=0;			
			vboard[97]=W_KING;
			vboard[96]=W_ROOK;
			vboard[95]=0;
			vboard[3] = -4;
			vboard[1] = -1;
			vboard_to_rboard();
			return 0;
		}

		if(vboard[11]==-3 && vboard[92]==0 && vboard[93]==0 && vboard[94]==0 && x2 + 21 + y2*10 == 93){
			vboard[91]=0;			
			vboard[92]=0;
			vboard[93]=W_KING;
			vboard[94]=W_ROOK;
			vboard[95]=0;
			vboard[3] = -4;
			vboard[1] = -1;
			vboard_to_rboard();
			return 0;
		}
	}

	if(vboard[x1 + 21 + y1*10] == B_KING){
		if((x1 + 21 + y1*10 -1 == x2 + 21 + y2*10) || (x1 + 21 + y1*10 -9 == x2 + 21 + y2*10) || (x1 + 21 + y1*10 -10 == x2 + 21 + y2*10) || (x1 + 21 + y1*10 -11 == x2 + 21 + y2*10) || (x1 + 21 + y1*10 +1 == x2 + 21 + y2*10) || (x1 + 21 + y1*10 +9 == x2 + 21 + y2*10) || (x1 + 21 + y1*10 +10 == x2 + 21 + y2*10) || (x1 + 21 + y1*10 +11 == x2 + 21 + y2*10)){
			if(vboard[x2 + 21 + y2*10]>=0){
				vboard[x2 + 21 + y2*10] = B_KING;
				vboard[x1 + 21 + y1*10] = 0;
				vboard[0] = -1;
				vboard_to_rboard();
				vboard[0]=-1;
				vboard[10]=-1;
				return 0;
			}
		}

		if(vboard[0]==-3 && vboard[27]==0 && vboard[26]==0 && x2 + 21 + y2*10 == 27){
			vboard[28]=0;			
			vboard[27]=B_KING;
			vboard[26]=B_ROOK;
			vboard[25]=0;
			vboard[2] = -4;
			vboard[0] = -1;
			vboard_to_rboard();
			return 0;
		}

		if(vboard[10]==-3 && vboard[22]==0 && vboard[23]==0 && vboard[24]==0 && x2 + 21 + y2*10 == 23){
			vboard[21]=0;			
			vboard[22]=0;
			vboard[23]=B_KING;
			vboard[24]=B_ROOK;
			vboard[25]=0;
			vboard[2] = -4;
			vboard[0] = -1;
			vboard_to_rboard();
			return 0;
		}
	}

	if(vboard[x1 + 21 + y1*10] == W_PAWN){
		if((x1 + 21 + y1*10 -10 == x2 + 21 + y2*10) || (x1 + 21 + y1*10 -9 == x2 + 21 + y2*10) || (x1 + 21 + y1*10 -11 == x2 + 21 + y2*10) || (x1 + 21 + y1*10 -20 == x2 + 21 + y2*10)){
			int a = (x2 + 21 + y2*10) - (x1 + 21 + y1*10);
			if(a%9==0 && vboard[x2 + 21 + y2*10]==0 && en_passant!=-5){
					vboard_to_rboard();
					return -1;
			}
			if(a%11==0 && vboard[x2 + 21 + y2*10]==0 && en_passant!=-5){
					vboard_to_rboard();
					return -1;
			}
			if(a%10==0 && vboard[x2 + 21 + y2*10]<-50){
					vboard_to_rboard();
					return -1;
			}

			if(a%20==0 && vboard[x1 + 21 + y1*10-10]==0 && vboard[x2 + 21 + y2*10]==0 && x1 + 21 + y1*10>80){
				vboard[x2 + 21 + y2*10] = W_PAWN;				
				vboard[x1 + 21 + y1*10] = 0;
				vboard[x1 + 21 + y1*10-10] = -2;
				vboard_to_rboard();
				return 0;
			}				
				
			if(a%20!=0 && (vboard[x2 + 21 + y2*10]==0 || vboard[x2 + 21 + y2*10]<-50)){
				if(en_passant==-5){
					vboard[x2 + 21 +y2*10 +10]=0;
				}
				vboard[x2 + 21 + y2*10] = W_PAWN;
				vboard[x1 + 21 + y1*10] = 0;
				vboard_to_rboard();
				if(x2 + 21 + y2*10<=28){
					return 1;
				}
				return 0;
			}
		}
	}

	if(vboard[x1 + 21 + y1*10] == B_PAWN){
		if((x1 + 21 + y1*10 +10 == x2 + 21 + y2*10) || (x1 + 21 + y1*10 +9 == x2 + 21 + y2*10) || (x1 + 21 + y1*10 +11 == x2 + 21 + y2*10) || (x1 + 21 + y1*10 +20 == x2 + 21 + y2*10)){
			int a = (x1 + 21 + y1*10)- (x2 + 21 + y2*10);
			if(a%9==0 && vboard[x2 + 21 + y2*10]==0 && en_passant!=-2){
					vboard_to_rboard();
					return -1;
			}
			if(a%11==0 && vboard[x2 + 21 + y2*10]==0 && en_passant!=-2){
					vboard_to_rboard();
					return -1;
			}
			if(a%10==0 && vboard[x2 + 21 + y2*10]>0){
					vboard_to_rboard();
					return -1;
			}

			if(a%20==0 && vboard[x1 + 21 + y1*10+10]==0 && vboard[x2 + 21 + y2*10]==0 && x1 + 21 + y1*10<=38){
				vboard[x2 + 21 + y2*10] = B_PAWN;
				vboard[x1 + 21 + y1*10] = 0;
				vboard[x1 + 21 + y1*10+10] = -5;
				vboard_to_rboard();
				return 0;
			}				
				
			if(a%20!=0 && vboard[x2 + 21 + y2*10]>=0){
				if(en_passant==-2){
					vboard[x2 + 21 +y2*10 -10]=0;
				}
				vboard[x2 + 21 + y2*10] = B_PAWN;
				vboard[x1 + 21 + y1*10] = -0;
				vboard_to_rboard();
				if(x2 + 21 + y2*10>=91){
					return 2;
				}
				return 0;
			}
		}
	}
	/*
		if((x1 + 21 + y1*10) - (x2 + 21 + y2*10)%21==0 || (x1 + 21 + y1*10) - (x2 + 21 + y2*10)%19==0 || (x1 + 21 + y1*10) - (x2 + 21 + y2*10)%12==0 || (x1 + 21 + y1*10) - (x2 + 21 + y2*10)%8==0){
			if(vboard[x2 + 21 + y2*10]==0 || vboard[x2 + 21 + y2*10]<-50){
				vboard[x2 + 21 + y2*10] = W_KNIGHT;
				vboard[x1 + 21 + y1*10] = 0;
				vboard_to_rboard();
				return 0;
			}
		}*/

	/*if(rboard[x1+8*y1] == W_BISHOP || rboard[x1+8*y1] == B_BISHOP){
		return 0;
	}
	
	if(rboard[x1+8*y1] == W_ROOK || rboard[x1+8*y1] == B_ROOK){
		return 0;
	}*/

	vboard_to_rboard();
	
	return -1;
}

void Board::vboard_to_rboard(){
	for(int i = 0; i<8; i++){
		for(int j = 0; j<8; j++){
			rboard[j+i*8] = vboard[j + 21 + i*10];
		}
	}
}

void Board::rboard_to_vboard(){
	for(int i = 0; i<8; i++){
		for(int j = 0; j<8; j++){
			vboard[j + 21 + i*10]= rboard[j+i*8];
		}
	}
}

void Board::add_to_rboard(int x, int y, int i){
	rboard[x+8*y]=i;
}

void Board::flip_board(){
	int tempboard[64];

	for(int i = 0; i<64; i++){
		tempboard[i]=rboard[63-i];
	}

	for(int i = 0; i<64; i++){
		rboard[i]=tempboard[i];
	}

	rboard_to_vboard();
}

int *Board::get_vboard(){
	return vboard;
}

int Board::get_vboard_field(int i){
	return vboard[i];
}

void  Board::set_vboard_field(int i, int content){
	vboard[i] = content;
}



















