#include "move_gen.hpp"
#include <iostream>

int get_pos_mov_black(int pos_mov[150][120], int vboard[120]){

	int d=21;
	for(;d<99; d++){
		if(vboard[d]==-2){
			vboard[d]=0;
			break;
		}
		
	}
	
	for(int i = 0; i<150; i++){
		memcpy(pos_mov[i], vboard, sizeof(int)*120);
	}
	int j=0;	

	for(int i = 21; i <99; i++){
		if(vboard[i] <-50){
			if(vboard[i]==B_KING){
				if(vboard[i+10]==0){
					pos_mov[j][1]=-3;
					pos_mov[j][i] = 0;
					pos_mov[j][i+10] = B_KING;
					pos_mov[j][0] = -1;					
					pos_mov[j][10] = -1;
					j++;
				}
				else if(vboard[i+10]>0){
					pos_mov[j][1]=-3;
					pos_mov[j][i] = 0;
					pos_mov[j][i+10] = B_KING;
					pos_mov[j][0] = -1;					
					pos_mov[j][10] = -1;
					pos_mov[j][5]--;
					j++;
				}
				if(vboard[i+1]==0){
					pos_mov[j][1]=-3;
					pos_mov[j][i] = 0;
					pos_mov[j][i+1] = B_KING;
					pos_mov[j][0] = -1;					
					pos_mov[j][10] = -1;
					j++;
				}
				else if(vboard[i+1]>0){
					pos_mov[j][1]=-3;
					pos_mov[j][i] = 0;
					pos_mov[j][i+1] = B_KING;
					pos_mov[j][0] = -1;					
					pos_mov[j][10] = -1;
					pos_mov[j][5]--;
					j++;
				}
				if(vboard[i-10]==0){
					pos_mov[j][1]=-3;
					pos_mov[j][i] = 0;
					pos_mov[j][i-10] = B_KING;
					pos_mov[j][0] = -1;					
					pos_mov[j][10] = -1;
					j++;
				}
				else if(vboard[i-10]>0){
					pos_mov[j][1]=-3;
					pos_mov[j][i] = 0;
					pos_mov[j][i-10] = B_KING;
					pos_mov[j][0] = -1;					
					pos_mov[j][10] = -1;
					pos_mov[j][5]--;
					j++;
				}
				if(vboard[i-1]==0){
					pos_mov[j][1]=-3;
					pos_mov[j][i] = 0;
					pos_mov[j][i-1] = B_KING;
					pos_mov[j][0] = -1;					
					pos_mov[j][10] = -1;
					j++;
				}
				else if(vboard[i-1]>0){
					pos_mov[j][1]=-3;
					pos_mov[j][i] = 0;
					pos_mov[j][i-1] = B_KING;
					pos_mov[j][0] = -1;					
					pos_mov[j][10] = -1;
					pos_mov[j][5]--;
					j++;
				}
				if(vboard[i+9]==0){
					pos_mov[j][1]=-3;
					pos_mov[j][i] = 0;
					pos_mov[j][i+9] = B_KING;
					pos_mov[j][0] = -1;					
					pos_mov[j][10] = -1;
					j++;
				}
				else if(vboard[i+9]>0){
					pos_mov[j][1]=-3;
					pos_mov[j][i] = 0;
					pos_mov[j][i+9] = B_KING;
					pos_mov[j][0] = -1;
					pos_mov[j][5]--;
					j++;
				}
				if(vboard[i+11]==0){
					pos_mov[j][1]=-3;
					pos_mov[j][i] = 0;
					pos_mov[j][i+11] = B_KING;
					pos_mov[j][0] = -1;					
					pos_mov[j][10] = -1;
					j++;
				}
				else if(vboard[i+11]>0){
					pos_mov[j][1]=-3;
					pos_mov[j][i] = 0;
					pos_mov[j][i+11] = B_KING;
					pos_mov[j][0] = -1;					
					pos_mov[j][10] = -1;
					pos_mov[j][5]--;
					j++;
				}
				if(vboard[i-9]==0){
					pos_mov[j][i] = 0;
					pos_mov[j][i-9] = B_KING;
					pos_mov[j][0] = -1;					
					pos_mov[j][10] = -1;
					j++;
				}
				else if(vboard[i-9]>0){
					pos_mov[j][1]=-3;
					pos_mov[j][i] = 0;
					pos_mov[j][i-9] = B_KING;
					pos_mov[j][0] = -1;					
					pos_mov[j][10] = -1;
					pos_mov[j][5]--;
					j++;
				}
				if(vboard[i-11]==0){
					pos_mov[j][1]=-3;
					pos_mov[j][i] = 0;
					pos_mov[j][i-11] = B_KING;
					pos_mov[j][0] = -1;					
					pos_mov[j][10] = -1;
					j++;
				}
				else if(vboard[i-11]>0){
					pos_mov[j][1]=-3;
					pos_mov[j][i] = 0;
					pos_mov[j][i-11] = B_KING;
					pos_mov[j][0] = -1;					
					pos_mov[j][10] = -1;
					pos_mov[j][5]--;
					j++;
				}
				if(pos_mov[j][0]== -3 && vboard[i+1]==0 && vboard[i+2]==0 && vboard[i+3]==B_ROOK){
					pos_mov[j][i]=0;
					pos_mov[j][i+1]=B_ROOK;
					pos_mov[j][i+2]=B_KING;
					pos_mov[j][i+3]=0;
					pos_mov[j][2] = -4;
					pos_mov[j][0] = -1;					
					pos_mov[j][10] = -1;
					j++;

					int pos_mov_next[150][120];
					int temp[120];
					memcpy(temp, pos_mov[j], sizeof(int)*120);
					temp[1]=-1;
					temp[11]=-1;						
					int num = get_pos_mov_white(pos_mov_next, temp);

					for(int k=0; k<num; k++){
						if(pos_mov_next[k][i] >0 || pos_mov_next[k][i+1] >0 || pos_mov_next[k][i+2] >0){
							j--;
							memcpy(pos_mov[j], vboard, sizeof(int)*120);
							break;
						}
					}
				}
				if(pos_mov[j][10]== -3 && vboard[i-1]==0 && vboard[i-2]==0 && vboard[i-3]==0 && vboard[i-4]==B_ROOK){
					pos_mov[j][i]=0;
					pos_mov[j][i-1]=B_ROOK;
					pos_mov[j][i-2]=B_KING;
					pos_mov[j][i-3]=0;
					pos_mov[j][i-4]=0;
					pos_mov[j][12] = -4;
					pos_mov[j][0] = -1;					
					pos_mov[j][10] = -1;
					j++;
						
					int pos_mov_next[150][120];
					int temp[120];
					memcpy(temp, pos_mov[j], sizeof(int)*120);
					temp[1]=-1;
					temp[11]=-1;
					int num = get_pos_mov_white(pos_mov_next, temp);

					for(int k=0; k<num; k++){
						if(pos_mov_next[k][i] >0 || pos_mov_next[k][i-1] >0 || pos_mov_next[k][i-2] >0){
							j--;
							memcpy(pos_mov[j], vboard, sizeof(int)*120);
							break;
						}
					}
				}
			}

			else if(vboard[i]==B_QUEEN){
				for(int k = 1;;k++){
					if(vboard[i+10*k]==0){
						pos_mov[j][i] = 0;
						pos_mov[j][i+k*10] = B_QUEEN;
						j++;
					}
					else if(vboard[i+10*k]>0){						
						pos_mov[j][i] = 0;
						pos_mov[j][i+k*10] = B_QUEEN;
						pos_mov[j][5]--;
						j++;
						break;
					}
					else{
						break;
					}
				}
				
				for(int k = 1;;k++){
					if(vboard[i+1*k]==0){
						pos_mov[j][i] = 0;
						pos_mov[j][i+k*1] = B_QUEEN;
						j++;
					}
					else if(vboard[i+1*k]>0){ 						
						pos_mov[j][i] = 0;
						pos_mov[j][i+k*1] = B_QUEEN;
						pos_mov[j][5]--;
						j++;
						break;
					}
					else{
						break;
					}
				}

				for(int k = 1;;k++){
					if(vboard[i+(-1)*k]==0){
						pos_mov[j][i] = 0;
						pos_mov[j][i+k*(-1)] = B_QUEEN;
						j++;
					}
					else if(vboard[i+(-1)*k]>0){ 						
						pos_mov[j][i] = 0;
						pos_mov[j][i+k*(-1)] = B_QUEEN;
						pos_mov[j][5]--;
						j++;
						break;
					}
					else{
						break;
					}
				}
				
				for(int k = 1;;k++){
					if(vboard[i+(-10)*k]==0){
						pos_mov[j][i] = 0;
						pos_mov[j][i+k*(-10)] = B_QUEEN;
						j++;
					}
					else if(vboard[i+(-10)*k]>0){ 					
						pos_mov[j][i] = 0;
						pos_mov[j][i+k*(-10)] = B_QUEEN;
						pos_mov[j][5]--;
						j++;
						break;
					}
					else{
						break;
					}
				}
				for(int k = 1;;k++){
					if(vboard[i+9*k]==0){
						pos_mov[j][i] = 0;
						pos_mov[j][i+k*9] = B_QUEEN;
						j++;
					}
					else if(vboard[i+9*k]>0){ 						
						pos_mov[j][i] = 0;
						pos_mov[j][i+k*9] = B_QUEEN;
						pos_mov[j][5]--;
						j++;
						break;
					}
					else{
						break;
					}
				}
				
				for(int k = 1;;k++){
					if(vboard[i+11*k]==0){
						pos_mov[j][i] = 0;
						pos_mov[j][i+k*11] = B_QUEEN;
						j++;
					}
					else if(vboard[i+11*k]>0){ 					
						pos_mov[j][i] = 0;
						pos_mov[j][i+k*11] = B_QUEEN;
						pos_mov[j][5]--;
						j++;
						break;
					}
					else{
						break;
					}
				}

				for(int k = 1;;k++){
					if(vboard[i+(-9)*k]==0){
						pos_mov[j][i] = 0;
						pos_mov[j][i+k*(-9)] = B_QUEEN;
						j++;
					}
					else if(vboard[i+(-9)*k]>0){ 					
						pos_mov[j][i] = 0;
						pos_mov[j][i+k*(-9)] = B_QUEEN;
						pos_mov[j][5]--;
						j++;
						break;
					}
					else{
						break;
					}
				}
				
				for(int k = 1;;k++){
					if(vboard[i+(-11)*k]==0){
						pos_mov[j][i] = 0;
						pos_mov[j][i+k*(-11)] = B_QUEEN;
						j++;
					}
					else if(vboard[i+(-11)*k]>0){ 						
						pos_mov[j][i] = 0;
						pos_mov[j][i+k*(-11)] = B_QUEEN;
						pos_mov[j][5]--;
						j++;
						break;
					}
					else{
						break;
					}
				}
			}

			else if(vboard[i]==B_ROOK){
				for(int k = 1;;k++){
					if(vboard[i+10*k]==0){
						pos_mov[j][i] = 0;
						pos_mov[j][i+k*10] = B_ROOK;
						if(i==28){
							pos_mov[j][0] = -1;
						}
						else if(i==21){
							pos_mov[j][10] = -1;
						}
						j++;
					}
					else if(vboard[i+10*k]>0){						
						pos_mov[j][i] = 0;
						pos_mov[j][i+k*10] = B_ROOK;
						pos_mov[j][5]--;
						if(i==28){
							pos_mov[j][0] = -1;
						}
						else if(i==21){
							pos_mov[j][10] = -1;
						}
						j++;
						break;
					}
					else{
						break;
					}
				}
				
				for(int k = 1;;k++){
					if(vboard[i+1*k]==0){
						pos_mov[j][i] = 0;
						pos_mov[j][i+k*1] = B_ROOK;
						if(i==28){
							pos_mov[j][0] = -1;
						}
						else if(i==21){
							pos_mov[j][10] = -1;
						}
						j++;
					}
					else if(vboard[i+1*k]>0){ 						
						pos_mov[j][i] = 0;
						pos_mov[j][i+k*1] = B_ROOK;
						pos_mov[j][5]--;
						if(i==28){
							pos_mov[j][0] = -1;
						}
						else if(i==21){
							pos_mov[j][10] = -1;
						}
						j++;
						break;
					}
					else{
						break;
					}
				}

				for(int k = 1;;k++){
					if(vboard[i+(-10)*k]==0){
						pos_mov[j][i] = 0;
						pos_mov[j][i+k*(-10)] = B_ROOK;
						if(i==28){
							pos_mov[j][0] = -1;
						}
						else if(i==21){
							pos_mov[j][10] = -1;
						}
						j++;
					}
					else if(vboard[i+(-10)*k]>0){ 					
						pos_mov[j][i] = 0;
						pos_mov[j][i+k*(-10)] = B_ROOK;
						pos_mov[j][5]--;
						if(i==28){
							pos_mov[j][0] = -1;
						}
						else if(i==21){
							pos_mov[j][10] = -1;
						}
						j++;
						break;
					}
					else{
						break;
					}
				}
				
				for(int k = 1;;k++){
					if(vboard[i+(-1)*k]==0){
						pos_mov[j][i] = 0;
						pos_mov[j][i+k*(-1)] = B_ROOK;
						if(i==28){
							pos_mov[j][0] = -1;
						}
						else if(i==21){
							pos_mov[j][10] = -1;
						}
						j++;
					}
					else if(vboard[i+(-1)*k]>0){ 						
						pos_mov[j][i] = 0;
						pos_mov[j][i+k*(-1)] = B_ROOK;
						pos_mov[j][5]--;
						if(i==28){
							pos_mov[j][0] = -1;
						}
						else if(i==21){
							pos_mov[j][10] = -1;
						}
						j++;
						break;
					}
					else{
						break;
					}
				}
			}

			else if(vboard[i]==B_BISHOP){
				for(int k = 1;;k++){
					if(vboard[i+9*k]==0){
						pos_mov[j][i] = 0;
						pos_mov[j][i+k*9] = B_BISHOP;
						j++;
					}
					else if(vboard[i+9*k]>0){						
						pos_mov[j][i] = 0; 
						pos_mov[j][i+k*9] = B_BISHOP;
						pos_mov[j][5]--;
						j++;
						break;
					}
					else{
						break;
					}
				}
				
				for(int k = 1;;k++){
					if(vboard[i+11*k]==0){
						pos_mov[j][i] = 0;
						pos_mov[j][i+k*11] = B_BISHOP;
						j++;
					}
					else if(vboard[i+11*k]>0){ 					
						pos_mov[j][i] = 0;
						pos_mov[j][i+k*11] = B_BISHOP;
						pos_mov[j][5]--;
						j++;
						break;
					}
					else{
						break;
					}
				}

				for(int k = 1;;k++){
					if(vboard[i+(-9)*k]==0){
						pos_mov[j][i] = 0;
						pos_mov[j][i+k*(-9)] = B_BISHOP;
						j++;
					}
					else if(vboard[i+(-9)*k]>0){ 					
						pos_mov[j][i] = 0;
						pos_mov[j][i+k*(-9)] = B_BISHOP;
						pos_mov[j][5]--;
						j++;
						break;
					}
					else{
						break;
					}
				}
				
				for(int k = 1;;k++){
					if(vboard[i+(-11)*k]==0){
						pos_mov[j][i] = 0;
						pos_mov[j][i+k*(-11)] = B_BISHOP;
						j++;
					}
					else if(vboard[i+(-11)*k]>0){ 						
						pos_mov[j][i] = 0;
						pos_mov[j][i+k*(-11)] = B_BISHOP;
						pos_mov[j][5]--;
						j++;
						break;
					}
					else{
						break;
					}
				}
			}

			else if(vboard[i]==B_KNIGHT){
				if(vboard[i+21]==0){
					pos_mov[j][i] = 0;
					pos_mov[j][i+21] = B_KNIGHT;
					j++;
				}
				else if(vboard[i+21]>0){
					pos_mov[j][i] = 0;
					pos_mov[j][i+21] = B_KNIGHT;
					pos_mov[j][5]--;
					j++;
				}
				if(vboard[i+19]==0){
					pos_mov[j][i] = 0;
					pos_mov[j][i+19] = B_KNIGHT;
					j++;
				}
				else if(vboard[i+19]>0){
					pos_mov[j][i] = 0;
					pos_mov[j][i+19] = B_KNIGHT;
					pos_mov[j][5]--;
					j++;
				}
				if(vboard[i+12]==0){
					pos_mov[j][i] = 0;
					pos_mov[j][i+12] = B_KNIGHT;
					j++;
				}
				else if(vboard[i+12]>0){
					pos_mov[j][i] = 0;
					pos_mov[j][i+12] = B_KNIGHT;
					pos_mov[j][5]--;
					j++;
				}
				if(vboard[i+8]==0){
					pos_mov[j][i] = 0;
					pos_mov[j][i+8] = B_KNIGHT;
					j++;
				}
				else if(vboard[i+8]>0){
					pos_mov[j][i] = 0;
					pos_mov[j][i+8] = B_KNIGHT;
					pos_mov[j][5]--;
					j++;
				}
				if(vboard[i-21]==0){
					pos_mov[j][i] = 0;
					pos_mov[j][i-21] = B_KNIGHT;
					j++;
				}
				else if(vboard[i-21]>0){
					pos_mov[j][i] = 0;
					pos_mov[j][i-21] = B_KNIGHT;
					pos_mov[j][5]--;
					j++;
				}
				if(vboard[i-19]==0){
					pos_mov[j][i] = 0;
					pos_mov[j][i-19] = B_KNIGHT;
					j++;
				}
				else if(vboard[i-19]>0){
					pos_mov[j][i] = 0;
					pos_mov[j][i-19] = B_KNIGHT;
					pos_mov[j][5]--;
					j++;
				}
				if(vboard[i-12]==0){
					pos_mov[j][i] = 0;
					pos_mov[j][i-12] = B_KNIGHT;
					j++;
				}
				else if(vboard[i-12]>0){
					pos_mov[j][i] = 0;
					pos_mov[j][i-12] = B_KNIGHT;
					pos_mov[j][5]--;
					j++;
				}
				if(vboard[i-8]==0){
					pos_mov[j][i] = 0;
					pos_mov[j][i-8] = B_KNIGHT;
					j++;
				}
				else if(vboard[i-8]>0){
					pos_mov[j][i] = 0;
					pos_mov[j][i-8] = B_KNIGHT;
					pos_mov[j][5]--;
					j++;
				}
			}

			else if(vboard[i]==B_PAWN){				
				if(vboard[i+10]==0){
					pos_mov[j][i] = 0;
					if(i>80){
						pos_mov[j][i+10] = B_QUEEN;
					}
					else{
						pos_mov[j][i+10] = B_PAWN;
					}
					j++;
				}				
				if(vboard[i+9]>0 || i+9==d){ 
					pos_mov[j][i] = 0;
					if(i>80){
						pos_mov[j][i+9] = B_QUEEN;
					}
					else{
						pos_mov[j][i+9] = B_PAWN;
					}
					if(i+9==d){
						pos_mov[j][i+1]=0;
					}
					pos_mov[j][5]--;
					j++;
				}				
				if(vboard[i+11]>0 || i+11==d){ 
					pos_mov[j][i] = 0;
					if(i>80){
						pos_mov[j][i+11] = B_QUEEN;
					}
					else{
						pos_mov[j][i+11] = B_PAWN;
					}
					pos_mov[j][i+11] = B_PAWN;
					if(i+11==d){
						pos_mov[j][i-1]=0;
					}
					pos_mov[j][5]--;
					j++;
				}
				if(i<39){				
					if(vboard[i+20]==0&& vboard[i+10]==0){
						pos_mov[j][i] = 0;
						pos_mov[j][i+10] = -5;
						pos_mov[j][i+20] = B_PAWN;
						j++;
					}
				}
					
			}

			

			
		}
	}
	if(d>=21 && d!=99){
		vboard[d]=-2;
	}
	return j;
				
}

			

	
		

