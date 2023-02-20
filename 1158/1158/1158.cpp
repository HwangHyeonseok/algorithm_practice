// 1158 - 요세푸스 문제 (S4) [소요 시간 : 11분 54초]
// 덱을 이용하여 k-1번째까지는 원소를 뒤로 보내는 작업을 한다.  => dq.push_back(dq.front());
// k번째 원소는 정답 배열에 순서대로 넣고 큐에서 pop을 한다.

// 성능 : 2156KB, 68ms
#include <iostream>
#include <deque>
#include <vector>

using namespace std;
deque<int> dq; // 1~n까지 담는 큐
vector<int> answer; // 요세푸스 문제를 해결하고 담긴 정답

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int n, k;

	cin >> n >> k;
	// 덱에 1부터 n까지 원소를 삽입한다.
	for (int i = 1; i <= n; i++) {
		dq.push_back(i);
	}

	while (!dq.empty()) { // 덱이 빌 때까지 반복한다.

		// k-1 번은 원소를 뒤로 보내는 작업을 한다.
		// ex. 1 2 3 4 5 6 7   ===>   2 3 4 5 6 7 1
		for (int i = 0; i < k-1; i++) { 
			dq.push_back(dq.front());
			dq.pop_front();
		}
		// k 번째 원소는 정답 배열에 넣고 덱에서 삭제한다.
		answer.push_back(dq.front());
		dq.pop_front();
	}

	// answer 배열에 담긴 요세푸스 배열을 형식에 맞게 출력한다.
	cout << "<";
	for (int i = 0; i < n; i++) {
		if (i == n - 1) {
			cout << answer[i];
		}
		else {
			cout << answer[i] << ", ";
		}
	}
	cout << ">";
	return 0;
}