// dfs 연습문제

// 첫 번째줄 입력은 정수 n으로 받고 n*n 모양의 배열을 만든다.
// 두 번째줄부터 n+1번째 줄까지 벽이면 1, 벽이 아니면 0을 입력을 받는다.
// 마지막줄의 첫 번째 값은 현재 행의 위치, 두 번째 값은 현재 열의 위치, 세 번째 값은 벽으로 막힐 때까지 돌아다니면서 채울 숫자를 입력 받는다.

// 입력 예시
/*
5
0 0 0 0 0
0 0 0 1 1
0 0 0 1 0
1 1 1 1 0
0 0 0 0 0
1 1 3
*/

// 출력 예시
/*
3 3 3 3 3
3 3 3 1 1 
3 3 3 1 0
1 1 1 1 0
0 0 0 0 0
*/

#define MAX_N 10
#include <iostream>
#include <stack>
#include <vector>

using namespace std;
// 하나의 점의 위치를 담은 구조체 Point
struct Point {
public:
	Point(int column, int row) : row(row), column(column) {};
	int row, column;
};
int Move[4][2] = { {-1, 0}, {1,0}, {0, -1}, {0,1} };
vector<vector<int>> Board(MAX_N, vector<int>(MAX_N, 0));
int n; // n*n 배열

// dfs 구현
// 1. 처음 원소(시작 위치, 루트 노드)를 넣는다.
// 2. 현재 위치를 스택에서 가져와서 저장하고 pop 한다.
// 3. 이미 방문한 노드가 아니라면 방문 처리와 지정했던 Color로 바꿔준다.
// 4. 그래프 탐색 실시 - 이미 방문한 노드인 경우 예외 처리, 
// 4. 기타 문제 특수 예외 처리 (이 문제에서는 맵(Board) 바깥쪽으로 가는 경우 예외 처리와 벽으로 지정한 곳을 지나가지 않도록 하는 예외 처리가 필요하다.)
void dfs(int column, int row, int color) {
	vector<vector<bool>> Visited(MAX_N, vector<bool>(MAX_N, false));
	stack<Point> dfs_stack;

	// 1. 처음 원소(시작 위치, 루트 노드)를 넣는다.
	dfs_stack.push(Point(column, row));
	
	while (!dfs_stack.empty()) { // 스택이 비지 않을때까지 반복
		Point current_location = dfs_stack.top(); // 2. 현재 위치를 스택에서 가져온다.
		dfs_stack.pop(); 
		
		// 3. 이미 방문을 한 노드라면 - 방문 처리와 Color을 바꿔줄 필요가 없다.
		if (Visited[current_location.column][current_location.row] == true)
			continue;
		// 3. 방문을 하지 않았던 노드라면 - 방문 처리와 지정했던 Color을 바꿔준다.
		Visited[current_location.column][current_location.row] = true;
		Board[current_location.column][current_location.row] = color;
		
		// 4. dfs 방식으로 그래프 탐색을 진행한다.
		for (int i = 0; i < 4; i++) {
			int x = current_location.column + Move[i][0]; // x좌표
			int y = current_location.row + Move[i][1]; // y좌표
			if (x < 0 || x >= n || y < 0 || y >= n) { // Board(맵)의 바깥으로 가는 경우에는 예외 처리
				continue;
			}
			if (Visited[x][y] == true) // 이미 방문한 노드인 경우 예외 처리
				continue;
			if (Board[x][y] == 1) // 벽으로 지정한 노드인 경우 예외 처리
				continue;

			// 이 모든 예외에 해당하지 않는 경우 스택에 push
			dfs_stack.push(Point(x, y));
		}
	}
}


int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

	cin >> n;
	// Board 판을 입력 받는다.
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> Board[i][j];
		}
	}

	int row, column, color; // row, column은 현재 위치의 행과 열 값, color은 칠할 색(숫자)를 의미
	cin >> row >> column >> color; // 현재 위치와 무슨 색으로 칠할건지를 입력 받는다.
	// dfs (깊이 우선 탐색 실행)
	dfs(column, row, color);
	// dfs 결과를 출력한다.
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << Board[i][j] << ' ';
		}
		cout << "\n";
	}
	return 0;
}