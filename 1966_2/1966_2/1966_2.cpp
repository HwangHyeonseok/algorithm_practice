// 1966_2 - 프린터 큐 (S3) [소요 시간 : 53분 42초]

// 새롭게 알게 된 점 : // 큐는 대입 연산이 가능하다. (temp = printer) 가능
// 실수했던 점 : 하나의 테스트 케이스가 끝나고 남아 있는 큐를 초기화하지 않아서 코드에 문제가 발생하였고 코드 작성 시간이 오래 걸렸다.
// (-) 우선순위 큐를 생각하지 못했다!

// 성능 : 2032KB, 0ms
#include <iostream>
#include <queue>
#include <math.h>
#include <algorithm>

using namespace std;

typedef pair<int, int> p; // pair의 첫 번째 인자로는 중요도가 들어가고, 두 번째 인자로는 문서 번째수를 나타낸다.
queue<p> printer; // 프린터의 모든 정보들을 큐로 담고 있다.
queue<p> temp; // 프린터의 모든 정보를 담는 임시 큐 (큐에서 중요도가 가장 높은 값을 구하기 위한 용도의 큐)

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

	int testcase; // 테스트 케이스

	cin >> testcase;
	// 테스트 케이스 만큼 반복 실행; 
	for (int i = 0; i < testcase; i++) {
		int n; // 문서의 개수
		int question; // 몇 번째로 인쇄가 되었는지 궁금한 문서
		int answer = 1; // 출력되는 번째수 (정답)
		int index = 0; // 문서 번째수

		cin >> n >> question;
		// 문서의 개수 만큼 프린터 정보를 입력 받아 프린터 큐에 넣는다. O(N) -> 문서의 개수는 최악의 경우 100
		for (int j = 0; j < n; j++) { 
			int importance = 0; // 중요도
			cin >> importance;
			printer.push(make_pair(importance, index));
			index++; // 문서를 추가했으므로 문서 번째수를 1 증가시킨다.
		}

		// 현재 큐에서 question번째가 몇 번째로 나오게 되는지 검사 O(N) -> 최악의 경우 99번을 똑같은 작업을 실행해야 한다.
		while (1) {
			int maximum = 0;
			// 현재 printer 큐에 남아 있는 문서의 중요도 중 최댓값을 구한다.
			temp = printer; // ★ 큐는 대입 연산이 가능하다.
			for (int j = 0; j < printer.size(); j++) {
				// 최댓값 구하기
				maximum = max(maximum, temp.front().first);
				temp.pop();
			}
			
			// 큐의 중요도의 front가 최댓값과 같다면 가장 우선순위인 문서이므로 pop을 한다.
			if (printer.front().first == maximum) {
				// 만약에 pop할 문서의 index가 question (몇 번째로 인쇄 되었는지 궁금한 문서) 와 같다면 정답을 출력하고 끝낸다.
				if (printer.front().second == question) {
					cout << answer << "\n"; // 정답 출력
					break;
				}
				// pop할 문서의 index가 question(몇 번째로 인쇄 되었는지 궁금한 문서) 와 다르다면 문서를 pop하고 answer을 1 증가시킨다.(순위를 한 순위 뒤로 밀린다.)
				else {
					printer.pop();
					answer++;
				}
			}

			// 큐의 중요도의 front가 최댓값과 다르다면 그 문서를 맨 뒤로 보낸다.
			else {
				printer.push(printer.front());
				printer.pop();
			}
		}

		// printer 큐를 깔끔하게 초기화 해준다. -> 최악의 경우 O(N) 99개의 원소를 지워야 한다.
		while (!printer.empty()) {
			printer.pop();
		}
		
	}
	return 0;
}