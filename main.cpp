#include "main.hpp"

void enter_fen(int vboard[120]){
	std::cout << "\nenter FEN>";
	std::string input;
	std::cin.ignore();
	std::getline(std::cin, input);
	int state = 0;
	int rboard[64];
	for(int i = 0; i<64; i++){
		rboard[i]=0;
	}
	int j = 0;
	int en;
	vboard[0]=-1;
	vboard[1]=-1;
	vboard[10]=-1;
	vboard[11]=-1;
	for(int i = 0; input[i]!='\0'; i++){
		if(state==0){
			if(input[i]=='p'){
				rboard[j]=B_PAWN;
				j++;
			}
			else if(input[i]=='P'){
				rboard[j]=W_PAWN;
				j++;
			}
			else if(input[i]=='r'){
				rboard[j]=B_ROOK;
				j++;
			}
			else if(input[i]=='R'){
				rboard[j]=W_ROOK;
				j++;
			}
			else if(input[i]=='n'){
				rboard[j]=B_KNIGHT;
				j++;
			}
			else if(input[i]=='N'){
				rboard[j]=W_KNIGHT;
				j++;
			}
			else if(input[i]=='b'){
				rboard[j]=B_BISHOP;
				j++;
			}
			else if(input[i]=='B'){
				rboard[j]=W_BISHOP;
				j++;
			}
			else if(input[i]=='q'){
				rboard[j]=B_QUEEN;
				j++;
			}
			else if(input[i]=='Q'){
				rboard[j]=W_QUEEN;
				j++;
			}
			else if(input[i]=='k'){
				rboard[j]=B_KING;
				j++;
			}
			else if(input[i]=='K'){
				rboard[j]=W_KING;
				j++;
			}
			else if(input[i]=='1'){
				j+=1;
			}
			else if(input[i]=='2'){
				j+=2;
			}
			else if(input[i]=='3'){
				j+=3;
			}
			else if(input[i]=='4'){
				j+=4;
			}
			else if(input[i]=='5'){
				j+=5;
			}
			else if(input[i]=='6'){
				j+=6;
			}
			else if(input[i]=='7'){
				j+=7;
			}
			else if(input[i]=='8'){
				j+=8;
			}
			else if(input[i]=='/'){
				//NOTHING, stands for a new row.
			}
			else if(input[i]==' '){
				state=1;
			}
		}
		else if(state==1){
			if(input[i]=='w'){
				WHOSE_MOVE=1;
			}
			else if(input[i]=='b'){
				WHOSE_MOVE=-1;
			}
			else if(input[i]==' '){
				state=2;
			}
		}
		else if(state==2){
			if(input[i]=='k'){
				vboard[0]=-3;
				vboard[2]=-1;
			}
			else if(input[i]=='q'){
				vboard[10]=-3;
				vboard[2]=-1;
			}
			else if(input[i]=='K'){
				vboard[1]=-3;
				vboard[3]=-1;
			}
			else if(input[i]=='Q'){
				vboard[11]=-3;
				vboard[3]=-1;
			}
			else if(input[i]==' '){
				state=3;
			}
		}
		else if(state==3){
			if(input[i]=='a'){
				en=1;
			}
			else if(input[i]=='b'){
				en=2;
			}
			else if(input[i]=='c'){
				en=3;
			}
			else if(input[i]=='d'){
				en=4;
			}
			else if(input[i]=='e'){
				en=5;
			}
			else if(input[i]=='f'){
				en=6;
			}
			else if(input[i]=='g'){
				en=7;
			}
			else if(input[i]=='h'){
				en=8;
			}			
			else if(input[i]=='3'){
				rboard[3*en]=-2;
			}			
			else if(input[i]=='6'){
				rboard[6*en]=-2;
			}						
			else if(input[i]==' '){
				state=4;
			}
		}
		else if(state==4){
			if(input[i]==' '){
				state=5;
			}
		}
		else if(state==5){
			if(input[i]==' '){
				state=6;
			}
			else{
				std::string t = input.substr(i);
				MOVE_COUNTER=std::stoi(t);
				state=6;
			}
		}
	}
	for(int i = 0; i<8; i++){
		for(j = 0; j<8; j++){
			vboard[j + 21 + i*10]= rboard[j+i*8];
		}
	}
}

void get_fen(int vboard[120]){
	int rboard[64];
	for(int i = 0; i<8; i++){
		for(int j = 0; j<8; j++){
			rboard[j+i*8] = vboard[j + 21 + i*10];
		}
	}
	int counter=0;
	for(int i = 0; i<8; i++){
		if(i!=0){
			std::cout << "/";
		}
		for(int j = 0; j<8; j++){
			if((rboard[i*8+j]<-50 || rboard[i*8+j]>0) && counter!=0){
				std::cout << counter;
				counter=0;
			}
			if(rboard[i*8+j]==B_PAWN){
				std::cout << "p";
			}
			else if(rboard[i*8+j]==W_PAWN){
				std::cout << "P";
			}
			else if(rboard[i*8+j]==B_KNIGHT){
				std::cout << "n";
			}
			else if(rboard[i*8+j]==W_KNIGHT){
				std::cout << "N";
			}
			else if(rboard[i*8+j]==B_BISHOP){
				std::cout << "b";
			}
			else if(rboard[i*8+j]==W_BISHOP){
				std::cout << "B";
			}
			else if(rboard[i*8+j]==B_ROOK){
				std::cout << "r";
			}
			else if(rboard[i*8+j]==W_ROOK){
				std::cout << "R";
			}
			else if(rboard[i*8+j]==B_QUEEN){
				std::cout << "q";
			}
			else if(rboard[i*8+j]==W_QUEEN){
				std::cout << "Q";
			}
			else if(rboard[i*8+j]==B_KING){
				std::cout << "k";
			}
			else if(rboard[i*8+j]==W_KING){
				std::cout << "K";
			}
			else{
				counter++;
			}
		}
		if(counter!=0){
			std::cout << counter;
		}
		counter=0;
	}
	std::cout << " ";

	if(WHOSE_MOVE==-1){
		std::cout << "b";
	}
	else if(WHOSE_MOVE==1){
		std::cout << "w";
	}
	std::cout << " ";

	int anything = 0;
	
	if(vboard[1]==-3){
		std::cout << "K";
		anything = 1;
	}
	if(vboard[11]==-3){
		std::cout << "Q";
		anything = 1;
	}
	if(vboard[0]==-3){
		std::cout << "k";
		anything = 1;
	}
	if(vboard[10]==-3){
		std::cout << "q";
		anything = 1;
	}
	if(anything==0){
		std::cout << "-";
	}
	std::cout << " ";
	anything = 0;

	
	for(int i = 0; i<8; i++){
		for(int j = 0; j<8; j++){
			if(rboard[i*8+j]==-2 || rboard[i*8+j]==-5){
				anything = 1;
				if(j==0){
					std::cout << "a";
				}
				else if(j==1){
					std::cout << "b";
				}
				else if(j==2){
					std::cout << "c";
				}
				else if(j==3){
					std::cout << "d";
				}
				else if(j==4){
					std::cout << "e";
				}
				else if(j==5){
					std::cout << "f";
				}
				else if(j==6){
					std::cout << "g";
				}
				else if(j==7){
					std::cout << "h";
				}
				std::cout << 8-i;
			}
		}
	}
	if(anything==0){
		std::cout << "-";
	}
	std::cout << " ";

	std::cout << "0";
	std::cout << " ";
	
	std::cout << MOVE_COUNTER;
}
			
			

	
	


void edit_deepness(){
	std::cout << "\nnew deepness>";
	int input;
	std::cin >> input;
	DEEPNESS = input;
}

void edit_sec_deepness(){
	std::cout << "\nnew secondary deepness>";
	int input;
	std::cin >> input;
	SEC_DEEPNESS = input;
}

void edit_required_captures(){
	std::cout << "\nnew required captures>";
	int input;
	std::cin >> input;
	REQUIRED_CAPTURES = (-1)*(input+3);
}

void edit_nopsd(){
	std::cout << "\nmax number of pieces needed for secondary deepness>";
	int input;
	std::cin >> input;
	NOPSD = input;
}

void edit_nomsd(){
	std::cout << "\nmax number of possible moves needed for secondary deepness>";
	int input;
	std::cin >> input;
	NOMSD = input;
}

void edit_horizon_deepness(){
	std::cout << "\nnew horizon-deepness>";
	int input;
	std::cin >> input;
	HORIZON_DEEPNESS = input;
}

void edit_field(int vboard[120]){
	std::cout << "\nenter index>";
	int input1;
	std::cin >> input1;
	std::cout << "\nenter new value for field>";
	int input2;
	std::cin >> input2;
	if(input1<120){
		vboard[input1] = input2;
	}
}

void get_values(int vboard[120]){
	std::cout << "\n\ndeepness: " << DEEPNESS;
	std::cout << "\nsecondary deepness: " << SEC_DEEPNESS;
	std::cout << "\nhorizon deepness: " << HORIZON_DEEPNESS;
	std::cout << "\ncaptures required for horizon deepness: " << REQUIRED_CAPTURES+3;
	std::cout << "\nnompsd: " << NOPSD;
	std::cout << "\nnommsd: " << NOMSD;
	std::cout << "\nnumber of moves: " << MOVE_COUNTER;
	std::cout << "\nwhose move: " << WHOSE_MOVE;
	std::cout << "\nFEN: ";
	get_fen(vboard);
	std::cout << "\n";
}

