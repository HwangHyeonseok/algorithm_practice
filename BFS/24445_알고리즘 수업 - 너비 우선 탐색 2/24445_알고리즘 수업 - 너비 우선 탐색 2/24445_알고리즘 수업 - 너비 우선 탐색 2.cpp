// 24445_알고리즘 수업 - 너비 우선 탐색 2
// #bfs+메모리 제한+sort(정렬)

// 해당 코드에서 메모리는 int 30~40만개 정도 사용되므로 메모리는 여유롭다. (512MB 기준 int 1.2억개 정도까지 OK)

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;
#define MAX_VERTAX 100001 // 최대 정점의 개수
#define MAX_EDGE 200001 // 최대 간선의 개수

int vertax, edge, root; // vertax : 정점(노드) 개수 | edge : 간선 개수 | root : 루트 노드

// 최대 정점의 개수와, 최대 간선의 개수가 많으므로 Graph을 2차원 배열에 담을 경우 메모리 초과가 발생한다.
// 따라서 vector<>[] 에 저장한다.
vector<int> Graph[MAX_VERTAX]; // i번째 노드의 연결된 원소들을 체크하는 Graph 배열 

int counts = 1;
vector<int> answer(MAX_VERTAX, 0); // i 번째 노드가 몇 번째에 방문했는지 체크하는 배열 (방문한 적이 없는 노드면 0)

// 너비 우선 탐색(bfs) + vector<>[]

void bfs(int node) {
	queue<int> bfs_queue; // bfs 연산을 하기 위한 큐
	vector<bool> visited(MAX_VERTAX, false); // 각 노드들이 이전에 방문한 적이 있는지 체크하는 배열
	
	// 1. 루트 노드 | 방문 처리 + 큐에 push
	visited[node] = true; // 방문 처리 
	bfs_queue.push(node);

	while (!bfs_queue.empty()) { // 큐가 빌 때까지 2. 3. 실행
		// 2. 현재 노드 저장 + pop + 노드 처리
		int current_node = bfs_queue.front();
		bfs_queue.pop();
		answer[current_node] = counts;
		counts++;

		// 3. 다음 노드가 될 조건을 만족하는 노드에 한해 다음 노드 탐색
		// 다음 노드가 될 조건 : A) 현재 노드와 연결이 되어 있는 노드여야 한다. B) 다음 노드는 이전에 한 번도 방문한 적이 없는 노드여야 한다.
		// C) Graph의 범위(Board의 범위)를 이탈하면 안된다. [여기서는 고려하지 않아도 된다.]
		for (int next_node : Graph[current_node]) { // A) | next_node : 다음 노드가 될 후보
			if (visited[next_node] == true) continue; // B)

			// 다음 노드가 될 조건을 만족하는 노드는 방문 처리 후 큐에 push
			visited[next_node] = true;
			bfs_queue.push(next_node);
		}
		
	}

}

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	
	cin >> vertax >> edge >> root;

	// 노드들의 연결 정보를 입력받고 Graph 배열에 저장한다.
	for (int i = 0; i < edge; i++) {
		int start_node, arrive_node; // 입력받은 시작 노드와 끝 노드를 연결한다.
		cin >> start_node >> arrive_node;
		Graph[start_node].push_back(arrive_node);
		Graph[arrive_node].push_back(start_node); // 1 4 가 연결된 것은 4 1 이 연결된 것과 같은 의미이다.
	}

	// 정점 번호를 내림차순으로 방문해야 하므로 Graph[i] 에 있는 원소들을 내림차순으로 정렬한다.
	for (int i = 1; i <= vertax; i++) { // ★
		sort(Graph[i].begin(), Graph[i].end(), greater<int>()); // 내림차순 정렬
	}
	
	// root 노드부터 너비 우선 탐색(bfs)을 실행한다. 
	bfs(root);

	// 1번째 노드부터 vertax 번째 노드까지 bfs 탐색한 순서를 출력한다.
	for (int i = 1; i <= vertax; i++) {
		cout << answer[i] << "\n";
	}

	return 0;
}