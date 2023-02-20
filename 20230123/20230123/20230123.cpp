// 20230123 백준 문제풀이
// 
/*
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef pair<int, int> line;
vector<line> lines;
vector<int> temp;
int main(void) {
	int k, n;

	cin >> k >> n;
	for (int i = 0; i < k; i++) {
		int x;
		cin >> x;
		lines.push_back(make_pair(x, 1)); // x는 선 길이, 1은 divid
		temp.push_back(x);
	}

	for (int i = 0; i < n-k; i++) {
		sort(temp.begin(), temp.end());
		
		lines[k - 1].second++;
	}
	sort(lines.begin(), lines.end());
	cout << lines[0].first;

	return 0;
}
*/
// ======================================================================================================================
/*
// 6. 10757번 - 큰 수 A+B(B5), 7. 15353번 - 큰 수 A+B(2)(S3) [소요 시간 : 2시간 38분 53초]
// long long int 도 담기지 않는다.
// 아이디어 : char 배열로 해결 아스키코드 표에서 '숫자' - '0' = int형 숫자가 나오는 것을 이용한다. 
// ex) int형 숫자 3을 얻고 싶으면 '3' - '0' = 3 
// 성능 : 2396KB, 0ms

#include <iostream>
#include <math.h>
#include <string>
#include <vector>
using namespace std;

vector<int> xnumber;
vector<int> ynumber;
int answer[10002] = { 0 };

using namespace std;
int main(void) {
	string x, y;
	int x_size = 0;
	int y_size = 0;
	int i = 0;
	int plus = 0;
	// 0. 고속 입출력
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	// 1. 입력받기
	cin >> x >> y;
	// 2. 각 자리수 구하기
	x_size = x.length();
	y_size = y.length();

	// 3. 숫자로 치환 + 자릿수 맞춰주기
	int jarisu = max(x_size, y_size);
	for (int i = 0; i < x_size; i++) {
		xnumber.push_back(x[x_size-1-i] - '0');
	}
	for (int i = 0; i < y_size; i++) {
		ynumber.push_back(y[y_size-1-i] - '0');
	}
	if (x_size < y_size) {
		while (x.length() + xnumber.size() != y.length() + ynumber.size()) {
			xnumber.push_back(0);
		}
	}
	else if (x_size > y_size) {
		while (x.length() + xnumber.size() != y.length() + ynumber.size()) {
			ynumber.push_back(0);
		}
	}
	// 4. 같은 자리수끼리 연산 (반올림 포함)
	for (int i = 0; i < jarisu; i++) {
		if (answer[i] + xnumber[i] + ynumber[i] <= 9) { // 반올림 할 필요가 없는 경우
			answer[i] = xnumber[i] + ynumber[i] + answer[i];
		}
		else { // 반올림 할 필요가 있는 경우
			if (jarisu - 1 == i) plus++;
			answer[i + 1]++;
			answer[i] = answer[i] + xnumber[i] + ynumber[i] - 10;
		}
	}

	// 5. 정답 출력
	for (int i = jarisu-1+plus; i >= 0; i--) {
		cout << answer[i];
	}
	
	return 0; 
}
*/
// ======================================================================================================================
// 5. 10816번 - 숫자 카드2(S4) [소요 시간 : 14분 7초]
// 풀이 전략1 : 입력 받아야 하는 테스트 케이스의 경우가 최악의 경우 500000*500000 이므로 시간 복잡도를 고려해야한다. 
// -> 숫자의 개수를 구해야 하므로 이진 탐색 기반의 upper_bound와 lower_bound의 차로 해당 숫자의 개수를 구한다.
// 성능 : 7176KB, 328ms

