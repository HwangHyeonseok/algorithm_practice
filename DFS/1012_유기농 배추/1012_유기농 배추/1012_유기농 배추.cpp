// 1012_유기농 배추(S2) - [소요 시간 : 1시간 27분 1초] + 디버깅

// 재귀 dfs로 구현한다. (어떤 영역의 탐색을 하는 것이므로 dfs가 적당하다.)

// 어려웠던 점 : 좌표 체계를 맞추는 것이 많이 헷갈렸다. (실수 유의)
// 새롭게 알게 된 점 : memset을 쓰기 위한 라이브러리 => #include<cstring>

// 성능 : 2032KB, 0ms
#include <iostream>
#include <cstring> // ★ memset을 쓰기 위한 라이브러리

using namespace std;
#define MAX_MAP 51 // 배추 밭의 가로 길이와 세로 길이의 최댓값
#define MAX_BAECOO 2501 // 배추의 최대 개수

// 1번 땅은 배추가 심어진 상태 | 0번 땅은 배추가 심어지지 않은 상태(벽과 똑같은 기능 - dfs 탐색을 하면 안되는 영역)
int Graph[MAX_MAP][MAX_MAP] = { 0 }; // 배추 밭의 상태를 나타내는 배열 // 배추 밭의 최대 가로 길이와 세로 길이가 작으므로 2차원 배열을 써도 메모리에 큰 문제가 없다.
int Move[4][2] = { {0,1}, {0,-1}, {-1,0}, {1,0} }; // 상하좌우 움직임을 구현하는 배열

int m, n; // 땅의 범위 : m*n

// 1. 루트 노드 | 방문 처리 + 해당 노드 처리
void dfs(int x, int y) {
	Graph[x][y] = 0; // 방문 처리
	int pos_x = x;
	int pos_y = y;
	
	// 2. 상하좌우로 움직여보면서 다음 노드 찾기
	// 다음 노드가 될 조건 : A) Graph 범위(배추 밭 범위)안에 있어야 한다. B) 이미 방문한 적이 없어야 한다. 
	// C) 해당 노드가 배추가 심어진 땅이어야 한다. (Graph[x][y]가 1인 값만 이동 가능) // D) 현재 위치와 연결이 되어 있어야 한다. (상하좌우로 후보 위치를 이동시켜서 볼 것이므로 조건 자동 패스)
	for (int i = 0; i < 4; i++) {
		// 다음 위치가 될 후보 위치 (x,y) // D)
 		int next_location_x = pos_x + Move[i][0]; 
		int next_location_y = pos_y + Move[i][1];

		if (Graph[next_location_x][next_location_y] == 0) continue; // B) C)
		if (next_location_x < 0 || next_location_x >= n || next_location_y < 0 || next_location_y >= m) continue; // A)

		// 다음 노드 될 조건을 모두 만족한 노드만 dfs 재귀 호출
		dfs(next_location_x, next_location_y);
	}
	
}

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int testcase; // 테스트 케이스
	int baecoo; // 배추 수 (dfs의 간선의 역할)

	cin >> testcase;
	for (int j = 0; j < testcase; j++) {
		int answer = 0;
		cin >> m >> n >> baecoo;

		// 배추의 개수만큼 지정한 위치에 배추를 심는다. 
		for (int i = 0; i < baecoo; i++) {
			int x, y;
			cin >> y >> x;
			Graph[x][y] = 1;
		}

		// dfs 탐색이 필요한 곳을 찾는다. (배추가 있는 곳 주변 탐색)
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (Graph[i][j] == 1) {
					dfs(i, j); // 루트 노드로 i,j(x,y) 좌표값을 보내준다.
					answer++;
				}
			}
		}

		// 필요한 배추흰지렁이의 수를 출력한다.
		cout << answer << "\n";

		// Graph 을 모두 0으로 초기화한다.
		memset(Graph, 0, sizeof(Graph)); 
	}
	return 0;
}