// 11286 - 절댓값 힙 (S1) - [소요 시간 : 30분 00초]

// #priority_queue + cmp 함수
// 정렬을 하는데 단순한 오름차순/내림차순 정렬이 아니라 원하는대로 정렬을 하고 싶은 경우 priority_queue에서 cmp 구조체를 정의하고 () 연산자를 오버로딩한다.

// 성능 : 2532KB, 16ms
#include <iostream>
#include <queue>
using namespace std;

struct cmp {
	bool operator()(int a, int b) {
		if (abs(a) == abs(b)) { // 절댓값이 같은 경우
			if (a > b) { // a가 양수 b가 음수일 경우
				return a > b; // true
			}
			else {
				return a > b; // b가 양수 a가 음수일 경우 false
			}
		}

		return abs(a) > abs(b); // 절댓값이 작은 순서대로(내림차순)
	}
};

priority_queue<int, vector<int>, cmp> pq;

int main(void) {
	int n;
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

	cin >> n;
	for (int i = 0; i < n; i++) {
		int x = 0;
		cin >> x;
		if (x == 0) { // 0 입력 시
			if (pq.empty()) { // 우선순위 큐가 비었다면
				cout << "0\n";
			}
			else { // 큐에 값이 있다면 조건에 맞는 값 출력
				cout << pq.top() << "\n";
				pq.pop();
			}
		}

		else { // 0이 아닌 값을 입력 시
			pq.push(x);
		}
	}
	return 0;
}