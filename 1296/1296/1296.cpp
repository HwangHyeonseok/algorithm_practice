// 1296

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, string> p;
vector<p> participants;

int main(void) {
	string yeondu;
	int n;

	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	
	cin >> yeondu;
	cin >> n;
	for (int i = 0; i < n; i++) {

		int L = 0;
		int O = 0;
		int V = 0;
		int E = 0;
		string name;
		cin >> name;
		for (int j = 0; j < name.size(); j++) {
			if (name[j] == 'L') { L++; }
			if (name[j] == 'O') { O++; }
			if (name[j] == 'V') { V++; }
			if (name[j] == 'E') { E++; }
		}
		participants.push_back(make_pair(((L + O) * (L + V) * (L + E) * (O + V) * (O + E) * (V + E)) % 100, name));
	}
	
	cout << participants[0].second;


	return 0;
}