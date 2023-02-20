// 1927번 - 최소 힙 (S2) - [소요 시간 : 11분 16초]

// 데이터를 추가하고 그 데이터를 오름차순으로 정렬해야 한다. 이에 적합한 DS(Data Structure)은 최소 힙이다.
// 최소 힙을 STL으로 구현한 priority_queue을 사용한다.
// x의 범위가 2^31 이므로 long long 자료형을 사용한다.

// 성능 : 2916KB, 16ms
#include <iostream>
#include <queue>

using namespace std;

priority_queue<int, vector<int>, greater<int>> pq; // 오름차순 정렬 큐

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int n;
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		long long x;
		cin >> x;
		
		if (x == 0) { // 0 입력 시
			if (pq.empty()) { // 큐가 빈 경우 - 0출력
				cout << "0\n";
			}
			else { // 큐에 값이 있는 경우 가장 위에 있는 원소 출력 - top
				cout << pq.top()  << "\n"; // 출력
				pq.pop(); // 제거
			}
		}
		else { // 0이 아닌 다른 숫자 입력 시 - 삽입
			pq.push(x);
		}
	}
	return 0;
}