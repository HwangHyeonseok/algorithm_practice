// 17298 - 오큰수(G4) [소요 시간 : 1시간 40분 46초]

// * Monotone Stack 을 모르고 풀었던 문제
// 풀이 전략 : 입력받은 원소를 input vector에 넣고 index 변수를 통해 input vector에 뒤에서부터 접근한다.
// 이때 스택(number)을 활용하여 input vector의 역순으로 값을 처리하는데,
// case 1 : 빈 스택인 경우에는 -1을 정답 벡터에 삽입하고 해당 원소를 스택에 push 해준다.
// case 2 : 스택의 최상위 원소(top) > 넣을 수인 input[index] | 에 해당하는 경우 스택의 top 값을 정답 벡터에 삽입하고 해당 원소를 스택에서 push 해준다.
// case 3 : 스택의 최상위 원소(top) <= 넣을 수인 input[index] | 에 해당하는 경우 스택의 최상위 원소(top) <= 넣을 수인 input[index]가 될 때까지 스택의 최상위 원소를 pop 해주고, 
// 모든 원소가 pop되어 빈 스택이 될 경우 -1을 정답 벡터에 삽입하고 input[index]을 해당 스택에 push 한다.
// pop 연산을 마치고 나서도 원소가 존재 할 경우 스택의 최상위 원소(top)을 출력한다.

// input vector을 뒤에서부터 접근하였으므로 그 정답 벡터 answer도 역순으로 정답이 저장되어 있을 것이다.
// 따라서 answer 벡터도 역순으로 출력하면 오큰수 정답이 된다.

// 실수했던 점 :★ top,pop 진행 시 빈 원소를 검사하게 되면 오류 발생 -> 빈 스택에 대한 예외 처리가 필수적으로 필요하다. ([50번째줄] while문으로 조건에 사용할 때 유의할 것!)
// 성능 : 14440KB, 220ms
#include <iostream>
#include <stack>
#include <vector>

using namespace std;
stack<int> number; // 연산을 위한 스택
vector<int> input; // 입력받은 원소
vector<int> answer; // 출력할 정답 : 정답을 뒤집어서 출력해야 정답이다.

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int n; // 입력받는 원소 개수

	cin >> n; 
	int index = n-1; // input 배열의 인덱스

	// 입력받은 원소 개수 만큼 원소를 입력받는다.
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		input.push_back(x);
	}
	
	// 모든 입력받은 원소의 오큰수를 구하는 연산을 while 안에 구현
	while (index != -1) {
		if (number.empty()) { // case 1 : 빈 스택이라면 | -1 출력 | push
			answer.push_back(-1);
			number.push(input[index]);
			index--;
		}

		// case 3 : 스택에 있는 수 <= 넣을 수 이라면 | s.pop() | s.top() 출력 | s.push()
		else if (number.top() <= input[index]) { 
			while ((number.top() <= input[index])) { // 스택에 있는 수가 <= 넣을 수가 될 때까지
				number.pop();
				if (number.empty()) { // ★ top 검사 시 빈 원소를 검사하게 되면 오류 발생 -> 빈 스택에 대한 예외 처리가 필수적으로 필요하다.
					break;
				}
			}
			if (number.empty()) { // 모든 원소를 pop해서 빈 스택이 된 경우 : -1 을 출력한다.
				answer.push_back(-1);
				number.push(input[index]);
				index--;
			}
			else { // 스택에 있는 수 <= 넣을 수가 될 때까지 pop을 진행하고도 남은 원소가 있을 경우 : 스택의 최상위 원소(top)을 출력한다.
				answer.push_back(number.top());
				number.push(input[index]);
				index--;
			}
		}

		// case 2 : 스택에 있는 수 > 넣을 수 이라면 | s.top() 출력 | s.push()
		else if (number.top() > input[index]) { 
			answer.push_back(number.top());
			number.push(input[index]);
			index--;
		}

	}

	// 오큰수를 반대로 담은 배열인 answer을 역순으로 출력하면 정답이다.
	for (int i = answer.size()-1; i >= 0; i--) {
		cout << answer[i] << " ";
	}

	return 0;
}

