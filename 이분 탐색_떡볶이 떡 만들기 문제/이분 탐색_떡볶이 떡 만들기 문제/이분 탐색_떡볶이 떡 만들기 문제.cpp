// 이분 탐색 - 떡볶이 떡 만들기 문제
// 절단기에 높이(H)를 지정하면 줄지어진 떡을 한 번에 절단한다. 높이가 H보다 긴 떡은 H 위의 부분이 잘릴 것이고 낮은 떡은 잘리지 않는다.
// 예를 들어 높이가 19, 14, 10, 17cm 인 떡이 나란히 있고 절단기 높이를 15cm로 지정하면 자른 뒤 떡의 높이는 15, 14, 10, 15cm가 될 것이다.
// 잘린 떡의 길이는 4, 0, 0, 2cm 이므로 손님은 6cm 만큼의 길이를 가져간다.
// 손님이 왔을 때 요청한 총 길이가 M일 때 적어도 M만큼의 떡을 얻기 위해 절단기에 설정할 수 있는 높이의 최댓값을 구하는 프로그램을 작성하시오.

// 첫 번째 줄 - N : 떡의 개수, M : 요청한 떡의 길이
// 두 번째 줄 - 떡의 개별 높이 (0 <= 높이 <= 10억)
// 입력 예시
// 4 6 (N, M)
// 19 15 10 17 
// 출력 예시
// 15

// 전략 : 탐색 범위가 크므로 선형 탐색보다 이진 탐색을 진행한다.

#include <iostream>
#include <vector>
using namespace std;

vector<int> dduk;

void check(int start, int end, int target, int data) {
	int sum = 0;
	int answer = 0;
	while (start <= end) {
		int mid = (start + end) / 2;
		for (int i = 0; i < data; i++) {
			if (dduk[i] - mid >= 0)
				sum = sum + dduk[i] - mid;
			else
				sum += 0;
		}

		if (sum >= target) {
			answer = mid;
			start = mid + 1;
		}
		else {
			end = mid - 1;
		}
		sum = 0;
	}
	cout << answer;
}

int main(void) {
	int n;
	int m; // 목표값
	int height = 0; // 절단기의 높이 0 ~ 19 

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		dduk.push_back(x);
		height = max(height, x);
	}
	check(0, height, m, n);
	
	return 0;
}

