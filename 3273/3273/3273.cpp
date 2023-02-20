// 3273 - 두 수의 합 (S3) 
// [오답] 완전 탐색으로 두 수의 합으로 나올 수 있는 모든 경우의 수를 구한다. => 시간 초과  [소요 시간 : 9분 55초]
// [HINT] idea : 예시에서 합이 13이 나와야 하는 값을 찾을 때 O(N) 시간복잡도로 해결하려면, [소요 시간 : 40분 00초]
// 5 12 7 10 9 1 2 3 11 에서 5는 8과 더해야 합이 13이 나온다.
// 즉, 1) 현재 넣은 배열에서 8이 있는지 찾는다.
// 2-1) 없다면 5을 배열에 넣고 12을 검사한다.
// 2-2) 있다면 5을 배열에 넣고 정답 개수 카운팅을 +1 한다. 그리고 12을 검사한다.

// 성능 : 10732KB, 12ms
#include <iostream>
#include <vector>

using namespace std;
vector<int> numbers;
vector<int> check_num(2000001, 0);


int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int n;
	int x;
	int answer = 0;

	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		numbers.push_back(x);
	}
	cin >> x;

	for (int i = 0; i < n; i++) {
		if (x - numbers[i] >= 0) {
			if (check_num[(x - numbers[i])] == 1) { // [오답노트 OutofBounds] => x-numbers[i]가 음수가 나올 수도 있다.
				answer++;
			}
		}
		check_num[numbers[i]] = 1;
	}
	

	cout << answer;
	return 0;
}