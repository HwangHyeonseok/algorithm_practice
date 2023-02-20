#include <iostream>

using namespace std;
void func1(int N) {
	int sum = 0;
	for (int i = 1; i <= N; i++) {
		if (i % 3 == 0 || i % 5 == 0) {
			sum += i;
		}
	}
	cout << sum;
}

int func2(int arr[], int N) {
	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			if (arr[i] + arr[j] == 100) return 1;
		}
	}
	return 0;
}

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int arr[] = { 1,52,48 };
	cout << func2(arr, sizeof(arr)/sizeof(arr[0]));
	return 0;
}
