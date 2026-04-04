#include <iostream>
#define _USE_MATH_DEFINES
#include <cmath>
using namespace std;

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

class Shape {
protected:
	double width, height;
public:
	Shape(double w, double h) {
		width = w;
		height = h;
	}

	double area() {
		return 0;
	}

	double perimeter() {
		return 0;
	}

	void display() {
		cout << "Shape: " << endl;
	}
};

class Rectangle : public Shape {
	public:
	Rectangle(double w, double h) : Shape(w, h) {}
	double area() {
		return width * height;
	}
	double perimeter() {
		return 2 * (width + height);
	}
	void display() {
		cout << "Shape: Rectangle " << endl;
	}

};

class Circle : public Shape {
	private:
		double radius;
public:
	Circle(double r) : Shape(0, 0), radius(r) {}
	double area() {
		return M_PI * radius * radius;
	}
	double perimeter() {
		return 2 * M_PI * radius;
	}
	void display() {
		cout << "Shape: Circle " << endl;
	}

};

class Square : public Shape {
public:
	Square(double side) : Shape(side, side) {}
	double area() {
		return width * height;
	}
	double perimeter() {
		return 4 * width;
	}
	void display() {
		cout << "Shape: Square " << endl;
	}
};

int main() {
	int choice;

	cout << "Select a shape: " << endl;
	cout << "1. Rectangle" << endl;
	cout << "2. Circle" << endl;
	cout << "3. Square" << endl;	
	cin >> choice;

	if (choice == 1) {
		double width, height;
		cout << "Enter width and height: ";
		cin >> width >> height;
		Rectangle rect(width, height);
		rect.display();
		cout << "Area: " << rect.area() << endl;
		cout << "Perimeter: " << rect.perimeter() << endl;
	} 
	else if (choice == 2) {
		double radius;
		cout << "Enter radius: ";
		cin >> radius;
		Circle circ(radius);
		circ.display();
		cout << "Area: " << circ.area() << endl;
		cout << "Perimeter: " << circ.perimeter() << endl;
	} 
	else if (choice == 3) {
		double side;
		cout << "Enter side length: ";
		cin >> side;
		Square sq(side);
		sq.display();
		cout << "Area: " << sq.area() << endl;
		cout << "Perimeter: " << sq.perimeter() << endl;
	} 
	else {
		cout << "Invalid choice!" << endl;
	}

	return 0;
}