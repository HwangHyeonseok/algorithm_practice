// 1181번 - 단어 정렬
// 문자열 sort -> 커스텀 마이징 필요 -> compare 함수

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<int, string> a, pair<int, string> b) {
	if (a.first == b.first) { // 길이가 같다면
		if (a.second == b.second) { // 길이도 같고 문자열도 같으면
			return false;
		}
		else
			return a.second < b.second; // 사전순 (오름차순)
	}
	if (a.first != b.first) { // 길이가 다르다면
		return a.first < b.first; // 글자순으로 (오름차순)
	}

}
int main(void) {
	typedef pair<int, string> word;
	vector<word> word_arr;
	int n;

	cin >> n;
	for (int i = 0; i < n; i++) {
		string x;
		cin >> x;
		word_arr.push_back(make_pair(x.length() - 1, x));
	}

	sort(word_arr.begin(), word_arr.end(), compare);

	for (int i = 0; i < n - 1; i++) {
		if (word_arr[i].second == word_arr[i + 1].second) {
			word_arr.erase(word_arr.begin() + i );
			i--;
			n--;
		}
	}
	//sort(word_arr.begin(), word_arr.end(), compare);

	for (int i = 0; i < n; i++) {
		cout << word_arr[i].second << "\n";
	}
	return 0;
}