#ifndef tetris
#define tetris

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
	
	private:
	int width;
	int *heights;
	char **data;

};

#endif