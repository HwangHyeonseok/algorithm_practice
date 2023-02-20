// 5430 - AC (G5) [소요 시간 : 2시간 35분 00초]

// [방법1]  [소요 시간 : 2시간 6분 52초] 원소 뒤집기 연산을 직접 구현 -> 시간 초과

// [방법2] [소요 시간 : 2시간 35분 00초] D, RRD 와 같이 누적 R이 짝수번 일어나고 D을 하는 경우 -> 앞에 있는거 그대로 출력 (pop_front) 
// RD, RRRD 와 같이 누적 R이 홀수번 일어나고 D을 하는 경우 -> 뒤에 있는거 출력 (pop_back)
// 마지막으로 남은 원소 출력 시 누적 R이 짝수 -> 그대로 출력, 홀수 -> 뒤집어서 출력 

// 성능 : 3552KB, 52ms
#include <iostream>
#include <deque>
#include <string>
#include <algorithm>

using namespace std;

deque<int> dq;
int main(void) {
	int T; // 테스트 케이스
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	cin >> T;

	for (int i = 0; i < T; i++) { // 테스트 케이스 만큼 진행
		string command;
		string input;
		string num = "";
		int n;
		int reverse_count = 0;
		bool error = false;
		cin >> command;
		cin >> n;
		cin >> input;
		for (int k = 0; k < input.size(); k++) {
			if (input[k] != '[' && input[k] != ',' && input[k] != ']') { // [ , ] 을 만나면 숫자를 끊어서 입력받는다.
				num += input[k];
			}
			else {
				if (num != "") {
					dq.push_back(stoi(num));
					num = "";
				}
			}
		}

		int command_count = 0;
		int mid = n / 2;

		while (command_count != command.size()) { // 함수 명령 실행
			if (command[command_count] == 'R') { // R 명령 - 원소 뒤집기
				reverse_count++;
			}

			else if (command[command_count] == 'D') { // D 명령 - 첫 번째 원소 뽑기
				if (dq.empty() == true) { // 데큐가 비었을 경우
					cout << "error\n";
					error = true;
					break;
				}
				else { // 데큐가 비지 않은 경우
					if (reverse_count % 2 == 0) { // R이 나온 횟수가 짝수
						dq.pop_front();
					}
					else { // R이 나온 횟수가 홀수
						dq.pop_back();
					}
				}
			}
			command_count++;
		} // 함수 명령 실행

		if (error == true) {
			continue;
		}
		int size = dq.size();
		if (reverse_count % 2 == 0) { // 누적 R의 개수가 짝수개면 -> 남은 원소 그대로 출력
			cout << "[";
			for (int k = 0; k < size; k++) {
				if (k == size - 1) {
					cout << dq.front();
				}
				else {
					cout << dq.front() << ",";
					dq.pop_front();
				}
			}
			cout << "]\n";
		}

		else { // 누적 R의 개수가 홀수개면 -> 남은 원소를 뒤집어서 출력
			reverse(dq.begin(), dq.end());
			cout << "[";
			for (int k = 0; k < size; k++) {
				if (k == size - 1) {
					cout << dq.front();
				}
				else {
					cout << dq.front() << ",";
					dq.pop_front();
				}
			}
			cout << "]\n";
		}
		dq.clear();
	} // 테스트 케이스

	return 0;
}