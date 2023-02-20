// 91 클래스 템플릿

#include <iostream>
#include <string>

using namespace std;

template<typename T>
class Vector2 {
public:
	Vector2() : x(0), y(0) { };
	Vector2(T x, T y) : x(x), y(y) { };

	virtual ~Vector2() {};

	T GetX() const { return x; }
	T GetY() const { return y; }
	Vector2 operator+(Vector2& rhs) {
		return Vector2(x + rhs.x, y + rhs.y);
	}
	Vector2 operator-(Vector2& rhs) {
		return Vector2(x - rhs.x, y - rhs.y);
	}
	Vector2 operator*(Vector2& rhs) {
		return Vector2(x * rhs.x, y * rhs.y);
	}
	Vector2 operator/(Vector2& rhs) {
		return Vector2(x / rhs.x, y / rhs.y);
	}

	Vector2 operator+=(Vector2& rhs) {
		x = x + rhs.x;
		y = y + rhs.y;
		return Vector2(x, y);
	}
	Vector2 operator-=(Vector2& rhs) {
		x = x - rhs.x;
		y = y - rhs.y;
		return *this;
	}

private:
	T x, y; 
};

int main(void) {
	Vector2<float> v1(2, 3);
	Vector2<double> v2(2.5, 3.5);
	
	cout << "x : " << v1.GetX() << "y : " << v1.GetY() << "\n";
	cout << "x : " << v2.GetX() << "y : " << v2.GetY() << "\n";
	
	Vector2<float> v3 = v1 + v2;
	cout << "x : " << v3.GetX() << "y : " << v3.GetY() << "\n";
	return 0;
} 