// 1966 - 프린터 큐 (S3) [소요 시간 : 50분 00초]
// [오답노트] 큐와 pair가 같이 사용할 수 있다.
// 우선순위 큐와 데이터, 순서를 담은 큐를 만들어서 비교하여 정답을 찾는다.
// 성능 : 2024KB, 0ms

#include <iostream>
#include <queue>

using namespace std;

queue<pair<int,int>> q;
priority_queue<int, vector<int>, less<int>> pq;

int main(void) {
	int testcase;
	int n = 0;
	int m = 0;
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

	cin >> testcase;

	for (int j = 0; j < testcase; j++) {
		cin >> n >> m;
		int location = 0;
		int answer = 1;
		for (int i = 0; i < n; i++) {
			int number;
			cin >> number;
			q.push(make_pair(number, location));
			pq.push(number);
			location++;
		}

		while (!q.empty()) {
			if (pq.top() == q.front().first) { // 제일 우선순위(큰 수) == 큐의 제일 앞 데이터 인 경우
				if (q.front().second == m) { // 우리가 구하고자 하는 순서인 경우
					cout << answer << "\n";
					break;
				}
				pq.pop();
				q.pop();
				answer++;
			}
			else {
				q.push(q.front());
				q.pop();
			}
		}

		while (!q.empty()) { // 큐를 깔끔히 비워준다.
			q.pop();
			pq.pop();
		}
	}
	return 0;
}