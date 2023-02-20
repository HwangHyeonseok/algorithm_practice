// 1931 포기

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> c;
vector<c> clocks;

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int n;

	cin >> n;
	for (int i = 0; i < n; i++) {
		int from, to;
		cin >> from >> to;
		clocks.push_back(make_pair(from, to));
	}

	sort(clocks.begin(), clocks.end());
	while(
	for (int i = 0; i < n; i++) {

		for (int j = i + 1; j < n; j++) {
			if (clocks[i].second < clocks[j].first) {
				count++;
				break;
			}
		}
	}

	return 0;
}