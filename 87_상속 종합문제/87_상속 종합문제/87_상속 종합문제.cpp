// 2번 문제 정답 - 가상 함수와 오버라이딩을 이용한다.
#include <iostream>
#include <string>
using namespace std;

const double PI = 3.141592653589793;

class Shape {
public:
	virtual ~Shape() {}
	virtual double GetArea() const = 0;
	virtual void ReSize(double factor) = 0;
	virtual string GetInfo() {
		return "도형의 넓이 : " + to_string(GetArea());
	}
};

class Circle : public Shape {
public:
	Circle(double r) : r(r) {}

	double GetArea() const {
		return r * r * PI;
	}
	void ReSize(double factor) {
		r *= factor;
	}

private:
	double r;
};

class Rectangle : public Shape {
public:
	Rectangle(double a, double b) : a(a), b(b) {}

	double GetArea() const {
		return a * b;
	}
	void ReSize(double factor) {
		a *= factor;
		b *= factor;
	}

	double GetDiag() const {
		return sqrt(a * a + b * b);
	}

	string GetInfo() {
		return Shape::GetInfo() + "\n도형의 최단 거리 : " + to_string(GetDiag());
	}

private:
	double a, b;
};

int main(void) {
	Shape* shapes[] = { new Circle(1), new Rectangle(1,2) };

	for (Shape* s : shapes) {
		cout << s->GetInfo() << "\n";
	}

	for (Shape* s : shapes) {
		delete s;
	}
}

/*
// 2번 문제
// 성능 저하의 원인인 dynamic_cast을 쓰지 않고 기능을 유지한 채 코드가 작동되도록 하시오.
#include <iostream>
using namespace std;

const double PI = 3.141592653589793;

class Shape {
public:
	virtual ~Shape() {}
	virtual double GetArea() const = 0;
	virtual void ReSize(double factor) = 0;
};

class Circle : public Shape {
public:
	Circle(double r) : r(r) {}

	double GetArea() const {
		return r * r * PI;
	}
	void ReSize(double factor) {
		r *= factor;
	}

private:
	double r;
};

class Rectangle : public Shape {
public:
	Rectangle(double a, double b) : a(a), b(b) {}

	double GetArea() const {
		return a*b;
	}
	void ReSize(double factor) {
		a *= factor;
		b *= factor;
	}

	double GetDiag() const {
		return sqrt(a * a + b * b);
	}

private:
	double a, b;
};

int main(void) {
	Shape* shapes[] = { new Circle(1), new Rectangle(1,2) };

	for (Shape* s : shapes) {
		cout << "도형의 넓이 : " << s->GetArea() << endl;
		Rectangle* r = dynamic_cast<Rectangle*>(s);
		if (r != NULL) {
			cout << "대각선의 길이 : " << r->GetDiag() << endl;
		}
	}

	for (Shape* s : shapes) {
		delete s;
	}
}
*/


/*
// 1번 문제
#include <iostream>
using namespace std;
// A(부모) - B - C 관계
class A {
public:
	virtual int f() { return x; }
	virtual ~A() {}
private:
	int x = 10;
};

class B : public A { 
public:
	int f() { return x; } // 오답노트 : A 클래스에서 	virtual int f() { return x; } 로 상속 받았으므로 B 클래스에서도 virtual이 생략되어 있는거다.
	//	(virtual) int f() { return x; } 와 똑같다. (가상 함수를 오버라이딩 한 함수도 가상 함수다.
	virtual int g() { return A::f(); }
private:
	int x = 20;
};

class C : public B {
public:
	int f() { return x; }
	int g() { return B::f(); }
	virtual int h() { return B::g(); }
private:
	int x = 30;
};

int main() {
	A* a = new B;
	A* b = new C;
	B* c = new C;
	C* d = new C;
// Q1. 다음 중 오류가 나는 코드는?
	cout << a->f() << endl; // 20
	//cout << a->g() << endl; // (X)
	cout << b->f() << endl; // 30
	//cout << b->g() << endl; // (X)
	cout << c->f() << endl; // 30
	cout << c->g() << endl; // 20
	cout << d->g() << endl; // 20
	cout << d->h() << endl; // 10

	delete a;
	delete b;
	delete c;
	delete d;
}
*/