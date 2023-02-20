// 1654번 - 랜선 자르기(S2) [소요 시간 : 52분 55초]

// 전략 : 만약 랜선을 자를 경우 길이의 최대가 되는 것을 잘라야 만들 수 있는 최대의 랜선 길이를 구할 수 있다. (랜선을 하나씩 늘려가면서 검사)

// 전략2 : 이분 탐색을 이용하여 최댓값과 최솟값의 합 mid을 전선의 길이로 나눈 값이 전선의 개수가 된다. 그 전선의 개수가 원하는 전선의 개수로 나누어질 때까지 이분 탐색을 진행한다.

// 성능 : 2288KB, 4ms
// [풀이 2]
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<long long> lines;
int main(void) {
	long long k, n;
	long long end = 0;
	long long start = 1;
	long long answer = 0;
	// 0. 고속 입출력
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	// 1. 입력받기
	cin >> k >> n;
	for (long long i = 0; i < k; i++) {
		long long x;
		cin >> x;
		lines.push_back(x);
		end = max(end, x);
	}
	// 2. 전략2 구현
	while (start <= end) {
		long long mid = (start + end) / 2;
		long long sum = 0;
		for (long long i = 0; i < k; i++) {
			sum = sum + (lines[i] / mid);
		}
		
		if (sum < n) { // 목표 전선보다 적은 경우
			end = mid - 1;
		}
		else {
			if (answer < mid) 
				answer = mid;
			start = mid + 1;
		}
		
	}
	cout << answer;
	return 0;
}


/*
// [풀이 1] -> 시간 초과
#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

typedef pair<int,int> line;
vector<line> lines; // lines.first는 전선의 길이, lines.second는 나눌 수 있는 수
vector<int> temp; // 전선의 길이 보관용

void check(int k, int n) { // k : 가지고 있는 랜선 개수 n : 필요한 랜선 개수
	int big = 0;
	int answer = 0;
	int j = 0;
	while (n - k - j > 0) {
		for (int i = 0; i < k; i++) {
			lines[i].first = lines[i].first / ++lines[i].second;
			big = max(big, lines[i].first);
		}
		
		for (int i = 0; i < k; i++) {
			if (big != lines[i].first) {
				lines[i].second--;
			}
		}
		j++;
		// 초기화
		for (int i = 0; i < k; i++) {
			lines[i].first = temp[i];
		}
		big = 0;
	}
	for (int i = 0; i < k; i++) {
		lines[i].first = lines[i].first / lines[i].second;
	}
	sort(lines.begin(), lines.end());
	cout << lines[0].first;
}
int main(void) {
	int k, n; // k : 오영식이 이미 가지고 있는 랜선의 개수 , n :  필요한 랜선의 개수

	//0.고속 입출력
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

	// 1. 입력 받기
	cin >> k >> n;
	for (int i = 0; i < k; i++) {
		int x;
		cin >> x;
		lines.push_back(make_pair(x, 1));
		temp.push_back(x);
	}
	// 2. 함수 구현
	check(k, n);

	return 0;
}
*/