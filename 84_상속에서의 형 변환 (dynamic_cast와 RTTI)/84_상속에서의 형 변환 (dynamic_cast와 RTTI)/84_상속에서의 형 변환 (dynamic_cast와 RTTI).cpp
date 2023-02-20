// 84_상속에서의 형 변환 (dynamic_cast와 RTTI)

// dynamic_cast 사용 예제

#include <iostream>
#include <math.h>
#define PI 3.14
using namespace std;

class Shape { // 추상 클래스, 다형 클래스
public:
	virtual float GetArea() const = NULL; // 순수 가상 함수
	virtual void ReSize(int f) = NULL;

private:
};

class Circle : public Shape{
public:
	Circle(float r) : r(r) { };
	~Circle() { }
	float GetArea() const {
		return r * r * PI;
	}
	void ReSize(int f) {
		r *= f;
	}

private:
	float r;
};

class Rectangle : public Shape{
public:
	Rectangle(float width, float height) : width(width), height(height) { };
	~Rectangle() { }

	float GetArea() const {
		return width*height;
	}
	void ReSize(int f) {
		width *= f;
		height *= f;
	}
	float GetDiag() const {
		return sqrt(width * width + height * height);
	}

private:
	float width;
	float height;
};

int main(void) {
	Shape* shapes[3] = { new Circle(2), new Rectangle(3,5), new Rectangle(10,20)}; // 업캐스팅이 묵시적으로 일어나고 있다.
	
	for (int i = 0; i < 3; i++) {
		cout << "도형의 넓이 : " << shapes[i]->GetArea() << "\n"; // 도형의 넓이 출력
		Rectangle* r = dynamic_cast<Rectangle*>(shapes[i]); // 직사각형인지 검사
		if (r != NULL) { // 직사각형 이라면
			cout << "대각선의 길이 : " << r->GetDiag() << "\n"; // 대각선의 길이를 출력
		}
	}
	// 메모리 할당 해제
	for (int i = 0; i < 3; i++) {
		delete shapes[i];
	}

}