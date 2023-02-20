// C++ 가상 함수와 동적 바인딩 연습 - 20230126
/*
#include <iostream>

using namespace std;
class Weapon {
public:
	Weapon(int power) : power(power) { };

	virtual void Use() {
		cout << "Weapon::Use 실행" << "\n";
	}

private:
	int power;
};

class Sword : public Weapon{
public:
	Sword(int power) : Weapon(power) { };

	void Use() {
		cout << "Sword::Use 실행" << "\n";
		Swing();
	}

private:
	//int power;
	void Swing() {
		cout << "칼을 휘둘렀다!" << "\n";
	}
};

class Magic : public Weapon {
public:
	Magic(int power, int manaCost) : Weapon(power), manaCost(manaCost) { };

	void Use() {
		cout << "Magic::Use 실행" << "\n";
		Swing();
	}
private:
	int manaCost;
	void Swing() {
		cout << "마법사가 마법을 썼다!" << "\n";
	}
};

int main(void) {
	Magic witch(20, 25); // power : 20 , manaCost : 25
	Sword Warrior(10); // power : 10

	witch.Use(); // Use::Magic 실행
	Warrior.Use(); // Use::Sword 실행

	Weapon* MyWeapon;
	MyWeapon = &witch;
	// 부모 클래스의 Use 메서드가 virtual가 아니라면 -> Weapon::Use 실행
	// 부모 클래스의 Use 메서드가 virtual 함수라면 -> Magic::Use 실행
	MyWeapon->Use(); 
	
	// 부모 클래스의 Use 메서드가 virtual이 아니라면 -> Weapon::Use 실행
	// 부모 클래스의 Use 메서드가 virtual 함수라면 -> Sword::Use 실행
	MyWeapon = &Warrior;
	MyWeapon->Use();

	return 0;
}
*/
// 오버라이딩 예시 - 무기 바꾸기


// ==========================================================================================
/*
// 오버로딩 예시 - 생성자
#include <iostream>
using namespace std;
class Character {
public:
	Character() : attack(0), hp(0), money(0) { };
	Character(int attack) : attack(attack), hp(0) { }; // 오버로딩
	Character(int attack, int hp, int money) : attack(attack), hp(hp), money(money) { }; // 오버로딩
	
	
private:
	int attack;
	int hp;
	int money;
};

int main(void) {
	Character minju; // 기본 생성자 실행 | attack : 0, hp : 0, money : 0
	Character sujin(10); // Character(int attack) 생성자 실행 | attack : 10, hp : 0, money : 0
	Character woojoo(10, 20); // 인자와 매개변수의 개수가 맞는 생성자가 없음 -> 오류 발생
	Character chowon(30, 100, 40); // Character(int attack, int hp, int money) 생성자 실행 | attack : 30, hp : 100, money : 40
}
*/