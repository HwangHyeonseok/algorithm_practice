// 2613 - 숫자구슬 (G2)

#include <iostream>
#include <vector>

using namespace std;

vector<int> input_numbers;
vector<int> answer2(301, 0);
int main(void) {
	int n, m;
	int start = 1;
	int end = 0;
	int answer = 0;
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		input_numbers.push_back(x);
		end += x;
	}

	while (start <= end) {
		int mid = (start + end) / 2;
		int i = 0;
		int sum = 0;
		int count = 0;
		int div = 0;
		vector<int> goosle(301, 0);

		while (i < n) {
			sum += input_numbers[i];
			if (sum > mid) {
				count++;
				div++;
				sum = input_numbers[i];
			}
			goosle[div]++;
			i++;
		}
		if (sum != 0) {
			count++;
		}

		// 파라메트릭 서치
		if (count <= m) { // 목표보다 더 적게 나온 경우 더 적게 나오는 mid가 큰 경우는 따질 필요가 없다.
			answer = mid;
			answer2 = goosle;
			end = mid - 1;
		}
		else { // 목표보다 더 크게 나온 경우 더 크게 나오는 mid가 작은 경우는 따질 필요가 없다.
			start = mid + 1;
		}
	}
	cout << answer << "\n";
	for (int i = 0; i < m; i++) {
		cout << answer2[i] << " ";
	}
	return 0;
}