// 함수 템플릿

#include <iostream>
#include <string>

using namespace std;

class Vector2 {
public:
	Vector2() : x(0), y(0) { };
	Vector2(float x, float y) : x(x), y(y) { };

	virtual ~Vector2() {};

	float GetX() const { return x; }
	float GetY() const { return y; }
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

	Vector2 operator+=(Vector2& rhs) { // 2번 문제 해결
		x = x + rhs.x;
		y = y + rhs.y;
		return Vector2(x, y);
	}
	Vector2 operator-=(Vector2& rhs) { // 2번 문제 해결
		x = x - rhs.x;
		y = y - rhs.y;
		return *this;
	}

private:
	float x;
	float y;
};

template<typename T>
T GetSumarr(T arr[], int n) {
	T sum = T(); // 1번 문제 해결
	for (int i = 0; i < n; i++) { // 1번 문제 해결
		sum += arr[i];
	}
	return sum;
}

int main(void) {
	int arr[] = { 1,2,3,4,5 };
	float farr[] = { 1.1, 2.2, 3.3, 4.4, 5.5 };
	Vector2 varr[] = { Vector2(1,3), Vector2(2,4), Vector2(3,5) };
	string sarr[] = { "Hello ", "World ", "Hyeonseok " };

	cout << GetSumarr<int>(arr, 5) << "\n";
	cout << GetSumarr<float>(farr, 5) << "\n";
	Vector2 answer = GetSumarr<Vector2>(varr, 3);
	cout << "x: " << answer.GetX() << " y: " << answer.GetY() << "\n";
	string sentence = GetSumarr<string>(sarr, 3); // 자동
	cout << sentence;

	return 0;
}
