#include "ai.hpp"
#include "pieces.hpp"
//#include <iostream>

int valuation(int vboard[120]){
	int value = 0;

	int state = 0;

	if(MOVE_COUNTER>=12){
		state=1;
		int pieces = 0;	
		for(int i = 21; i<99; i++){
			if(vboard[i]<-50 || vboard[i]>0){
				pieces++;
			}
		}
		if(pieces<=17){
			state=3;
		}
	}

	if(state==0){
		for(int i = 21; i<99; i++){
			value+=vboard[i];
			if(vboard[i]<-50){
				value-=(i/10)*4;
				if(vboard[i]>-465 && ((i>=43 && i<=46) || (i>=53 && i<=56) || (i>=63 && i<=66) || (i==73 && i<=76))){
					value-=20;
					if(i==54 || i==55 || i==64 || i==65){
						value-=25;
					}
				}
				if(vboard[i]==B_PAWN && (vboard[i+11]==B_PAWN || vboard[i+9]==B_PAWN)){
					if(vboard[i+11]==B_PAWN || vboard[i+9]==B_PAWN){
						value-=33;
					}					
					if(vboard[i-1]==B_PAWN || vboard[i+1]==B_PAWN || vboard[i+21]==B_PAWN || vboard[i+19]==B_PAWN){
						value-=28;
					}
					if(vboard[i+10]==B_PAWN){
						value+=35;
					}
					if(vboard[i+20]==B_PAWN){
						value+=33;
					}
					value-=((i/10)*(i/10)+7)/11;
				}
				else if(vboard[i]<B_PAWN && i<30 && vboard[i]>B_ROOK){
					value+=20;
				}
				else if(vboard[i]==B_QUEEN && i<29 && vboard[0]== -3){
					value-=25;
				}
				else if(vboard[i]==B_KING){
					if(vboard[12]==-4 || vboard[2]==-4){
						if(vboard[i+10]==B_PAWN || vboard[i+20]==B_PAWN){
							value-=43;
						}
						if(vboard[i+11]==B_PAWN || vboard[i+21]==B_PAWN){
							value-=35;
						}
						if(vboard[i+9]==B_PAWN || vboard[i+19]==B_PAWN){
							value-=35;
						}
					}
				}							
			}
	
			else if(vboard[i]>0){
				value-=(i/10)*4;
				if(vboard[i]<465 && ((i>=43 && i<=46) || (i>=53 && i<=56) || (i>=63 && i<=66) || (i==73 && i<=76))){
					value+=20;
					if(i==54 || i==55 || i==64 || i==65){
						value+=25;
					}
				}
				if(vboard[i]==W_PAWN){
					if(vboard[i-11]==W_PAWN || vboard[i-9]==W_PAWN){
						value+=33;
					}					
					if(vboard[i-1]==W_PAWN || vboard[i+1]==W_PAWN || vboard[i-21]==W_PAWN || vboard[i-19]==W_PAWN){
						value+=28;
					}
					if(vboard[i-10]==W_PAWN){
						value-=35;
					}
					if(vboard[i-20]==W_PAWN){
						value-=33;
					}
					value-=((i/10)*(i/10)+7)/11;
				}
				else if(vboard[i]>W_PAWN && i>90 && vboard[i]<W_ROOK){
					value-=20;
				}
				else if(i>90 && vboard[i]==W_QUEEN && vboard[1]== -3){
					value+=25;
				}
				else if(vboard[i]==W_KING){
					if(vboard[13]==-4 || vboard[3]==-4){
						if(vboard[i-10]==W_PAWN || vboard[i-20]==W_PAWN){
							value+=40;
						}
						if(vboard[i-11]==W_PAWN || vboard[i-21]==W_PAWN){
							value+=35;
						}
						if(vboard[i-9]==W_PAWN || vboard[i-19]==W_PAWN){
							value+=35;
						}
					}
				}
			}
		}
	
		if(vboard[2]!=-4){
			value+=40;
		}
		if(vboard[3]!=-4){
			value-=40;
		}
	
		if(vboard[12]!=-4){
			value+=25;
		}
		if(vboard[13]!=-4){
			value-=25;
		}
	}
	else if(state==1){
		for(int i = 21; i<99; i++){
			value+=vboard[i];
			if(vboard[i]<-50){
				value-=(i/10)*4;
				if(vboard[i]>=-900 && ((i>=43 && i<=46) || (i>=53 && i<=56) || (i>=63 && i<=66) || (i==73 && i<=76))){
					value-=20;
					if(i==54 || i==55 || i==64 || i==65){
						value-=25;
					}
				}
				if(vboard[i]==B_PAWN && (vboard[i+11]==B_PAWN || vboard[i+9]==B_PAWN)){
					if(vboard[i+11]==B_PAWN || vboard[i+9]==B_PAWN){
						value-=30;
					}					
					if(vboard[i-1]==B_PAWN || vboard[i+1]==B_PAWN || vboard[i+21]==B_PAWN || vboard[i+19]==B_PAWN){
						value-=25;
					}
					if(vboard[i+10]==B_PAWN){
						value+=55;
					}
					if(vboard[i+20]==B_PAWN){
						value+=40;
					}
					value-=(((i/10)*(i/10)+7)/11)*2;
				}
				else if(vboard[i]<B_PAWN && i<30 && vboard[i]>B_ROOK){
					value+=20;
				}
				else if(vboard[i]==B_KING){
					if(vboard[i+10]==B_PAWN || vboard[i+20]==B_PAWN){
						value-=40;
					}
					if(vboard[i+11]==B_PAWN || vboard[i+21]==B_PAWN){
						value-=35;
					}
					if(vboard[i+9]==B_PAWN || vboard[i+19]==B_PAWN){
						value-=35;
					}
				}
			}
	
			else if(vboard[i]>0){
				value-=(i/10)*4;
				if(vboard[i]<=900 && ((i>=43 && i<=46) || (i>=53 && i<=56) || (i>=63 && i<=66) || (i==73 && i<=76))){
					value+=20;
					if(i==54 || i==55 || i==64 || i==65){
						value+=25;
					}
				}
				if(vboard[i]==W_PAWN){
					if(vboard[i-11]==W_PAWN || vboard[i-9]==W_PAWN){
						value+=30;
					}					
					if(vboard[i-1]==W_PAWN || vboard[i+1]==W_PAWN || vboard[i-21]==W_PAWN || vboard[i-19]==W_PAWN){
						value+=25;
					}
					if(vboard[i-10]==W_PAWN){
						value-=55;
					}
					if(vboard[i-20]==W_PAWN){
						value-=40;
					}
					value-=(((i/10)*(i/10)+7)/11)*2;
				}
				else if(vboard[i]>W_PAWN && i>90 && vboard[i]<W_ROOK){
					value-=20;
				}
				else if(vboard[i]==W_KING){
					if(vboard[i-10]==W_PAWN || vboard[i-20]==W_PAWN){
						value+=40;
					}
					if(vboard[i-11]==W_PAWN || vboard[i-21]==W_PAWN){
						value+=35;
					}
					if(vboard[i-9]==W_PAWN || vboard[i-19]==W_PAWN){
						value+=35;
					}			
				}
			}
		}
	
		if(vboard[2]!=-4){
			value+=30;
		}
		if(vboard[3]!=-4){
			value-=30;
		}
	
		if(vboard[12]!=-4){
			value+=20;
		}
		if(vboard[13]!=-4){
			value-=20;
		}
	}
	else{
		for(int i = 21; i<99; i++){
			value+=vboard[i];
			if(vboard[i]<-50){
				if((i>=43 && i<=46) || (i>=53 && i<=56) || (i>=63 && i<=66) || (i==73 && i<=76)){
					value-=20;
					if(i==54 || i==55 || i==64 || i==65){
						value-=25;
					}
				}
				if(vboard[i]==B_PAWN && (vboard[i+11]==B_PAWN || vboard[i+9]==B_PAWN)){
					if(vboard[i+11]==B_PAWN || vboard[i+9]==B_PAWN){
						value-=20;
					}					
					if(vboard[i-1]==B_PAWN || vboard[i+1]==B_PAWN || vboard[i+21]==B_PAWN || vboard[i+19]==B_PAWN){
						value-=15;
					}
					if(vboard[i+10]==B_PAWN){
						value+=40;
					}
					if(vboard[i+20]==B_PAWN){
						value+=35;
					}
					value-=(((i/10)*(i/10)*(i/10))/10)*3;
				}
			}
	
			else if(vboard[i]>0){
				if((i>=43 && i<=46) || (i>=53 && i<=56) || (i>=63 && i<=66) || (i==73 && i<=76)){
					value+=20;
					if(i==54 || i==55 || i==64 || i==65){
						value+=25;
					}
				}
				if(vboard[i]==W_PAWN){
					if(vboard[i-11]==W_PAWN || vboard[i-9]==W_PAWN){
						value+=20;
					}					
					if(vboard[i-1]==W_PAWN || vboard[i+1]==W_PAWN || vboard[i-21]==W_PAWN || vboard[i-19]==W_PAWN){
						value+=15;
					}
					if(vboard[i-10]==W_PAWN){
						value-=40;
					}
					if(vboard[i-20]==W_PAWN){
						value-=35;
					}
					value-=(((i/10)*(i/10)*(i/10))/10)*3;
				}
			}
		}
	}

	MOVES++;	

	return value;
}



