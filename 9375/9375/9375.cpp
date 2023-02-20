//9375번 - 패션왕 신해빈 (S3) [소요 시간 : 33분 48초]

// 풀이 전략
// 의상 종류가 headgear인 의상이 2개 있을 때 고를 수 있는 경우의 수는 안 입거나, 1개를 골라 입거나 2개를 골라 입는거다.
// 의상의 종류가 eyewear인 것이 1개 있을 때 고를 수 있는 경우의 수는 0개를 고르거나, 1개를 고르는거다.
// 즉, headgear와 eyewear로 나올 수 있는 경우의 수는 3*2 이다. 여기서 둘 다 안입는 경우는 카운트하지 않으므로 1을 빼준다.

// 가질 수 있는 의상 수는 최대 30개 이고, 최악의 경우 pow(2,30)의 경우의 수가 나온다.
// 즉, 출력하는 정답의 자료형은 long long 형 이어야 한다.

// 성능 : 2028KB, 0ms
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int main(void) {
	unordered_map<string, int> fassion;

	int n;
	long long answer = 1;
	// 0. 고속 입출력
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

	// 1. 입력 받기
	cin >> n;
	for (int i = 0; i < n; i++) {
		int m;
		cin >> m;
		for (int j = 0; j < m; j++) {
			string fassion_name, use;
			cin >> fassion_name >> use;
			fassion.insert(make_pair(use,1)); // use : 용도 | 1: 옷 개수
			if (fassion.find(use) != fassion.end()) { // 이미 있는 경우
				fassion[use]++; // 두 번째 원소(second)을 1 추가
			}
		}

		// 2. 정답 출력
		unordered_map<string, int>::iterator iter;
		for (iter = fassion.begin(); iter != fassion.end(); iter++) {
			answer = answer * iter->second;
		}
		answer = answer - 1; // 모두 안 입는 경우
		cout << answer << "\n";
		// 3. 출력 후 초기화
		answer = 1;
		fassion.clear();
	}

}
