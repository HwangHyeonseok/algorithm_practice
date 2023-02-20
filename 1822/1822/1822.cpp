// 1822 - 차집합 (S4) [소요 시간 : 14분 50초]

// 중복을 제거하는 문제는 unordered_set의 find 메서드를 통해 구현이 가능하다.
// [오답노트] 문제점 : unordered_set은 sort (정렬)이 지원되지 않는다.
// [정렬 방법1] 그래서, 값을 출력할 때 순서대로 정렬하기 위해서 정답을 vector에 넣고, 그 vector에서 sort 함수를 사용하여 정렬 후 순서대로 출력한다.
// [정렬 방법2] 자동으로 정렬 기능을 지원하는 set STL을 사용하면 된다.
// 성능 : 27440KB, 448ms

// [정렬 방법2 사용] - 25520KB, 672ms
#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

set<long long> numbers;

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int n, m;

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		long long x;
		cin >> x;
		numbers.insert(x);
	}

	for (int i = 0; i < m; i++) {
		long long x;
		cin >> x;
		if (numbers.find(x) != numbers.end()) { // 이미 있는 숫자인 경우
			numbers.erase(x);
		}
	}

	cout << numbers.size() << "\n";
	set<long long>::iterator iter;
	for (iter = numbers.begin(); iter != numbers.end(); iter++) {
		cout << *iter << " ";
	}


	return 0;
}


/*
// [정렬 방법1] - 27440KB, 448ms
#include <iostream>
#include <unordered_set>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

unordered_set<long long> numbers; 
vector<int> answers; 

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int n, m;

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		long long x;
		cin >> x;
		numbers.insert(x);
	}

	for (int i = 0; i < m; i++) {
		long long x;
		cin >> x;
		if (numbers.find(x) != numbers.end()) { // 이미 있는 숫자인 경우
			numbers.erase(x);
		}
	}

	cout << numbers.size() << "\n";
	unordered_set<long long>::iterator iter;
	for (iter = numbers.begin(); iter != numbers.end(); iter++) {
		answers.push_back(*iter); 
	}
	
	// 정렬 방법 1 활용
	sort(answers.begin(), answers.end());
	
	for (int i = 0; i < answers.size(); i++) {
		cout << answers[i] << " ";
	}
	

	return 0;
}
*/