int explore_one_move_for_black(int pos_mov[150][120], int num, int deepness, int *beta){
	int alpha = 40000;

	if(deepness<=0){
		int act_best=valuation(pos_mov[0]);
		int valuated;

		int pos_mov_next[150][120];
		int next_num;
		int value;

		for(int i = 1; i<num; i++){

			valuated=valuation(pos_mov[i]);

			if(valuated<act_best){
				if(HORIZON_DEEPNESS>0 && pos_mov[i][5]<=REQUIRED_CAPTURES && pos_mov[i][8]!=-3){
					pos_mov[i][8]=-3;
					next_num = get_pos_mov_white(pos_mov_next, pos_mov[i]);
					value = explore_one_move_for_white(pos_mov_next, next_num, HORIZON_DEEPNESS, &alpha);
					if(value<act_best){
						act_best = value;
					}
				}
				else{
					act_best = valuated;
				}
			}

			if(act_best<=*beta){
				return act_best;
			}
		}

		*beta=act_best;
		return act_best;
	}//else
	
	int pos_mov_next[150][120];
	int act_best = 40000;
	int next_num;
	int valuated;
	for(int i = 0; i<num; i++){

		for(int k = 21; k<99; k++){
			valuated+=pos_mov[i][k];
		}

		if(valuated-LAST_VALUATION>=B_KING+5000){

			next_num = get_pos_mov_white(pos_mov_next, pos_mov[i]);

			valuated = explore_one_move_for_white(pos_mov_next, next_num, deepness-1, &alpha);
		}
		else{
			return valuated;
		}		

		if(valuated<act_best){
			act_best = valuated;
		}

		if(act_best<=*beta){
			return act_best;
		}
	}

	*beta=act_best;

	return act_best;
}		


