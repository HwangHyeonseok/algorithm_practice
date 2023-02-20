// 4949번 - 균형잡힌 세상 (S4) [소요 시간 : 1시간 30분 00초]
// 풀이 전략 : 문자 입력은 getline으로 한 줄씩 통으로 받는다. 괄호들을 스택을 이용하여 스택이 빌 경우 균형잡힌 문장으로 본다.
// 스택에서 pop 할 때 빈 스택인 경우를 예외처리하고, 개수 뿐 만이 아니라 ( ) [ ] 관계도 수학 등식처럼 성립해야 한다.
// ex. ( [ ] ) => O
// ex. [ ( ] ) => X
// ex. [ ( [ ] ) ] => O

//성능 : 2024KB, 4ms
#include <iostream>
#include <string>
#include <stack>

using namespace std;

stack<char> s;
int main(void) {
	string word;
	bool ordered = true;
	// 0. 고속 입출력
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

	// 1. 반복해서 한 문장씩 입력받기 
	while (1) {
		getline(cin, word); // 문장 입력 통으로 받기 - 공백까지 입력 받으므로 scanf나 cin은 부적절

		if (word == ".") break;
		// 2. 대괄호와 소괄호를 스택에 push 하기
		for (int i = 0; i < word.length() - 1; i++) {

			if (word[i] == '(') { s.push('('); }
			else if (word[i] == ')') {
				if (s.empty() == false && s.top() == '(') { s.pop(); }
				else {
					ordered = false;
				}
			}
			else if (word[i] == '[') {s.push('[');}
			else if (word[i] == ']') {
				if (s.empty() == false && s.top() == '[') { s.pop(); }
				else {
					ordered = false;
				}
			}
		}

		// 3. 대괄호와 소괄호가 비었는지 조건 검사 + 끝 글자가 .인 경우에만 검사 결과 출력
		if (s.empty() && ordered == true && word[word.length()-1] == '.') { // 다 비었다면
			cout << "yes" << "\n";
		}
		else if(word[word.length()-1] == '.' && s.empty() == false || ordered == false) {
			cout << "no" << "\n";
		}

		// 4. 초기화
		ordered = true;
		while (s.empty() == false) {
			s.pop();
		}
	}
	return 0;
}