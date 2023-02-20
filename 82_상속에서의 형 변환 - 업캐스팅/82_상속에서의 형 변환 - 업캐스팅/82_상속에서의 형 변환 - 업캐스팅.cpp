// 82_상속에서의 형 변환 - 업캐스팅

// 클래스 배열에서 업캐스팅을 할 때 발생하는 문제점 코드
/*
#include <iostream>

using namespace std;

class Animal {
public:
	float xpos = 1;
	float ypos = 2;
};

class FlyingAnimal : public Animal {
public:
	float zpos = 3;
};

void printAnimals(Animal a[], int n) {
	for (int i = 0; i < n; i++) {
		cout << "(" << a[i].xpos << "," << a[i].ypos << ")" << "\n";
	}
}

int main(void) {
	FlyingAnimal* a = new FlyingAnimal[10];
	printAnimals(a, 10);
	delete[] a;
	return 0;
}

// 출력 결과 // 
// (1,2)
// (3,1)
// (2,3)
// (1,2)
// (3,1)
// (2,3)
// (1,2)
// (3,1)
// (2,3)
// (1,2)
*/
//=================================================================================================================
// [문제 해결 코드] => 포인터 배열 사용
#include <iostream>

using namespace std;

class Animal {
public:
	float xpos = 1;
	float ypos = 2;
};

class FlyingAnimal : public Animal {
public:
	float zpos = 3;
};

void printAnimals(Animal** a, int n) {
	for (int i = 0; i < n; i++) {
		cout << "(" << a[i]->xpos << "," << a[i]->ypos << ")" << "\n";
	}
}

int main(void) {
	Animal** a = new Animal*[10];
	for (int i = 0; i < 10; i++) {
		a[i] = new FlyingAnimal;
	}
	printAnimals(a, 10);
	delete[] a;
	for (int i = 0; i < 10; i++) {
		delete a[i];
	}
	return 0;
}