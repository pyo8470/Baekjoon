#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;
int N;
vector<int> rope;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> N; rope.resize(N, 0);
	for (int i = 0; i < N; i++) { 
		cin >> rope[i];
	}

	sort(rope.begin(), rope.end(),greater<int>());
	int cap = rope[0];

	// 모든 줄을 매달았을 때, 그게 용량이 크면..ㅇㅇ
	for (int i = 1; i < N; i++) {
		cap = max(cap, rope[i] * (i + 1));
	}
	cout << cap;
}