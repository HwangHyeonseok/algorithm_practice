// 10773 - 제로 (S4) [소요 시간 : 12분 20초]

// 스택 사용 이유 : 부른 돈이 0 이라면 "가장 최근에 적은 수를 지우게" 한다. => 스택을 사용하게 된 계기
// 어려웠던 점 : 원소 순회 시 인덱스, iterator 접근이 안된다는 점을 몰랐다.

// 성능 : 2548KB, 8ms 
#include <iostream>
#include <stack>

using namespace std;

stack<int> number; // 재민이가 적은 수들의 모임

int main(void) {
	int sum = 0; // 재민이가 최종적으로 적어 낸 수들의 합 (정답)
	int k; // 적어내는 수 개수
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

	cin >> k; 
	for (int i = 0; i < k; i++) { // 적어내는 수 만큼 연산;  O(N) / N은 최악의 경우 10만개 
		int money; // 재현이가 부른 돈
		cin >> money;
		// 부른 돈이 0 이라면 가장 최근에 적은 수를 지우게 한다. 적은 수가 없다면 0을 그냥 쓴다. => 스택을 사용하게 된 계기
		if (money == 0) { 
			if (number.empty()) { // 장서에 적힌 돈이 없다면 0을 쓴다.
				number.push(0);
			}
			else { // 장서에 적힌 돈이 있다면 가장 최근에 쓴 수를 지운다.
				number.pop();
			}
		}
		// 0 이외의 수가 적혔을 경우 그 돈을 장서에 적는다.
		else { 
			number.push(money);
		}
	}

	// 장서에 있는 수의 합을 모두 구하면 정답이다. 
	// ★ 스택은 인덱스로 접근이 불가능한가? => 불가능
	
	// 스택이 빌 때까지 sum에 스택에 있는 숫자를 더하고 pop 한다.
	while (!number.empty()) { 
		sum += number.top();
		number.pop();
	}
	
	//  재민이가 최종적으로 적어 낸 수들의 합 (정답)을 출력한다.
	cout << sum;
	
}