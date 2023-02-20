// 2023.02.11 백준 문제풀이 [소요 시간 : 9분 59초]
// 2164[2회차] - 카드2 (S4)

// 시간 복잡도 : O(2N) -> 빅오 표기법 : O(N)

// 성능 : 4156KB, 4ms
#include <iostream>
#include <queue>

using namespace std;
queue<int> card_number;

int main(void) {
	int n;
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

	cin >> n; // 1~n번까지 만들 카드 범위 입력

	// 1~n번까지의 카드를 만든다.; O(N) - 최악의 경우 50만회
	for (int i = 1; i <= n; i++) {
		card_number.push(i);
	}
	
	// 카드가 한 개 남을 때까지 가장 앞에 있는 카드를 바닥에 버리고 그 다음 제일 위에 있는 카드를 제일 아래의 카드 밑으로 옮긴다.
	// 카드의 개수가 n 이라면 n-1회 실시 O(N-1) - 최악의 경우 (50만회 - 1회)
	while (card_number.size() != 1) { // 카드가 한 개 남을 때까지 반복한다.
		// 가장 앞에 있는 카드를 바닥에 버린다.
		card_number.pop();

		// 그 다음 제일 위에 있는 카드를 제일 아래의 카드 밑으로 옮긴다.
		card_number.push(card_number.front());
		card_number.pop();
	}

	// 제일 마지막에 남는 카드를 출력한다.
	cout << card_number.front();
	return 0;
}