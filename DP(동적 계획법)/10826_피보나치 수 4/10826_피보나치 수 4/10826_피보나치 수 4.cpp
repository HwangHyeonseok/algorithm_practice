// 10826_피보나치 수 4
// #DP, #큰 수 처리(string)
// 피보나치 수열의 시간 복잡도는 O(N^2) 이다. 즉, n의 범위가 25보다 클 경우 시간 초과가 날 수도 있다.
// 현재 문제에서는 n의 범위가 25보다 크므로 DP을 사용해야 한다.

// 실수했던 점 : n이 커질 경우 기하급수적으로 피보나치 값이 커지기 때문에 long long 자료형을 사용해야 안전하다고 생각했으나,
// long long 자료형 범위도 초과하여 string으로 긴 수에 대한 문자열을 처리해야 했다. (10757번 참고)

#include <iostream>
#define MAX_N 10001 // N의 최댓값은 10000
using namespace std;

// dp 사용
long long int save[MAX_N] = { 0 }; // f(n)값을 저장하기 위한 배열 | 전역 범위인 경우 자동으로 0으로 초기화

long long int fibo(long long int n) {
	if (n == 0) return 0;
	if (n == 1 || n == 2) return 1;
	if (save[n] != 0) // 이미 값이 저장 되어 있는 경우
		return save[n];

	return save[n] = fibo(n - 1) + fibo(n - 2); // save[n]에 fibo(n-1) + fibo(n-2) 값을 save[n]에 대입하고 그 값을 리턴한다.
}

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	long long int n;
	cin >> n;
	cout << fibo(n);

	return 0;
}