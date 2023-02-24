// 2667_2번째 - 단지번호붙이기 [소요 시간 : 36분 39초]
//#dfs응용 #bfs응용 #2차원 좌표 이동 #한 칸마다 숫자를 받는 테크닉
// 붙어있는 영역의 범위를 탐색해야 하므로 DFS를 사용한다.
// 1 -> 이동 가능, 0 -> 이동 불가능(벽)

// 어려웠던 점 : 중간중간 자꾸 좌표값 변수 실수를 하는 점이 어려웠다.

// 성능 : 2028KB, 0ms
#include <iostream>
#include <vector>
#include <algorithm>
#define MAX_N 26 // N의 최댓값은 25 (N이 1000이하 이므로 2차원 배열로 맵의 정보를 담아도 메모리 초과 우려가 없다.)

using namespace std;

int N; // 맵(지도)의 크기를 나타내는 변수 
int Board[MAX_N][MAX_N] = { 0 }; // 맵의 크기 n*n | 맵의 상태를 담는 배열
vector<int> answer(450, 0); // 각 단지 별 세대수를 저장하는 배열


void dfs(int y_location, int x_location, int draw) { // x,y 좌표계를 사용하기 위해 매개변수를 다음과 같이 받았다.
	int Move[4][2] = { {0,-1}, {0,1}, {-1,0}, {1,0} }; // 상 하 좌 우 움직임을 구현하기 위한 배열
	
	// 1. 초기 노드 | 방문 처리 + 노드 처리
	Board[y_location][x_location] = 0; // 방문 처리
	answer[draw]++; // 해당 단지의 세대 수를 1 증가 (노드 처리)

	// 2. 붙어 있는 아파트를 찾아 계속 탐색한다. 
	// 다음 노드가 될 조건 : A) 현재 위치와 상하좌우로 연결 되어 있어야 한다. B) 다음 노드는 이전에 방문한 적이 없는 노드여야 한다.
	// C) Board(맵)의 범위를 벗어나면 안된다. // D) 벽이 아니어야 한다.
	for (int i = 0; i < 4; i++) { // A)
		int next_location_x = x_location + Move[i][0];
		int next_location_y = y_location + Move[i][1];

		if (Board[next_location_y][next_location_x] == 0) continue; // B), D)
		if (next_location_x < 0 || next_location_x >= N || next_location_y < 0 || next_location_y >= N) continue; // C)
		
		// 다음 노드가 될 조건에 해당하는 노드만 재귀적으로 dfs 탐색을 한다.
		dfs(next_location_y, next_location_x, draw);
	}

}

int main(void) {
	//지도의 크기를 입력 받는다. (지도의 크기 : n*n)
	cin >> N;
	
	// 지도의 각 칸의 상태를 입력 받는다.
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int condition; // 각 칸에 아파트가 있는지 없는지 상태 | 1 : 집이 있음, 0 : 집이 없음
			scanf_s("%1d", &condition);
			Board[i][j] = condition;
		}
	}
	
	// 집이 모여있는 단지의 범위를 정하기 위해 집이 있는 곳에 한해 dfs 탐색을 실시한다.
	int draw = 1;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (Board[i][j] == 1) {
				dfs(i, j, draw);
				draw++;
			}
		}
	}
	// 단지 수를 출력한다.
	cout << draw - 1 << "\n";

	// 단지 수가 많은 순서대로 정렬한다. (내림차순)
	sort(answer.begin(), answer.end(), greater<int>());

	// 오름차순으로 출력해야 하므로 for문을 잘 조절하여 출력한다.
	for (int i = draw - 2; i >= 0; i--) {
		cout << answer[i] << "\n";
	}
	return 0;
}