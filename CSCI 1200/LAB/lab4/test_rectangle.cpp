#include <iostream>
#include "Rectangle.h"
using namespace std;

int main(){
	Point2D pointll(4,5);
	Point2D pointur(17,11);
	Point2D pointtest1(9,3.5);
	Point2D pointtest2(8,15);
	
	Rectangle rec(pointll,pointur);
	
	print_rectangle(rec);
	
	if(rec.is_point_within(pointtest1)){
		cout<<"a"<<endl;
	}
	
	if(rec.is_point_within(pointtest2)){
		cout<<"b"<<endl;
	}
	
	if(rec.add_point(pointtest1)){
		cout<<"c"<<endl;
	}
	
	return 0;
}