void change_theme(){
	std::cout << "\ntheme ('black', 'green', 'red' or 'manually'>";
	std::string input;
	std::cin >> input;
	if(input=="black"){
		COLOR_R=400;
		COLOR_G=400;
		COLOR_B=400;
	}
	else if(input=="green"){
		COLOR_R=280;
		COLOR_G=380;
		COLOR_B=280;
	}
	else if(input=="red"){
		COLOR_R=600;
		COLOR_G=0;
		COLOR_B=0;
	}
	else if(input=="manually"){
		std::cout << "COLOR R (0-1000)>";
		int input1;
		std::cin >> input1;
		COLOR_R = input1;
		std::cout << "COLOR G (0-1000)>";
		input1;
		std::cin >> input1;
		COLOR_G = input1;
		std::cout << "COLOR B (0-1000)>";
		input1;
		std::cin >> input1;
		COLOR_B = input1;
	}
}
	

void print_board(int vboard[120]){
	std::cout << "\n";
	for(int j = 0; j<12; j++){
		for(int i = 0; i<10; i++){
			std::cout << vboard[i+j*10] <<"\t";
		}
		std::cout << "\n";
	}
	std::cout << "\n";
}

void edit_field_al(int vboard[120]){
	std::cout << "\nenter field (e.g. h3 or c5)>";
	std::string input;
	int x=1000;
	int y=1000;
	int value = 0;;
	std::cin >> input;

	if(input[0]=='a'){
		x = 0;
	}
	else if(input[0]=='b'){
		x = 1;
	}
	else if(input[0]=='c'){
		x = 2;
	}
	else if(input[0]=='d'){
		x = 3;
	}
	else if(input[0]=='e'){
		x = 4;
	}
	else if(input[0]=='f'){
		x = 5;
	}
	else if(input[0]=='g'){
		x = 6;
	}
	else if(input[0]=='h'){
		x = 7;
	}
	if(input[1]=='8'){
		y = 0;
	}
	else if(input[1]=='7'){
		y = 1;
	}
	else if(input[1]=='6'){
		y = 2;
	}
	else if(input[1]=='5'){
		y = 3;
	}
	else if(input[1]=='4'){
		y = 4;
	}
	else if(input[1]=='3'){
		y = 5;
	}
	else if(input[1]=='2'){
		y = 6;
	}
	else if(input[1]=='1'){
		y = 7;
	}


	std::cout << "\nenter new value for field (e.g. b_pawn, w_knight or void)>";
	std::cin >> input;

	if(input=="b_pawn"){
		value=B_PAWN;
	}
	else if(input=="b_knight"){
		value=B_KNIGHT;
	}
	else if(input=="b_bishop"){
		value=B_BISHOP;
	}
	else if(input=="b_rook"){
		value=B_ROOK;
	}
	else if(input=="b_queen"){
		value=B_QUEEN;
	}
	else if(input=="b_king"){
		value=B_KING;
	}
	else if(input=="w_pawn"){
		value=W_PAWN;
	}
	else if(input=="w_knight"){
		value=W_KNIGHT;
	}
	else if(input=="w_bishop"){
		value=W_BISHOP;
	}
	else if(input=="w_rook"){
		value=W_ROOK;
	}
	else if(input=="w_queen"){
		value=W_QUEEN;
	}
	else if(input=="w_king"){
		value=W_KING;
	}
	else if(input=="void" || input=="0"){
		value=0;
	}

	if(x + 21 + y*10<120){
		vboard[x + 21 + y*10] = value;
	}
}

void edit_whose_move(){
	std::cout << "\nwhose move (-1 for black, 1 for white)>";
	int input;
	std::cin >> input;
	WHOSE_MOVE = input;
}

void edit_number_of_moves(){
	std::cout << "\nnumber of moves>";
	int input;
	std::cin >> input;
	MOVE_COUNTER = input;
}

	

int config(int vboard[120]){
	std::cout << "\033[2J\033[1;1H";
	std::string input;
	while(input!="exit"){
		std::cout << "\nconfiguration>";
		std::cin >> input;
	
	
		if(input=="edit_deepness" || input=="deepness"){
			edit_deepness();
		}
		else if(input=="edit_secondary_deepness" || input=="sec_deepness"){
			edit_sec_deepness();
		}
		else if(input=="edit_required_captures_for_horizon_deepness" || input=="required_captures"){
			edit_required_captures();
		}
		else if(input=="edit_horizon_deepness" || input=="horizon_deepness"){
			edit_horizon_deepness();
		}
		else if(input=="edit_max_number_of_pieces_needed_for_secondary_deepness" || input=="nompsd"){
			edit_nopsd();
		}
		else if(input=="edit_max_number_of_moves_needed_for_secondary_deepness" || input=="nommsd"){
			edit_nomsd();
		}
		else if(input=="edit_field" || input=="field"){
			edit_field(vboard);
		}
		else if(input=="print_board" || input=="print"){
			print_board(vboard);
		}
		else if(input=="edit_field_abstraction_layered" || input=="field_al"){
			edit_field_al(vboard);
		}
		else if(input=="edit_whose_move" || input=="move"){
			edit_whose_move();
		}
		else if(input=="edit_number_of_moves" || input=="number_of_moves" || input=="move_counter"){
			edit_number_of_moves();
		}
		else if(input=="enter_fen" || input=="fen"){
			enter_fen(vboard);
		}
		else if(input=="get_fen"){
			get_fen(vboard);
		}
		else if(input=="get_values" || input =="values"){
			get_values(vboard);
		}
		else if(input=="change_theme" || input =="theme"){
			change_theme();
		}
		else if(input=="help"){
			std::cout << "\ncommands:\n\tedit_deepness / deepness\n\tedit_secondary_deepness / sec_deepness\n\tedit_max_number_of_pieces_needed_for_secondary_deepness / nompsd\n\tedit_max_number_of_pieces_needed_for_secondary_deepness / nommsd\n\tedit_horizon_deepness / horizon_deepness\n\tedit_required_captures_for_horizon_deepness / required_captures\n\tedit_field / field\n\tedit_field_abstraction_layered / field_al\n\tedit_whose_move / move\n\tedit_number_of_moves / number_of_moves / move_counter\n\tenter_fen / fen\n\tget_fen\n\tget_values / values\n\tprint_board / print\n\tchange_theme / theme\n\texit\n\tback_to_start_menu / start_menu\n\thelp\n";
		}
		else if(input=="back_to_start_menu" || input=="start_menu"){
			return -1;
		}
		else{
			std::cout << "Inoperative Input\n";
		}
	}
	return 0;
}


