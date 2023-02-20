// 10808 - 알파벳 개수 (B4) [소요 시간 : 14분 41초]
// 풀이 전략 : 아스키코드를 이용하여 해당 아스키코드 인덱스에 접근하여 알파벳을 카운팅한다.
// [오답노트 1] : A = 65, a 아스키코드 97 z 아스키코드 122

// 성능 : 2024KB, 0ms
#include <iostream>
#include <string>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	string c;
	int alphabet[123] = { 0 };

	cin >> c;
	
	for (int i = 0; i < c.size(); i++) {
		int input_number = (int)c[i];
		alphabet[input_number]++;
	}

	for (int i = 97; i <= 122; i++) {
		cout << alphabet[i] << " ";
	}

	return 0;
}