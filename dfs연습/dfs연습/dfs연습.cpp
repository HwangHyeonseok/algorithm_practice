// dfs 연습

// 사전 지식 : 2차원 배열 vector - https://leeeegun.tistory.com/3

// 다음 dfs을 구현하라. - 재귀함수를 통한 구현
/*
	 0
   1   2
 3   4  
*/

#include <iostream>
#include <vector>
#include <stack>

#define MAX_N 10
using namespace std;

vector<vector<int>> Graph(MAX_N,vector<int>(MAX_N, 0)); // Graph[MAX_N][MAX_N] = {0}; 과 같다. | Graph에 담긴 노드들의 간선과 노드를 나타내었다.
int edge_count, node_count; // edge_count은 간선의 개수, node_count는 노드의 개수

// dfs 함수 - 스택으로 구현
// 1. 처음 루트 노드를 스택에 담는다.
// 2. 현재 노드(스택의 top)을 현재 노드를 저장하는 current_node 변수에 저장
// 3. 스택에서 최상위 노드를 pop
// 4. 만약에 현재 노드 current_node 노드가 이전에 방문되었던 노드면 1)번으로, 
// 만약 현재 노드 current_node 노드가 이전에 방문이 된 적 없는 노드라면 방문 처리를 해주고 그 curr 노드의 원소를 출력
// 5. 다음 노드가 방문된 이력이 없고, 해당 노드와 연결이 되어 있는 노드라면 스택에 push한다.

void dfs(int node) {
	vector<bool> Visited(MAX_N, false); // 각 노드가 이전에 방문이 되었는지 체크하기 위한 배열
	stack<int> dfs_stack; // 노드들을 담는 스택

	dfs_stack.push(node); // 1) 처음 루트 노드를 스택에 담는다.
	
	while (!dfs_stack.empty()) { // 스택이 빌 때까지 반복
		int current_node = dfs_stack.top(); // 2)
		dfs_stack.pop(); // 3)

		if (Visited[current_node] == true) // 4) 조건 검사 - 이전에 방문한 기록이 있을 경우 이미 방문했으므로 방문 처리랑 현재 노드 원소를 출력할 필요가 없다.
			continue;
		
		Visited[current_node] = true; // 4) 방문 처리
		cout << current_node << " "; // 4) current_node 노드의 원소를 출력

		for (int next_node = 0; next_node < node_count; next_node++) { // 5)
			if (!Visited[next_node] && Graph[current_node][next_node] == 1) { // 다음 노드가 방문된 이력이 없고, 해당 노드와 연결이 되어 있는 노드라면 스택에 push한다.
				dfs_stack.push(next_node);
			}
		}
	}
}

int main(void) {
	
	// 간선의 개수와 노드의 개수를 차례로 입력 받는다.
	cin >> edge_count >> node_count;
	
	// 노드의 개수만큼 그래프의 관계를 입력 받는다.
	for (int i = 0; i < node_count; i++) {
		int prev_node, next_node; // 연결된 두 노드를 입력한다.
		cin >> prev_node >> next_node;

		Graph[prev_node][next_node] = Graph[next_node][prev_node] = 1; // 1 0 이 연결된 것과 0 1 이 연결된 것은 같은 의미를 지닌다. 따라서 반대의 경우도 그래프 배열에 1을 넣어준다.
	}
	
	dfs(0); // 0번째 노드를 루트 노드라고 가정했을 때의 dfs을 구한다. 
	return 0;
}










// 재귀함수 DFS 구현
/*
#include <iostream>
#include <vector>

#define MAX_N 10
using namespace std;

vector<bool> Visited(MAX_N, false); // 방문 여부 체크
vector<vector<int>> Graph(MAX_N, vector<int>(9, 0)); // 2차원 vector | int Graph[MAX_N][9] = { 0 }; 과 같다. // 입력받은 그래프의 정보 노드의 연결 정보를 담는다.

// dfs 구현 - 재귀함수 사용
// 1. 해당 노드 출력
// 2. 해당 노드를 방문 표시
// 3. 현재 노드와 연결된 다음 노드를 찾아 그래프를 dfs 방식으로 순회한다. (재귀적)
// 3 참고. 다음 노드가 될 조건 : 1) 이전에 방문한 적이 없고, 2) 현재 노드와 다음 노드가 될 후보가 간선으로 연결이 되어 있어야 한다.

int n, m; // n 은 간선의 개수, m 은 원소의 개수 | n과 m은 main 함수에서도 쓰이고 dfs 함수에서도 쓰이므로 전역 범위에 선언

void dfs(int node) {
	cout << node << " "; // 1. 해당 노드 출력
	Visited[node] = true; // 2. 해당 노드를 방문 표시

	for (int next_node = 0; next_node < m; next_node++) { // 3. 원소의 개수만큼 반복하여 조건 검사 | next : 다음 노드가 될 후보
		if (!Visited[next_node] && Graph[node][next_node] == 1) { // 다음 노드가 될 조건 : 1) 이전에 방문한 적이 없고, 2) 현재 노드와 다음 노드가 될 후보가 간선으로 연결이 되어 있어야 한다.
			dfs(next_node); // 재귀적 호출로 다음 노드를 방문한다.
		}
	}
}


int main(void) {
	// 간선의 개수와 원소의 개수를 입력받는다.
	cin >> n >> m;
	// 원소들의 연결 정보를 입력 받는다.
	for (int i = 0; i < m; i++) { 
		int prev_node, next_node; // prev_node 노드와 next_node 노드는 서로 연결되어 있다.
		cin >> prev_node >> next_node;
		Graph[prev_node][next_node] = Graph[next_node][prev_node] = 1; // 반대인 것도 똑같이 연결 된거니까 1로 해준다.
	}
	dfs(0); // 루트 노드가 0인 경우에서의 dfs 호출
	return 0;
}
*/