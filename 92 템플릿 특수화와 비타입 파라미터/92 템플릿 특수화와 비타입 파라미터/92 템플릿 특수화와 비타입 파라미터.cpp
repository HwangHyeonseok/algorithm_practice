// 92 템플릿 특수화와 비타입 파라미터

// 비타입 파라미터 예제
// 특정 차원의 벡터를 클래스로 만들고 벡터의 덧셈을 연산하는 코드

#include <iostream>

using namespace std;

template<typename T, int n>
class Vector {
public:
	T GetComp(int i) const { // i 번째 성분을 리턴한다.
		return comp[i];
	}
	void SetComp(int i, T val) { // i 번째 성분을 val으로 바꾼다.
		comp[i] = val;
	}

	Vector operator+(Vector &v) const {
		Vector<T, n> res; // <T, n> 생략 가능
		for (int i = 0; i < n; i++) {
			res.comp[i] = this->comp[i] + v.comp[i];
		}
		return res;
	}

private:
	T comp[n];
};
int main(void) {
	Vector<float, 3> v1;
	Vector<float, 3> v2;
	v1.SetComp(0, 2);
	v1.SetComp(1, 3);
	v1.SetComp(2, 4);
	
	v2.SetComp(0, 5);
	v2.SetComp(1, 6);
	v2.SetComp(2,7);

	Vector<float, 3> v3 = v1.operator+(v2);

	cout << v3.GetComp(0) << ' ' << v3.GetComp(1) << ' ' << v3.GetComp(2) << endl; // 7 9 11 출력

	cout << v1.GetComp(0) << ' ' << v1.GetComp(1) << ' ' << v1.GetComp(2) << endl; // 2 3 4 출력
	return 0;
}




/*
// 템플릿 특수화 예제
#include <iostream>
#include <string>

using namespace std;

template<typename T>

T GetSumarr(T arr[], int n) {
	cout << "템플릿" << endl;
	T sum = arr[0];
	for (int i = 1; i < n; i++) {
		sum += arr[i];
	}
	return sum;
}

// 템플릿 특수화
// GetSumarr<string> 타입 일때만 템플릿 특수화 적용
template<>
string GetSumarr<string>(string arr[], int n) {
	cout << "템플릿 특수화" << endl;
	string sum = arr[0];
	for (int i = 1; i < n; i++) {
		sum += ' ' + arr[i];
	}
	return sum;
}

int main() {
	int iarr[4] = { 2,1,3,4 };
	string sarr[3] = { "Hello", "World", "Hyeonseok" };

	cout << GetSumarr<int>(iarr, 4) << endl;

	string ssum = GetSumarr<string>(sarr, 3); 
	cout << ssum << endl;
}
*/