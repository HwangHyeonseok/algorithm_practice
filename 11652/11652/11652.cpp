// 11652 - 카드 (S4) [소요 시간 : 20분 58초]
// 풀이 전략 : map 자료구조를 사용하여 숫자와 숫자가 입력된 횟수를 저장하여 관리한다.
// 이때 출력은 빈출 횟수가 같은 경우 더 작은 것을 출력해야 하므로 순서를 고려한 map 자료구조를 사용하였다.
// 숫자 카드는 -pow(2, 62) ~ pow(2,62) 범위이므로 long long 범위로 해야 한다.

// 성능 : 8360KB, 72ms
#include <iostream>
#include <map>
using namespace std;

map<long long, int> Card;

int main(void) {
	int n;
	// 0. 고속 입출력
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	// 1. 입력 받기
	cin >> n;
	for (int i = 0; i < n; i++) {
		long long x;
		cin >> x;
		if (Card.find(x) != Card.end()) { // x가 이미 있는 경우
			Card[x]++;
		}
		else { // x 가 새롭게 입력된 경우
			Card.insert(make_pair(x, 1));
		}
	}
	int large = 0;
	map<long long, int>::iterator iter;
	for (iter = Card.begin(); iter != Card.end(); iter++) {
		large = max(large, iter->second);
	}
	for (iter = Card.begin(); iter != Card.end(); iter++) {
		if (large == iter->second) {
			cout << iter->first;
			return 0;
		}
	}
	
	return 0;
}