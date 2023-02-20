// 1021 - 회전하는 큐 (S3) [소요 시간 : 52분 28초]
// #덱
// 전략 : 양쪽에서 삽입과 삭제가 일어나므로 deque(덱) 사용
// 덱에는 인덱스가 지원 된다는 것을 적극 활용 - [오답 노트1 : 덱은 가장 나중에 넣은 것이 [0](0인덱스)가 된다. 즉, 의도대로 하려면 거꾸로 입력 받아야 한다.]
// 꺼내고자 하는 값의 인덱스가 < (덱의 원소 개수 / 2) 보다 작으면 2번 방식이 유리하고, 
// 꺼내고자 하는 값의 인덱스가 > (덱의 원소 개수 / 2) 보다 크면 3번 방식이 유리하다.


// 성능 : 2024KB, 0ms
#include <iostream>
#include <deque>
#include <vector>

using namespace std;

deque<int> dq;
vector<int> out;

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int n, m;
	int answer = 0;
	int out_finding = 0;

	cin >> n >> m;

	for (int i = n; i >= 1; i--) { // 초기 큐 값 넣기 - [오답 노트1]
		dq.push_front(i);
	}
	
	for (int i = 0; i < m; i++) { // 꺼내야 할 숫자들
		int x;
		cin >> x;
		out.push_back(x);
	}

	while (m != 0) {
		int mid = dq.size() / 2;
		int location = 0;

		for (int i = 0; i < dq.size(); i++) { // 같은게 발견 될 경우 위치 저장
			if (dq[i] == out[out_finding]) {
				location = i;
				break;
			}
		}
		
		if (location <= mid) { // 2번 연산이 더 효율적인 경우
			while (dq[0] != out[out_finding]) { // 원하는 값을 찾을 때까지 반복
				dq.push_back(dq.front());
				dq.pop_front();
				answer++;
			}
			m--;
			dq.pop_front();
			out_finding++;
		}

		else if (location > mid) { // 3번 연산이 더 효율적인 경우
			while (dq[0] != out[out_finding]) { // 원하는 값을 찾을 때까지 반복
				dq.push_front(dq.back());
				dq.pop_back();
				answer++;
			}
			m--;
			dq.pop_front();
			out_finding++;
		}

	}
	
	cout << answer;
	return 0;
}