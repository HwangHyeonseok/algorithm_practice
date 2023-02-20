#include <iostream>
using namespace std;
class Time {
public:
	Time() : h(0), m(0), s(0) { };
	Time(int s_) : Time() {
		s = s_;
	}
	Time(int m_, int s_) : Time(s_) {
		m = m_;
	};
	Time(int h_, int m_, int s_) : Time(m_, s_) {
		h = h_;
	}

private:
	int h;
	int m;
	int s;
};

int main(void) {
	Time t1;
	Time t2(5); 
	Time t3(3, 16);
	Time t4(2, 42, 15);
}


/*
// 63강 : 2번 문제
#include <iostream>
using namespace std;
class GameWindow {
public:
	GameWindow(); // 생성자에는 const를 붙이지 않는다. const GameWindow(); //(X)
	GameWindow(const int width,const int height); // 생성자에는 const를 붙이지 않는다. const GameWindow(); //(X)
	
	const int GetWidth() const;
	const int GetHeight() const;

	const void ResizeWindow(const int width_, const int height_); // 멤버 변수가 변하는 메서드이기 때문에 const를 붙일 수 없다.
	// ResizeWindow(const int width_, const int height_) const; // (X)

private:
	int width;
	int height;
};

GameWindow::GameWindow() : width(0), height(0) { };
GameWindow::GameWindow(const int width_,const int height_) {
	if (width_ <= 800 || height_ <= 600) {
		width = 800;
		height = 600;
	}
	else {
		width = width_;
		height = height_;
	}
}
const int GameWindow::GetWidth() const { return width; }
const int GameWindow::GetHeight() const { return height; }
const void GameWindow::ResizeWindow(const int width_,const int height_) {
	if (width_ <= 800 || height_ <= 600) {
		width = 800;
		height = 600;
	}
	else {
		width = width_;
		height = height_;
	}
}

int main(void) {
	GameWindow talesRunner;
	GameWindow LOL(1400, 1800);
	talesRunner.ResizeWindow(700, 1500);
	cout << "width: " << talesRunner.GetWidth() << "height: " << talesRunner.GetHeight() << "\n";
	cout << "width: " << LOL.GetWidth() << "height: " << LOL.GetHeight() << "\n";
	return 0;

}
*/

/*
//62강 : 연산자 오버로딩
#include <iostream>
using namespace std;

class Vector2 {
public: 
	Vector2() : x(0), y(0) { };
	Vector2(int x, int y) : x(x), y(y) { };
	int GetX() { return x; }
	int GetY() { return y; }
	
	const Vector2 operator+(Vector2 a) const { // + 연산자 오버로딩 -> 멤버 연산자 -> 우변의 값을 받아준다.
		return Vector2(x + a.GetX(), y + a.GetY());
	}
	const Vector2 operator-(Vector2 a) const { // - 연산자 오버로딩
		return Vector2(x - a.x, y - a.y);
	}
	float operator*(Vector2 a) const {
		return x*a.GetX()+ y * a.GetY();
	}
	const Vector2 operator*(float a) const {
		return Vector2(x * a, y * a);
	}
	const Vector2 operator/(float a) const {
		return Vector2(x / a, y / a);
	}

private:
	int x;
	int y;
};
// 전역 함수 연산자 오버로딩 1.6*a 처럼 객체.operator*(a); 에서 객체가 아닌 경우 사용
// 1.6.operator*(a); 불가능하기 때문에 매개변수 2개를 받는다. (좌변, 우변 값)
// 비멤버 연산자
const Vector2 operator*(const float a, Vector2 b) { 
	return Vector2(a * b.GetX(), a * b.GetY()); 
}

int main(void) {
	Vector2 a(5, 3);
	Vector2 b(-1, 8);

	Vector2 plus = a + b; // Vector2 plus = a.operator+(b);
	Vector2 minus = a - b;
	float mult1 = a * b;
	Vector2 mult2 = a * 1.6; // Vector2 mult2 = a.operator*(1.6);
	Vector2 mult3 = 1.6 * a; // Vector3 mult3 = operator*(1.6, a);
	Vector2 div = a / 2;

	cout << "x: " << plus.GetX() << "y: " << plus.GetY() << "\n";
	cout << "x: " << minus.GetX() << "y: " << minus.GetY() << "\n";
	cout << "x: " << mult1 << "\n";
	cout << "x: " << mult2.GetX() << "y: " << mult2.GetY() << "\n";
	cout << "x: " << mult3.GetX() << "y: " << mult3.GetY() << "\n";
	cout << "x: " << div.GetX() << "y: " << div.GetY() << "\n";
	return 0;
}
*/

