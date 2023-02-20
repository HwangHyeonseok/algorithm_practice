//11279 - 최대 힙 (S2) [소요 시간 : 14분 25초]

// 입력되는 자연수가 pow(2,31) 이므로 long long 자료형을 사용한다.
// 우선순위 큐 연습문제 - ADT를 바탕으로 DS 구현 연습은 나중에!

// 성능 : 3684KB, 16ms
#include <iostream>
#include <queue>

using namespace std;

int main(void) {
	int n;
	priority_queue<long long, vector<long long>, less<long long>> pq; // 우선순위 큐 선언 (내림차순)
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

	cin >> n;
	for (int i = 0; i < n; i++) {
		long long x;
		cin >> x;
		if (x == 0) { 
			if(pq.empty()) // 0을 입력했는데 빈 큐 인 경우
				cout << "0\n";
			else { // 0을 입력했는데 큐에 값이 있는 경우 - 큐에서 가장 큰 값 출력 후 그 값을 큐에서 제거
				cout << pq.top() << "\n";
				pq.pop();
			}
		}
		
		else { // 0이 아닌 수를 입력한 경우 큐에 내림차순으로 push
			pq.push(x);
		}

	}
	return 0;
}