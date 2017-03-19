#include "mice.h"

char mice_data[3];

int fd_mice;

int get_mice(){
	mice_data[1] = 0;//x
	mice_data[2] = 0;//y
	read(fd_mice, mice_data, sizeof(mice_data));
	return 0; 
}

int open_mice(){
	fd_mice = open("/dev/input/mice", O_RDONLY | O_NONBLOCK);
	if(fd_mice == -1){
		return -1;
	}
	return 0;
}

int close_mice(){	
	if(close(fd_mice)==0){
		return 0;
	}
	return -1;
}
