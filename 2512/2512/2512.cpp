// 2512번 - 예산 (S3) [소요 시간 : 29분 29초]

// 조사를 해야 하는 M 값의 범위가 최악의 경우 10억이므로 로그 단위 이하의 시간 복잡도가 나와야 한다.
// 즉, 선형으로 일일이 탐색하기보다 최소 이분 탐색으로 탐색을 진행해야 하므로 파라메트리 서치를 이용한다.

// [파라메트리 서치 활용]
// 상한액을 0부터 총 예산(m) 까지 일일이 이분 탐색으로 검사하는데, 조건을 따져서 검사한다.
// 지급할 예산(sum)이 최대 예산(m)보다 큰 경우 지금보다 상한액(mid)이 더 높은 경우는 볼 필요 없다.
// 지급할 예산(sum)이 최대 예산(m)보다 작거나 같은 경우 지금보다 상한액(mid)이 더 낮은 경우는 볼 필요 없다.

// 성능 : 2156KB, 0ms
#include <iostream>
#include <vector>
using namespace std;

int main(void) {
	int n; // 지방의 수
	vector<int> need_money; // 필요하다고 하는 예산
	int m; // 총 예산
	int end = 0;
	int start = 0;
	int answer = 0;
	int max_need_money = 0;

	// 0. 고속 입출력
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	// 1. 입력 받기
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		need_money.push_back(x);
		max_need_money = max(max_need_money, x);
	}
	cin >> m;
	end = m;
	// 2. 파라메트릭 서치 활용
	while (start <= end) {
		int mid = (start + end) / 2;
		int sum = 0;
		for (int i = 0; i < n; i++) {
			if (mid >= need_money[i]) {
				sum += need_money[i];
			}
			else {
				sum += mid;
			}
		}

		if (sum > m) { // 지급할 예산(sum)이 최대 예산(m)보다 큰 경우 지금보다 상한액(mid)이 더 높은 경우는 볼 필요 없다.
			end = mid - 1;
		}
		else { // 지급할 예산(sum)이 최대 예산(m)보다 작거나 같은 경우 지금보다 상한액(mid)이 더 낮은 경우는 볼 필요 없다.
			answer = mid;
			start = mid + 1;
		}
	}
	if (answer > max_need_money)
		cout << max_need_money;
	else 
		cout << answer;
	return 0;
}