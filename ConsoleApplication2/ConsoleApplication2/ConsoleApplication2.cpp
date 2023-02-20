// 80강 - 순수 가상 함수와 추상 클래스
//추상 클래스를 활용하여
//원과 사각형의 넓이와 크기 배율 조정을 하는 프로그램을 작성하고,
//반지름이 10인 원과 가로 세로가 각각 20, 30인 사각형의 넓이를 한꺼번에 구하는 프로그램을 작성하시오.
// 출력은 범위 기반 for문을 이용하시오.

//#추상 클래스, #순수 가상 함수, # 범위 기반 for문, #포인터 배열

#include <iostream>
#define PI 3.141592
using namespace std;
class Shape { // 추상 클래스 -> 인스턴스(객체)를 만들 수 없다.
public:
	virtual double GetArea() = NULL; // 순수 가상 함수 -> 순수 가상 함수가 존재하기 때문에 Shape 클래스는 인스턴스(객체)를 생성할 수 없다. - 함수의 정의가 없는 상태
	virtual void ReSize(double multple) = NULL; // 순수 가상 함수 -> 순수 가상 함수가 존재하기 때문에 Shape 클래스는 인스턴스(객체)를 생성할 수 없다. - 함수의 정의가 없는 상태
};

class Circle : public Shape{ // 구상 클래스 -> 객체를 생성할 수 있는 클래스
public:
	Circle() : r(0) { };
	Circle(int r) : r(r) { };

	double GetArea() {
		return PI * r * r;
	}
	
	void ReSize(double multple) {
		r = r * multple;
	}

private:
	double r; // 반지름
};

class Rectangle : public Shape{
public:
	Rectangle() : width(0), length(0) { };
	Rectangle(int width, int length) : width(width), length(length) { };

	double GetArea() {
		return width *length;
	}
	
	void ReSize(double multple) {
		width = width * multple;
		length = length * multple;
	}

private:
	double width; // 가로
	double length; // 세로
};


int main(void) {
	// 포인터 배열 활용
	Shape* shapes[] = {
		new Circle(10),
		new Circle(20),
		new Circle(22),
		new Rectangle(10,15),
		new Rectangle(15,20),
		new Rectangle(25,30),
	};


	// Shape s1; 이건 안되지만, 
	//Shape* s1 = new Circle(10); // 이건 가능
	
	//for (int i = 0; i < 10; i++) {
	//	cout << shapes[i]->GetArea() << "\n";
	//}

	// 범위 기반 for 문 활용
	for (Shape* s : shapes) { // shpaes[0]부터 끝 인덱스까지 순서대로 s에 넣어준다.
		cout << s->GetArea() << "\n";
	}
	for (Shape* s : shapes) {
		s->ReSize(2);
	}
	for (Shape* s : shapes) {
		cout << s->GetArea() << "\n";
	}

	for (Shape* t : shapes) {
		delete t;
	}

}