// 20230126 백준 문제풀이
// 2164번 - 카드2 (S4) 
// 풀이 전략 : 큐를 통해 그대로 pop과 push(q.front()) 연산을 통해 구현한다. [소요 시간 : 12분 8초]
// 성능 : 4156KB, 4ms

#include <iostream>
#include <queue>
using namespace std;

queue<int> q;

int main(void) {
	// 0. 고속입출력
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

	// 1. 입력 받기
	int n;

	cin >> n;
	for (int i = 1; i <= n; i++) {
		q.push(i);
	}
	// 2. 구현 - 큐에서 pop 한 후 제일 앞에 있는 값을 뒤로 보내기
	while (q.size() != 1) {
		q.pop();
		q.push(q.front());
		q.pop();
	}

	cout << q.back() << "\n";
	return 0;
}