int sandbox(){
	mouse_open();
	init_picture(COLOR_R, COLOR_G, COLOR_B);
	Picture frame;
	
	Board board;

	int move_active = 0;
	int move_cont = 0;
	int move_old_xfield = 0;
	int move_old_yfield = 0;

	WHOSE_MOVE=1;
	const unsigned char pawn[] =  { "             o       ( )      |_|            " };

	char input;

	int value; 
	

	while(input!=27){
		input = getch();

		if(input=='z'){
			board.undo();
			
			frame.build_pic(board, move_cont);
			while(MOUSE_L_BUTTON == 1){
				mouse_update();
			}			
		}

		if(input=='c'){
			endwin();
			if(config(board.get_vboard())==-1){
				return 0;
			}
			board.vboard_to_rboard();
			init_picture(COLOR_R, COLOR_G, COLOR_B);
		}
		
		if(move_active == 0){
			value=0;
			for(int i = 0; i<64; i++){
				if(board.get_field(i%8, i/8)<-50 || board.get_field(i%8, i/8)>0){
						value+=board.get_field(i%8, i/8);
				}
			}
		}
			

		std::stringstream r;
		std::stringstream s;
		s << value;
		r << MOVE_COUNTER;
		std::string str_r = r.str();
		std::string str_s = s.str();
		frame.print("\n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n"+str_s);

		

		mouse_update();
		if(MOUSE_X_POS<0){
			MOUSE_X_POS=0;
		}
		if(MOUSE_X_POS>=frame.get_width()){
			MOUSE_X_POS=frame.get_width()-1;
		}
		if(MOUSE_Y_POS<0){
			MOUSE_Y_POS=0;
		}
		if(MOUSE_Y_POS>=frame.get_height()){
			MOUSE_Y_POS=frame.get_height()-1;
		}

		if(MOUSE_R_BUTTON==2){
			board.vboard_to_rboard();			
			move_cont = 0;
			move_old_xfield = 0;
	 		move_old_yfield = 0;
			move_active = 0;
		}
	
		/*if(MOUSE_L_BUTTON==1 && MOUSE_X_FIELD>=0 && MOUSE_Y_FIELD>=0){
			board.add(MOUSE_X_FIELD, MOUSE_Y_FIELD, 3840);
		}
		if(MOUSE_R_BUTTON==2 && MOUSE_X_FIELD>=0 && MOUSE_Y_FIELD>=0){
			board.add(MOUSE_X_FIELD, MOUSE_Y_FIELD, B_KNIGHT);
		}
		if(MOUSE_M_BUTTON==4 && MOUSE_X_FIELD>=0 && MOUSE_Y_FIELD>=0){
			board.add(MOUSE_X_FIELD, MOUSE_Y_FIELD, 0);
		}*/

		if(MOUSE_L_BUTTON == 1 && move_active == 1){
			int status = board.move(move_old_xfield, move_old_yfield, MOUSE_X_FIELD, MOUSE_Y_FIELD);
			frame.print("\n \n \n hello");
			board.vboard_to_rboard();
			move_cont = 0;
			move_active = 0;
			if(status==1){
				for(int k = 0; k<CHESS_FIELD_WIDTH; k++){
					for(int l = 0; l<CHESS_FIELD_HEIGHT; l++){
						frame.add_b_pixel( (k+MOUSE_X_FIELD*CHESS_FIELD_WIDTH), (l+MOUSE_Y_FIELD*CHESS_FIELD_HEIGHT), ' ' );
						frame.add_w_pixel( (k+MOUSE_X_FIELD*CHESS_FIELD_WIDTH), (l+MOUSE_Y_FIELD*CHESS_FIELD_HEIGHT), pawn[k+l*CHESS_FIELD_WIDTH] );
					}
				}
				//std::string s = "Which piece do you want?\n1) Queen\n2) ?";
				frame.clear_printed();
				frame.print("Which piece do you want?\n1) Queen\n2) Knight\n3) Rook\n4) Bishop");				
				frame.build_pic(board, move_cont);
				timeout(10000);
				input = getch();
				timeout(0);
				if(input=='1'){
					board.add_to_rboard(MOUSE_X_FIELD, MOUSE_Y_FIELD, W_QUEEN);
					board.rboard_to_vboard();
				}
				else if(input=='2'){
					board.add_to_rboard(MOUSE_X_FIELD, MOUSE_Y_FIELD, W_KNIGHT);
					board.rboard_to_vboard();
				}
				else if(input=='3'){
					board.add_to_rboard(MOUSE_X_FIELD, MOUSE_Y_FIELD, W_ROOK);
					board.rboard_to_vboard();
				}
				else if(input=='4'){
					board.add_to_rboard(MOUSE_X_FIELD, MOUSE_Y_FIELD, W_BISHOP);
					board.rboard_to_vboard();
				}
				else{
					board.add_to_rboard(MOUSE_X_FIELD, MOUSE_Y_FIELD, W_QUEEN);
					board.rboard_to_vboard();
				}
				
			}
			else if(status==2){
				for(int k = 0; k<CHESS_FIELD_WIDTH; k++){
					for(int l = 0; l<CHESS_FIELD_HEIGHT; l++){
						frame.add_w_pixel( (k+MOUSE_X_FIELD*CHESS_FIELD_WIDTH), (l+MOUSE_Y_FIELD*CHESS_FIELD_HEIGHT), ' ' );
						frame.add_b_pixel( (k+MOUSE_X_FIELD*CHESS_FIELD_WIDTH), (l+MOUSE_Y_FIELD*CHESS_FIELD_HEIGHT), pawn[k+l*CHESS_FIELD_WIDTH] );
					}
				}
				frame.clear_printed();
				std::string s = "Which piece do you want?\n1) Queen\n2) ?";
				frame.print("Which piece do you want?\n1) Queen\n2) Knight\n3) Rook\n4) Bishop");
				frame.build_pic(board, move_cont);
				timeout(10000);
				input = getch();
				timeout(0);
				if(input=='1'){
					board.add_to_rboard(MOUSE_X_FIELD, MOUSE_Y_FIELD, B_QUEEN);
					board.rboard_to_vboard();
				}
				else if(input=='2'){
					board.add_to_rboard(MOUSE_X_FIELD, MOUSE_Y_FIELD, B_KNIGHT);
					board.rboard_to_vboard();
				}
				else if(input=='3'){
					board.add_to_rboard(MOUSE_X_FIELD, MOUSE_Y_FIELD, B_ROOK);
					board.rboard_to_vboard();
				}
				else if(input=='4'){
					board.add_to_rboard(MOUSE_X_FIELD, MOUSE_Y_FIELD, B_BISHOP);
					board.rboard_to_vboard();
				}
				else{
					board.add_to_rboard(MOUSE_X_FIELD, MOUSE_Y_FIELD, B_QUEEN);
					board.rboard_to_vboard();
				}
			}
				
			while(MOUSE_L_BUTTON == 1){
				mouse_update();
			}
		}

		if(MOUSE_L_BUTTON == 1 && move_active == 0 && board.get_field(MOUSE_X_FIELD, MOUSE_Y_FIELD)!=0){
			move_cont = board.get_field(MOUSE_X_FIELD, MOUSE_Y_FIELD);
			move_active = 1;
			move_old_xfield = MOUSE_X_FIELD;
			move_old_yfield = MOUSE_Y_FIELD;
			board.add_to_rboard(MOUSE_X_FIELD, MOUSE_Y_FIELD, 0);
		}



		//if(move_active == 1){}
		/*std::string s = "hallo\nwie gehts?";
		int j=1;
		int k=1;
		for(int i = 0; i<s.length(); i++){
			if(s[i]=='\n'){
				j++;
				i++;
				k=1;
			}	
			frame.add_mouse_pixel(CHESS_FIELD_WIDTH*8+k, j,  s[i]);
			k++;
		}*/
		
		frame.add_w_pixel(MOUSE_X_POS, MOUSE_Y_POS, ' ');
		frame.add_b_pixel(MOUSE_X_POS, MOUSE_Y_POS, ' ');
		frame.add_mouse_pixel(MOUSE_X_POS, MOUSE_Y_POS, 'x');
		frame.build_pic(board, move_cont);
		frame.clear_printed();
		frame.add_mouse_pixel(MOUSE_X_POS, MOUSE_Y_POS, ' ');
		while(MOUSE_L_BUTTON == 1){
			mouse_update();
		}
	}

	endwin();
	return 0;
}

