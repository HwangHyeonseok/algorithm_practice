// 11003

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

priority_queue<pair<int, int>, vector<pair<int, int>>, greater<int>> pq; // 첫 번째 원소 : input_number (입력한 값) | 두 번째 원소 : 입력된 순서 (index)
vector<int> answer; // Di 정답값

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int n, l; // n : n개의 수 , l : 최대 l개의 원소를 비교
	int index = 1; // 우선순위 큐의 두 번째 원소로 들어갈 변수이며 값이 들어간 순서를 의미한다.
	cin >> n >> l;

	for (int i = 0; i < n; i++) {
		// 입력 받기
		int input_number;
		cin >> input_number;
		// A-1,A-2,A0 이라는 원소는 없는 경우(초반)
		if (i - l + 1 <= 0 && index >= 0) {
			pq.push(make_pair(input_number, index));
			index++;
		}

		else {
			if (pq.top().second == delete_index) {
				pq.pop();
			}

			pq.push(make_pair(input_number, index));
			index++;
		}
		


	}


	return 0;
}