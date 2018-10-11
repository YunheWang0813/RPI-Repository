#include<iostream>
#include<string>
#include<vector>
#include"polygons.h"
#include"utilities.h"
using namespace std;

//compare all sides' values
bool Polygon::HasAllEqualSides(){
	vector<double> sides;
	for(int i=0;i<int(vertices.size())-1;i++){
		double tempdist=DistanceBetween(vertices[i],vertices[i+1]);
		sides.push_back(tempdist);
	}
	double tempdist=DistanceBetween(vertices[0],vertices[int(vertices.size())-1]);
	sides.push_back(tempdist);
	
	bool answer=true;
	for(int i=0;i<int(sides.size())-1;i++){
		if(!EqualSides(sides[i],sides[i+1])){
			answer=false;
			break;
		}
	}
	if(!EqualSides(sides[0],sides[int(sides.size())-1])){
		answer=false;
	}
	return answer;
}

//compare all angles' values
bool Polygon::HasAllEqualAngles(){
	vector<double> angles;
	for(int i=0;i<int(vertices.size())-2;i++){
		double tempangle=Angle(vertices[i],vertices[i+1],vertices[i+2]);
		angles.push_back(tempangle);
	}
	double tempangle=Angle(vertices[int(vertices.size())-2],vertices[int(vertices.size())-1],vertices[0]);
	angles.push_back(tempangle);
	tempangle=Angle(vertices[int(vertices.size())-1],vertices[0],vertices[1]);
	angles.push_back(tempangle);
	
	bool answer=true;
	for(int i=0;i<int(angles.size())-1;i++){
		if(!EqualAngles(angles[i],angles[i+1])){
			answer=false;
			break;
		}
	}	
	if(!EqualAngles(angles[0],angles[int(angles.size())-1])){
		answer=false;
	}
	return answer;	
}

//check routinely for all angles until find a required angle
bool Polygon::HasARightAngle(){
	for(int i=0;i<int(vertices.size())-2;i++){
		double tempangle=Angle(vertices[i],vertices[i+1],vertices[i+2]);
		if(RightAngle(tempangle)){
			return true;
		}
	}
	double tempangle=Angle(vertices[int(vertices.size())-2],vertices[int(vertices.size())-1],vertices[0]);
	if(RightAngle(tempangle)){
		return true;
	}
	tempangle=Angle(vertices[int(vertices.size())-1],vertices[0],vertices[1]);
	if(RightAngle(tempangle)){
		return true;
	}
	return false;
}

bool Polygon::HasAnObtuseAngle(){
	for(int i=0;i<int(vertices.size())-2;i++){
		double tempangle=Angle(vertices[i],vertices[i+1],vertices[i+2]);
		if(ObtuseAngle(tempangle)){
			return true;
		}
	}
	double tempangle=Angle(vertices[int(vertices.size())-2],vertices[int(vertices.size())-1],vertices[0]);
	if(ObtuseAngle(tempangle)){
		return true;
	}
	tempangle=Angle(vertices[int(vertices.size())-1],vertices[0],vertices[1]);
	if(ObtuseAngle(tempangle)){
		return true;
	}
	return false;
}

bool Polygon::HasAnAcuteAngle(){
	for(int i=0;i<int(vertices.size())-2;i++){
		double tempangle=Angle(vertices[i],vertices[i+1],vertices[i+2]);
		if(AcuteAngle(tempangle)){
			return true;
		}
	}
	double tempangle=Angle(vertices[int(vertices.size())-2],vertices[int(vertices.size())-1],vertices[0]);
	if(AcuteAngle(tempangle)){
		return true;
	}
	tempangle=Angle(vertices[int(vertices.size())-1],vertices[0],vertices[1]);
	if(AcuteAngle(tempangle)){
		return true;
	}
	return false;
}

