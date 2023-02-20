// 1300 - K번째 수(G2) - [소요 시간 : 42분 53초]

// 1부터 배열의 최대 숫자까지 일일이 해당 숫자가 몇 등에 해당하는지 알려면 해당 숫자보다 큰 개수가 몇 개인지를 따지면 될 것 같다.
// 완전 탐색으로 풀려고 보니 k는 최악의 경우 10억의 자연수이므로 이분 탐색 중에 파라메트릭 서치를 사용해야겠다고 생각했다.
// 큰 수의 개수를 따져서 큰 수의 개수가 목표 개수(k)보다 많거나 같은 경우 숫자가 더 큰 경우는 따질 필요가 없고,
// 큰 수의 개수가 목표 개수(k)보다 작은 경우 더 작은 숫자의 경우는 따질 필요가 없으므로 이를 이용했다.

// N은 최악의 경우 10만이고, 그로 인해 나올 수 있는 최댓값은 10만 * 10만 이므로 100억이다.
// int 자료형의 범위는 약 21억이므로 long long 자료형을 사용해야 한다.

// [1차 오답노트] : N의 범위가 최악의 경우 10만이기 때문에 최악의 경우 100억의 배열이 필요했다. [소요 시간 : 25분 51초]
// 1개를 1byte라고 잡아도 10GB가 들어가기 때문에 메모리 초과가 발생했다.
// 즉, 이 문제는 1) vector와 배열로 자료를 담으면 안된다. 2) 로그 단위의 시간 복잡도인 알고리즘을 짜야 한다.

// [풀이 아이디어] : 예시 배열에서 4보다 크거나 같은 수의 개수를 찾으려고 할 때 min(mid/i, n) 식을 도출할 수 있다.
// 1 2 3 -> 3개 -> min(mid/i, n)
// 2 4 6 -> 2개
// 3 6 9 -> 1개

//성능 : 2020KB, 32ms
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long n, k;

long long answer = 0;

int main(void) {
	long long start = 1;
	long long end = 0;
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	
	cin >> n;
	cin >> k;
	
	end = n*n;
	
	// 파라메트릭 서치
	while (start <= end) {
		long long mid = (start + end) / 2;
		long long count = 0;

		for (long long i = 1; i <= n; i++) {
			count = count + min(mid / i, n);
		}
		
		if (count >= k) { // 큰 수가 더 많은 경우
			answer = mid;
			end = mid - 1;
		}
		else {
			start = mid + 1;
		}
	}
	cout << answer;

	return 0;
}