// 2805 - 나무 자르기(S2) [소요 시간 : 21분 40초]
// 아이디어 : 절단기의 최대 높이를 구하기 위해서 나무를 자를 수 있는 최대한의 절단기 높이부터 0까지 순회하면서 검사한다.
// 나무의 수가 최악의 경우 100만개, 나무의 길이 또한 최악의 경우 20억의 높이이므로 일반 순회보다 이진 탐색을 하여야 한다.

// 주의 : 이때 집으로 가져가려고 하는 나무의 길이 M은 최대 20억까지이고, 둘째 줄에 입력받는 나무의 높이 또한 최대 100억까지이기 때문에 long long 자료형을 사용해야 한다.

// 성능 : 14436KB, 188ms

#include <iostream>
#include <vector>
using namespace std;

vector<long long> tree;
int main(void) {
	long long n, m; // 적어도 m미터의 나무를 집에 가져가야 한다. n은 나무의 개수이다.
	long long start = 0;
	long long end = 0; // end는 나무의 최대 높이
	long long answer = 0; // 절단기에 설정할 수 있는 최대 높이 (정답)
	// 0. 고속 입출력
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	// 1. 입력 받기
	cin >> n >> m;
	for (long long i = 0; i < n; i++) {
		long long x;
		cin >> x;
		tree.push_back(x);
		end = max(end, x);
	}
	// 2. 이진 탐색 - 파라메트리 서치 이용
	while (start <= end) {
		long long sum = 0;
		long long mid = (start + end) / 2;
		for (long long i = 0; i < n; i++) {
			if(tree[i] - mid >= 0)
				sum = sum + tree[i] - mid;
		}

		if (sum >= m) { // 원하는 길이를 넘었을 경우 -> 절단기의 높이가 현재 mid보다 낮은 경우는 고려하지 않아도 된다.
			answer = mid;
			start = mid + 1;
		}
		else if (sum < m) { // 원하는 길이를 넘지 못했을 경우 -> 절단기의 높이가 현재 mid보다 높은 경우는 고려하지 않아도 된다. (어짜피 원하는 길이를 넘지 못할거니까)
			end = mid - 1;
		}

	}
	cout << answer;
	return 0;
}