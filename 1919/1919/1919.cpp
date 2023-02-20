// 1919 - 애너그램 만들기 (B2) [소요 시간 : 11분 48초]
// 각 문자열의 알파벳 개수를 추출해서 첫 번째 문자열의 각 알파벳 개수 - 두 번째 문자열의 각 알파벳 개수 를 한 후 절댓값을 취해 각 알파벳에 대해 모두 더하는 연산을 한다.

// 예시 ) aabbcc / xxyybb 입력 시,
// 첫 번째 문자열의 각 알파벳 개수 - a 2개, b 2개, c 2개, d 0개 .... z 0개
// 두 번째 문자열의 각 알파벳 개수 - a 0개, b 2개, c 0개, d 0개 ... x 2개 y 2개 z 0개
// 첫 번째 문자열의 각 알파벳 개수 - 두 번째 문자열의 각 알파벳 개수 => a 2개 b 0개 c 2개 ... x -2개, y -2개, z 0개
// 절댓값을 취해서 없앨 문자열의 개수를 구한다. => a 2개, b 0개 c 2개 ... x 2개, y 2개, z 0개
// a부터 z까지 없앨 문자열의 개수 합을 구한다. => 2+2+2+2 = 8개

// 성능 : 2024KB, 0ms
#include <iostream>
#include <vector>
using namespace std;

vector<int> alphabet(26, 0);

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	string x, y;
	int answer = 0;

	cin >> x;
	cin >> y;

	for (int i = 0; i < x.size(); i++) {
		alphabet[x[i] - 'a']++;
	}

	for (int i = 0; i < y.size(); i++) {
		alphabet[y[i] - 'a']--;
	}

	for (int i = 0; i < 26; i++) {
		answer = answer + abs(alphabet[i]);
	}

	cout << answer;
	return 0;
}