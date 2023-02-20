// 1874번 - 스택 수열 (S3) [소요 시간 : 58분 17초]

// 풀이 전략 : 스택의 top과 원하는 값과 비교를 한다.
// 스택의 top == 필요한 값 => pop 하고 - 출력
// 스택의 top < 필요한 값 => push 하고 + 출력
// 스택의 top > 필요한 값 => 예외 처리

// 성능 : 3172KB, 20ms
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<int> goal;
vector<char> answer;
stack<int> s;
int main(void) {

	int n;
	int k = 0; // s 스택에 접근
	int i = 1;
	// 0. 고속 입출력
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

	// 1. 입력
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		goal.push_back(x);
	}

	while (k != n) {
		if (s.size() == 0) { // 스택에 아무것도 없는 경우라면
			s.push(i);
			i++;
			answer.push_back('+');
		}

		if (s.top() < goal[k]) {
			s.push(i);
			i++; 
			answer.push_back('+');
		}
		else if (s.top() == goal[k]) {
			s.pop();
			k++;
			answer.push_back('-');
		}
		else if (s.top() > goal[k]) { // 예외
			cout << "NO";
			return 0;
		}

	}
	
	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i] << "\n";
	}
	
	return 0;
}