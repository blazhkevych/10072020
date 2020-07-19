#include <iostream>
using namespace std;

class Point {
protected:
	int x;
	int y;
public:
	Point() : x(0), y(0) {}
	Point(int X, int Y) : x(X), y(Y) {
		cout << "Ya tyt byv (Point)\n";
	}
	void Print() {
		cout << "x = " << x << endl;
		cout << "y = " << y << endl;
	}
	~Point() { cout << "Destruct Point\n"; }
};

class Circle : public Point {
protected:
	int R;
public:
	Circle() : R(0), Point(0, 0) {
		cout << "Ya tyt byv (Circle)\n";
	}
	Circle(int R1, int x1, int y1) : R(R1), Point(x1, y1) {
		cout << "Ya tyt byv (Circle)\n";
	}
	void Print() {
		cout << "R = " << R << endl;
		Point::Print();
	}
	double Square() {
		return 4 * atan(1) * R * R;
	}
	double Length() {
		return 8 * atan(1) * R;
	}
	~Circle() { cout << "Destruct circle\n"; }
};

class Rectangle : public Point {
protected:
	int h;
	int w;
public:
	Rectangle() :h(0), w(0), Point(0, 0) {
		cout << "Ya tyt byv (Rectangle)\n";
	}
	Rectangle(int h1, int w1, int x1, int y1) :h(h1), w(w1), Point(x1, y1) {
		cout << "Ya tyt byv (Rectangle)\n";
	}
	double Perimeter() {
		return 2 * (h + w);
	}
	double Square() {
		return h * w;
	}
	void Print() {
		cout << "h = " << h << endl;
		cout << "w = " << w << endl;
		Point::Print();
	}
	~Rectangle() {
		cout << "Destruct rectungle\n";
	}
};

class Figure :public Rectangle, public Circle {
protected:
	int color;
public:
	Figure(int R, int h, int w, int c, int xc, int yc, int xr, int yr) : Circle(R, xc, yc), Rectangle(h, w, xr, yr), color(c) {
		cout << "Ya tyt byv (Figure)\n";
	}
	double Square() {
		return Circle::Square() + Rectangle::Square();
	}
	~Figure() {
		cout << "Destruct figure\n";
	}
	void Print() {

	}
};

int main() {
	/*Circle C(1);
	C.Print();
	cout << "L = " << C.Length() << endl << "S = " << C.Square() << endl;
	Rectangle R(10, 5);
	R.Print();
	cout << "L = " << R.Perimeter() << endl << "S = " << R.Square() << endl;*/
	Figure A(1, 1, 1, 1, 1, 1, 1, 1);
	cout << "S = " << A.Square() << endl;
}