int human_v_human(){
	mouse_open();
	init_picture(COLOR_R, COLOR_G, COLOR_B);
	Picture frame;
	
	Board board;

	int move_active = 0;
	int move_cont = 0;
	int move_old_xfield = 0;
	int move_old_yfield = 0;

	WHOSE_MOVE=1;
	const unsigned char pawn[] =  { "             o       ( )      |_|            " };

	char input;

	int value; 
	

	while(input!=27){
		input = getch();

		if(input=='z'){
			if(WHOSE_MOVE>0 && MOVE_COUNTER>1){
				MOVE_COUNTER--;
			}
			WHOSE_MOVE*=-1;
			
			board.undo();
			if(WHOSE_MOVE==1){
				frame.build_pic(board, move_cont);
			}
			else{
				frame.build_pic_flipped(board, move_cont);
			}
			while(MOUSE_L_BUTTON == 1){
				mouse_update();
			}			
		}

		if(input=='c'){
			endwin();
			if(config(board.get_vboard())==-1){
				return 0;
			}
			board.vboard_to_rboard();
			init_picture(COLOR_R, COLOR_G, COLOR_B);
		}

		if(move_active == 0){
			value = 0;
			for(int i = 0; i<64; i++){
				if(board.get_field(i%8, i/8)<-50 || board.get_field(i%8, i/8)>0){
						value+=board.get_field(i%8, i/8);
				}
			}
		}
			

		std::stringstream r;
		std::stringstream s;
		s << value;
		r << MOVE_COUNTER;
		std::string str_r = r.str();
		std::string str_s = s.str();
		frame.print("\n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n"+str_r+"\n"+str_s);

		if(WHOSE_MOVE>0){
			mouse_update();
			if(MOUSE_X_POS<0){
				MOUSE_X_POS=0;
			}
			if(MOUSE_X_POS>=frame.get_width()){
				MOUSE_X_POS=frame.get_width()-1;
			}
			if(MOUSE_Y_POS<0){
				MOUSE_Y_POS=0;
			}
			if(MOUSE_Y_POS>=frame.get_height()){
				MOUSE_Y_POS=frame.get_height()-1;
			}

			if(MOUSE_R_BUTTON==2){
				board.vboard_to_rboard();			
				move_cont = 0;
				move_old_xfield = 0;
	 			move_old_yfield = 0;
				move_active = 0;
			}
		
			/*if(MOUSE_L_BUTTON==1 && MOUSE_X_FIELD>=0 && MOUSE_Y_FIELD>=0){
				board.add(MOUSE_X_FIELD, MOUSE_Y_FIELD, 3840);
			}
			if(MOUSE_R_BUTTON==2 && MOUSE_X_FIELD>=0 && MOUSE_Y_FIELD>=0){
				board.add(MOUSE_X_FIELD, MOUSE_Y_FIELD, B_KNIGHT);
			}
			if(MOUSE_M_BUTTON==4 && MOUSE_X_FIELD>=0 && MOUSE_Y_FIELD>=0){
				board.add(MOUSE_X_FIELD, MOUSE_Y_FIELD, 0);
			}*/

			if(MOUSE_L_BUTTON == 1 && move_active == 1){
				int status = board.move(move_old_xfield, move_old_yfield, MOUSE_X_FIELD, MOUSE_Y_FIELD);
				if(status==1){
					for(int k = 0; k<CHESS_FIELD_WIDTH; k++){
						for(int l = 0; l<CHESS_FIELD_HEIGHT; l++){
							frame.add_b_pixel( (k+MOUSE_X_FIELD*CHESS_FIELD_WIDTH), (l+MOUSE_Y_FIELD*CHESS_FIELD_HEIGHT), ' ' );
							frame.add_w_pixel( (k+MOUSE_X_FIELD*CHESS_FIELD_WIDTH), (l+MOUSE_Y_FIELD*CHESS_FIELD_HEIGHT), pawn[k+l*CHESS_FIELD_WIDTH] );
						}
					}
					//std::string s = "Which piece do you want?\n1) Queen\n2) ?";
					frame.clear_printed();
					frame.print("Which piece do you want?\n1) Queen\n2) Knight\n3) Rook\n4) Bishop");					
					frame.build_pic(board, move_cont);
					timeout(10000);
					input = getch();
					timeout(0);
					if(input=='1'){
						board.add_to_rboard(MOUSE_X_FIELD, MOUSE_Y_FIELD, W_QUEEN);
						board.rboard_to_vboard();
					}
					else if(input=='2'){
						board.add_to_rboard(MOUSE_X_FIELD, MOUSE_Y_FIELD, W_KNIGHT);
						board.rboard_to_vboard();
					}
					else if(input=='3'){
						board.add_to_rboard(MOUSE_X_FIELD, MOUSE_Y_FIELD, W_ROOK);
						board.rboard_to_vboard();
					}
					else if(input=='4'){
						board.add_to_rboard(MOUSE_X_FIELD, MOUSE_Y_FIELD, W_BISHOP);
						board.rboard_to_vboard();
					}
					else{
						board.add_to_rboard(MOUSE_X_FIELD, MOUSE_Y_FIELD, W_QUEEN);
						board.rboard_to_vboard();
					}
					
				}
				else if(status==2){
					for(int k = 0; k<CHESS_FIELD_WIDTH; k++){
						for(int l = 0; l<CHESS_FIELD_HEIGHT; l++){
							frame.add_w_pixel( (k+MOUSE_X_FIELD*CHESS_FIELD_WIDTH), (l+MOUSE_Y_FIELD*CHESS_FIELD_HEIGHT), ' ' );
							frame.add_b_pixel( (k+MOUSE_X_FIELD*CHESS_FIELD_WIDTH), (l+MOUSE_Y_FIELD*CHESS_FIELD_HEIGHT), pawn[k+l*CHESS_FIELD_WIDTH] );
						}
					}//std::string s = "Which piece do you want?\n1) Queen\n2) ?";
					frame.clear_printed();
					frame.print("Which piece do you want?\n1) Queen\n2) Knight\n3) Rook\n4) Bishop");
					frame.build_pic(board, move_cont);
					timeout(10000);
					input = getch();
					timeout(0);
					if(input=='1'){
						board.add_to_rboard(MOUSE_X_FIELD, MOUSE_Y_FIELD, B_QUEEN);
						board.rboard_to_vboard();
					}
					else if(input=='2'){
						board.add_to_rboard(MOUSE_X_FIELD, MOUSE_Y_FIELD, B_KNIGHT);
						board.rboard_to_vboard();
					}
					else if(input=='3'){
						board.add_to_rboard(MOUSE_X_FIELD, MOUSE_Y_FIELD, B_ROOK);
						board.rboard_to_vboard();
					}
					else if(input=='4'){
						board.add_to_rboard(MOUSE_X_FIELD, MOUSE_Y_FIELD, B_BISHOP);
						board.rboard_to_vboard();
					}
					else{
						board.add_to_rboard(MOUSE_X_FIELD, MOUSE_Y_FIELD, B_QUEEN);
						board.rboard_to_vboard();
					}
					
				}
				if(status>=0){
					if(WHOSE_MOVE<0){
						MOVE_COUNTER++;
					}
					WHOSE_MOVE*=-1;				
				}
				move_cont = 0;
				move_old_xfield = 0;
	 			move_old_yfield = 0;
				move_active = 0;
			}
	
			if(MOUSE_L_BUTTON == 1 && move_active == 0 && board.get_field(MOUSE_X_FIELD, MOUSE_Y_FIELD)!=0 && board.get_field(MOUSE_X_FIELD, MOUSE_Y_FIELD)*WHOSE_MOVE>0){
				move_cont = board.get_field(MOUSE_X_FIELD, MOUSE_Y_FIELD);
				move_active = 1;
				move_old_xfield = MOUSE_X_FIELD;
				move_old_yfield = MOUSE_Y_FIELD;
				board.add_to_rboard(MOUSE_X_FIELD, MOUSE_Y_FIELD, 0);
			}
	
	
	
			//if(move_active == 1){}
			/*std::string s = "hallo\nwie gehts?";
			int j=1;
			int k=1;
			for(int i = 0; i<s.length(); i++){
				if(s[i]=='\n'){
					j++;
					i++;
					k=1;
				}	
				frame.add_mouse_pixel(CHESS_FIELD_WIDTH*8+k, j,  s[i]);
				k++;
			}*/
			
			frame.add_w_pixel(MOUSE_X_POS, MOUSE_Y_POS, ' ');
			frame.add_b_pixel(MOUSE_X_POS, MOUSE_Y_POS, ' ');
			frame.add_mouse_pixel(MOUSE_X_POS, MOUSE_Y_POS, 'x');
			frame.build_pic(board, move_cont);
			frame.add_mouse_pixel(MOUSE_X_POS, MOUSE_Y_POS, ' ');
		}
		else{
			mouse_update();
			if(MOUSE_X_POS<0){
				MOUSE_X_POS=0;
			}
			if(MOUSE_X_POS>=frame.get_width()){
				MOUSE_X_POS=frame.get_width()-1;
			}
			if(MOUSE_Y_POS<0){
				MOUSE_Y_POS=0;
			}
			if(MOUSE_Y_POS>=frame.get_height()){
				MOUSE_Y_POS=frame.get_height()-1;
			}

			if(MOUSE_R_BUTTON==2){
				board.vboard_to_rboard();			
				move_cont = 0;
				move_old_xfield = 0;
	 			move_old_yfield = 0;
				move_active = 0;
			}
		
			/*if(MOUSE_L_BUTTON==1 && 7-MOUSE_X_FIELD>=0 && 7-MOUSE_Y_FIELD>=0){
				board.add(7-MOUSE_X_FIELD, 7-MOUSE_Y_FIELD, 3840);
			}
			if(MOUSE_R_BUTTON==2 && 7-MOUSE_X_FIELD>=0 && 7-MOUSE_Y_FIELD>=0){
				board.add(7-MOUSE_X_FIELD, 7-MOUSE_Y_FIELD, B_KNIGHT);
			}
			if(MOUSE_M_BUTTON==4 && 7-MOUSE_X_FIELD>=0 && 7-MOUSE_Y_FIELD>=0){
				board.add(7-MOUSE_X_FIELD, 7-MOUSE_Y_FIELD, 0);
			}*/

			if(MOUSE_L_BUTTON == 1 && move_active == 1){
				int status = board.move(move_old_xfield, move_old_yfield, 7-MOUSE_X_FIELD, 7-MOUSE_Y_FIELD);
				if(status==1){
					for(int k = 0; k<CHESS_FIELD_WIDTH; k++){
						for(int l = 0; l<CHESS_FIELD_HEIGHT; l++){
							frame.add_b_pixel( (k+7-MOUSE_X_FIELD*CHESS_FIELD_WIDTH), (l+7-MOUSE_Y_FIELD*CHESS_FIELD_HEIGHT), ' ' );
							frame.add_w_pixel( (k+7-MOUSE_X_FIELD*CHESS_FIELD_WIDTH), (l+7-MOUSE_Y_FIELD*CHESS_FIELD_HEIGHT), pawn[k+l*CHESS_FIELD_WIDTH] );
						}
					}
					//std::string s = "Which piece do you want?\n1) Queen\n2) ?";
					frame.clear_printed();
					frame.print("Which piece do you want?\n1) Queen\n2) Knight\n3) Rook\n4) Bishop");					
					frame.build_pic_flipped(board, move_cont);
					timeout(10000);
					input = getch();
					timeout(0);
					if(input=='1'){
						board.add_to_rboard(7-MOUSE_X_FIELD, 7-MOUSE_Y_FIELD, W_QUEEN);
						board.rboard_to_vboard();
					}
					else if(input=='2'){
						board.add_to_rboard(7-MOUSE_X_FIELD, 7-MOUSE_Y_FIELD, W_KNIGHT);
						board.rboard_to_vboard();
					}
					else if(input=='3'){
						board.add_to_rboard(7-MOUSE_X_FIELD, 7-MOUSE_Y_FIELD, W_ROOK);
						board.rboard_to_vboard();
					}
					else if(input=='4'){
						board.add_to_rboard(7-MOUSE_X_FIELD, 7-MOUSE_Y_FIELD, W_BISHOP);
						board.rboard_to_vboard();
					}
					else{
						board.add_to_rboard(7-MOUSE_X_FIELD, 7-MOUSE_Y_FIELD, W_QUEEN);
						board.rboard_to_vboard();
					}
					
				}
				else if(status==2){
					for(int k = 0; k<CHESS_FIELD_WIDTH; k++){
						for(int l = 0; l<CHESS_FIELD_HEIGHT; l++){
							frame.add_w_pixel( (k+7-MOUSE_X_FIELD*CHESS_FIELD_WIDTH), (l+7-MOUSE_Y_FIELD*CHESS_FIELD_HEIGHT), ' ' );
							frame.add_b_pixel( (k+7-MOUSE_X_FIELD*CHESS_FIELD_WIDTH), (l+7-MOUSE_Y_FIELD*CHESS_FIELD_HEIGHT), pawn[k+l*CHESS_FIELD_WIDTH] );
						}
					}
					frame.clear_printed();
					frame.print("Which piece do you want?\n1) Queen\n2) Knight\n3) Rook\n4) Bishop");
					frame.build_pic_flipped(board, move_cont);
					timeout(10000);
					input = getch();
					timeout(0);
					if(input=='1'){
						board.add_to_rboard(7-MOUSE_X_FIELD, 7-MOUSE_Y_FIELD, B_QUEEN);
						board.rboard_to_vboard();
					}
					else if(input=='2'){
						board.add_to_rboard(7-MOUSE_X_FIELD, 7-MOUSE_Y_FIELD, B_KNIGHT);
						board.rboard_to_vboard();
					}
					else if(input=='3'){
						board.add_to_rboard(7-MOUSE_X_FIELD, 7-MOUSE_Y_FIELD, B_ROOK);
						board.rboard_to_vboard();
					}
					else if(input=='4'){
						board.add_to_rboard(7-MOUSE_X_FIELD, 7-MOUSE_Y_FIELD, B_BISHOP);
						board.rboard_to_vboard();
					}
					else{
						board.add_to_rboard(7-MOUSE_X_FIELD, 7-MOUSE_Y_FIELD, B_QUEEN);
						board.rboard_to_vboard();
					}
					
				}
				if(status>=0){
					if(WHOSE_MOVE<0){
						MOVE_COUNTER++;
					}
					WHOSE_MOVE*=-1;
				}
				move_cont = 0;
				move_active = 0;
			}
	
			if(MOUSE_L_BUTTON == 1 && move_active == 0 && board.get_field(7-MOUSE_X_FIELD, 7-MOUSE_Y_FIELD)!=0 && board.get_field(7-MOUSE_X_FIELD, 7-MOUSE_Y_FIELD)*WHOSE_MOVE>0){
				move_cont = board.get_field(7-MOUSE_X_FIELD, 7-MOUSE_Y_FIELD);
				move_active = 1;
				move_old_xfield = 7-MOUSE_X_FIELD;
				move_old_yfield = 7-MOUSE_Y_FIELD;
				board.add_to_rboard(7-MOUSE_X_FIELD, 7-MOUSE_Y_FIELD, 0);
			}
	
	
	
			//if(move_active == 1){}
			/*std::string s = "hallo\nwie gehts?";
			int j=1;
			int k=1;
			for(int i = 0; i<s.length(); i++){
				if(s[i]=='\n'){
					j++;
					i++;
					k=1;
				}	
				frame.add_mouse_pixel(CHESS_FIELD_WIDTH*8+k, j,  s[i]);
				k++;
			}*/
			
			frame.add_w_pixel(MOUSE_X_POS, MOUSE_Y_POS, ' ');
			frame.add_b_pixel(MOUSE_X_POS, MOUSE_Y_POS, ' ');
			frame.add_mouse_pixel(MOUSE_X_POS, MOUSE_Y_POS, 'x');
			frame.build_pic_flipped(board, move_cont);
			frame.clear_printed();
			frame.add_mouse_pixel(MOUSE_X_POS, MOUSE_Y_POS, ' ');
		}
		while(MOUSE_L_BUTTON == 1){
			mouse_update();
		}
	}
	
	endwin();
	return 0;
}

