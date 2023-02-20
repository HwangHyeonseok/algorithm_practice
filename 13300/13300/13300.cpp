// 13300 - 방 배정 (B2) [소요 시간 : 17분 32초]

// 여학생 1~6학년은 각각 0~5 인덱스에, 남학생 1~6학년은 각각 6~11 인덱스에 담고 k 개 방 만큼 인원을 할당해준다.

// 성능 : 2020KB, 0ms
#include <iostream>
#include <vector>

using namespace std;

vector<int> students(12, 0);

int main(void) {
	int n = 0;
	int k = 0;
	int answer = 0;
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		int s; // 성별
		int y; // 학년
		cin >> s >> y;
		students[s * 6 + y-1]++; // 여학생 1~6학년은 각각 0~5 인덱스에, 남학생 1~6학년은 각각 6~11 인덱스에 담는다. 
	}

	for (int i = 0; i < 12; i++) {
		while (students[i] > 0) {
			students[i] = students[i] - k;
			answer++;
		}
	}
	cout << answer;
	return 0;
}