int get_pos_mov_white(int pos_mov[150][120], int vboard[120]){

	int d=21;
	for(;d<99; d++){
		if(vboard[d]==-5){
			vboard[d]=0;
			break;
		}
	}

	for(int i = 0; i<150; i++){
		memcpy(pos_mov[i], vboard, sizeof(int)*120);
	}


	int j=0;	

	for(int i = 21; i <99; i++){
		if(vboard[i] > 0){			

			if(vboard[i]==W_KING){
				if(vboard[i+10]==0){
					pos_mov[j][i] = 0;
					pos_mov[j][i+10] = W_KING;
					pos_mov[j][1] = -1;
					pos_mov[j][11] = -1;
					j++;
				}
				else if(vboard[i+10]<-50){
					pos_mov[j][i] = 0;
					pos_mov[j][i+10] = W_KING;
					pos_mov[j][1] = -1;
					pos_mov[j][11] = -1;
					pos_mov[j][5]--;
					j++;
				}
				if(vboard[i+1]==0){
					pos_mov[j][i] = 0;
					pos_mov[j][i+1] = W_KING;
					pos_mov[j][1] = -1;
					pos_mov[j][11] = -1;
					j++;
				}
				else if(vboard[i+1]<-50){
					pos_mov[j][i] = 0;
					pos_mov[j][i+1] = W_KING;
					pos_mov[j][1] = -1;
					pos_mov[j][11] = -1;
					pos_mov[j][5]--;
					j++;
				}
				if(vboard[i-10]==0){
					pos_mov[j][i] = 0;
					pos_mov[j][i-10] = W_KING;
					pos_mov[j][1] = -1;
					pos_mov[j][11] = -1;
					j++;
				}
				else if(vboard[i-10]<-50){
					pos_mov[j][i] = 0;
					pos_mov[j][i-10] = W_KING;
					pos_mov[j][1] = -1;
					pos_mov[j][11] = -1;
					pos_mov[j][5]--;
					j++;
				}
				if(vboard[i-1]==0){
					pos_mov[j][i] = 0;
					pos_mov[j][i-1] = W_KING;
					pos_mov[j][1] = -1;
					j++;
				}
				else if(vboard[i-1]<-50){
					pos_mov[j][i] = 0;
					pos_mov[j][i-1] = W_KING;
					pos_mov[j][1] = -1;
					pos_mov[j][11] = -1;
					pos_mov[j][5]--;
					j++;
				}
				if(vboard[i+9]==0){
					pos_mov[j][i] = 0;
					pos_mov[j][i+9] = W_KING;
					pos_mov[j][1] = -1;
					pos_mov[j][11] = -1;
					j++;
				}
				else if(vboard[i+9]<-50){
					pos_mov[j][i] = 0;
					pos_mov[j][i+9] = W_KING;
					pos_mov[j][1] = -1;
					pos_mov[j][11] = -1;
					pos_mov[j][5]--;
					j++;
				}
				if(vboard[i+11]==0){
					pos_mov[j][i] = 0;
					pos_mov[j][i+11] = W_KING;
					pos_mov[j][1] = -1;
					pos_mov[j][11] = -1;
					j++;
				}
				else if(vboard[i+11]<-50){
					pos_mov[j][i] = 0;
					pos_mov[j][i+11] = W_KING;
					pos_mov[j][1] = -1;
					pos_mov[j][11] = -1;
					pos_mov[j][5]--;
					j++;
				}
				if(vboard[i-9]==0){
					pos_mov[j][i] = 0;
					pos_mov[j][i-9] = W_KING;
					pos_mov[j][1] = -1;
					pos_mov[j][11] = -1;
					j++;
				}
				else if(vboard[i-9]<-50){
					pos_mov[j][i] = 0;
					pos_mov[j][i-9] = W_KING;
					pos_mov[j][1] = -1;
					pos_mov[j][11] = -1;
					pos_mov[j][5]--;
					j++;
				}
				if(vboard[i-11]==0){
					pos_mov[j][i] = 0;
					pos_mov[j][i-11] = W_KING;
					pos_mov[j][1] = -1;
					pos_mov[j][11] = -1;
					j++;
				}
				else if(vboard[i-11]<-50){
					pos_mov[j][i] = 0;
					pos_mov[j][i-11] = W_KING;
					pos_mov[j][1] = -1;
					pos_mov[j][11] = -1;
					pos_mov[j][5]--;
					j++;
				}
				if(pos_mov[j][1]== -3 && vboard[i+1]==0 && vboard[i+2]==0 && vboard[i+3]==W_ROOK){
					pos_mov[j][i]=0;
					pos_mov[j][i+1]=W_ROOK;
					pos_mov[j][i+2]=W_KING;
					pos_mov[j][i+3]=0;
					pos_mov[j][3] = -4;
					pos_mov[j][1] = -1;
					pos_mov[j][11] = -1;
					j++;

					int pos_mov_nextw[150][120];
					int temp[120];
					memcpy(temp, pos_mov[j], sizeof(int)*120);
					temp[0]=-1;
					temp[10]=-1;
					int numw = get_pos_mov_black(pos_mov_nextw, temp);

					for(int k=0; k<numw; k++){
						if(pos_mov_nextw[k][i] <-50 || pos_mov_nextw[k][i+1] <-50 || pos_mov_nextw[k][i+2] <-50){
							j--;
							memcpy(pos_mov[j], vboard, sizeof(int)*120);
							break;
						}
					}
				}
				if(pos_mov[j][11]== -3 && vboard[i-1]==0 && vboard[i-2]==0 && vboard[i-3]==0 && vboard[i-4]==W_ROOK){
					pos_mov[j][i]=0;
					pos_mov[j][i-1]=W_ROOK;
					pos_mov[j][i-2]=W_KING;
					pos_mov[j][i-3]=0;
					pos_mov[j][i-4]=0;
					pos_mov[j][13] = -4;
					pos_mov[j][1] = -1;
					pos_mov[j][11] = -1;
					j++;
						
					int pos_mov_nextw[150][120];
					int temp[120];
					memcpy(temp, pos_mov[j], sizeof(int)*120);
					temp[0]=-1;
					temp[10]=-1;
					int numw = get_pos_mov_black(pos_mov_nextw, temp);

					for(int k=0; k<numw; k++){
						if(pos_mov_nextw[k][i] <-50 || pos_mov_nextw[k][i-1] <-50 || pos_mov_nextw[k][i-2] <-50){
							j--;
							memcpy(pos_mov[j], vboard, sizeof(int)*120);
							break;
						}
					}
				}
			}

			else if(vboard[i]==W_QUEEN){
				for(int k = 1;;k++){
					if(vboard[i+10*k]==0){
						pos_mov[j][i] = 0;
						pos_mov[j][i+k*10] = W_QUEEN;
						j++;
					}
					else if(vboard[i+10*k]<-50){ 						
						pos_mov[j][i] = 0;
						pos_mov[j][i+k*10] = W_QUEEN;
						pos_mov[j][5]--;
						j++;
						break;
					}
					else{
						break;
					}
				}
				
				for(int k = 1;;k++){
					if(vboard[i+1*k]==0){
						pos_mov[j][i] = 0;
						pos_mov[j][i+k*1] = W_QUEEN;
						j++;
					}
					else if(vboard[i+1*k]<-50){ 					
						pos_mov[j][i] = 0;
						pos_mov[j][i+k*1] = W_QUEEN;
						pos_mov[j][5]--;
						j++;
						break;
					}
					else{
						break;
					}
				}

				for(int k = 1;;k++){
					if(vboard[i+(-1)*k]==0){
						pos_mov[j][i] = 0;
						pos_mov[j][i+k*(-1)] = W_QUEEN;
						j++;
					}
					else if(vboard[i+(-1)*k]<-50){ 					
						pos_mov[j][i] = 0;
						pos_mov[j][i+k*(-1)] = W_QUEEN;
						pos_mov[j][5]--;
						j++;
						break;
					}
					else{
						break;
					}
				}
				
				for(int k = 1;;k++){
					if(vboard[i+(-10)*k]==0){
						pos_mov[j][i] = 0;
						pos_mov[j][i+k*(-10)] = W_QUEEN;
						j++;
					}
					else if(vboard[i+(-10)*k]<-50){ 			
						pos_mov[j][i] = 0;
						pos_mov[j][i+k*(-10)] = W_QUEEN;
						pos_mov[j][5]--;
						j++;
						break;
					}
					else{
						break;
					}
				}
				for(int k = 1;;k++){
					if(vboard[i+9*k]==0){
						pos_mov[j][i] = 0;
						pos_mov[j][i+k*9] = W_QUEEN;
						j++;
					}
					else if(vboard[i+9*k]<-50){ 				
						pos_mov[j][i] = 0;
						pos_mov[j][i+k*9] = W_QUEEN;
						pos_mov[j][5]--;
						j++;
						break;
					}
					else{
						break;
					}
				}
				
				for(int k = 1;;k++){
					if(vboard[i+11*k]==0){
						pos_mov[j][i] = 0;
						pos_mov[j][i+k*11] = W_QUEEN;
						j++;
					}
					else if(vboard[i+11*k]<-50){ 				
						pos_mov[j][i] = 0;
						pos_mov[j][i+k*11] = W_QUEEN;
						pos_mov[j][5]--;
						j++;
						break;
					}
					else{
						break;
					}
				}

				for(int k = 1;;k++){
					if(vboard[i+(-9)*k]==0){
						pos_mov[j][i] = 0;
						pos_mov[j][i+k*(-9)] = W_QUEEN;
						j++;
					}
					else if(vboard[i+(-9)*k]<-50){ 			
						pos_mov[j][i] = 0;
						pos_mov[j][i+k*(-9)] = W_QUEEN;
						pos_mov[j][5]--;
						j++;
						break;
					}
					else{
						break;
					}
				}
				
				for(int k = 1;;k++){
					if(vboard[i+(-11)*k]==0){
						pos_mov[j][i] = 0;
						pos_mov[j][i+k*(-11)] = W_QUEEN;
						j++;
					}
					else if(vboard[i+(-11)*k]<-50){ 			
						pos_mov[j][i] = 0;
						pos_mov[j][i+k*(-11)] = W_QUEEN;
						pos_mov[j][5]--;
						j++;
						break;
					}
					else{
						break;
					}
				}
			}

			else if(vboard[i]==W_ROOK){
				for(int k = 1;;k++){
					if(vboard[i+10*k]==0){
						pos_mov[j][i] = 0;
						pos_mov[j][i+k*10] = W_ROOK;
						if(i==98){
							pos_mov[j][1] = -1;
						}
						else if(i==91){
							pos_mov[j][11] = -1;
						}
						j++;
					}
					else if(vboard[i+10*k]<-50){ 					
						pos_mov[j][i] = 0;
						pos_mov[j][i+k*10] = W_ROOK;
						pos_mov[j][5]--;
						if(i==98){
							pos_mov[j][1] = -1;
						}
						else if(i==91){
							pos_mov[j][11] = -1;
						}
						j++;
						break;
					}
					else{
						break;
					}
				}
				
				for(int k = 1;;k++){
					if(vboard[i+1*k]==0){
						pos_mov[j][i] = 0;
						pos_mov[j][i+k*1] = W_ROOK;
						if(i==98){
							pos_mov[j][1] = -1;
						}
						else if(i==91){
							pos_mov[j][11] = -1;
						}
						j++;
					}
					else if(vboard[i+1*k]<-50){ 					
						pos_mov[j][i] = 0;
						pos_mov[j][i+k*1] = W_ROOK;
						pos_mov[j][5]--;
						if(i==98){
							pos_mov[j][1] = -1;
						}
						else if(i==91){
							pos_mov[j][11] = -1;
						}
						j++;
						break;
					}
					else{
						break;
					}
				}

				for(int k = 1;;k++){
					if(vboard[i+(-10)*k]==0){
						pos_mov[j][i] = 0;
						pos_mov[j][i+k*(-10)] = W_ROOK;
						if(i==98){
							pos_mov[j][1] = -1;
						}
						else if(i==91){
							pos_mov[j][11] = -1;
						}
						j++;
					}
					else if(vboard[i+(-10)*k]<-50){ 		
						pos_mov[j][i] = 0;
						pos_mov[j][i+k*(-10)] = W_ROOK;
						pos_mov[j][5]--;
						if(i==98){
							pos_mov[j][1] = -1;
						}
						else if(i==91){
							pos_mov[j][11] = -1;
						}
						j++;
						break;
					}
					else{
						break;
					}
				}
				
				for(int k = 1;;k++){
					if(vboard[i+(-1)*k]==0){
						pos_mov[j][i] = 0;
						pos_mov[j][i+k*(-1)] = W_ROOK;
						if(i==98){
							pos_mov[j][1] = -1;
						}
						else if(i==91){
							pos_mov[j][11] = -1;
						}
						j++;
					}
					else if(vboard[i+(-1)*k]<-50){ 				
						pos_mov[j][i] = 0;
						pos_mov[j][i+k*(-1)] = W_ROOK;
						pos_mov[j][5]--;
						if(i==98){
							pos_mov[j][1] = -1;
						}
						else if(i==91){
							pos_mov[j][11] = -1;
						}
						j++;
						break;
					}
					else{
						break;
					}
				}
			}

			else if(vboard[i]==W_BISHOP){
				for(int k = 1;;k++){
					if(vboard[i+9*k]==0){
						pos_mov[j][i] = 0;
						pos_mov[j][i+k*9] = W_BISHOP;
						j++;
					}
					else if(vboard[i+9*k]<-50){ 				
						pos_mov[j][i] = 0;
						pos_mov[j][i+k*9] = W_BISHOP;
						pos_mov[j][5]--;
						j++;
						break;
					}
					else{
						break;
					}
				}
				
				for(int k = 1;;k++){
					if(vboard[i+11*k]==0){
						pos_mov[j][i] = 0;
						pos_mov[j][i+k*11] = W_BISHOP;
						j++;
					}
					else if(vboard[i+11*k]<-50){ 				
						pos_mov[j][i] = 0;
						pos_mov[j][i+k*11] = W_BISHOP;
						pos_mov[j][5]--;
						j++;
						break;
					}
					else{
						break;
					}
				}

				for(int k = 1;;k++){
					if(vboard[i+(-9)*k]==0){
						pos_mov[j][i] = 0;
						pos_mov[j][i+k*(-9)] = W_BISHOP;
						j++;
					}
					else if(vboard[i+(-9)*k]<-50){ 			
						pos_mov[j][i] = 0;
						pos_mov[j][i+k*(-9)] = W_BISHOP;
						pos_mov[j][5]--;
						j++;
						break;
					}
					else{
						break;
					}
				}
				
				for(int k = 1;;k++){
					if(vboard[i+(-11)*k]==0){
						pos_mov[j][i] = 0;
						pos_mov[j][i+k*(-11)] = W_BISHOP;
						j++;
					}
					else if(vboard[i+(-11)*k]<-50){	 		
						pos_mov[j][i] = 0;
						pos_mov[j][i+k*(-11)] = W_BISHOP;
						pos_mov[j][5]--;
						j++;
						break;
					}
					else{
						break;
					}
				}
			}

			else if(vboard[i]==W_KNIGHT){
				if(vboard[i+21]==0){
					pos_mov[j][i] = 0;
					pos_mov[j][i+21] = W_KNIGHT;
					j++;
				}
				else if(vboard[i+21]<-50){
					pos_mov[j][i] = 0;
					pos_mov[j][i+21] = W_KNIGHT;
					pos_mov[j][5]--;
					j++;
				}
				if(vboard[i+19]==0){
					pos_mov[j][i] = 0;
					pos_mov[j][i+19] = W_KNIGHT;
					j++;
				}
				else if(vboard[i+19]<-50){
					pos_mov[j][i] = 0;
					pos_mov[j][i+19] = W_KNIGHT;
					pos_mov[j][5]--;
					j++;
				}
				if(vboard[i+12]==0){
					pos_mov[j][i] = 0;
					pos_mov[j][i+12] = W_KNIGHT;
					j++;
				}
				else if(vboard[i+12]<-50){
					pos_mov[j][i] = 0;
					pos_mov[j][i+12] = W_KNIGHT;
					pos_mov[j][5]--;
					j++;
				}
				if(vboard[i+8]==0){
					pos_mov[j][i] = 0;
					pos_mov[j][i+8] = W_KNIGHT;
					j++;
				}
				else if(vboard[i+8]<-50){
					pos_mov[j][i] = 0;
					pos_mov[j][i+8] = W_KNIGHT;
					pos_mov[j][5]--;
					j++;
				}
				if(vboard[i-21]==0){
					pos_mov[j][i] = 0;
					pos_mov[j][i-21] = W_KNIGHT;
					j++;
				}
				else if(vboard[i-21]<-50){
					pos_mov[j][i] = 0;
					pos_mov[j][i-21] = W_KNIGHT;
					pos_mov[j][5]--;
					j++;
				}
				if(vboard[i-19]==0){
					pos_mov[j][i] = 0;
					pos_mov[j][i-19] = W_KNIGHT;
					j++;
				}
				else if(vboard[i-19]<-50){
					pos_mov[j][i] = 0;
					pos_mov[j][i-19] = W_KNIGHT;
					pos_mov[j][5]--;
					j++;
				}
				if(vboard[i-12]==0){
					pos_mov[j][i] = 0;
					pos_mov[j][i-12] = W_KNIGHT;
					j++;
				}
				else if(vboard[i-12]<-50){
					pos_mov[j][i] = 0;
					pos_mov[j][i-12] = W_KNIGHT;
					pos_mov[j][5]--;
					j++;
				}
				if(vboard[i-8]==0){
					pos_mov[j][i] = 0;
					pos_mov[j][i-8] = W_KNIGHT;
					j++;
				}
				else if(vboard[i-8]<-50){
					pos_mov[j][i] = 0;
					pos_mov[j][i-8] = W_KNIGHT;
					pos_mov[j][5]--;
					j++;
				}
			}

			else if(vboard[i]==W_PAWN){				
				if(vboard[i-10]==0){
					pos_mov[j][i] = 0;
					if(i<40){
						pos_mov[j][i-10] = W_QUEEN;
					}
					else{
						pos_mov[j][i-10] = W_PAWN;
					}
					j++;
				}				
				if(vboard[i-9]<-50 || i-9==d){
					pos_mov[j][i] = 0;
					if(i<40){
						pos_mov[j][i-9] = W_QUEEN;
					}
					else{
						pos_mov[j][i-9] = W_PAWN;
					}
					if(i-9==d){
						pos_mov[j][i+1]=0;
					}
					pos_mov[j][5]--;
					j++;
				}				
				if(vboard[i-11]<-50 || i-11==d){
					pos_mov[j][i] = 0;
					if(i<40){
						pos_mov[j][i-11] = W_QUEEN;
					}
					else{
						pos_mov[j][i-11] = W_PAWN;
					}
					if(i-11==d){
						pos_mov[j][i-1]=0;
					}
					pos_mov[j][5]--;
					j++;
				}
				if(i>80){				
					if(vboard[i-20]==0 && vboard[i-10]==0){
						pos_mov[j][i] = 0;
						pos_mov[j][i-10] = -2;
						pos_mov[j][i-20] = W_PAWN;
						j++;
					}
				}
					
			}
		}
	}
	if(d>=21 && d!=99){
		vboard[d]=-5;
	}
	return j;
}