int human_v_human_network(){
	return 0;
}






/*void *chess_thread_black(void* arg){
	struct chess_data *f = (struct chess_data *)arg;
	*f->value = explore_one_move_for_black(f->pos_mov, f->num, f->deepness);
}*/


void *chess_thread_white(void* arg){
	struct sched_param para;
	para.sched_priority = -10;

	pthread_setschedparam(pthread_self(), SCHED_FIFO, &para);

	struct chess_data *f = (struct chess_data *)arg;
	int alpha = 40000;
	*f->value = explore_one_move_for_white(f->pos_mov, f->num, f->deepness, &alpha);
}

void find_best_move_for_black(int deepness, int sec_deepness, int vboard[120], Picture frame, Board board){
	if(MOVE_COUNTER==1){
		int i;
		for(i = 61; i<79; i++){
			if(vboard[i]>0){
				break;
			}
		}

		int j = (i%10)+50;

		vboard[j]=B_PAWN;
		vboard[j-10]=-5;
		vboard[j-20]=0;
	

		for(int k = 21; k<99; k++){
			LAST_VALUATION+=vboard[k];
		}
		return;
	}
	int pos_mov[150][120];
	int num_one = get_pos_mov_black(pos_mov, vboard);

	
	int pieces = 0;	
	for(int i = 0; i<120; i++){
		if(vboard[i]<-50 || vboard[i]>0){
			pieces++;
		}
	}

	if(pieces<=NOPSD && num_one<=NOMSD){
		deepness=sec_deepness;
	}

	int act_best[4];
	int value[num_one];

	struct chess_data f[num_one];
	pthread_t th[num_one];
	
	for(int i = 0; i<num_one; i++){
		int pos_mov_next[150][120];
		int num = get_pos_mov_white(pos_mov_next, pos_mov[i]);

		memcpy(f[i].pos_mov, pos_mov_next, sizeof(int)*120*150);
		f[i].num=num;
		f[i].deepness=deepness-1;
		f[i].value=&value[i];
		pthread_create(&th[i], NULL, &chess_thread_white, &f[i]);
		//std::cout << "Thats debug-try 3\n";
		//value[i] = explore_one_move_for_white(pos_mov_next, num, deepness-1);
		/*for(int i = 0; i<12; i++){
			for(int j = 0; j<10; j++){
				std::cout << pos_mov_next[i][i*10+j] <<"\t";
			}
			std::cout << "\n";
		}
		std::cout << "\n"<<value[i]<<"\n\n";*/
	}

	void* result;
	for(int i = 0; i<num_one; i++){				
		int procent = (i*W_PAWN)/num_one;
		std::stringstream s;
		s << procent;
		std::string str = s.str();
		frame.print("\n"+str+"%");
		frame.build_pic(board, 0);
		pthread_join(th[i],&result);
	}

	act_best[0] = value[0];
	act_best[1] = 0;
	act_best[2] = 0;
	act_best[3] = 0;
		/*for(int k = 0; k<12; k++){
			for(int j = 0; j<10; j++){
				std::cout << pos_mov[0][k*10+j] <<"\t";
			}
			std::cout << "\n";
		}
		std::cout << "\n"<< value[0] <<"\n\n";
		while(MOUSE_L_BUTTON != 1){
			mouse_update();
		}	
		while(MOUSE_L_BUTTON == 1){
			mouse_update();
		}*/

	for(int i = 1; i<num_one; i++){
		/*for(int k = 0; k<12; k++){
			for(int j = 0; j<10; j++){
				std::cout << pos_mov[i][k*10+j] <<"\t";
			}
			std::cout << "\n";
		}
		std::cout << "\n"<< value[i] <<"\n\n";
		while(MOUSE_L_BUTTON != 1){
			mouse_update();
		}	
		while(MOUSE_L_BUTTON == 1){
			mouse_update();
		}*/
		if(value[i]<act_best[0]){
			act_best[3] = act_best[0];
			act_best[2] = act_best[1];
			act_best[0] = value[i];
			act_best[1] = i;
		}
	}
	
	pos_mov[act_best[1]][5]=-1;
	
	pos_mov[act_best[2]][5]=-1;


	
	int equal = 1;

	//vboard = pos_mov[act_best[1]];int equal = 1;
	for(int i = 0; i<120; i++){
		if(xboard[i]!=pos_mov[act_best[1]][i]){
			equal=0;
		}
	}

	/*endwin();
	std::cout << "\033[2J";
	for(int i = 0; i<=LINES; i++){
		std::cout << "\033[1A";
	}
	std::string input;
	while(input!="exit"){
		std::cout << act_best[3] <<" "<<act_best[0];
		std::cin >> input;
	}
	init_picture(COLOR_R, COLOR_G, COLOR_B);*/

	if(equal==1 && act_best[3]-act_best[0] <200){
		memcpy(vboard, pos_mov[act_best[2]], sizeof(int)*120);
	}
	else{
		memcpy(vboard, pos_mov[act_best[1]], sizeof(int)*120);		
	}
	
	LAST_VALUATION = 0;
	for(int k = 21; k<99; k++){
		LAST_VALUATION+=vboard[k];
	}

	memcpy(xboard, wboard, sizeof(int)*120);

	memcpy(wboard, vboard, sizeof(int)*120);


	/*for(int i = 0; i<12; i++){
		for(int j = 0; j<10; j++){
			std::cout << pos_mov[act_best[1]][i*10+j] <<"\t";
		}
		std::cout << "\n";
	}

	return vboard;*/

	//std::cout << &vboard <<"\t";
	/*

	


	int pos_mov[150][120];
	int num = get_pos_mov_black(150, pos_mov, vboard);

	std::cout << "Thats debug-try 2\n";

	int act_best[2];
	int value[150];     //Мня зовут Йост Триллэр

	for(int i = 0; i<num; i++){
		int pos_mov[i][120];
		int num2 = get_pos_mov_black(150, pos_mov, vboard);
		
	}*/

}