int explore_one_move_for_white(int pos_mov[150][120], int num, int deepness, int *beta){
	int alpha = -40000;
	
	if(deepness<=0){
		int act_best=valuation(pos_mov[0]);
		int valuated;

		int pos_mov_next[150][120];
		int next_num;
		int value;

		for(int i = 1; i<num; i++){

			valuated=valuation(pos_mov[i]);

			if(valuated>act_best){
				if(HORIZON_DEEPNESS>0 && pos_mov[i][5]<=REQUIRED_CAPTURES && pos_mov[i][8]!=-3){
					pos_mov[i][8]=-3;
					next_num = get_pos_mov_black(pos_mov_next, pos_mov[i]);
					value = explore_one_move_for_black(pos_mov_next, next_num, HORIZON_DEEPNESS, &alpha);
					if(value>act_best){
						act_best = value;
					}
				}
				else{
					act_best = valuated;
				}
			}

			if(act_best>=*beta){
				return act_best;
			}
		}

		*beta=act_best;
		return act_best;
	}//else
	
	int pos_mov_next[150][120];
	int act_best = -40000;
	int next_num;
	int valuated;
	for(int i = 0; i<num; i++){

		for(int k = 21; k<99; k++){
			valuated+=pos_mov[i][k];
		}

		if(valuated-LAST_VALUATION<=W_KING-5000){

			next_num = get_pos_mov_black(pos_mov_next, pos_mov[i]);

			valuated = explore_one_move_for_black(pos_mov_next, next_num, deepness-1, &alpha);
		}
		else{
			return valuated;
		}

		if(valuated>act_best){
			act_best = valuated;
		}

		if(act_best>=*beta){
			return act_best;
		}
	}

	*beta=act_best;

	return act_best;
}
