// 2178_미로 탐색 [디버깅 찬스 + 소요 시간 : 1시간 20분 30초]
//#BFS응용, #붙여서 받는 숫자열

// 문제 파악
// 최단 거리 문제 -> BFS 탐색
// N*M 배열 -> Graph[N][M] -> N과 M의 최대값은 100 -> 2차원 배열을 사용해도 메모리 문제 발생 X
// 1 -> 이동 가능 0 -> 이동 불가능(벽) 
// 출발지 : (1,1) -> 인덱스로 따지면 [0][0]
// 도착지 : (N,M) -> 인덱스로 따지면 [N-1][M-1]
// 루트 노드도 이동해야 되는 개수로 카운트

// 성능 : 2060KB, 0ms
#include <iostream>
#include <queue>
#define MAX_NM 101 // N과 M의 최대값은 100 -> 2차원 배열을 사용해도 메모리 문제 발생 X

using namespace std;

int N, M; // N*M 배열

int Move[4][2] = { {0,1}, {0,-1}, {-1,0}, {1,0} }; // 상 하 좌 우 이동 구현
int Board[MAX_NM][MAX_NM] = { 0 }; // 맵을 담는 배열

// 위치 정보와 이동 횟수를 가지고 있는 구조체
struct Point { // struct는 default가 public
public:
	int x; // x 위치
	int y; // y 위치
	int move_answer; // 이동 횟수
};

// 최단경로를 구하는 bfs 함수 구현
int bfs(int x_location, int y_location, int goal_location_x, int goal_location_y) {
	queue<Point> bfs_queue; // bfs 연산을 위한 queue

	// 1. 초기 위치가 들어오면 방문 처리 후 큐에 push
	Board[x_location][y_location] = 0; // 방문 처리
	bfs_queue.push({ x_location, y_location, 0} ); // 첫 위치에 대해서도 이동 횟수로 반영하므로 이동 횟수 1
	
	while (!bfs_queue.empty()) { // 큐가 빌 때까지 2. 3. 실행
		int current_location_x = bfs_queue.front().x;
		int current_location_y = bfs_queue.front().y;
		int moves = bfs_queue.front().move_answer + 1;// 이동 횟수 
		if (goal_location_x == current_location_x && goal_location_y == current_location_y) { // 목표 지점 도달 시 moves 리턴
			return moves;
		}
		bfs_queue.pop();

		// 상하좌우로 이동하면서 이동이 가능한 위치로 이동한다.
		// 이동이 가능할 조건 : A) 현재 위치에서 상/하/좌/우 1 칸 범위이다. B) 다음 위치가 벽이 아니어야 한다.
		// C) 맵(Board)을 벗어나면 안된다. 
		for (int i = 0; i < 4; i++) { // A)
			int next_location_x = current_location_x + Move[i][0]; 
			int next_location_y = current_location_y + Move[i][1];
			
			if (Board[next_location_x][next_location_y] == 0) continue; // B)
			if (next_location_x < 0 || next_location_x >= N || next_location_y < 0 || next_location_y >= M) continue; // C)

			// 이동이 가능할 조건에 해당하는 노드들은 방문 처리 + bfs 큐에 push 한다.
			Board[next_location_x][next_location_y] = 0; // 방문 처리
			bfs_queue.push({ next_location_x, next_location_y, moves}); // 도착 위치에 대해서도 이동 횟수로 반영하므로 이동 횟수 +1
		}
	}
}

int main(void) {

	// Board의 크기를 정한다. (맵의 크기)
	cin >> N >> M;

	// 맵의 정보를 입력받고 Board 배열에 넣는다.
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			int condition;
			scanf_s("%1d", &condition); // 정수 하나만 입력받는다. (정수를 연속해서 하나씩 입력받는 테크닉)
			Board[i][j] = condition;
		}
	}
	
	// bfs 을 실행하여 최단경로를 찾는다.
	cout << bfs(0, 0, N-1, M-1);

	return 0;
}