int human_v_black_computer(){
	B_KING=-20000;
	B_QUEEN=-975;
	mouse_open();
	init_picture(COLOR_R, COLOR_G, COLOR_B);
	Picture frame;
	
	Board board;

	int move_active = 0;
	int move_cont = 0;
	int move_old_xfield = 0;
	int move_old_yfield = 0;

	WHOSE_MOVE=1;
	const unsigned char pawn[] =  { "             o       ( )      |_|            " };

	char input;

	time_t start_time, stop_time;
	double delta_time;

	int value;
	

	while(input!=27){
		input = getch();

		if(input=='z'){
			if(WHOSE_MOVE>0 && MOVE_COUNTER>1){
				MOVE_COUNTER--;
			}
			board.undo();
			
			frame.build_pic(board, move_cont);
			while(MOUSE_L_BUTTON == 1){
				mouse_update();
			}			
		}

		if(input=='c'){
			endwin();
			if(config(board.get_vboard())==-1){
				return 0;
			}
			board.vboard_to_rboard();
			init_picture(COLOR_R, COLOR_G, COLOR_B);
		}

		if(move_active == 0){
			value=10075;
			for(int i = 0; i<64; i++){
				if(board.get_field(i%8, i/8)<-50 || board.get_field(i%8, i/8)>0){
						value+=board.get_field(i%8, i/8);
				}
			}
		}
			

		std::stringstream r;
		std::stringstream s;
		s << value;
		r << MOVE_COUNTER;
		std::string str_r = r.str();
		std::string str_s = s.str();
		frame.print("\n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n"+str_r+"\n"+str_s);

		

		std::stringstream t;
		t << delta_time;
		std::string str_t = t.str();
		std::string str_u = std::to_string(MOVES);
		frame.print("Computer thought in "+str_t+" seconds about "+str_u+" possible games.");
		

		mouse_update();
		if(MOUSE_X_POS<0){
			MOUSE_X_POS=0;
		}
		if(MOUSE_X_POS>=frame.get_width()){
			MOUSE_X_POS=frame.get_width()-1;
		}
		if(MOUSE_Y_POS<0){
			MOUSE_Y_POS=0;
		}
		if(MOUSE_Y_POS>=frame.get_height()){
			MOUSE_Y_POS=frame.get_height()-1;
		}

		if(MOUSE_R_BUTTON==2){
			board.vboard_to_rboard();			
			move_cont = 0;
			move_old_xfield = 0;
	 		move_old_yfield = 0;
			move_active = 0;
		}

		if(WHOSE_MOVE==-1){
			//endwin();
			frame.print("Computer is thinking.                                                                ");
			frame.build_pic(board, 0);
			//std::cout << "Thats a debug-try 1\n";
			MOVES=0;

			int temp_board[120];

			memcpy(temp_board, board.get_vboard(), sizeof(int)*120);

			//std::cout << &temp_board[0] <<"\n";
			start_time=time(NULL);
			find_best_move_for_black(DEEPNESS, SEC_DEEPNESS, temp_board, frame, board);
			stop_time=time(NULL);
			delta_time=difftime(stop_time, start_time);

			frame.clear_printed();
			/*for(int i = 0; i<12; i++){
				for(int j = 0; j<10; j++){
					std::cout << temp_board[i*10+j] <<"\t";
				}
				std::cout << "\n";
			}*/
			memcpy(board.get_vboard(), temp_board, sizeof(int)*120);
			board.vboard_to_rboard();
			if(WHOSE_MOVE<0){
				MOVE_COUNTER++;
			}
			WHOSE_MOVE*=-1;
			//std::this_thread::sleep_for(std::chrono::milliseconds(500000));
			while(MOUSE_L_BUTTON == 1){
				mouse_update();
			}
			//init_picture(COLOR_R, COLOR_G, COLOR_B);
		}
	
		/*if(MOUSE_L_BUTTON==1 && MOUSE_X_FIELD>=0 && MOUSE_Y_FIELD>=0){
			board.add(MOUSE_X_FIELD, MOUSE_Y_FIELD, 3840);
		}
		if(MOUSE_R_BUTTON==2 && MOUSE_X_FIELD>=0 && MOUSE_Y_FIELD>=0){
			board.add(MOUSE_X_FIELD, MOUSE_Y_FIELD, B_KNIGHT);
		}
		if(MOUSE_M_BUTTON==4 && MOUSE_X_FIELD>=0 && MOUSE_Y_FIELD>=0){
			board.add(MOUSE_X_FIELD, MOUSE_Y_FIELD, 0);
		}*/

		if(MOUSE_L_BUTTON == 1 && move_active == 1){
			int status = board.move(move_old_xfield, move_old_yfield, MOUSE_X_FIELD, MOUSE_Y_FIELD);
			if(status==1){
				for(int k = 0; k<CHESS_FIELD_WIDTH; k++){
					for(int l = 0; l<CHESS_FIELD_HEIGHT; l++){
						frame.add_b_pixel( (k+MOUSE_X_FIELD*CHESS_FIELD_WIDTH), (l+MOUSE_Y_FIELD*CHESS_FIELD_HEIGHT), ' ' );
						frame.add_w_pixel( (k+MOUSE_X_FIELD*CHESS_FIELD_WIDTH), (l+MOUSE_Y_FIELD*CHESS_FIELD_HEIGHT), pawn[k+l*CHESS_FIELD_WIDTH] );
					}
				}
				//std::string s = "Which piece do you want?\n1) Queen\n2) ?";
				frame.clear_printed();
				frame.print("Which piece do you want?\n1) Queen\n2) Knight\n3) Rook\n4) Bishop");				
				frame.build_pic(board, move_cont);
				timeout(10000);
				input = getch();
				timeout(0);
				frame.clear_printed();
				if(input=='1'){
					board.add_to_rboard(MOUSE_X_FIELD, MOUSE_Y_FIELD, W_QUEEN);
					board.rboard_to_vboard();
				}
				else if(input=='2'){
					board.add_to_rboard(MOUSE_X_FIELD, MOUSE_Y_FIELD, W_KNIGHT);
					board.rboard_to_vboard();
				}
				else if(input=='3'){
					board.add_to_rboard(MOUSE_X_FIELD, MOUSE_Y_FIELD, W_ROOK);
					board.rboard_to_vboard();
				}
				else if(input=='4'){
					board.add_to_rboard(MOUSE_X_FIELD, MOUSE_Y_FIELD, W_BISHOP);
					board.rboard_to_vboard();
				}
				else{
					board.add_to_rboard(MOUSE_X_FIELD, MOUSE_Y_FIELD, W_QUEEN);
					board.rboard_to_vboard();
				}
				
			}
			else if(status==2){
				for(int k = 0; k<CHESS_FIELD_WIDTH; k++){
					for(int l = 0; l<CHESS_FIELD_HEIGHT; l++){
						frame.add_w_pixel( (k+MOUSE_X_FIELD*CHESS_FIELD_WIDTH), (l+MOUSE_Y_FIELD*CHESS_FIELD_HEIGHT), ' ' );
						frame.add_b_pixel( (k+MOUSE_X_FIELD*CHESS_FIELD_WIDTH), (l+MOUSE_Y_FIELD*CHESS_FIELD_HEIGHT), pawn[k+l*CHESS_FIELD_WIDTH] );
					}
				}std::string s = "Which piece do you want?\n1) Queen\n2) ?";
				frame.clear_printed();
				frame.print("Which piece do you want?\n1) Queen\n2) Knight\n3) Rook\n4) Bishop");
				frame.build_pic(board, move_cont);
				timeout(10000);
				input = getch();
				timeout(0);
				frame.clear_printed();
				if(input=='1'){
					board.add_to_rboard(MOUSE_X_FIELD, MOUSE_Y_FIELD, B_QUEEN);
					board.rboard_to_vboard();
				}
				else if(input=='2'){
					board.add_to_rboard(MOUSE_X_FIELD, MOUSE_Y_FIELD, B_KNIGHT);
					board.rboard_to_vboard();
				}
				else if(input=='3'){
					board.add_to_rboard(MOUSE_X_FIELD, MOUSE_Y_FIELD, B_ROOK);
					board.rboard_to_vboard();
				}
				else if(input=='4'){
					board.add_to_rboard(MOUSE_X_FIELD, MOUSE_Y_FIELD, B_BISHOP);
					board.rboard_to_vboard();
				}
				else{
					board.add_to_rboard(MOUSE_X_FIELD, MOUSE_Y_FIELD, B_QUEEN);
					board.rboard_to_vboard();
				}
				
			}
			if(status>=0){
				if(WHOSE_MOVE<0){
					MOVE_COUNTER++;
				}
				WHOSE_MOVE*=-1;
			}
			move_cont = 0;
			move_active = 0;
		}

		if(MOUSE_L_BUTTON == 1 && move_active == 0 && board.get_field(MOUSE_X_FIELD, MOUSE_Y_FIELD)!=0 && board.get_field(MOUSE_X_FIELD, MOUSE_Y_FIELD)*WHOSE_MOVE>0){
			move_cont = board.get_field(MOUSE_X_FIELD, MOUSE_Y_FIELD);
			move_active = 1;
			move_old_xfield = MOUSE_X_FIELD;
			move_old_yfield = MOUSE_Y_FIELD;
			board.add_to_rboard(MOUSE_X_FIELD, MOUSE_Y_FIELD, 0);
		}



		//if(move_active == 1){}
		/*std::string s = "hallo\nwie gehts?";
		int j=1;
		int k=1;
		for(int i = 0; i<s.length(); i++){
			if(s[i]=='\n'){
				j++;
				i++;
				k=1;
			}	
			frame.add_mouse_pixel(CHESS_FIELD_WIDTH*8+k, j,  s[i]);
			k++;
		}*/
		
		frame.add_w_pixel(MOUSE_X_POS, MOUSE_Y_POS, ' ');
		frame.add_b_pixel(MOUSE_X_POS, MOUSE_Y_POS, ' ');
		frame.add_mouse_pixel(MOUSE_X_POS, MOUSE_Y_POS, 'x');
		frame.build_pic(board, move_cont);
		frame.clear_printed();
		frame.add_mouse_pixel(MOUSE_X_POS, MOUSE_Y_POS, ' ');		
		while(MOUSE_L_BUTTON == 1){
			mouse_update();
		}
	}

	endwin();
	return 0;
}

void *chess_thread_black(void* arg){
	struct sched_param para;
	para.sched_priority = -10;

	pthread_setschedparam(pthread_self(), SCHED_FIFO, &para);

	struct chess_data *f = (struct chess_data *)arg;
	int alpha = -40000;
	*f->value = explore_one_move_for_black(f->pos_mov, f->num, f->deepness, &alpha);
}

