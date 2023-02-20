// 2776 - 암기왕 (S4) [소요 시간 : 30분 00초]
// 같은지 검사해야 하므로, unordered_set의 find 메서드를 사용한다.
// 최악의 경우 수첩 1에서 100만개를 입력받고, 수첩 2에서 100만개를 입력 받으므로 1억개*testcase의 경우의 수가 발생한다.
// O(N) 이하의 시간 복잡도를 가져야 한다.

// 성능 : 44620KB, 940ms
#include <iostream>
#include <unordered_set>

using namespace std;

unordered_set<int> memory;

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

	int testcase;
	int n, m;

	cin >> testcase;
	
	for(int i=0; i<testcase; i++) {
		cin >> n;
		for (int j = 0; j < n; j++) {
			int x;
			cin >> x;
			memory.insert(x);
		}

		cin >> m;
		for (int k = 0; k < m; k++) {
			int y;
			cin >> y;
			if (memory.find(y) != memory.end()) { // 이미 있는 경우
				cout << "1" << "\n";
			}
			else {
				cout << "0" << "\n";
			}
		}
		
		memory.clear(); // 새로운 테스트 케이스로 갈 경우 memory을 새롭게 입력 받으므로 비워주어야 한다.
	}
	return 0;
}