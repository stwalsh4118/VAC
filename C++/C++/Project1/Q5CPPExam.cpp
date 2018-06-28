#include <iostream>
#include <string>
using namespace std;

class Shape {
	public :
		Shape() {
			sides = -1;
			classification = "NULL";
		}
		Shape(int s, string c) {
			sides = s;
			classification = c;	
		}
		virtual ~Shape() {
			cout << "This shape is destructed" << endl;
		}
		virtual double area() = 0;
		virtual void display() = 0;
	protected: 
		int sides;
		string classification;
};

class Triangle : public Shape {
	public:
		double height;
		double base;
		Triangle():Shape() {

		}
		Triangle(int s, double h, double b, string c) : Shape(s, c) {
			height = h;
			base = b;
		}
		~Triangle() {
			cout << "This triangle is being destructed" << endl;
		}
		void display() {
			cout << "A triangle has "<<  sides << " sides" << endl;
			cout << "A triangle is a " << classification << endl;
			cout << "This triangle's height is: " << height << " This triangle's base is: " << base << endl;
		}
		double area() {
			cout << "This triangles area is: ";
			return .5*(base*height);
		}
};

class Rectangle : public Shape {
public:
	double side1;
	double side2;
	Rectangle() :Shape() {

	}
	Rectangle(int s, double s1, double s2, string c) : Shape(s, c) {
		side1 = s1;
		side2 = s2;
	}
	~Rectangle() {
		cout << "This rectangle is being destructed" << endl;
	}
	void display() {
		cout << "A rectangle has " << sides << " sides" << endl;
		cout << "A rectangle is a " << classification << endl;
		cout << "This rectangles sides are, " << side1 << " " << side2 << endl;
	}
	double area() {
		cout << "This rectangle's area is: ";
		return side1 * side2;
	}

};

int main() {

	Shape* t = new Triangle(3, 3, 3, "polygon");
	cout << t->area() << endl;
	t->display();
	Shape* r = new Rectangle(4, 5, 5, "Quadralateral");
	cout << r->area() << endl;
	r->display();

	delete r;
	delete t;

	system("PAUSE");
	return 0;
}