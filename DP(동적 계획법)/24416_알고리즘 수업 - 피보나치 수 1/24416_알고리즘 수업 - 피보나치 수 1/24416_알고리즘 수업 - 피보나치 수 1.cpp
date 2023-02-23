// 24416_알고리즘 수업 
// #재귀vsDP
// 문제에서 n번째 피보나치 수열을 구해야 하는데, 그 n의 범위가 25를 넘어가는 경우에는 O(N^2)으로 해결하는 재귀함수 방법보다, DP 방법을 사용하여야 한다.

#include <iostream>

using namespace std;

int answer_dp = 0; // DP 연산 횟수
int answer_recursive = 0; // 재귀 함수 연산 횟수

int save[41] = { 0 };

// DP 풀이 - 중복되는 연산을 배열에 저장하여 시간 복잡도를 O(N)으로 낮춰준다.
int fibo_dp(int n) {
	if (n == 1) {
		answer_dp++;
		return 1;
	}
	if (n == 2) {
		answer_dp++;
		return 1;
	}
	if (save[n] != 0) {
		answer_dp++;
		return save[n]; // 이미 나왔던 값(저장되었던 값)이면 그 값을 리턴
	}

	return save[n] = fibo_dp(n - 1) + fibo_dp(n - 2);
}

// 재귀 풀이 -  n이 커지면 연산 횟수는 2의 n-1승 만큼 커지기 때문에 시간 복잡도가 O(n^2) 이라 n이 25를 넘어가면 1초 만에 문제를 해결하지 못한다.
int fibo_recursive(int n) {
	// 종료 조건
	if (n == 1) {
		answer_recursive++;
		return 1;
	}
	if (n == 2) {
		answer_recursive++;
		return 1;
	}

	// 점화식
	return fibo_recursive(n - 1) + fibo_recursive(n - 2);
}


int main(void) {
	int n;
	cin >> n;
	fibo_dp(n);
	fibo_recursive(n);
	cout << answer_recursive << " " << answer_dp-1;
}