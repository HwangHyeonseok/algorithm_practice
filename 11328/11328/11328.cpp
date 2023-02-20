// 11328 - Strfry (B2) [소요 시간 : 41분 51초]

// [새롭게 알게 된 점] Strfry는 문자열 관련 함수로 입력된 문자열을 무작위로 재배열하여 새로운 문자열을 만들어낸다. (무조건 달라지지 않아도 된다.)
// 문자열을 입력 받아서 각 알파벳의 개수를 카운팅 한 후 뒤에 입력된 문자열의 알파벳이 있는지 검사해준다.

// 성능 : 2024KB, 4ms
#include <iostream>
#include <vector>

using namespace std;


int main(void) {
	int n;
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

	cin >> n;
	for (int i = 0; i < n; i++) {
		vector<int> alphabet(26, 0);
		string x, y;
		cin >> x >> y;
		for (int j = 0; j < x.size(); j++) {
			alphabet[x[j] - 'a']++;
		}
		if (x.size() != y.size()) {
			cout << "Impossible\n";
			continue;
		}
		for (int j = 0; j < y.size(); j++) {
			if (alphabet[y[j] - 'a'] == 0) {
				cout << "Impossible\n";
				break;
			}
			if ((j == y.size() - 1) && alphabet[y[j] - 'a'] == 1) {
				cout << "Possible\n";
			}

			alphabet[y[j] - 'a']--;
		}
	}

	return 0;
}