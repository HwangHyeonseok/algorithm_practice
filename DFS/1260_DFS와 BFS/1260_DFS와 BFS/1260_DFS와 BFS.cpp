// 1260_DFS와 BFS [소요 시간 : 47분 10초]
// #DFS구현+정렬 #BFS구현+정렬

// 최대 정점의 개수가 1000개 이므로 2차원 배열을 사용해도 메모리에 크게 무리가 가지 않는다.
// 하지만, 입력을 연결된 노드들로 받으므로 vector<>[] 형식으로 Graph에 담았다가 범위 기반 for문으로 순회하는 것이 더 구현하기 편할 것 같다.

// 헷갈렸던 점 : DFS 스택 구현 -> DFS는 다음 노드 조건을 만족하는 노드 "하나만" 가지고 가서 순회를 한다.
//				 BFS 큐 구현 -> BFS은 다음 노드 조건을 만족하는 "모든" 노드에 대해서 순회를 한다.

// 성능 : 2312KB, 0ms
#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#include <cstring> // C++에서 memset 메서드를 사용하기 위한 라이브러리

#define MAX_VERTAX 1001 // 정점의 최대 개수 : 1000개
#define MAX_EDGE 10001 // 간선의 최대 개수 : 10000개

using namespace std;

int vertax, edge, root; // vertax : 정점의 개수 , edge : 간선의 개수 , root : 루트 노드
vector<int> Graph[MAX_VERTAX]; // 각 노드들이 어떤 다른 노드들과 연결 되어 있는지 담는 배열

#pragma region // 깊이 우선 탐색 구현 - 스택
void dfs(int node) {
	stack<int> dfs_stack; // dfs 구현을 위한 스택
	bool visited[MAX_VERTAX]; // 각 노드가 이전에 방문을 했는지 체크하는 배열
	memset(visited, false, sizeof(visited)); // visited 배열의 원소를 모두 false로 초기화

	// 1. 루트 노드 | 노드 스택 처리(stack에 push)
	dfs_stack.push(node);

	while (!dfs_stack.empty()) { // 스택이 빌 때까지 2. 3. 반복 진행

		// 2. 최상위 원소를 현재 노드 변수에 넣고 + pop + 노드 출력 처리
		int current_node = dfs_stack.top();
		dfs_stack.pop(); 
		if (visited[current_node] == true) continue; // ★ 만약 이미 방문이 된 적이 있는 노드라면 패스

		visited[current_node] = true;
		cout << current_node << " ";

		// 3. 다음 노드가 될 조건에 맞는 노드에 한해 다음 노드 bfs 탐색
		// 다음 노드가 될 조건 : A) 현재 노드와 연결이 되어 있는 노드여야 한다. B) 이전에 방문한 적이 없는 노드여야 한다.
		// C) Graph 범위(맵 범위) 안에 있어야 한다. (여기서는 따지지X)
		for (int next_node : Graph[current_node]) { // A)
			if (visited[next_node] == true) continue; // B)
			
			// 다음 노드가 될 조건을 모두 만족하는 노드 "하나만" 방문 처리 후 다음 노드로 지정
			dfs_stack.push(next_node);
		}
	}
}
#pragma endregion

/*
#pragma region // 깊이 우선 탐색 구현 - 재귀
bool visited[MAX_VERTAX] = {false}; // 각 노드가 이전에 방문한 적이 있는지 체크

void dfs(int node) {

	int current_node = node;
	// 1. 방문한 적이 없는 노드에 한해서 | 방문 처리 + 노드 출력
	if (visited[current_node] == false) {
		visited[current_node] = true;
		cout << current_node << " ";
	}

	// 2. 다음 노드 조건에 맞는 노드만 재귀적으로 호출하여 순회
	// 다음 노드 조건 : A) 현재 노드와 연결이 되어 있는 노드 B) 이전에 방문한 적이 없는 노드
	// C) 벽이 아닌 노드 (이동 가능한 노드) D) 맵 범위 안에 있는 노드
	// C) , D) 는 이 문제에서 따지지 않는다.
	for (int next_node : Graph[current_node]) { // A)
		if (visited[next_node] == true) continue; // B)
		
		// 다음 노드 조건에 해당하는 노드만 재귀적으로 dfs 함수 호출
		dfs(next_node);
	}
	
}

#pragma endregion
*/

