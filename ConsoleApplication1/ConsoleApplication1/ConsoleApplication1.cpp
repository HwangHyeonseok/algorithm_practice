// ConsoleApplication1.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
using namespace std;

int main(void) {
	char a[100] = "Hello";
	char b[100];

	strcpy_s(b, a);
	printf_s("%s", b);
	return 0;
}

/*
// 65강 : 동적 할당

#include <iostream>
using namespace std;
class Vector2 {
public:
	Vector2() : x(0), y(0) { };
	Vector2(int x, int y) : x(x), y(y) { };
	
	const int GetX() const { return x; }
	const int GetY() const { return y; }

	Vector2 operator+(Vector2 b) {
		return Vector2(x + b.GetX(), y + b.GetY());
	}

private:
	int x;
	int y;

};

int main(void) {
	Vector2 a(2, 3);
	Vector2 *b = new Vector2(4, 5); // b는 주소이고 *b는 b가 가르키는 값
	Vector2 c = a + *b;

	cout << c.GetX() << c.GetY() << "\n";

	delete b;
	return 0;
}
*/