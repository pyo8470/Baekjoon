#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<queue>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N; cin >> N;

	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
	for (int i = 0; i < N; i++) {
		int x; cin >> x;
		if (x == 0) {
			if (!pq.empty()) {
				cout << pq.top().second << '\n';
				pq.pop();
			}
			else cout << 0 << '\n';
		}
		else {
			pq.push({abs(x),x});
		}
	}
}