/*
//[풀이 전략1 코드]
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> sanggeun;
int answer[500001] = { 0 };


int main(void) {
	int n, m;
	// 0. 고속 입출력
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	// 1. 입력 받기
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		sanggeun.push_back(x);
	}
	// 2. 값 비교하면서 있으면 +1
	sort(sanggeun.begin(), sanggeun.end());
	cin >> m;
	for (int i = 0; i < m; i++) {
		int x;
		cin >> x;
		answer[i] = upper_bound(sanggeun.begin(), sanggeun.end(), x) - lower_bound(sanggeun.begin(), sanggeun.end(), x);
	}

	// 3. 정답 출력
	for (int i = 0; i < m; i++) {
		cout << answer[i] << " ";
	}
	return 0;
}
*/
// ======================================================================================================================
/*
// 4. 14425번 - 문자열 집합(S3) [전략1 소요 시간 : 3분 53초] | [전략2 소요 시간 : 5분 53초(문제 이해시간 포함)] | [전략3 소요 시간 : 3분 17초]
// 풀이 전략1 : 이진 탐색(binary_search)+vector으로 일일이 검사한다. => log(10000*10000)
// 성능 : 7636KB, 80ms
// 풀이 전략2 : set 자료구조의 find 클래스 이용하여 검사한다.
// 성능 : 7944KB, 84ms
// 풀이 전략3 : 순서가 상관 없으므로 unordered_set을 사용하여 자동으로 sort되는 set과 비교하여 성능 시간적 측면 이득을 본다.
// 성능 : 7828KB, 68ms

//[풀이 전략3]
#include <iostream>
#include <unordered_set>
#include <algorithm>
#include <vector>

using namespace std;
unordered_set<string> s;
int main(void) {
	int n, m;
	int count = 0;
	// 0. 고속 입출력
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	// 1. 입력 받기
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string x;
		cin >> x;
		s.insert(x);
	}
	// 2. 입력받은 정보를 바탕으로 비교하기
	for (int i = 0; i < m; i++) {
		string x;
		cin >> x;
		if (s.find(x) != s.end()) // 이미 단어가 있는 경우
		{
			count++;
		}
	}
	
	cout << count;
	return 0;
}

/*
//[풀이 전략1 코드] 
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
vector<string> s;
int main(void) {
	int n, m;
	int count = 0;
	// 0. 고속 입출력
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n >> m;
	// 1. 정보 입력
	for (int i = 0; i < n; i++) {
		string x;
		cin >> x;
		s.push_back(x);
	}

	// 2. 이진 탐색을 통해 비교 - 사전에 정렬 필수
	sort(s.begin(), s.end()); // 오름차순 정렬
	for (int i = 0; i < m; i++) {
		string x;
		cin >> x;
		if (binary_search(s.begin(), s.end(), x) == true) { // x가 이미 있으면
			count++;
		}
	}
	cout << count;
	return 0;
}
*/
/*
// [풀이 전략2 코드]
#include <iostream>
#include <set>

using namespace std;
set<string> s;

int main(void) {
	int a, b;
	int answer = 0;
	// 0. 고속 입출력
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	// 1. 정보 입력
	cin >> a >> b;

	for (int i = 0; i < a; i++) {
		string word;
		cin >> word;
		s.insert(word);
	}
	// 2. 해당 set에 이미 있는 단어면 +1
	for (int i = 0; i < b; i++) {
		string word;
		cin >> word;
		if (s.find(word) != s.end()) { // 이미 있는 단어인 경우
			answer++;
		}
	}

	cout << answer;
	return 0;
}
*/
// ======================================================================================================================
/*
// 3. 9012번 - 괄호 (S4) [소요 시간 : 28분 17초]
// 풀이 전략 : 올바른 괄호가 성립될 조건은 stack에서 ( 을 push 라고 생각하고 )을 pop 이라고 생각했을 때 모든 연산을 수행한 스택의 사이즈는 0이 되어야 한다는 아이디어를 활용한다.
// 풀이 전략2 : ( 와 ) 의 개수가 같은 경우는 올바른 괄호, 다른 경우는 올바른 괄호가 아니다. ( 이면 +1, )이면 -1로 계산하여 합이 0이 되는지 체크한다.
// 성능 : 2024KB, 4ms
// [풀이 전략1 사용]
#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;
int main(void) {
	int testcase;
	string test;
	stack<char> s;
	int wrong = 0;

	cin >> testcase;
	for (int i = 0; i < testcase; i++) {
		cin >> test;
		for (int j = 0; j < test.size(); j++) { // 문자열 길이만큼 
			if (test[j] == '(') {
				s.push('(');
			}
			else if (test[j] == ')') {
				if (s.empty() == true) {
					wrong = 1;
				}
				else { s.pop(); }
			}
		}

		if (s.empty() == true && wrong == 0) { // 빈 스택이라면 올바른 괄호 문자열 => YES 출력
			cout << "YES\n";
		}
		else if(s.empty() == false || wrong == 1) // 빈 스택이 아니라면 올바른 괄호 문자열이 아니다 => NO 출력
			cout << "NO\n";

		// 스택 초기화, 조건 초기화
		while (s.empty() != true) {
			s.pop();
		}
		wrong = 0;
		
	}


	return 0;
}
*/
// ======================================================================================================================
/*
// 2. 10773번 - 제로 (S4) [소요 시간 : 16분 24초]
// 풀이 전략 : 가장 최근에 쓴 수를 지운다 => 스택 응용 문제 
// 새롭게 알게 된 주의사항 : 스택에 있는 값들을 순회할 때 스택 사이즈도 변하므로 for문을 사용할 때 주의해야한다.
// 성능 : 2416KB, 28ms
#include <iostream>
#include <stack>

using namespace std;
stack<int> s;

int main(void) {
	int testcase;
	int money;
	int answer = 0;
	int s_size = 0;

	cin >> testcase;

	for (int i = 0; i < testcase; i++) {
		cin >> money;
		if (money == 0) {
			s.pop();
		}
		else {
			s.push(money);
		}
	}

	//s_size = s.size(); // 스택을 꺼내면 사이즈가 줄어들으므로 미리 넣어놓고 for문으로 선형 탐색을 한다.
	//for (int i = 0; i < s_size; i++) { // 하나씩 꺼내면서 합 구한다.
	//	answer = answer + s.top();
	//	s.pop();
	//}
	
	while (s.size() != 0) {
		answer = answer + s.top();
		s.pop();
	}

	cout << answer;
	return 0;
}
*/
// ======================================================================================================================
/*
// 1. 10828번 - 스택 (S4) [소요 시간 : 12분 8초]
// 풀이 전략 : 스택 연습 문제이다. 빈 스택을 다룰 때 빈 스택에 pop을 하면 오류가 발생하므로 continue; 구문을 사용하여 빠져나오도록 유도한다.

#include <stack>
#include <iostream>
#include <string>

using namespace std;

int main(void) {
	int testcase;
	string menu;
	int n;
	stack <int> s;

	cin >> testcase;

	for (int i = 0; i < testcase; i++) {
		cin >> menu;
		if (menu == "push") { // push 명령
			cin >> n;
			s.push(n);
		}
		else if (menu == "top") { // top 명령
			if (s.empty() == true) {
				cout << "-1\n";
				continue;
			}
			cout << s.top() << "\n";
		}
		else if (menu == "size") { // size 명령
			cout << s.size() << "\n";
		}
		else if (menu == "empty") { // empty 명령
			cout << s.empty() << "\n";
		}
		else if (menu == "pop") { // top 명령
			if(s.empty() == true) {
				cout << "-1\n";
				continue;
			}
			cout << s.top() << "\n";
			s.pop();
		}

	}
}
*/