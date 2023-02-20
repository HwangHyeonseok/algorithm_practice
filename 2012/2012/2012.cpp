// 2012 - 등수 매기기 (S3) [소요 시간 : 15분 00초]

// 예상 등수의 합에서 원래 나와야 할 등수를 빼서 절댓값을 취하면 정답이다.
// 원래 나와야 할 등수는 최악의 경우 1~500000등까지 더해야 한 값이므로 long long 자료형을 사용한다.

// 성능 : 8292KB, 84ms 
#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

vector<long long> v;
int main(void) {
	long long n;
	long long answer = 0;
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	
	cin >> n;
	for (int i = 1; i <= n; i++) {
		long long score;
		cin >> score;
		v.push_back(score);
	}
	sort(v.begin(), v.end());

	for (int i = 0; i < n; i++) {
		answer += abs(v[i] - (i+1));
	}
	cout << answer;
	return 0;
}