// 1475 - 방 번호 (S5) [소요 시간 : 25분 34초]

// 풀이 전략 : 방 번호에서 각 숫자를 추출하여 각 숫자의 개수의 최댓값을 출력하면 된다.
// 이때 6과 9는 서로 같은 것처럼 사용할 수 있다고 하였으므로 6와 9는 같은 것으로 취급하는 예외처리를 해야 한다.
// ex. 6999 -> 2세트 필요 | 1235 -> 1세트 필요

// [오답 노트1] : 반올림 처리하는 함수 -> round() 함수가 존재한다. round(2.5) -> 3 | round(2.4) -> 2
// [오답 노트1] : 반올림을 처리하는 함수인 round() 함수를 사용하기 위해 #include<cmath> 라이브러리가 필요하다.
// 성능 : 2020KB, 0ms
#include <iostream>
#include <vector>
#include <cmath> // round 함수를 사용하기 위해서 include

using namespace std;
vector<int> num_set(10, 0);
int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int n;
	int answer = 0;

	cin >> n;
	// 각 숫자 추출
	while (n != 0) { 
		num_set[n % 10]++;
		n = n / 10;
	}
	// 홀수인 경우 예외처리 , ex.6과 9의 개수 합이 5개인 경우 3세트가 나와야한다. (2로 나눈 값의 나머지가 2.5,3.5 ... 일 때를 생각한다.)
	//if ((num_set[6]+num_set[9]) % 2 != 0) {
	//	num_set[6]++;
	//}
	// [오답노트1] - 반올림 처리 함수인 round() 함수가 있다.


	// 6와 9에 대한 예외처리
	num_set[6] = round((float)(num_set[6] + num_set[9]) / (float)2);
	num_set[9] = 0;

	// 각 인덱스 값 중 최댓값이 필요한 세트의 개수이다.
	for (int i = 0; i < 10; i++) {
		answer = max(answer, num_set[i]);
	}

	cout << answer;
	return 0;
}