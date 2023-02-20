// 2343번 - 기타 레슨 (S1) [소요 시간 : 3시간 + a] - RE
// 풀이 전략 : 강의를 잘라야 하는 모든 경우의 수를 따지기 어렵다. 
// 그래서 나눠지는 수에 따라서 블루레이 크기를 이분 탐색 기법을 이용한 파라메트리 서치를 활용하였다.

// 성능 : 2916KB, 8ms
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main(void) {
	int n, m;
	int start = 1;
	long long end = 0;
	vector<int> lecture;
	long long answer = 100000001;

	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		int input_number;
		cin >> input_number;
		lecture.push_back(input_number);
		end = end + input_number;
		start = max(start, input_number);
	}

	while (start <= end) {
		int sum = 0;
		long long mid = (start + end) / 2;
		int blueray = 0;

		for (int i = 0; i < n; i++) {
			if (sum + lecture[i] > mid) {
				blueray++;
				sum = 0;
			}
			
			sum += lecture[i];
			
		}
		// 블루레이 크기로 가정한 mid보다 작아서 1증가 하지 못한 마지막 분
		if(sum != 0)
			blueray++;

		// 더 적은 블루레이가 생성되거나 원하는 블루레이만큼 생성된 경우
		if (blueray <= m) { 
			end = mid - 1;
		}
		// 더 많은 블루레이가 생성된 경우 -> mid가 적은 경우를 따질 필요가 없음 (어짜피 더 많은 블루레이가 생성되게 될 것이므로)
		else { 
			start = mid + 1;
		}
	}
	cout << start;
	return 0;
}