#ifndef _picture_hpp_
#define _picture_hpp_

/*#include <iostream>
#include <sys/ioctl.h>
#include <cstdio>*/
#include <ncurses.h>
#include <string>
#include "board.hpp"
#include "mouse.hpp"
#include "pieces.hpp"


int init_picture(int a, int b, int c);

class Picture{
public:
	Picture();

	~Picture();

	void add_b_pixel(int width, int height, unsigned char c);

	void add_w_pixel(int width, int height, unsigned char c);

	void add_mouse_pixel(int width, int height, unsigned char c);

	void build_pic(Board board, int move_cont);

	void build_pic_flipped(Board board, int move_cont);

	int get_width();

	int get_height();

	void print(std::string s);

	void clear_printed();
		
private:
	unsigned char *picture_b_piece = NULL;

	unsigned char *picture_w_piece = NULL;

	unsigned char *picture_mouse = NULL;

	int width_;

	int height_;
};

#endif
