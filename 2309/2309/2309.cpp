// 2309번 - 일곱 난쟁이 (B1) [소요 시간 : 50분 48초]
// 풀이 전략1 : 9개 중 2개만 빼서 그 합이 100이 되는 것을 일일이 찾아본다. - vector의 erase 이용

// 성능 :  2024KB, 0ms
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> dwarf;
vector<int> temp; // 원본
vector<int> temp2;
int main(void) {
	int sum = 0;
	// 0. 고속 입출력
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

	// 1. 입력받기
	for (int i = 0; i < 9; i++) {
		int x;
		cin >> x;
		dwarf.push_back(x);
		temp.push_back(x);
	}
	sort(dwarf.begin(), dwarf.end());
	sort(temp.begin(), temp.end());
	// 2. 모든 조건 검사
	for (int i = 0; i < 9; i++) {
		dwarf.erase(dwarf.begin()+i, dwarf.begin()+i+1);
		for (int j = 0; j < 8; j++) {
			temp2 = dwarf;
			dwarf.erase(dwarf.begin()+j, dwarf.begin()+j+1);
			for (int k = 0; k < 7; k++) {
				sum += dwarf[k];
				if (sum == 100 && k == 6) {
					for (int h = 0; h < 7; h++)
					{
						cout << dwarf[h] << "\n";
						if (h == 6) return 0;
					}
				}
			}
			sum = 0;
			dwarf = temp2;
		}
		dwarf = temp;
	}
	return 0;
}