// bfs 연습 문제
/* 문제 지시
* n*n의 맵이 있고 시작점과 도착점이 주어질 경우 시작점에서 도착점까지 도착하는 최단 거리를 구하여라. 간선의 가중치는 없으며 한 칸 이동할 때마다 이동 거리는 1로 계산한다.
* 맵에서 0은 이동이 가능한 지형, 1은 벽이므로 이동이 불가능한 지형이다.
*/

/* 입력 형태
* 첫 번째 줄에 n*n의 맵을 만드는 n이 주어진다. (n은 1000 이하이다.)
* 두 번째 줄 부터 n+1 번째 줄까지 맵의 형태를 입력 받는다.
* 마지막 줄에는 시작점 인덱스 위치와 도착점 인덱스 위치가 순서대로 주어진다.
*/

/* 출력 형태
* 시작점 인덱스 위치부터 도착점 인덱스 위치까지 이동하는 최단 경로의 길이를 출력한다.
* 벽으로 막혀서 도착점까지 도착할 수 없는 경우 -1을 출력한다.
*/

/* 입출력 예시
<입력>
5
0 0 0 0 0
0 1 1 1 1
0 0 0 0 0
1 1 1 1 0
0 0 0 0 0
0 1 4 2

<출력>
11
*/

/* 문제 풀이 
최단 경로 문제이므로 bfs을 이용한다.
*/

#include <iostream>
#include <queue>

#define MAX_N 1001

using namespace std;
int n; // 맵의 크기 : n*n
int Graph[MAX_N][MAX_N]; // 전역 범위이므로 0으로 자동 초기화가 된다.

int Move[4][2] = { {0,1}, {0,-1}, {-1,0}, {1,0} }; // 상하좌우 이동 구현을 위한 배열

struct Location { // default : public
public:
	Location(int x_pos, int y_pos, int distance) : x_pos(x_pos), y_pos(y_pos), distance(distance) {};
#pragma region 클래스, 구조체 안에서는 코드 묶고 안에 내용 채워도 된다.
	int x_pos; // x 좌표
	int y_pos; // y 좌표
	int distance; // 거리
#pragma endregion
};

// 2차원 배열 bfs 구현
// 1. 루트 노드는 방문 처리 + dfs_queue에 push
// 2. 
int bfs(Location start_location, int arrive_x, int arrive_y) {
	bool visited[MAX_N][MAX_N]; // 각 위치의 이전 방문 여부를 확인하는 배열
	memset(visited, false, sizeof(visited)); // visited 배열을 false로 초기화한다.
	queue<Location> dfs_queue; // dfs 탐색을 위한 queue
	// 1. 루트 노드는 방문 처리 + dfs_queue에 push
	visited[start_location.x_pos][start_location.y_pos] = true;
	dfs_queue.push({ start_location.x_pos, start_location.y_pos, start_location.distance}); // struct Location과 대치되어 x_pos와 y_pos와 distance 변수에 각각 넣어준다.

	while (!dfs_queue.empty()) { // 큐가 빌 때까지 while 루프(2,3) 계속 진행
		// 2. 현재 위치를 가져오고 + pop을 한다.
		Location current_location = dfs_queue.front();
		dfs_queue.pop();

		if (current_location.x_pos == arrive_x && current_location.y_pos == arrive_y) { // 만약 도착 위치와 같다면 그 거리를 리턴
			return current_location.distance;
		}
		// 3. 다음 노드 조건을 만족하는 모든 노드를 큐에 push한다. 
		// 다음 노드의 조건 : A) 현재 노드와 연결이 되어 있어야 한다. B) 벽이 아니어야 한다. C) 맵을 이탈하면 안된다. D) 이전에 방문했던 노드가 아니어야 한다.
		for (int i = 0; i < 4; i++) { // 상 하 좌 우 중 다음 탐색할 노드 찾기 A)
			int next_location_x = current_location.x_pos + Move[i][0]; // 다음 노드의 x 좌표
			int next_location_y = current_location.y_pos + Move[i][1]; // 다음 노드의 y 좌표
			
			if (Graph[next_location_x][next_location_y] == 1) continue; // B)
			if (next_location_x < 0 || next_location_x >= n || next_location_y < 0 || next_location_y >= n) continue; // C)
			if (visited[next_location_x][next_location_y] == true) continue; // D)
			
			visited[next_location_x][next_location_y] = true; // 방문 처리 후 큐에 push 
			dfs_queue.push({ next_location_x, next_location_y, current_location.distance+1});
		}
	}
	return -1; // 다 끝났는데도 도착점까지 갈 수 있는 경로를 찾지 못한 경우
}

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); // 고속 입출력 | C 입출력 문법이 있으면 사용하면 안된다.
	
	int start_x, start_y; // 시작 위치 (x,y)
	int arrive_x, arrive_y; // 도착 위치 (x,y)

	// 맵의 크기를 입력 받는다.
	cin >> n;
	// 맵의 정보를 입력 받는다. ( 해당 지형이 벽인지 인도인지)
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int input;
			cin >> input;
			Graph[i][j] = input;
		}
	}
	// 시작 위치와 도착 위치를 입력 받는다.
	cin >> start_x >> start_y >> arrive_x >> arrive_y;
	Location start_location(start_x, start_y, 0); // 시작 위치
	// bfs 탐색 실행
	cout << bfs(start_location, arrive_x,arrive_y); // 시작 위치(루트 노드)를 보낸다.
	return 0;
}

