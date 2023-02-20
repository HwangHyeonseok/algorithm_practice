// 11399 - ATM (S4) [소요 시간 : 5분 52초]

// 각 사람이 돈을 인출하는데 걸리는 시간의 총합이 낮으려면 처음 뽑는 사람이 적은 시간이 걸리는 사람 순으로 뽑게 되면 전체적으로 걸리는 시간은 낮아지게 된다.
// 즉, 걸리는 시간을 오름차순으로 정렬하고 그 시간을 기다려야 하는 사람 수를 가중치로 곱하면 그 값이 최소값이다.

// 성능 : 2020KB, 0ms
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> minutes;

int main(void) {
	int n;
	int answer = 0;
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		minutes.push_back(x);
	}

	sort(minutes.begin(), minutes.end());
	int multple = n;

	for (int i = 0; i < n; i++) {
		answer += (minutes[i] * multple);
		multple--;
	}
	cout << answer;
	return 0;
}