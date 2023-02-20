/*
// ============================================ [실습 1] =============================================================
#include <iostream>
using namespace std;

class Ice {
public:
	Ice() {
		cout << "Ice() 생성자 호출\n";
	}
	~Ice() {
		cout << "~Ice() 소멸자 호출\n";
	}

private:

};

class Pat {
public:
	Pat() {
		cout << "Pat() 생성자 호출\n";
	}
	~Pat() {
		cout << "~Pat() 소멸자 호출\n";
	}

private:

};

class BingSoo {
public:
	BingSoo() {
		cout << "BingSoo() 생성자 호출\n";
	}
	~BingSoo() {
		cout << "~BingSoo() 소멸자 호출\n";
	}

private:
	Ice ice;
};

class PatBingSoo : public BingSoo{
public:
	PatBingSoo() {
		cout << "PatBingSoo() 생성자 호출\n";
	}
	~PatBingSoo() {
		cout << "~PatBingSoo() 소멸자 호출\n";
	}

private:
	Pat pat;
};

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); // 고속 입출력
	BingSoo* p = new PatBingSoo; // 포인터 p를 메모리에 할당하면서 생성자 호출 
	//부모 클래스는 자식 클래스를 가르킬 수 있다. (그 반대는 불가능)
	delete p; // p 객체 메모리 할당 해제하면서 소멸자 호출
	return 0;
}

/////////////////// 실 행 결 과 //////////////////
/*
Ice() 생성자 호출
BingSoo() 생성자 호출
Pat() 생성자 호출
PatBingSoo() 생성자 호출
~BingSoo() 소멸자 호출
~Ice() 소멸자 호출
*/


// ============================================ [실습 2] =============================================================
#include <iostream>
using namespace std;

class Ice {
public:
	Ice() {
		cout << "Ice() 생성자 호출\n";
	}
	~Ice() {
		cout << "~Ice() 소멸자 호출\n";
	}

private:

};

class Pat {
public:
	Pat() {
		cout << "Pat() 생성자 호출\n";
	}
	~Pat() {
		cout << "~Pat() 소멸자 호출\n";
	}

private:

};

class BingSoo {
public:
	BingSoo() {
		cout << "BingSoo() 생성자 호출\n";
	}
	virtual ~BingSoo() { // 소멸자도 가상 함수를 사용하여 동적 바인딩을 해준다. - 가상 소멸자
		cout << "~BingSoo() 소멸자 호출\n";
	}

private:
	Ice ice;
};

class PatBingSoo : public BingSoo {
public:
	PatBingSoo() {
		cout << "PatBingSoo() 생성자 호출\n";
	}
	~PatBingSoo() {
		cout << "~PatBingSoo() 소멸자 호출\n";
	}

private:
	Pat pat;
};

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); // 고속 입출력
	BingSoo* p = new PatBingSoo; // 포인터 p를 메모리에 할당하면서 생성자 호출 
	//부모 클래스는 자식 클래스를 가르킬 수 있다. (그 반대는 불가능)
	delete p; // p 객체 메모리 할당 해제하면서 소멸자 호출
	return 0;
}

/////////////////// 실 행 결 과 //////////////////
/*
Ice() 생성자 호출
BingSoo() 생성자 호출
Pat() 생성자 호출
PatBingSoo() 생성자 호출
~PatBingSoo() 소멸자 호출
~Pat() 소멸자 호출
~BingSoo() 소멸자 호출
~Ice() 소멸자 호출
*/