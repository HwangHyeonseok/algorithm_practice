// 71_묵시적 형변환

#include <iostream>
#include <string>

using namespace std;

class Item {
public:
	explicit Item(int num) : num(num) { }; // 변환 생성자
	explicit Item(string name) : name(name) { }; // 변환 생성자
	explicit Item(int num, string name) : num(num), name(name) { };
	// 형 변환 연산자 오버로딩은 특이하게 반환형을 operator 뒤에 적는다.
	explicit operator int() { // int형 변환 연산자 오버로딩 
		return num;
	}
	explicit operator string() { // string형 변환 연산자 오버로딩
		string str = to_string(num) + " : " + name;
		return str;
	}

private:
	int num;
	string name;
};

int main(void) {
	Item i1(2); // Item(int num) 호출
	Item i2 = Item(1);  // Item(int num) 호출
	Item i3 = 3;  // 오류
	i3 = 3; // 오류
	Item i4 = (Item)4; // 명시적 변환

	Item i5(5); // Item(int num) 호출
	i5 = (string)"stone"; // 오류

	Item i6(1, "grass");
	Item i7 = { 2, "dirt" }; // 오류
	i7 = { 2, "dirt" }; // 오류
	Item i8{ 3, "wood" };

	int itemNum1 = (int)i8; // 명시적 형 변환
	int itemNum3 = i8; // 묵시적 형 변환 (Item -> int) // 오류
	cout << itemNum1 << endl; // 3 출력
	cout << itemNum3 << endl; // 3 출력
	string item2 = (string)i8; // 명시적 형 변환
	string item4 = i8; // 묵시적 형 변환 (Item -> string) // 오류
	cout << item2 << endl; // 3 : wood 출력
	cout << item4 << endl; // 3 : wood 출력
	return 0;
}


