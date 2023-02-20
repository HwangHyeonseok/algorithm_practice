// 7785번 - 회사에 있는 사람 (S5) [소요 시간 : 15분 20초]
// 전략 : 만약 해당 사람이 enter이면 set에 넣고, leave면 set에서 erase 연산으로 원소를 빼준다.
// 순서가 상관이 있으므로 set을 사용하고 역순 출력이므로 reverse_iterator을 사용한다.

//성능 : 9948KB, 80ms
#include <iostream>
#include <set>
using namespace std;

set<string> employees;

int main(void) {
	int n;
	// 0. 고속 입출력
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	// 1. 입력 받기
	cin >> n;
	for (int i = 0; i < n; i++) {
		string name;
		string condition;
		cin >> name >> condition;
		if (condition == "enter") {
			employees.insert(name);
		}
		else if (condition == "leave") {
			employees.erase(name);
		}
	}
	set<string>::reverse_iterator iter;
	for (iter = employees.rbegin(); iter != employees.rend(); iter++) {
		cout << *iter << "\n";
	}
	return 0;
}