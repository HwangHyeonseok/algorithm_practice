// 1026 - 보물 (S4) [소요 시간 : 8분 16초]

// 아이디어 : a 배열과 b 배열을 곱해서 최소가 되려면, a 배열의 가장 큰 값과 b 배열의 가장 작은 값을 곱해야 하므로,
// a 배열과 b 배열을 각각 다른 정렬을 행하면 된다. (예를 들어, a 배열을 오름차순으로 정렬했다면 b 배열을 내림차순으로 정렬한다.)

// 성능 : 2024KB, 0ms
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
vector<int> a; // A 배열
vector<int> b; // B 배열

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int n;
	int answer = 0; // 각 인덱스에 맞는 배열 A의 원소와 배열 B의 원소를 곱했을 때 최솟값 S (정답)

	cin >> n; // 배열 A와 배열 B의 원소 개수를 입력 받는다.

	// 배열 A에 입력받은 원소를 삽입한다. ; O(N)
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		a.push_back(x);
	}

	// 배열 B에 입력받은 원소를 삽입한다. ; O(N)
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		b.push_back(x);
	}

	// 하나는 내림차순, 하나는 오름차순으로 정렬한다. ; O(N log N)
	sort(a.begin(), a.end(), greater<int>()); // 내림차순 정렬
	sort(b.begin(), b.end()); // 오름차순 정렬

	// 최솟값(S)을 구하고 출력한다. ; O(N)
	for (int i = 0; i < n; i++) {
		answer += (a[i] * b[i]);
	}
	cout << answer;
	return 0;
}

