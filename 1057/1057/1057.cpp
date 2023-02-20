// 1057 - 토너먼트 (S4) [소요 시간 : 19분 40초]

// 두 사람이 토너먼트에서 만나는 경기 수를 세야 하므로 두 사람의 참가 번호(대진표 순)을 2로 나누고 반올림 했을 때 몇 번째에 두 수가 같아지는지를 구하면 된다.

//성능 : 2020KB, 0ms
#include <iostream>
#include <cmath> // round 함수를 쓰기 위함

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int n;
	double jimin_num = 0;
	double jisu_num = 0;
	int answer = 0;

	cin >> n >> jimin_num >> jisu_num;
	if (jimin_num > n || jisu_num > n) {
		cout << "-1";
	}

	else { // 정상적인 입력인 경우
		while (jimin_num != jisu_num) {
			jimin_num = round(jimin_num / 2);
			jisu_num = round(jisu_num / 2);
			answer++;
		}
	}
	cout << answer;
}