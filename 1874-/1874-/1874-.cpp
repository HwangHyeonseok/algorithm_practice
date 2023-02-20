// 2023.02.10 백준 문제풀이
// 1874(2차) - 스택 수열 (S2) [소요 시간 : 41분 5초]

// 문제 풀이 전략 : 
// 스택의 top 원소 < 입력받은 원소 ==> 스택에 다음 원소 push 하고 , + 출력
// 스택의 top 원소 = 입력받은 원소 ==> 스택에 해당 원소 pop 하고, - 출력
// 스택의 top 원소 > 입력받은 원소 ==> NO 출력하고 프로그램 종료

// 성능 : 3172KB, 20ms
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

stack<int> s; // 1~n까지의 원소를 담는 스택
vector<char> answer; // +와 -을 담는 스택 (정답출력용도)
vector<int> compare; // pop을 해야 하는 수를 입력받는 스택 

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int n; // n 개의 수를 입력 받는다.
	int stack_number =1; // 스택에 들어갈 숫자
	int out = 0; // pop한 원소의 개수
	int s_index = 0; // stack_number의 인덱스 
	cin >> n;

	for (int i = 0; i < n; i++) {
		int compare_number; // 스택에서 뽑아야 할 숫자
		cin >> compare_number;
		compare.push_back(compare_number);
	}


	while (out != n) { // n개를 뽑아낼 때까지 반복

		if (s.empty()) { // 스택이 빌 경우 스택에 n 번째 원소 삽입
			s.push(stack_number);
			stack_number++;
			answer.push_back('+');
		}
		else { // 스택이 비지 않았을 경우 조건에 따라 연산
			if (s.top() < compare[s_index]) { // 최상위 원소가 i 보다 작은 경우
				s.push(stack_number);
				answer.push_back('+');
				stack_number++;
			}

			else if (s.top() == compare[s_index]) { // 최상위 원소가 i와 같은 경우
				s.pop();
				answer.push_back('-');
				out++;
				s_index++;
			}
			else { // 최상위 원소가 i 보다 큰 경우 (예외처리)
				cout << "NO";
				return 0;
			}
		}

	}
		
	// answer에 넣은 원소들 출력 (정답 출력)
	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i] << "\n";
	}

	return 0;
}

