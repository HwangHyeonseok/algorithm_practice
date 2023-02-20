// 11866 - 요세푸스 문제0 (S5) [소요 시간 : 11분 5초]
// 큐를 이용하여 k개마다 출력하고 pop을 해준다. 
// k개에 해당하지 않는 수는 그때그때마다 뒤로 보내준다.

// 예 시
// 1 2 3 4 5 6 7
// 2 3 4 5 6 7 1
// 3 4 5 6 7 1 2 
// 4 5 6 7 1 2
// 5 6 7 1 2 4 .......

// 성능 : 2156KB, 0ms
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

queue<int> q;
vector<int> answer;
int main(void) {
	int n, k;
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	
	cin >> n >> k;

	for (int i = 1; i <= n; i++) {
		q.push(i);
	}

	while (!q.empty()) { // 큐가 다 빌 때까지
		for (int i = 0; i < k-1; i++) {
			q.push(q.front());
			q.pop();
		}
		answer.push_back(q.front());
		q.pop();
	}
	cout << "<";
	for (int i = 0; i < n; i++) {
		if (i == n - 1)
			cout << answer[i];
		else
			cout << answer[i] << ", ";
	}
	cout << ">";
	return 0;
}