// ---------------------------------------------------------------------------------------------------------------------
// bfs 구현 연습
// 구현 방법 : 큐로 구현 - 2차원 배열, vector<>[]

#pragma region 2) bfs 큐로 구현 - vector<>[] 방식 - 인접 노드를 직접적으로 입력받았을 경우 용이, 메모리 부담 X
// 2) bfs 큐로 구현 - vector<>[] 방식 - 인접 노드를 직접적으로 입력받았을 경우 용이, 메모리 부담 X
// => 메모리가 제한적일 때나 인접 노드를 직접적으로 입력 받을 경우 사용
#include <iostream>
#include <queue>
#include <vector>

using namespace std;
#define MAX_N 10 // 1000이 넘어가도 크게 상관 없음. 메모리에 유연하게 대처 가능

int vertax, edge, root; // vertax : 정점(노드) 개수 | edge : 간선 개수 | root : root 노드
vector<int> Graph[MAX_N]; // 1번 노드와 연결된 노드 : 2 , 4 , 5 | 2번 노드와 연결된 노드 : 3 , 4 이런 식으로 간선의 연결이 입력으로 주어진 경우 유용하고 효율적으로 연결 정보를 저장할 수 있다.

// 1. 루트 노드(초기 노드)는 방문 처리 + 큐 push + 출력
// 2. 현재 노드 저장 + 큐 pop + 현재 노드 출력
// 3. 다음 노드가 될 수 있는 조건을 만족하는 노드 "모두" A)방문 처리 후 B)큐에 push
// 다음 노드가 될 수 있는 조건 : a) 현재 노드와 연결되어 있는 노드이면서 b) 다음 노드는 이전에 방문된 적이 없는 노드

void bfs(int node) {
	bool visited[MAX_N]; // 노드의 방문 여부를 체크하는 배열
	memset(visited, false, sizeof(visited)); // visited 배열을 모두 false 로 초기화한다.
	queue<int> bfs_queue; // bfs 그래프 순회 처리를 위한 큐

	// 1. 루트 노드(초기 노드)는 방문 처리 + 큐 push 
	visited[node] = true;
	bfs_queue.push(node);


	while (!bfs_queue.empty()) { // 큐가 빌 때까지 while 문( 2,3번 ) 루프 안에서 계속 진행
		// 2. 현재 노드 저장 + 큐 pop + 현재 노드 출력
		int current_node = bfs_queue.front(); // 현재 노드 저장
		bfs_queue.pop(); // 큐에서 pop
		cout << current_node << " "; // 현재 노드 출력

		// 3. 다음 노드가 될 수 있는 조건을 만족하는 노드 "모두" A)방문 처리 후 B)큐에 push
		// 다음 노드가 될 수 있는 조건 : a) 현재 노드와 연결되어 있는 노드이면서 b) 다음 노드는 이전에 방문된 적이 없는 노드
		for (int next_node : Graph[current_node]) { // a)
			if (visited[next_node] == true) continue; // 방문된 적이 있는 노드면 무시 b)
			
			// a,b 조건에 모두 해당하면 다음 노드가 될 수 있는 조건을 만족하므로 방문 처리 후 큐에 push
			visited[next_node] = true; // 다음 노드 방문 처리
			bfs_queue.push(next_node); // 다음 노드 큐에 push
		}
	}
}

int main(void) {
	cin >> vertax >> edge >> root;

	// 노드의 연결 정보를 그래프 배열에 넣는다.
	for (int i = 0; i < edge; i++) {
		int start_node, arrive_node; // start_node : 연결의 시작 노드, arrive_node : 연결의 도착 노드
		cin >> start_node >> arrive_node;
		Graph[start_node].push_back(arrive_node);
		Graph[arrive_node].push_back(start_node); // 1 4 와 4 1이 연결된 것은 같은 것을 의미하므로
	}
	// root 노드부터 bfs 탐색을 실시한다.
	bfs(root);

	return 0;
}
#pragma endregion 

