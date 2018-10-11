#ifndef _polygons_
#define _polygons_

#include<iostream>
#include<string>
#include<vector>
#include "utilities.h"
using namespace std;

class Polygon{
public:
	//base constructor will assign the name and the points vector of a shape
	Polygon(const string& n, const vector<Point>& pts){	
		name=n;
		vertices=pts;
	}
	virtual ~Polygon() {}		//define destructor to delete the all shape at last
	//a series of judgement states (implemented in .cpp file)
	virtual bool HasAllEqualSides();
	virtual bool HasAllEqualAngles();
	virtual bool HasARightAngle();
	virtual bool HasAnObtuseAngle();
	virtual bool HasAnAcuteAngle();
	virtual bool IsConvex();
	bool IsConcave(){return !IsConvex();}		//shape is concave when it isn't convex
	const string& getName() const {return name;}
	
protected:
	string name;
	vector<Point> vertices;
};

class Triangle : public Polygon{
public:
	Triangle(const string& n, const vector<Point>& pts) : Polygon(n, pts){
		if(int(pts.size())!=3){			//throw the exception if the shape doen't match the basic requirement
			throw 1;
		}
	}
	//assign the default property to any triangles
	virtual bool HasAllEqualSides(){return false;}
	virtual bool HasAllEqualAngles(){return false;}
	virtual bool HasARightAngle(){return false;}
	virtual bool HasAnObtuseAngle(){return false;}
	bool HasAnAcuteAngle(){return true;}
	bool IsConvex(){return true;}
};

class Quadrilateral : public Polygon{
public:
	Quadrilateral(const string& n, const vector<Point>& pts) : Polygon(n, pts){
		if(int(pts.size())!=4){
			throw 1;
		}
	}
	virtual bool HasAllEqualSides(){return false;}
	virtual bool HasAllEqualAngles(){return false;}
	//quadliterals are not as simple as triangles, so we need to check their properties at this point
	virtual bool HasARightAngle(){
		double a1=Angle(vertices[0],vertices[1],vertices[2]);
		double a2=Angle(vertices[1],vertices[2],vertices[3]);
		double a3=Angle(vertices[2],vertices[3],vertices[0]);
		double a4=Angle(vertices[3],vertices[0],vertices[1]);
		if(RightAngle(a1)||RightAngle(a2)||RightAngle(a3)||RightAngle(a4)){
			return true;
		}
		return false;
	}
	virtual bool HasAnObtuseAngle(){
		double a1=Angle(vertices[0],vertices[1],vertices[2]);
		double a2=Angle(vertices[1],vertices[2],vertices[3]);
		double a3=Angle(vertices[2],vertices[3],vertices[0]);
		double a4=Angle(vertices[3],vertices[0],vertices[1]);
		if(ObtuseAngle(a1)||ObtuseAngle(a2)||ObtuseAngle(a3)||ObtuseAngle(a4)){
			return true;
		}
		return false;
	}
	virtual bool HasAnAcuteAngle(){return true;}		//a quadliteral must have an acute angle as long as it isn't rectangle or square
	virtual bool IsConvex(){
		double a1=Angle(vertices[0],vertices[1],vertices[2]);
		double a2=Angle(vertices[1],vertices[2],vertices[3]);
		double a3=Angle(vertices[2],vertices[3],vertices[0]);
		double a4=Angle(vertices[3],vertices[0],vertices[1]);
		if(ReflexAngle(a1)||ReflexAngle(a2)||ReflexAngle(a3)||ReflexAngle(a4)){
			return false;
		}
		return true;
	}
};

class IsoscelesTriangle : virtual public Triangle{
public:
	IsoscelesTriangle(const string& n, const vector<Point>& pts);
};

class RightTriangle : virtual public Triangle{
public:
	RightTriangle(const string& n, const vector<Point>& pts);
	bool HasARightAngle(){return true;}
};

class IsoscelesRightTriangle : public IsoscelesTriangle, public RightTriangle{
public:
	IsoscelesRightTriangle(const string& n, const vector<Point>& pts);
};

class ObtuseTriangle : virtual public Triangle{
public:
	ObtuseTriangle(const string& n, const vector<Point>& pts);
	bool HasAnObtuseAngle(){return true;}
};

class IsoscelesObtuseTriangle : public IsoscelesTriangle, public ObtuseTriangle{
public:
	IsoscelesObtuseTriangle(const string& n, const vector<Point>& pts);
};

class EquilateralTriangle : public IsoscelesTriangle{
public:
	EquilateralTriangle(const string& n, const vector<Point>& pts);
	bool HasAllEqualSides(){return true;}
	bool HasAllEqualAngles(){return true;}
};

class Trapezoid : virtual public Quadrilateral{
public:
	Trapezoid(const string& n, const vector<Point>& pts);
};

class Kite : virtual public Quadrilateral{
public:
	Kite(const string& n, const vector<Point>& pts);
};

class Arrow : public Quadrilateral{
public:
	Arrow(const string& n, const vector<Point>& pts);
	bool IsConvex(){return false;}		//this is the difference between Kite and Arrow
};

class Parallelogram : virtual public Trapezoid{
public:
	Parallelogram(const string& n, const vector<Point>& pts);
};

class IsoscelesTrapezoid : virtual public Trapezoid{
public:
	IsoscelesTrapezoid(const string& n, const vector<Point>& pts);
};

class Rectangle : virtual public Parallelogram, public IsoscelesTrapezoid{
public:
	Rectangle(const string& n, const vector<Point>& pts);
	bool HasAllEqualAngles(){return true;}
	bool HasARightAngle(){return true;}
	bool HasAnObtuseAngle(){return false;}
	bool HasAnAcuteAngle(){return false;}
};

class Rhombus : virtual public Parallelogram, public Kite{
public:
	Rhombus(const string& n, const vector<Point>& pts);
	bool HasAllEqualSides(){return true;}
};

class Square : public Rectangle, public Rhombus{
public:
	Square(const string& n, const vector<Point>& pts);
	bool HasARightAngle(){return true;}
};


#endif