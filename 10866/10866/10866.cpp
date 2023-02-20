// 10866 - 덱 (S4) [소요 시간 : 9분 48초]
// 덱 STL 연습 - push_back, push_front, pop_front, pop_back, size, empty, front, back 메서드
// pop 연산과 front, back 연산 시 덱이 비어있는지 체크를 해야 한다.

// 성능 : 2024KB, 0ms
#include <iostream>
#include <deque>
#include <string>

using namespace std;

deque<int> dq;

int main(void) {
	int n;

	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		string command;
		cin >> command;

		if (command == "push_back") { // push_back 명령
			int number;
			cin >> number;
			dq.push_back(number);
		}

		else if (command == "push_front") { // push_front 명령
			int number;
			cin >> number;
			dq.push_front(number);
		}

		else if (command == "pop_front") { // pop_front 명령 - 주의 : 원소가 없는 경우 예외 처리를 해주어야 한다.
			if (dq.empty()) { // 원소가 비었다면 -1 출력
				cout << "-1\n";
			}
			else { // 원소가 있는 경우 출력 후 삭제
				cout << dq.front() << "\n";
				dq.pop_front();
			}
		}

		else if (command == "pop_back") { // pop_back 명령 - 주의 : 원소가 없는 경우 예외 처리를 해주어야 한다.
			if (dq.empty()) { // 원소가 비었다면 -1 출력
				cout << "-1\n";
			}
			else { // 원소가 있는 경우 출력 후 삭제
				cout << dq.back() << "\n";
				dq.pop_back();
			}
		}

		else if (command == "size") { // size 명령 - 덱에 들어있는 원소 개수 출력
			cout << dq.size() << "\n";
		}
		
		else if (command == "empty") { // empty 명령 - 덱이 비었는지 확인 (비었으면 1, 안비었으면 0)
			cout << dq.empty() << "\n";
		}

		else if (command == "front") { // front 명령 - 덱의 가장 앞 원소 출력 - 주의 : 원소가 없는 경우 예외 처리를 해주어야 한다.
			if (dq.empty()) {
				cout << "-1\n";
			}
			else {
				cout << dq.front() << "\n";
			}
		}

		else if (command == "back") { // back 명령 - 덱의 가장 뒤 원소 출력 - 주의 : 원소가 없는 경우 예외 처리를 해주어야 한다.
			if (dq.empty()) {
				cout << "-1\n";
			}
			else {
				cout << dq.back() << "\n";
			}
		}

	}
	return 0;
}