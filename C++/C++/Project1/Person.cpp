#include <iostream>
#include <string>
using namespace std;

class Person {

public: 
	string profession;
	int age;

	Person() {
		profession = "NULL";
		age = -1;
	};
	Person(string p, int a) {
		profession = p;
		age = a;
	}

	void display() {
		cout << "Profession: " << profession << " Age: " << age << endl;
	}

};

class MathsTeacher: public Person {
	
public:
	MathsTeacher():
		Person() {
	};
	MathsTeacher(string p, int a):
		Person(p, a) {
	};

	void teachMaths() {
		cout << "Im teaching math." << endl;
	}
};

class Footballer : public Person {

public:
	Footballer() :
		Person() {
	};
	Footballer(string p, int a) :
		Person(p, a) {
	};

	void playFootball() {
		cout << "Im playing football." << endl;
	}
};

int main() {
	MathsTeacher teacher;
	teacher.profession = "Teacher";
	teacher.age = 23;
	teacher.display();
	teacher.teachMaths();

	Footballer footballer;
	footballer.profession = "Footballer";
	footballer.age = 19;
	footballer.display();
	footballer.playFootball();
	system("PAUSE");
	return 0;
}