bool Polygon::IsConvex(){
	for(int i=0;i<int(vertices.size())-2;i++){
		double tempangle=Angle(vertices[i],vertices[i+1],vertices[i+2]);
		if(ReflexAngle(tempangle)){
			return false;
		}
	}
	double tempangle=Angle(vertices[int(vertices.size())-2],vertices[int(vertices.size())-1],vertices[0]);
	if(ReflexAngle(tempangle)){
		return false;
	}
	tempangle=Angle(vertices[int(vertices.size())-1],vertices[0],vertices[1]);
	if(ReflexAngle(tempangle)){
		return false;
	}
	return true;
}

//accept if its 2 sides' size are the same
IsoscelesTriangle::IsoscelesTriangle(const string& n, const vector<Point>& pts) : Triangle(n, pts){
	if(int(pts.size())!=3){
		throw 1;
	}
	double d1=DistanceBetween(pts[0],pts[1]);
	double d2=DistanceBetween(pts[1],pts[2]);
	double d3=DistanceBetween(pts[0],pts[2]);
	if(!(EqualSides(d1,d2)||EqualSides(d2,d3)||EqualSides(d1,d3))){
		throw 1;
	}
}

//accept if it has a right angle
RightTriangle::RightTriangle(const string& n, const vector<Point>& pts) : Triangle(n, pts){
	if(int(pts.size())!=3){
		throw 1;
	}
	double a1=Angle(pts[0],pts[1],pts[2]);
	double a2=Angle(pts[1],pts[2],pts[0]);
	double a3=Angle(pts[2],pts[0],pts[1]);
	if(!(RightAngle(a1)||RightAngle(a2)||RightAngle(a3))){
		throw 1;
	}
}

//accept if its 2 sides' size are the same and it has a right angle
IsoscelesRightTriangle::IsoscelesRightTriangle(const string& n, const vector<Point>& pts) : Triangle(n, pts), IsoscelesTriangle(n, pts), RightTriangle(n, pts){
	if(int(pts.size())!=3){
		throw 1;
	}
	double a1=Angle(pts[0],pts[1],pts[2]);
	double a2=Angle(pts[1],pts[2],pts[0]);
	double a3=Angle(pts[2],pts[0],pts[1]);
	if(!(RightAngle(a1)||RightAngle(a2)||RightAngle(a3))){
		throw 1;
	}
	double d1=DistanceBetween(pts[0],pts[1]);
	double d2=DistanceBetween(pts[1],pts[2]);
	double d3=DistanceBetween(pts[0],pts[2]);
	if(!(EqualSides(d1,d2)||EqualSides(d2,d3)||EqualSides(d1,d3))){
		throw 1;
	}
}

//accept if it has an obtuse angle
ObtuseTriangle::ObtuseTriangle(const string& n, const vector<Point>& pts) : Triangle(n, pts){
	if(int(pts.size())!=3){
		throw 1;
	}
	double a1=Angle(pts[0],pts[1],pts[2]);
	double a2=Angle(pts[1],pts[2],pts[0]);
	double a3=Angle(pts[2],pts[0],pts[1]);
	if(!(ObtuseAngle(a1)||ObtuseAngle(a2)||ObtuseAngle(a3))){
		throw 1;
	}
}

//accept if its 2 sides' size are the same and it has an obtuse angle
IsoscelesObtuseTriangle::IsoscelesObtuseTriangle(const string& n, const vector<Point>& pts) : Triangle(n, pts), IsoscelesTriangle(n, pts), ObtuseTriangle(n, pts){
	if(int(pts.size())!=3){
		throw 1;
	}
	double a1=Angle(pts[0],pts[1],pts[2]);
	double a2=Angle(pts[1],pts[2],pts[0]);
	double a3=Angle(pts[2],pts[0],pts[1]);
	if(!(ObtuseAngle(a1)||ObtuseAngle(a2)||ObtuseAngle(a3))){
		throw 1;
	}
	double d1=DistanceBetween(pts[0],pts[1]);
	double d2=DistanceBetween(pts[1],pts[2]);
	double d3=DistanceBetween(pts[0],pts[2]);
	if(!(EqualSides(d1,d2)||EqualSides(d2,d3)||EqualSides(d1,d3))){
		throw 1;
	}
}

