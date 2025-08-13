#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;


// 시작, 끝
int N;
priority_queue<int,vector<int>,greater<int>> pq;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie();
	cin >> N;
	for (int i = 0; i < N; i++) {
		int num; cin >> num;
		pq.push(num);
	}


	int result = 0;
	for (int i = 1; i < N; i++) {
		int a = pq.top(); pq.pop();
		int b = pq.top(); pq.pop();

		pq.push(a + b);
		result += (a + b);
	}
	cout << result << '\n';
}