// 1406 - 에디터 (S2) [소요 시간: 1시간 42분 11초]
// #list STL + iterator 응용 문제

// 처음에는 문자열을 입력받으면 iter이 li.end()을 가르키도록 한다.
// L : iter--; => iter이 li.begin() 이라면 예외처리
// D : iter++; => iter이 li.end() 이라면 예외처리
// B : iter--; 후 iter = li.erase(iter); => iter이 li.begin() 이라면 예외처리
// P $ : li.insert(iter, $);

// insert(iter, $); 연산은 iter가 가르키고 있는 곳 왼쪽에 값을 $ 삽입
// iter = li.erase(iter); 연산은 iter이 가르키고 있는 값을 삭제하고 그 다음 원소 위치를 반환
// 단, 마지막 원소를 삭제한 경우 그 다음 원소 위치를 가르키고 있지 않고 현재 원소 위치를 가르키고 있는다.

// 성능 : 21020KB, 68ms

#include <iostream>
#include <list>
#include <string>

using namespace std;

list<char> li;
int main(void) {
	int m;
	string word;
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	
	cin >> word;
	for (int i = 0; i < word.size(); i++) {
		li.push_back(word[i]);
	}
	list<char>::iterator iter = li.end();

	cin >> m;

	for (int i = 0; i < m; i++) {
		char command;
		cin >> command;

		if (command == 'L') {
			if (iter != li.begin()) { // 커서가 문장 맨 앞이 아닌 경우
				iter--;
			}
		}

		if (command == 'D') {
			if (iter != li.end()) { // 커서가 문장 맨 뒤가 아닌 경우
				iter++;
			}
		}

		if (command == 'B') {
			if (iter != li.begin()) { // 커서가 문장 맨 앞이 아닌 경우
				iter--;
				iter = li.erase(iter);
			}
		}

		if (command == 'P') {
			char input;
			cin >> input;

			li.insert(iter, input);
		}
	}

	for (iter = li.begin(); iter != li.end(); iter++) {
		cout << *iter;
	}
	return 0;
}