//accept if its all sides' size are the same
EquilateralTriangle::EquilateralTriangle(const string& n, const vector<Point>& pts) : Triangle(n, pts), IsoscelesTriangle(n, pts){
	if(int(pts.size())!=3){
		throw 1;
	}
	double d1=DistanceBetween(pts[0],pts[1]);
	double d2=DistanceBetween(pts[1],pts[2]);
	double d3=DistanceBetween(pts[0],pts[2]);
	if(!(EqualSides(d1,d2)&&EqualSides(d2,d3)&&EqualSides(d1,d3))){
		throw 1;
	}
}

//accept if its 2 sides are parallel
Trapezoid::Trapezoid(const string& n, const vector<Point>& pts) : Quadrilateral(n, pts){
	if(int(pts.size())!=4){
		throw 1;
	}
	Vector v1(pts[0],pts[1]);
	Vector v2(pts[1],pts[2]);
	Vector v3(pts[2],pts[3]);
	Vector v4(pts[3],pts[0]);
	if(!(Parallel(v1,v3)||Parallel(v2,v4))){
		throw 1;
	}
}

//accept if two pairs of sides have the same size
Kite::Kite(const string& n, const vector<Point>& pts) : Quadrilateral(n, pts){
	if(int(pts.size())!=4){
		throw 1;
	}
	double d1=DistanceBetween(pts[0],pts[1]);
	double d2=DistanceBetween(pts[1],pts[2]);
	double d3=DistanceBetween(pts[2],pts[3]);
	double d4=DistanceBetween(pts[3],pts[0]);
	if(!((EqualSides(d1,d2)&&EqualSides(d3,d4))||(EqualSides(d1,d4)&&EqualSides(d2,d3)))){
		throw 1;
	}
}

//accept if two pairs of sides have the same sides, and have a reflex angle
Arrow::Arrow(const string& n, const vector<Point>& pts) : Quadrilateral(n, pts){
	if(int(pts.size())!=4){
		throw 1;
	}
	double a1=Angle(pts[0],pts[1],pts[2]);
	double a2=Angle(pts[1],pts[2],pts[3]);
	double a3=Angle(pts[2],pts[3],pts[0]);
	double a4=Angle(pts[3],pts[0],pts[1]);
	if(!(ReflexAngle(a1)||ReflexAngle(a2)||ReflexAngle(a3)||ReflexAngle(a4))){
		throw 1;
	}
	double d1=DistanceBetween(pts[0],pts[1]);
	double d2=DistanceBetween(pts[1],pts[2]);
	double d3=DistanceBetween(pts[2],pts[3]);
	double d4=DistanceBetween(pts[3],pts[0]);
	if(!((EqualSides(d1,d2)&&EqualSides(d3,d4))||(EqualSides(d1,d4)&&EqualSides(d2,d3)))){
		throw 1;
	}
}

//accept if two pairs of sides' size are the same and they are parallel
Parallelogram::Parallelogram(const string& n, const vector<Point>& pts) : Quadrilateral(n, pts), Trapezoid(n, pts){
	if(int(pts.size())!=4){
		throw 1;
	}
	Vector v1(pts[0],pts[1]);
	Vector v2(pts[1],pts[2]);
	Vector v3(pts[2],pts[3]);
	Vector v4(pts[3],pts[0]);
	if(!(Parallel(v1,v3)&&Parallel(v2,v4))){
		throw 1;
	}
	double d1=DistanceBetween(pts[0],pts[1]);
	double d2=DistanceBetween(pts[1],pts[2]);
	double d3=DistanceBetween(pts[2],pts[3]);
	double d4=DistanceBetween(pts[3],pts[0]);
	if(!(EqualSides(d1,d3)&&EqualSides(d2,d4))){
		throw 1;
	}
}

