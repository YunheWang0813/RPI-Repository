#ifndef _tetris
#define _tetris

#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Tetris{
	public:
	Tetris(int w);
	
	int get_width() const {return width;}
	void set_width(int w) {width=w;}
	
	void add_piece(char mino, int rot, int place);
	int get_max_height() const;
	int count_squares() const;
	void print() const;
	int remove_full_rows() const;
	void destroy();
	void add_left_column();
	void add_right_column();
	void remove_left_column();
	void remove_right_column();
	
	private:
	int width;
	int *heights;
	char **data;

};

#endif