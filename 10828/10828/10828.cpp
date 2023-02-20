// 2023.02.10 백준 문제풀이
// 10828 - 스택 (S4) [소요 시간 : 9분 44초]

// #스택 함수 연습 (push,pop,size,empty,top)
// pop 연산 시 => 꺼낼 원소가 있는지 먼저 체크 필요 => s.empty() 체크
// top 연산 시 => 최상위 원소가 있는지 먼저 체크 필요 => s.empty() 체크

// 성능 : 2156KB, 0ms
#include <iostream>
#include <stack>

using namespace std;

stack<int> s; 

int main(void) {
	int n;
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); // 고속 입출력

	cin >> n; // 명령의 수 입력 받기
	// 테스트 케이스 O(N) - N은 최악의 경우 10,000개 연산
	for (int i = 0; i < n; i++) { 
		string command; // 명령 (push X, pop, size, empty, top)
		cin >> command; // 명령의 수 만큼 명령 입력 받기
		
		if (command == "push") { // push 명령 입력 시
			int x;
			cin >> x; // 스택에 삽입할 원소를 입력 받는다.
			s.push(x); // 스택에 해당 원소를 삽입한다.
		}
		
		else if (command == "pop") { // pop 명령 입력 시
			if (s.empty()) { // 꺼낼 원소가 없다면
				cout << "-1\n"; 
			}
			else { // 꺼낼 원소가 있다면 상단에 있는 원소를 꺼내고 출력한다.
				cout << s.top() << "\n";
				s.pop();
			}
		}

		else if (command == "size") { // size 명령 입력 시
			cout << s.size() << "\n";
		}

		else if (command == "empty") { // empty 명령 입력 시
			if (s.empty() == true) { // 스택이 비었다면
				cout << "1\n";
			}
			else { // 스택이 비지 않았다면
				cout << "0\n";
			}
		}
		
		else if (command == "top") { // top 명령 입력 시
			if (s.empty()) { // 스택이 비었다면 -1 출력
				cout << "-1\n";
			}
			else { // 스택에 값이 있는 경우
				cout << s.top() << "\n";
			}
		}

	}
	return 0;
}