void find_best_move_for_white(int deepness, int sec_deepness, int vboard[120], Picture frame, Board board){
	if(MOVE_COUNTER==1){

		vboard[85]=0;
		vboard[75]=-2;
		vboard[65]=W_PAWN;
	

		for(int k = 21; k<99; k++){
			LAST_VALUATION+=vboard[k];
		}
		return;
	}	
	//std::cout << &vboard[0] <<"\n";
	int pos_mov[150][120];
	int num_one = get_pos_mov_white(pos_mov, vboard);

	int pieces = 0;	
	for(int i = 0; i<120; i++){
		if(vboard[i]<-50 || vboard[i]>0){
			pieces++;
		}
	}

	if(pieces<=NOPSD && num_one<=NOMSD){
		deepness=sec_deepness;
	}
	//std::cout << "Thats debug-try 2\n";
	/*for(int k = 0; k<150; k++){
		for(int i = 0; i<12; i++){
			for(int j = 0; j<10; j++){
				std::cout << pos_mov[k][i*10+j] <<"\t";
			}
			std::cout << "\n";
		}
		std::cout << "\n\n\n";		
	}
	std::this_thread::sleep_for(std::chrono::milliseconds(500000));*/
	int act_best[4];
	int value[num_one];

	struct chess_data f[num_one];
	pthread_t th[num_one];
	
	for(int i = 0; i<num_one; i++){
		int pos_mov_next[150][120];
		int num = get_pos_mov_black(pos_mov_next, pos_mov[i]);

		memcpy(f[i].pos_mov, pos_mov_next, sizeof(int)*120*150);
		f[i].num=num;
		f[i].deepness=deepness-1;
		f[i].value=&value[i];
		pthread_create(&th[i], NULL, &chess_thread_black, &f[i]);
		//std::cout << "Thats debug-try 3\n";
		//value[i] = explore_one_move_for_white(pos_mov_next, num, deepness-1);
		/*for(int i = 0; i<12; i++){
			for(int j = 0; j<10; j++){
				std::cout << pos_mov_next[i][i*10+j] <<"\t";
			}
			std::cout << "\n";
		}
		std::cout << "\n"<<value[i]<<"\n\n";*/
	}

	void* result;
	for(int i = 0; i<num_one; i++){				
		int procent = (i*W_PAWN)/num_one;
		std::stringstream s;
		s << procent;
		std::string str = s.str();
		frame.print("\n"+str+"%");
		frame.build_pic_flipped(board, 0);
		pthread_join(th[i],&result);
	}

	act_best[0] = value[0];
	act_best[1] = 0;
	act_best[2] = 0;
	act_best[3] = 0;
		/*for(int k = 0; k<12; k++){
			for(int j = 0; j<10; j++){
				std::cout << pos_mov[0][k*10+j] <<"\t";
			}
			std::cout << "\n";
		}
		std::cout << "\n"<< value[0] <<"\n\n";
		while(MOUSE_L_BUTTON != 1){
			mouse_update();
		}	
		while(MOUSE_L_BUTTON == 1){
			mouse_update();
		}*/

	for(int i = 1; i<num_one; i++){
		/*for(int k = 0; k<12; k++){
			for(int j = 0; j<10; j++){
				std::cout << pos_mov[i][k*10+j] <<"\t";
			}
			std::cout << "\n";
		}
		std::cout << "\n"<< value[i] <<"\n\n";
		while(MOUSE_L_BUTTON != 1){
			mouse_update();
		}	
		while(MOUSE_L_BUTTON == 1){
			mouse_update();
		}*/
		if(value[i]>act_best[0]){
			act_best[3] = act_best[0];
			act_best[2] = act_best[1];
			act_best[0] = value[i];
			act_best[1] = i;
		}
	}

	/*if(!board_equal(stored_boards[0], pos_mov[act_best[1]])){
		if(!board_equal(stored_boards[1], pos_mov[act_best[1]])){
			if(!board_equal(stored_boards[2], pos_mov[act_best[1]])){
				memcpy(vboard, pos_mov[act_best[2]], sizeof(int)*120);
				memcpy(stored_boards[0], pos_mov[act_best[2]], sizeof(int)*120);
				printf("sdsdsad");
			}
			else{
				memcpy(stored_boards[2], pos_mov[act_best[1]], sizeof(int)*120);
			}
		}
		else{
			memcpy(stored_boards[1], pos_mov[act_best[1]], sizeof(int)*120);
		}
		
	}
	else{
		memcpy(stored_boards[0], pos_mov[act_best[1]], sizeof(int)*120);
		memcpy(vboard, pos_mov[act_best[1]], sizeof(int)*120);
	}*/
	pos_mov[act_best[1]][5]=-1;
	
	pos_mov[act_best[2]][5]=-1;


	
	
	int equal = 1;

	//vboard = pos_mov[act_best[1]];int equal = 1;
	for(int i = 0; i<120; i++){
		if(xboard[i]!=pos_mov[act_best[1]][i]){
			equal=0;
		}
	}

	if(equal==1 && act_best[3]-act_best[0] >-200){
		memcpy(vboard, pos_mov[act_best[2]], sizeof(int)*120);
		LAST_VALUATION = 0;
		for(int k = 21; k<99; k++){
			LAST_VALUATION+=pos_mov[act_best[2]][k];
		}
	}
	else{
		memcpy(vboard, pos_mov[act_best[1]], sizeof(int)*120);
		LAST_VALUATION = 0;
		for(int k = 21; k<99; k++){
			LAST_VALUATION+=pos_mov[act_best[1]][k];
		}		
	}

	memcpy(xboard, wboard, sizeof(int)*120);

	memcpy(wboard, vboard, sizeof(int)*120);



	/*for(int i = 0; i<12; i++){
		for(int j = 0; j<10; j++){
			std::cout << pos_mov[act_best[1]][i*10+j] <<"\t";
		}
		std::cout << "\n";
	}

	return vboard;*/

	//std::cout << &vboard <<"\t";
	/*

	


	int pos_mov[150][120];
	int num = get_pos_mov_black(150, pos_mov, vboard);

	std::cout << "Thats debug-try 2\n";

	int act_best[2];
	int value[150];     //Мня зовут Йост Триллэр

	for(int i = 0; i<num; i++){
		int pos_mov[i][120];
		int num2 = get_pos_mov_black(150, pos_mov, vboard);
		
	}*/

}

