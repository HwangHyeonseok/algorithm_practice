// 10974번 - 모든 순열 (S3) [소요 시간 : 3분 40초]
// 순열 기본 문제

// 순열은 자동으로 사전순으로 정렬된다.

//성능 2020KB, 28ms
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(void) {
	int n;
	vector<int> v;

	cin >> n;
	for (int i = 1; i <= n; i++) {
		v.push_back(i);
	}

	do {
		for (int i = 0; i < n; i++) {
			cout << v[i] << " ";
		}
		cout << "\n";
	} while (next_permutation(v.begin(), v.end()));
	return 0;
}