// 1972 나중에 풀이

#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

unordered_set<string> check_word;

int main(void) {
	

	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

	while (1) {
		string word;
		int k = 1;

		cin >> word;
		if (word == "*") break; // 종료 조건

		while (k <= word.size()-1) {
			
			for (int i = 0; i < word.size(); i=i+k) {
				string words;
				words = strcat(word[i] + word[i + 1]);
				cout << words;
			}

			k++;
		}
	}
	return 0;
}