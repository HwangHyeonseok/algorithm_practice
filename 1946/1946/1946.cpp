// 2023.02.14 백준 문제풀이
// 1946 - 신입 사원 (S1) [소요 시간 : 1시간 30분 51초]

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef pair<int, int> grade; // 성적 등수를 담는 쌍

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int testcase; // 테스트 케이스 개수


	cin >> testcase;
	for (int i = 0; i < testcase; i++) {
		int n = 0; // 지원자 수
		int answer = 0; // 신규 사원 채용에서 선발할 수 있는 신입사원의 최대 인원수
		int mini = 100001; // 최소 등수
		vector<grade> grades; // 성적 등수 배열 (testcase가 끝나면 초기화)
		cin >> n;
		
		// 지원자의 서류심사 성적과 면접시험 성적을 입력받는다.
		for (int j = 0; j < n; j++) {
			int test1 = 0; // 서류심사 성적
			int test2 = 0; // 면접시험 성적
			cin >> test1 >> test2;

			grades.push_back(make_pair(test1, test2)); // 입력받은 서류심사 성적과 면접시험 성적을 grades 배열에 삽입
		}
		// 등수별로 오름차순 정렬을 한다. (서류심사 성적 test1이 우선순위)
		sort(grades.begin(), grades.end());

		for (int j = 0; j < n; j++) {
			
			if (grades[j].second < mini) { // case : 3 6 | 4 2 => 4 2 지원자는 합격
				answer++;
				mini = grades[j].second;
			}
		}

		cout << answer << "\n";
	}

	return 0;
}