#pragma region // 너비 우선 탐색 구현 - 큐
void bfs(int node) {
	queue<int> bfs_queue; // bfs 구현을 위한 큐
	bool visited[MAX_VERTAX]; // 노드의 이전 방문 여부를 체크하는 visited 배열
	memset(visited, false, sizeof(visited)); // visited 배열을 모두 false로 초기화

	// 1. 루트 노드 | 방문 처리 + 큐에 push
	visited[node] = true;
	bfs_queue.push(node);

	while (!bfs_queue.empty()) { // 큐가 빌 때까지 2. 3. 실행
		// 2. 최상위 원소를 현재 원소 변수에 삽입 + pop + 출력 처리
		int current_node = bfs_queue.front();
		bfs_queue.pop();
		cout << current_node << " ";

		// 3. 다음 정점이 될 조건에 맞는 정점을 방문한다.
		// 다음 정점이 될 조건 : A) 현재 노드와 연결이 되어 있는 노드여야 한다. B) 다음 노드는 이전에 방문한 적이 없어야 한다.
		// C) 방문이 가능한 곳이어야 한다. (벽이면 안된다.) D) 주어진 맵 안의 범위여야 한다. 
		// C) 와 D)는 문제에서 주어지지 않았으므로 따지지 않는다.

		for (int next_node : Graph[current_node]) { // A)
			if (visited[next_node] == true) continue; // B)
			
			// 다음 정점이 될 조건을 모두 만족한 노드에 한해서 방문 처리 + 큐에 push + 노드 출력처리 하여 순회한다.
			visited[next_node] = true;
			bfs_queue.push(next_node);
		}
	}
}
#pragma endregion

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	cin >> vertax >> edge >> root;

	// 노드의 연결 정보를 Graph 배열에 담는다.
	for (int i = 0; i < edge; i++) {
		// 시작 노드와 도착 노드를 입력 받는다.
		int start_node, arrive_node; 
		cin >> start_node >> arrive_node;
		// 두 노드의 연결 상태를 Graph 배열에 넣는다. ( 1 4 와 4 1 이 연결된 것은 같은 것을 의미한다. )
		Graph[start_node].push_back(arrive_node);
		Graph[arrive_node].push_back(start_node);
	}
	// 방문할 수 있는 정점이 여러 개인 경우 정점 번호가 작은 것을 우선으로 방문
	// 스택을 사용하는 깊이 우선 탐색 (dfs)의 경우 -> i 번째에 연결되 있는 노드들을 내림차순 정렬을 해야 한다.
	// 만약 dfs을 재귀로 구현할 경우 -> 오름차순 정렬해야 한다.
	for (int i = 1; i <= vertax; i++) { // ★ int i=0; i<vertax; i++ 하면 안된다. 원소가 5개일 때 그러면 원소가 5인 원소와 연결된 노드 번호는 정렬하지 못한다.
		sort(Graph[i].begin(), Graph[i].end(), greater<int>()); // 내림차순 정렬
	}

	// dfs을 수행한다. - 스택
	dfs(root);
	cout << "\n"; // 출력 형식에 맞게 한 줄 띄어준다.

	// 큐을 사용하는 너비 우선 탐색 (bfs)의 경우 -> i 번째에 연결되 있는 노드들을 오름차순 정렬을 해야 한다.
	for (int i = 1; i <= vertax; i++) {
		sort(Graph[i].begin(), Graph[i].end()); // 오름차순 정렬
	}
	// bfs을 수행한다. - 큐
	bfs(root);

	return 0;
}