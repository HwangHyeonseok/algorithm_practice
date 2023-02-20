// 17299 - 오등큰수 (G3) [소요 시간 : 1시간 29분 39초]

// 스택은 뒤에서 접근해야 한다.
// 빈 스택이면 : -1 출력, push()
// 빈 스택이 아닐 경우 두 가지 경우로 다시 나눈다.
// 1. 이전 숫자 빈도수가 더 많은 경우 | top(), push()
// 2. 현재 숫자 빈도수가 더 많거나 이전과 숫자 빈도수와 같은 경우 | 현재 숫자 빈도수가 작아질 때까지 pop(), top(), push()

// 이후 스택을 뒤에서 접근했으므로 정답의 역순을 출력한다.

// 성능 : 18348KB, 252ms
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

vector<int> counter(1000001, 0); // 입력된 숫자의 개수를 저장하는 배열
vector<int> number; // 입력받은 input을 저장하는 배열 // 첫 번째 인자값 : input(입력받은 숫자)
stack<int> s_number; // 스택 연산 시 input과 counter[i]을 활용하여 연산을 하기 위한 스택
vector<int> answer; // 정답 벡터 (거꾸로 출력해야 한다.)

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int n; // 수열의 크기
	int index = 0; //  index 번째의 오등큰수를 구한다.

	cin >> n; 
	index = n-1; // 뒤에서부터 스택을 처리하기 위해 해당 구문이 필요

	// 입력받은 숫자에 대한 정보 처리를 해준다. 
	for (int i = 0; i < n; i++) {
		int x; // 입력받은 수열의 숫자
		cin >> x;
		number.push_back(x); // 입력받은 숫자의 정보를 저장한다.
		counter[x]++; // 해당 입력된 숫자의 개수를 1 증가 시켜준다.
	}


	for (int i = 0; i < n; i++) {
		// 빈 스택이면 : -1 출력, push()
		if (s_number.empty()) { 
			answer.push_back(-1);
			s_number.push(number[index]);
			index--;
		}
		// 빈 스택이 아닐 경우
		else {
			// 1. 이전 숫자 빈도수가 더 많은 경우 | top(), push()
			if (counter[number[index]] < counter[s_number.top()]) {
				answer.push_back(s_number.top());
				s_number.push(number[index]);
				index--;
			}

			// 2. 현재 숫자 빈도수가 더 많거나 이전과 숫자 빈도수와 같은 경우 | 현재 숫자 빈도수가 작아질 때까지 pop(), top(), push()
			else if (counter[number[index]] >= counter[s_number.top()]) {
				// 현재 숫자 빈도수가 작아질 때까지 pop()을 한다.
				while (counter[number[index]] >= counter[s_number.top()]) { // ★ 주의 :계속 pop을 하여 빈 스택인 경우 s_number.top() 값을 가져올 수 없으므로 에러가 발생한다.
					s_number.pop();
					if (s_number.empty()) { // 스택이 비었다면 -1 출력
						answer.push_back(-1);
						break;
					}
				}
				if (!s_number.empty()) { // 스택이 비지 않은 경우
					answer.push_back(s_number.top());
				}
				s_number.push(number[index]);
				index--;
			}
		}

	}
	// 정답의 역순을 출력한다.
	for (int i = answer.size() - 1; i >= 0; i--) {
		cout << answer[i] << " ";
	}

	return 0;
}