#pragma region //1) bfs 큐로 구현 - 2차원 배열 방식 (#맵(Graph)의 범위가 작을 때, #구현 용이, #메모리 고려해야함)
//1) bfs 큐로 구현 - 2차원 배열 방식 (#맵(Graph)의 범위가 작을 때, #구현 용이, #메모리 고려해야함) [C2014 오류 시 #pragma region 부분의 내용을 지운다.]

// ---------------------------------------------------------------------------------------------------------------------

// 1) bfs 큐로 구현 - 2차원 배열 방식 , Graph의 크기가 10000*10000 을 넘어가면 메모리 부담 (int 1.2억개 => 약 512MB)
// => 일반적인 어떤 그래프의 맵이 주어지거나, 맵의 크기가 작을 때 구현이 용이하여 사용
#include <iostream>
#include <queue>

#define MAX_N 10 // MAX_N이 통상적으로 1000 이하라면 2차원 배열로 했을 때도 메모리 초과가 발생하지 않는다.

using namespace std;

int Graph[MAX_N][MAX_N]; // 노드들의 연결 상태를 나타내는 그래프를 담는 배열
int vertax, edge, root; // vertax : 정점(노드) 개수 | edge : 간선 개수 | root : root 노드

// bfs 구현 - 큐
// 1. 처음에 들어온 루트 노드를 방문 처리하고 큐에 push
// 2. 현재 노드를 변수에 담아주고 출력 후 pop한다.
// 3. 현재 노드와 A) 인접한 노드중에서 B) 방문된 적이 없는 노드를 모두 큐에 push (다음 노드가 될 조건에 해당하는 모든 큐를 push한다.)
// 3. ★해당 노드를 push 하기 전에 선 방문 처리를 진행한다.
void bfs(int node) {
	bool visited[MAX_N]; // 노드가 이전에 방문한 적이 있는지 체크하는 배열 | false : 방문한 적 없음, true : 방문한 적 있음
	memset(visited, false, sizeof(visited)); // visited 배열을 false로 모두 초기화한다.
	queue<int> bfs_queue; // bfs 연산을 위한 큐

	
	// 1. 처음에 들어온 루트 노드를 방문 처리하고 push
	visited[node] = true; // 방문 처리
	bfs_queue.push(node); // bfs_queue에 push
	
	// 2. 현재 노드를 변수에 담아주고 출력 후 pop한다. + 방문 처리
	// 3. 현재 노드와 A) 인접한 노드중에서 B) 방문된 적이 없는 노드를 모두 큐에 push (다음 노드가 될 조건에 해당하는 모든 큐를 push한다.)
	while (!bfs_queue.empty()) { // 큐가 비지 않을때까지 계속 안에서 연산 실행
		// 2. 큐에서 현재 노드를 변수에 담고 현재 노드를 출력한 뒤 pop
		int current_node = bfs_queue.front(); // 2. 현재 노드를 변수에 담아준다.
		bfs_queue.pop(); // 2. 현재 노드를 pop 

		cout << current_node << " "; // 2. 현재 노드를 출력

	// 3. 현재 노드와 A) 인접한 노드중에서 B) 방문된 적이 없는 노드를 모두 큐에 push (다음 노드가 될 조건에 해당하는 모든 큐를 push한다.)
		for (int next_node = 0; next_node < vertax; next_node++) {
			if (Graph[current_node][next_node] == 1 && visited[next_node] == false) { // 3. 의 A) B) 조건에 모두 해당하는 경우
				visited[next_node] = true; // ★ 2. 방문 처리 - 미리 방문 처리를 하지 않으면 중복된 원소가 담길 수 있다.
				bfs_queue.push(next_node);
			}
		}
	}
}

int main(void) {
	cin >> vertax >> edge >> root;
	
	memset(Graph, 0, sizeof(Graph)); // Graph 배열의 모든 원소를 0으로 초기화한다.
	// 노드들의 연결 정보를 Graph 에 저장
	for (int i = 0; i < edge; i++) {
		int start_node, arrive_node; // 시작 노드와 도착 노드 (연결)
		cin >> start_node >> arrive_node;
		Graph[start_node][arrive_node] = Graph[arrive_node][start_node] = 1; // 연결 정보 저장 | 1 4 와 4 1 은 같은 의미이다.
	}

	// root 노드를 시작으로 bfs 탐색 시작
	bfs(root);

	return 0;
}
#pragma endregion