//accept if there is the property of trapezoid and one of its angle if same as its adjacent angle 
IsoscelesTrapezoid::IsoscelesTrapezoid(const string& n, const vector<Point>& pts) : Quadrilateral(n, pts), Trapezoid(n, pts){
	if(int(pts.size())!=4){
		throw 1;
	}
	double d1=DistanceBetween(pts[0],pts[1]);
	double d2=DistanceBetween(pts[1],pts[2]);
	double d3=DistanceBetween(pts[2],pts[3]);
	double d4=DistanceBetween(pts[3],pts[0]);
	if(!(EqualSides(d1,d3)||EqualSides(d2,d4))){
		throw 1;
	}
	Vector v1(pts[0],pts[1]);
	Vector v2(pts[1],pts[2]);
	Vector v3(pts[2],pts[3]);
	Vector v4(pts[3],pts[0]);
	if(!(Parallel(v1,v3)||Parallel(v2,v4))){
		throw 1;
	}
	double a1=Angle(pts[0],pts[1],pts[2]);
	double a2=Angle(pts[1],pts[2],pts[3]);
	double a4=Angle(pts[3],pts[0],pts[1]);
	if(!(EqualAngles(a1,a2)||EqualAngles(a1,a4))){
		throw 1;
	}
}

//accept if all angles are the right angle
Rectangle::Rectangle(const string& n, const vector<Point>& pts) : Quadrilateral(n, pts), Trapezoid(n, pts), Parallelogram(n, pts), IsoscelesTrapezoid(n, pts){
	if(int(pts.size())!=4){
		throw 1;
	}
	double a1=Angle(pts[0],pts[1],pts[2]);
	double a2=Angle(pts[1],pts[2],pts[3]);
	double a3=Angle(pts[2],pts[3],pts[0]);
	double a4=Angle(pts[3],pts[0],pts[1]);
	if(!(RightAngle(a1)&&RightAngle(a2)&&RightAngle(a3)&&RightAngle(a4))){
		throw 1;
	}
}

//accept if all sides' size are the same
Rhombus::Rhombus(const string& n, const vector<Point>& pts) : Quadrilateral(n, pts), Trapezoid(n, pts), Parallelogram(n, pts), Kite(n, pts){
	if(int(pts.size())!=4){
		throw 1;
	}
	double d1=DistanceBetween(pts[0],pts[1]);
	double d2=DistanceBetween(pts[1],pts[2]);
	double d3=DistanceBetween(pts[2],pts[3]);
	double d4=DistanceBetween(pts[3],pts[0]);
	if(!(EqualSides(d1,d2)&&EqualSides(d2,d3)&&EqualSides(d3,d4)&&EqualSides(d4,d1))){
		throw 1;
	}
}

//accept if it has both rectangle and rhombus property
Square::Square(const string& n, const vector<Point>& pts) : Quadrilateral(n, pts), Trapezoid(n, pts), Parallelogram(n, pts), Rectangle(n, pts), Rhombus(n, pts){
	if(int(pts.size())!=4){
		throw 1;
	}
	double d1=DistanceBetween(pts[0],pts[1]);
	double d2=DistanceBetween(pts[1],pts[2]);
	double d3=DistanceBetween(pts[2],pts[3]);
	double d4=DistanceBetween(pts[3],pts[0]);
	if(!(EqualSides(d1,d2)&&EqualSides(d2,d3)&&EqualSides(d3,d4)&&EqualSides(d4,d1))){
		throw 1;
	}
	double a1=Angle(pts[0],pts[1],pts[2]);
	double a2=Angle(pts[1],pts[2],pts[3]);
	double a3=Angle(pts[2],pts[3],pts[0]);
	double a4=Angle(pts[3],pts[0],pts[1]);
	if(!(RightAngle(a1)&&RightAngle(a2)&&RightAngle(a3)&&RightAngle(a4))){
		throw 1;
	}
}





