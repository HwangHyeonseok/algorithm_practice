// 24444_알고리즘 수업 - 너비 우선 탐색 1 [소요 시간 : 37분 51초]
// #bfs+메모리 제한

// 최대 정점의 개수가 10만, 최대 간선의 개수가 20만개이므로 2차원 배열을 사용할 경우 int가 200억개인 배열이 되므로 메모리 초과가 발생한다.
// 따라서 Graph에 노드들의 연결 상태를 저장할 때 2차원 배열로 저장하는 것이 아니라 vector<>[] 방식으로 저장해야 한다.

// 어려웠던 점 : [69번째 줄] / - Graph.begin() 으로 혼동했었다. Graph 배열 자체가 아니라 Graph[i] 안에 있는 원소를 정렬해야 한다!
// 메모리 : 9828KB, 88ms

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;
#define MAX_VERTAX 100001 // 최대 정점의 개수 : 100,000
#define MAX_EDGE 200001 // 최대 간선의 개수 : 200,000

vector<int> Graph[MAX_VERTAX]; // vector<>[] 방식으로 Graph의 노드들의 연결 상태를 저장

int vertax, edge, root; // vertax : 정점의 수 | edge : 간선의 수 | root : 루트 노드
int answer[MAX_VERTAX] = {0}; // 각 노드의 방문 순서를 나타내는 배열 (정답)

// dfs - 큐와 vector<>[] 을 이용하여 구현
// 1. 루트 노드는 방문 처리 + 노드 출력
void dfs(int node) {
	int count = 1; // count 는 방문 순서를 나타낸다.
	vector<int> visited(MAX_VERTAX, false); // 노드가 이전에 방문한 적이 있는지 체크하는 배열
	queue<int> dfs_queue;

	// 1. 루트 노드는 방문 처리 + queue에 push
	visited[node] = true; // 방문 처리
	dfs_queue.push(node); // 초기 노드를 큐에 push

	while (!dfs_queue.empty()) { // 큐가 빌 때까지 2. 3. 실행
		// 2. 큐의 front 노드를 current_node 변수에 넣어주고 + pop + (front 노드를 출력) -> 대신 answer 배열에 삽입
		int current_node = dfs_queue.front();
		dfs_queue.pop();
		answer[current_node] = count; // 노드의 방문 순서를 넣어준다.
		count++;

		// 3. 다음 노드가 될 조건에 만족하는 노드는 dfs_queue에 push한다.
		// 다음 노드가 될 조건 : A) 현재 노드와 연결 되어 있는 노드여야 한다. B) 맵 안에 있는 노드여야 한다. (여기서는 따지지 않아도 됨)
		// C) 이전에 방문한 적이 없는 노드여야 한다.
		for (int next_node : Graph[current_node]) { // A)
			if (visited[next_node] == true) continue; // C) 이전에 방문한 적이 있다면 패스

			// 다음 노드가 될 조건을 모두 만족한 노드에 한해서 해당 코드 실행 - 방문 처리 + 큐에 다음 노드 정보 push 
			visited[next_node] = true; // 방문 처리
			dfs_queue.push(next_node); // 큐에 다음 노드 정보 push
		}

	}
}

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	cin >> vertax >> edge >> root;

	// 노드들의 연결 정보를 입력받아서 연결 정보를 Graph 배열에 넣는다.
	for (int i = 0; i < edge; i++) {
		int start_node, arrive_node;
		cin >> start_node >> arrive_node;
		Graph[start_node].push_back(arrive_node); // 정점과 정점의 연결을 구현한다.
		Graph[arrive_node].push_back(start_node); // 1 4 와 4 1 은 연결된게 같은 의미를 지니기 때문이다.
	}
	
	// 방문 순서는 같은 인접한 노드일 때 오름차순 순이므로 sorting을 오름차순으로 진행한다.
	for(int i = 1; i<=vertax; i++) {
		sort(Graph[i].begin(), Graph[i].end()); // ★ 이 부분이 헷갈렸다. - Graph.begin() 으로 혼동했었다. Graph[i] 안에 있는 원소를 정렬해야 한다!
	}

	// 너비 우선 탐색 실시 (root 노드부터)
	dfs(root);

	// 각 노드의 방문 순서를 1번 노드부터 순서대로 출력한다.
	for (int i = 1; i <= vertax; i++) {
		cout << answer[i] << "\n";
	}

}