/*
// 61강 : 정적 멤버 함수와 동적 멤버 함수, 선언 및 정의 분리
#include <iostream>
#include <vector>
using namespace std;

class Vector2 {
public: 
	Vector2();
	Vector2(int x, int y);
	const int GetX() const;
	const int GetY() const;
	//static Vector2 sum(Vector2 a, Vector2 b) { // 정적 멤버 함수
	//	return Vector2(a.GetX() + b.GetX(), a.GetY() + b.GetY());
	//}
	static Vector2 sum(Vector2 a, Vector2 b);
	Vector2 Add(Vector2 a) { // 동적 멤버 함수
		return Vector2(x + a.GetX(), y + a.GetY());
	}
	
private:
	int x;
	int y;
};

Vector2::Vector2() : x(0), y(0) { };
Vector2::Vector2(int x, int y) : x(x), y(y) { };
const int Vector2::GetX() const { return x; }
const int Vector2::GetY() const { return y; }
Vector2 Vector2::sum(Vector2 a, Vector2 b) { // 정적 멤버 함수
	return Vector2(a.GetX() + b.GetX(), a.GetY() + b.GetY());
}


int main(void) {
	vector<Vector2> Point;
	int n; // n 개를 입력받는다.
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		Point.push_back(Vector2(x, y));
	}

	Vector2 answer1 = Vector2::sum(Point[0], Point[1]); // 정적 멤버 함수 사용
	Vector2 answer2 = Point[0].Add(Point[1]); // 동적 멤버 함수 사용

	cout << "x: " << answer1.GetX() << "y: " << answer1.GetY() << "\n";
	cout << "x: " << answer2.GetX() << "y: " << answer2.GetY() << "\n";
	return 0;
}
*/

/*
// 60강 : 상수형 매개변수와 상수형 메서드
#include <iostream>

using namespace std;
class Account {
public:
	Account() : money(0) { };
	Account(int money) : money(money) { };

	void Deposit(const int plus) {  // 매개변수의 상수화 -> 매개변수인 plus 가 변하면 안될 때
		// plus = 20; (X)
		money += plus;
		cout << plus << " 원이 예금되었습니다." << "\n";
	}
	
	void Draw(const int minus) { // 매개변수의 상수화 -> 매개변수인 minus 가 변하면 안될 때
		if (money >= minus) {
			// minus = 5; (X)
			money -= minus;
			cout << minus << " 원이 인출되었습니다." << "\n";
		}
	}

	const int Viewmoney() const { // 멤버 메서드의 상수화 -> 멤버 변수의 값을 바꾸면 안될 때 사용 (주로 값을 리턴만 할 때 사용)
		// money++; (X)
		return money;
	}
	
private:
	int money;
};

int main(void) {
	Account sinhan(100);
	sinhan.Deposit(300);
	sinhan.Draw(120);
	cout << sinhan.Viewmoney();
	return 0;
}
*/

/*
// 59강 : 정적 변수와 정적 메서드
#include <iostream>

using namespace std;

class Color {
public:
	Color() : r(0), g(0), b(0), id(idCounter++) { };
	Color(float r, float g, float b) : r(r), g(g), b(b), id(idCounter++) { };
	float Getred() { return r; }
	float Getgreen() { return g; }
	float Getblue() { return b; }
	int Getid() { return id; }

	static Color MixColors(Color a, Color b) {
		return Color((a.Getred() + b.Getred()) / 2, (a.Getgreen() + b.Getgreen()) / 2, (a.Getblue() + b.Getblue()) / 2);
	}
	static int idCounter;

private:
	float r;
	float g;
	float b;
	int id;
};

int Color::idCounter = 1;



int main(void) {
	Color red(1, 0, 0);
	Color blue(0, 0, 1);
	Color purple = Color::MixColors(red, blue);

	cout << "r: " << purple.Getred() << "g: " << purple.Getgreen() << "b: " << purple.Getblue() << "\n";
	cout << red.Getid() << "\n";
	cout << blue.Getid() << "\n";
	cout << purple.Getid() << "\n";

	return 0;
}
*/