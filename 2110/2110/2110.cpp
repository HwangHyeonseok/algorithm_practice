
// 집의 좌표는 최악의 경우 10억, 집의 개수 20만개, 공유기의 개수 20만개이므로 따져야 하는 경우가 최소 10억*20만개이다.
// 처음에는 조합을 생각했지만 시간 복잡도가 O(n^2) 이므로 시간 초과 오류가 발생하기 충분하다.
// 따라서 로그 단위의 시간복잡도를 가진 파라메트릭 서치(이분 탐색)을 사용해야 한다.

// 성능 : 3568KB, 124ms
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v;

int main(void) {
	int c, n;
	int answer = 0;

	cin >> c >> n;
	for (int i = 0; i < c; i++) {
		int x;
		cin >> x;
		v.push_back(x);
	}
	sort(v.begin(), v.end());
	int start = 1;
	int end = v[v.size()-1];

	while (start <= end) {
		int mid = (start + end) / 2;
		int temp = v[0];
		int i = 1;
		int gongugi = 1;
		while (i != v.size()) {
			if (v[i] - temp < mid) { i++; }
			else{
				temp = v[i];
				gongugi++;
				i++;
			}
		}

		if (gongugi >= n) { // 공유기 개수가 원하는 것보다 같거나 많은 경우
			answer = mid;
			start = mid +1;
		}
		else { // 공유기 개수가 원하는 것보다 적은 경우
			end = mid - 1;
		}
	}
	cout << answer;
}