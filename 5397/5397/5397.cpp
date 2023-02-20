// 5397 - 키로거 (S2) [소요 시간 : 29분 6초]

// - : 백스페이스 => iter--; iter = li.erase(iter);
// [예외] 지울 글자가 없는 경우 - 즉, iter이 li.begin()인 경우

// < : 커서 위치 왼쪽으로 => iter--;
// [예외] iterator가 begin() 위치에 있는 경우

// > : 커서 위치 오른쪽으로 => iter++;
// [예외] iterator가 end() 위치에 있는 경우

// 나머지 문자 : 비밀번호로 추가 => li.insert(iter,입력된 글자);

// 성능 : 19384KB, 264ms
#include <iostream>
#include <list>

using namespace std;

list<char> li;
int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int testcase;

	cin >> testcase;

	for (int i = 0; i < testcase; i++) {
		string command;
		list<char>::iterator iter = li.begin();

		cin >> command;

		for (int j = 0; j < command.size(); j++) {
			if (command[j] == '-') {
				if (iter != li.begin()) {
					iter--;
					iter = li.erase(iter);
				}
			}

			else if (command[j] == '<') {
				if (iter != li.begin()) {
					iter--;
				}
			}

			else if (command[j] == '>') {
				if(iter != li.end()) 
					iter++;
			}

			else {
				li.insert(iter, command[j]);
			}

		}

		for (iter = li.begin(); iter != li.end(); iter++) {
			cout << *iter;
		}
		cout << "\n";
		
		li.clear();
	}

	return 0;
}