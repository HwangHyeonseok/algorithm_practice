// 18870번 - 좌표 압축(S2) [소요시간 : 1시간 51분 40초]
// 풀이 전략1 : 숫자값과 출력값을 pair와 함께 묶어 저장하고, vector을 통해 배열 하나를 만들어 정렬 전용 배열로 만든다.
// 이후 인덱스 번호를 활용하여 정답값을 출력한다.

// 풀이 전략2(구글링) :	중복을 제거하고 정렬 기반 lower_bound 함수를 이용한다.

//성능 : 12524KB, 476ms
// [풀이 전략2 코드]
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> numbers;
vector<int> temp;
int main(void) {
	int testcase;
	//0. 고속 입출력
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

	// 1. 입력받기
	cin >> testcase;
	for (int i = 0; i < testcase; i++) {
		int x;
		cin >> x;
		numbers.push_back(x);
		temp.push_back(x);
	}
	sort(numbers.begin(), numbers.end());
	// 2. 중복 원소 제거
	numbers.erase(unique(numbers.begin(), numbers.end()), numbers.end());
	// 3. lower_bound로 출력
	for (int i = 0; i < testcase; i++) {
		cout << lower_bound(numbers.begin(), numbers.end(), temp[i]) - numbers.begin() << " ";
	}
	
	return 0;
}

/*x
// [풀이1 - 시간 초과] - 시간 복잡도가 O(n^2)
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
// 힙 영역으로 보내 메모리를 절약한다.
vector<int> sort_numbers; // 정렬할 배열
typedef pair<int,int> temp; 
vector<temp> temps; // 임시 저장할 pair 배열 (정답 출력)
int main(void) {
	int testcase;
	
	// 0. 고속 입출력
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

	// 1. 입력 받기
	cin >> testcase;
	for (int i = 0; i < testcase; i++) {
		int x;
		cin >> x;
		sort_numbers.push_back(x);
		temps.push_back(make_pair(x, 0));
	}
	// 2. 정렬 
	sort(sort_numbers.begin(), sort_numbers.end()); // 오름차순 정렬
	// 3. 정렬된 숫자를 pair에 넣기
	for (int i = 0; i < testcase; i++) {
		for (int k = 0; k < testcase; k++) {

			if (temps[k].first == sort_numbers[i]) {
				int j = i;
				if (i >= 1) {
					while (sort_numbers[j - 1] == sort_numbers[j] && j > 1) {
						j--;
					}
				}
				if (j == 1 && sort_numbers[j-1] == sort_numbers[j]) {
					j--;
				}

				
				int d = j-1;
				while (d >= 1) {
					if (sort_numbers[d] == sort_numbers[d - 1]) j--;
					d--;
				}

				temps[k].second = j;
			}

		}
	}

	for (int i = 0; i < testcase; i++) {
		cout << temps[i].second << " ";
	}
	return 0;
}
*/