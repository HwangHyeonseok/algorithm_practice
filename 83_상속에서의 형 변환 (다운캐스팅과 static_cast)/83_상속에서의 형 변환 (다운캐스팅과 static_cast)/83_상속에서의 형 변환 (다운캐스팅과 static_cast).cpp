#include <iostream>

using namespace std;

class Base {
public:
	void f() {
		cout << a << "\n";
	}
private:
	int a = 10;
};

class Derived1 : public Base {
public:
	void f() {
		cout << b << "\n";
	}
private:
	float b = 3.14;
};

class Derived2 : public Base {
public:
	void f() {
		cout << c << "\n";
	}
private:
	int c = 30;
};

int main(void) {
	Base* b = new Derived2;
	Derived2* d = static_cast<Derived2*>(b);
	d->f();
	return 0;
}