// 순열 구현하기
/*
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	vector<int> v;
	v.push_back(3);
	v.push_back(5);
	v.push_back(4);

	do {
		for (int i = 0; i < v.size(); i++) {
			cout << v[i] << " ";
		}
		cout << "\n";
	} while (next_permutation(v.begin(), v.end()));
	return 0;
}
*/

// 조합 구현하기

// 벡터 1,2,3을 순서를 고려하지 않고 2개를 뽑을 때 나올 수 있는 경우의 수를 모두 출력하고 그 갯수를 출력하시오.
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


void combination(int start, vector<int> b) {
	int cnt = 0;
	if (b.size() == 3) { // 3개를 뽑는다.
		for (int i = 0; i < b.size(); i++) {
			cout << b[i] << " ";
		}
		cnt++;
		return;
	}
	for (int i = start+1; i < 3; i++) {
		b.push_back(i);
		combination(i, b);
		b.pop_back();
	}
	return;
}

int main(void) {
	vector<int> b;


	combination(-1, b);

	
	return 0;
}