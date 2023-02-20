// 20230124 백준 문제풀이

// 2. 1431번 - 시리얼 번호 (S3) [소요 시간 : 14분 4초]
// 문제 이해 : 정렬 우선순위 (길이 -> A,B 숫자 합 -> 사전 순)이며 모두 (오름차순) 이다.
// 풀이 전략 : 문제 이해에 나온 정렬 우선순위를 바탕으로 sort 함수의 세 번째 인자(compare 함수)를 통해 정렬 커스텀을 진행하여 정렬을 진행하고 출력한다.
// 성능 : 2032KB, 0ms

/*
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

vector<string> word;

// 2. 정렬 하기 (compare 함수)
bool compare(string a, string b) {
	int SumA = 0;
	int SumB = 0;
	for (int i = 0; i < a.length(); i++) {
		if (a[i] - '0' >= 0 && a[i] - '0' <= 9) { // 숫자 판별
			SumA += a[i] - '0';
		}
	}
	for (int i = 0; i < b.length(); i++) {
		if (b[i] - '0' >= 0 && b[i] - '0' <= 9) { // 숫자 판별
			SumB += b[i] - '0';
		}
	}
	if (a.length() != b.length()) { // 1순위 : 길이가 다른 경우 길이순으로 오름차순
		return a.length() < b.length(); // 오름차순
	}
	else if (a.length() == b.length() && SumA != SumB) { // 2순위 : 길이가 같은 경우 A,B의 합으로 오름차순
		return SumA < SumB;
	}
	else { // 3순위 : 사전 순으로 오름차순
		return a < b;
	}
}

int main(void) {
	int n;
	// 0. 고속 입출력
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	// 1. 입력 받기
	cin >> n;
	for (int i = 0; i < n; i++) {
		string x;
		cin >> x;
		word.push_back(x);
	}
	// 2. 정렬 하기
	sort(word.begin(), word.end(), compare);

	// 3. 출력 하기
	for (int i = 0; i < n; i++) {
		cout << word[i] << "\n";
	}
	return 0;
}
*/
// ========================================================================================================================
// 1. 11478번 - 서로 다른 부분 문자열의 개수 (S3) [소요 시간 : 34분 04초]
// 풀이 전략 : 부분 문자열 추출을 string 클래스의 substr을 이용하여 추출하고 set 자료구조에 저장한다. 이때 find 메서드를 사용하여 중복을 검사한다.
// 새롭게 알게 된 개념 : string 클래스에 str1.substr() 메서드가 있다.
// str1 이 "Hello" 라면 str1.substr(4,1) 은 4번째 인자부터 1의 길이만큼 반환 -> o 출력

// 성능 : 209852KB, 612ms
/*
#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

unordered_set<string> words;

int main(void) {
	string input;
	// 0. 고속 입출력
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	// 1. 입력받기
	cin >> input;
	// 2. 부분 문자열 추출하고 그 문자열을 set 자료구조에 넣기 + 중복검사
	for (int i = 1; i <= input.length(); i++) { // 문자 길이 5개라면, 5개 출력 -> 4개 출력 ... -> 1개 출력 (추출 개수)
		for (int j = 0; j <= input.length() - i; j++) { // 0번째 인자부터 추출
			if (words.find(input.substr(j, i)) == words.end()) { // 중복되는 것이 아니라면 삽입
				words.insert(input.substr(j, i));
			}
			// 문자 개수 : 5개
			// 1개 추출 : input[j] -> 5개
			// 2개 추출 : input[j]와 input[j+1] -> 4개
			// 3개 추출 : input[j~j+2] -> 3개
			// 4개 추출 : input[j~j+3] -> 2개
			// 5개 추출 : input[j~j+4] -> 1개
		}
	}
	// 3. 정답 출력
	cout << words.size();
	return 0;
}
*/