int human_v_white_computer(){
	W_KING=20000;
	W_QUEEN=975;
	mouse_open();
	init_picture(COLOR_R, COLOR_G, COLOR_B);
	Picture frame;
	
	Board board;

	int move_active = 0;
	int move_cont = 0;
	int move_old_xfield = 0;
	int move_old_yfield = 0;

	WHOSE_MOVE=1;
	const unsigned char pawn[] =  { "             o       ( )      |_|            " };

	char input;

	
	time_t start_time, stop_time;
	double delta_time;

	int value;

	

	while(input!=27){
		input = getch();

		if(input=='z'){
			if(WHOSE_MOVE>0 && MOVE_COUNTER>1){
				MOVE_COUNTER--;
			}
			board.undo();
			
			frame.build_pic(board, move_cont);
			while(MOUSE_L_BUTTON == 1){
				mouse_update();
			}			
		}

		if(input=='c'){
			endwin();
			if(config(board.get_vboard())==-1){
				return 0;
			}
			board.vboard_to_rboard();
			init_picture(COLOR_R, COLOR_G, COLOR_B);
		}

		if(move_active == 0){
			value=-10075;
			for(int i = 0; i<64; i++){
				if(board.get_field(i%8, i/8)<-50 || board.get_field(i%8, i/8)>0){
						value+=board.get_field(i%8, i/8);
				}
			}
		}
			

		std::stringstream r;
		std::stringstream s;
		s << value;
		r << MOVE_COUNTER;
		std::string str_r = r.str();
		std::string str_s = s.str();
		frame.print("\n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n"+str_r+"\n"+str_s);

		std::stringstream t;
		t << delta_time;
		std::string str_t = t.str();
		std::string str_u = std::to_string(MOVES);
		frame.print("Computer thought in "+str_t+" seconds about "+str_u+" possible games.");
				

		mouse_update();
		if(MOUSE_X_POS<0){
			MOUSE_X_POS=0;
		}
		if(MOUSE_X_POS>=frame.get_width()){
			MOUSE_X_POS=frame.get_width()-1;
		}
		if(MOUSE_Y_POS<0){
			MOUSE_Y_POS=0;
		}
		if(MOUSE_Y_POS>=frame.get_height()){
			MOUSE_Y_POS=frame.get_height()-1;
		}

		if(MOUSE_R_BUTTON==2){
			board.vboard_to_rboard();			
			move_cont = 0;
			move_old_xfield = 0;
	 		move_old_yfield = 0;
			move_active = 0;
		}

		if(WHOSE_MOVE==1){
			//endwin();
			frame.print("Computer is thinking.                                                                                       ");
			frame.build_pic_flipped(board, 0);
			//std::cout << "Thats a debug-try 1\n";
			MOVES=0;

			int temp_board[120];

			memcpy(temp_board, board.get_vboard(), sizeof(int)*120);

			//std::cout << &temp_board[0] <<"\n";
			start_time=time(NULL);
			find_best_move_for_white(DEEPNESS, SEC_DEEPNESS, temp_board, frame, board);
			stop_time=time(NULL);
			delta_time=difftime(stop_time, start_time);
			frame.clear_printed();
			/*for(int i = 0; i<12; i++){
				for(int j = 0; j<10; j++){
					std::cout << temp_board[i*10+j] <<"\t";
				}
				std::cout << "\n";
			}*/
			memcpy(board.get_vboard(), temp_board, sizeof(int)*120);
			board.vboard_to_rboard();
			if(WHOSE_MOVE<0){
				MOVE_COUNTER++;
			}
			WHOSE_MOVE*=-1;
			//std::this_thread::sleep_for(std::chrono::milliseconds(500000));
			while(MOUSE_L_BUTTON == 1){
				mouse_update();
			}
			//init_picture(COLOR_R, COLOR_G, COLOR_B);
		}
	
		/*if(MOUSE_L_BUTTON==1 && 7-MOUSE_X_FIELD>=0 && 7-MOUSE_Y_FIELD>=0){
			board.add(7-MOUSE_X_FIELD, 7-MOUSE_Y_FIELD, 3840);
		}
		if(MOUSE_R_BUTTON==2 && 7-MOUSE_X_FIELD>=0 && 7-MOUSE_Y_FIELD>=0){
			board.add(7-MOUSE_X_FIELD, 7-MOUSE_Y_FIELD, B_KNIGHT);
		}
		if(MOUSE_M_BUTTON==4 && 7-MOUSE_X_FIELD>=0 && 7-MOUSE_Y_FIELD>=0){
			board.add(7-MOUSE_X_FIELD, 7-MOUSE_Y_FIELD, 0);
		}*/

		if(MOUSE_L_BUTTON == 1 && move_active == 1){
			int status = board.move(move_old_xfield, move_old_yfield, 7-MOUSE_X_FIELD, 7-MOUSE_Y_FIELD);
			if(status==1){
				for(int k = 0; k<CHESS_FIELD_WIDTH; k++){
					for(int l = 0; l<CHESS_FIELD_HEIGHT; l++){
						frame.add_b_pixel( (k+7-MOUSE_X_FIELD*CHESS_FIELD_WIDTH), (l+MOUSE_Y_FIELD*CHESS_FIELD_HEIGHT), ' ' );
						frame.add_w_pixel( (k+7-MOUSE_X_FIELD*CHESS_FIELD_WIDTH), (l+MOUSE_Y_FIELD*CHESS_FIELD_HEIGHT), pawn[k+l*CHESS_FIELD_WIDTH] );
					}
				}
				//std::string s = "Which piece do you want?\n1) Queen\n2) ?";
				frame.clear_printed();
				frame.print("Which piece do you want?\n1) Queen\n2) Knight\n3) Rook\n4) Bishop");				
				frame.build_pic_flipped(board, move_cont);
				timeout(10000);
				input = getch();
				timeout(0);
				frame.clear_printed();
				if(input=='1'){
					board.add_to_rboard(7-MOUSE_X_FIELD, 7-MOUSE_Y_FIELD, W_QUEEN);
					board.rboard_to_vboard();
				}
				else if(input=='2'){
					board.add_to_rboard(7-MOUSE_X_FIELD, 7-MOUSE_Y_FIELD, W_KNIGHT);
					board.rboard_to_vboard();
				}
				else if(input=='3'){
					board.add_to_rboard(7-MOUSE_X_FIELD, 7-MOUSE_Y_FIELD, W_ROOK);
					board.rboard_to_vboard();
				}
				else if(input=='4'){
					board.add_to_rboard(7-MOUSE_X_FIELD, 7-MOUSE_Y_FIELD, W_BISHOP);
					board.rboard_to_vboard();
				}
				else{
					board.add_to_rboard(7-MOUSE_X_FIELD, 7-MOUSE_Y_FIELD, W_QUEEN);
					board.rboard_to_vboard();
				}
				
			}
			else if(status==2){
				for(int k = 0; k<CHESS_FIELD_WIDTH; k++){
					for(int l = 0; l<CHESS_FIELD_HEIGHT; l++){
						frame.add_w_pixel( (k+7-MOUSE_X_FIELD*CHESS_FIELD_WIDTH), (l+MOUSE_Y_FIELD*CHESS_FIELD_HEIGHT), ' ' );
						frame.add_b_pixel( (k+7-MOUSE_X_FIELD*CHESS_FIELD_WIDTH), (l+MOUSE_Y_FIELD*CHESS_FIELD_HEIGHT), pawn[k+l*CHESS_FIELD_WIDTH] );
					}
				}
				frame.clear_printed();
				std::string s = "Which piece do you want?\n1) Queen\n2) ?";
				frame.print("Which piece do you want?\n1) Queen\n2) Knight\n3) Rook\n4) Bishop");
				frame.build_pic_flipped(board, move_cont);
				timeout(10000);
				input = getch();
				timeout(0);
				frame.clear_printed();
				if(input=='1'){
					board.add_to_rboard(7-MOUSE_X_FIELD, 7-MOUSE_Y_FIELD, B_QUEEN);
					board.rboard_to_vboard();
				}
				else if(input=='2'){
					board.add_to_rboard(7-MOUSE_X_FIELD, 7-MOUSE_Y_FIELD, B_KNIGHT);
					board.rboard_to_vboard();
				}
				else if(input=='3'){
					board.add_to_rboard(7-MOUSE_X_FIELD, 7-MOUSE_Y_FIELD, B_ROOK);
					board.rboard_to_vboard();
				}
				else if(input=='4'){
					board.add_to_rboard(7-MOUSE_X_FIELD, 7-MOUSE_Y_FIELD, B_BISHOP);
					board.rboard_to_vboard();
				}
				else{
					board.add_to_rboard(7-MOUSE_X_FIELD, 7-MOUSE_Y_FIELD, B_QUEEN);
					board.rboard_to_vboard();
				}
				
			}
			if(status>=0){
				if(WHOSE_MOVE<0){
					MOVE_COUNTER++;
				}
				WHOSE_MOVE*=-1;
			}
			move_cont = 0;
			move_active = 0;
		}

		if(MOUSE_L_BUTTON == 1 && move_active == 0 && board.get_field(7-MOUSE_X_FIELD, 7-MOUSE_Y_FIELD)!=0 && board.get_field(7-MOUSE_X_FIELD, 7-MOUSE_Y_FIELD)*WHOSE_MOVE>0){
			move_cont = board.get_field(7-MOUSE_X_FIELD, 7-MOUSE_Y_FIELD);
			move_active = 1;
			move_old_xfield = 7-MOUSE_X_FIELD;
			move_old_yfield = 7-MOUSE_Y_FIELD;
			board.add_to_rboard(7-MOUSE_X_FIELD, 7-MOUSE_Y_FIELD, 0);
		}



		//if(move_active == 1){}
		/*std::string s = "hallo\nwie gehts?";
		int j=1;
		int k=1;
		for(int i = 0; i<s.length(); i++){
			if(s[i]=='\n'){
				j++;
				i++;
				k=1;
			}	
			frame.add_mouse_pixel(CHESS_FIELD_WIDTH*8+k, j,  s[i]);
			k++;
		}*/
		
		frame.add_w_pixel(MOUSE_X_POS, MOUSE_Y_POS, ' ');
		frame.add_b_pixel(MOUSE_X_POS, MOUSE_Y_POS, ' ');
		frame.add_mouse_pixel(MOUSE_X_POS, MOUSE_Y_POS, 'x');
		frame.build_pic_flipped(board, move_cont);
		frame.clear_printed();
		frame.add_mouse_pixel(MOUSE_X_POS, MOUSE_Y_POS, ' ');		
		while(MOUSE_L_BUTTON == 1){
			mouse_update();
		}
	}

	endwin();
	return 0;
}

int main(){

	struct sched_param para;

	para.sched_priority = 0;

	pthread_setschedparam(pthread_self(), SCHED_OTHER, &para);

	int input;

	while(input != 6){

		std::cout << "\n1) Sandbox\n2) Human vs. Human\n3) Human vs. Human over Network\n4) Human vs. Computer\n5) Configuration (limited)\n6) Exit\n\n>";
		std::cin >> input;
	
		switch(input){
			case 1: sandbox();
				break;
			
			case 2: human_v_human();
				break;
			
			case 3: human_v_human_network();
				std::cout << "Not implemented yet\n\n";
				break;
			
			case 4: std::cout <<"\nPlease enter the deepness of the computer beetween 1 and a positive number.\nRecommended for computer that have at least 24 virtual cores is 5.\nFor slower computers you should take account of setting the deepness to 4 or 3.\n\n>";
				std::cin >> input;
				DEEPNESS = input;
	
				std::cout <<"\nPlease enter the secondary deepness of the computer beetween 1 and a positive number.\nRecommended for computer that have at least 24 virtual cores is 6.\nFor slower computers you should take account of setting the secondary deepness to 5 or 4.\n\n>";
				std::cin >> input;
				SEC_DEEPNESS = input;
	
				std::cout <<"\nPlease enter the horizon-deepness of the computer beetween 1 and a positive number.\nRecommended for blitzgames  is 0.\nFor longer games  you should take account of setting the horizon-deepness to 1 or 2.\n\n>";
				std::cin >> input;
				HORIZON_DEEPNESS = input;
	
				
				std::cout << "\nPlease enter the required captures to use the horizon-deepness.\nRecommended is between 2 and 4\n\n>";
				std::cin >> input;
				REQUIRED_CAPTURES = (-1)*(input+3);
	
	
				std::cout <<"\nWhat do you want to play?\n1) Black\n2) White\n\n>";
				std::cin >> input;
	
				switch(input){
					case 1: human_v_white_computer();
						break;
	
					case 2: human_v_black_computer();
						break;
	
					default: std::cout << "Inoperative Input\n\n";
				}
				break;
			
			case 5:	int a[120];
				config(a);	
				break;
			
			case 6:	std::cout << "GOOD BYE\n\n>";
				std::this_thread::sleep_for(std::chrono::milliseconds(600));	
				break;
	
			default: std::cout << "Inoperative Input\n\n";
				 //std::cin.ignore();
		}
	}
	
		
	/*int vboard[120]={      //x=0 x=1 x=2 x=3 x=4 x=5 x=6 x=7 x=8 x=9
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

	int pos_mov[150][120];

	int num = get_pos_mov_black(pos_mov, vboard);

	for(int i = 0; i<num; i++){
		for(int j = 0; j<120; j++){
			std::cout << pos_mov[i][j] << "\t";
			if((j+1)%10==0){
				std::cout << "\n";
			}
		}
		std::this_thread::sleep_for(std::chrono::milliseconds(2000));
		std::cout << "\n\n\n";
	}*/
	/*std::cout << "\033[2J";
	for(int i = 0; i<=LINES; i++){
		std::cout << "\033[1A";
	}*/
	std::cout << "\033[2J\033[1;1H";

	return 0;
}

























































