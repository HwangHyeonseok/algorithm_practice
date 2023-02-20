// 2295 (포기)

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> numbers;
int main(void) {
	int n;
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		numbers.push_back(x);
	}

	sort(numbers.begin(), numbers.end()); // 오름차순 정렬

	

	return 0;
}