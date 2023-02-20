// 2023.02.11 백준 문제풀이
// 10845 큐 (S4) [소요 시간 : 7분 19초]

// continue : continue을 만나면 반복문 전체를 벗어나지 않고 다음 반복을 실행한다. => 전체 반복 중 특정 조건을 만족하는 경우를 제외하고자 할 때 유용하게 사용
// break : break을 만나면 반복문 전체를 벗어난다. => 특정 조건 만족 시 반복문을 벗어나게 할 때 유용하게 사용

//성능 : 2156KB, 0ms
#include <iostream>
#include <queue>

using namespace std;

queue<int> q;

int main(void) {
	int n;
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

	cin >> n; // 주어지는 명령의 개수를 입력받는다.

	// 명령의 개수만큼 명령어를 입력받고 명령을 실행한다.; O(N)
	for (int i = 0; i < n; i++) {
		string command;
		cin >> command;

		if (command == "push") { // push 연산 : 정수 X를 큐에 넣는다.
			int x;
			cin >> x;
			q.push(x);
		}

		else if (command == "pop") { // pop 연산 : 가장 앞에 있는 정수를 빼고 그 수를 출력한다. | 예외 : 큐에 들어있는 정수가 없을 경우 -1 출력
			if (q.empty()) { // 큐가 비었다면 -1 출력
				cout << "-1\n";
				continue;
			}
			else { // 큐가 비지 않았다면 가장 앞에 있는 정수를 빼고 그 수 출력
				cout << q.front() << "\n";
				q.pop();
			}
		}

		else if (command == "size") { // size 연산 : 큐에 들어있는 정수의 개수 출력
			cout << q.size() << "\n";
		}

		else if (command == "empty") { // empty 연산 : 큐가 비어있으면 1 출력, 비어있지 않으면 0 출력
			cout << q.empty() << "\n"; // 큐가 비면 1 출력, 큐가 비지 않으면 0 출력
		}

		else if (command == "front") { // front 연산 : 큐의 가장 앞에 있는 원소 출력 | 예외 처리 : 큐에 들어있는 정수가 없을 경우 -1 출력
			if (q.empty()) { // 큐가 비어있을 경우
				cout << "-1\n";
				continue;
			}
			else { // 큐에 값이 있을 경우
				cout << q.front() << "\n";
			}
		}

		else if (command == "back") { // back 연산 : 큐의 가장 뒤에 있는 원소 출력 | 예외 처리 : 큐에 들어있는 정수가 없을 경우 -1 출력
			if (q.empty()) { // 큐가 비어있을 경우
				cout << "-1\n";
				continue;
			}
			else { // 큐에 값이 있을 경우
				cout << q.back() << "\n";
			}
		}

	}
	return 0;
}