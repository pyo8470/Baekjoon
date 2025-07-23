#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <climits>
#include <queue>
#include <set>
#include <algorithm>

using namespace std;



int main() {
	// 야구
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N, L;
	cin >> N >> L;
	vector<pair<int,int>> A;
	// 수, 인덱스
	// front가 최솟값이 되도록 하자
	deque<pair<int, int>> dq;
	for (int i = 0; i < N; i++) {
		int n; cin >> n;
		A.push_back(make_pair(n, i));
	}
	// O(NlogL)에 해결해야한다.

	// 
	for (int i = 0; i < N; i++) {
		// 최솟값 후보만 넣기.
		while (!dq.empty() && dq.back().first > A[i].first) {
			dq.pop_back();
		}
		// 슬라이딩 윈도우
		// 최솟값의 인덱스가 범위를 벗어나면
		while (!dq.empty() && dq.front().second <= i - L) {
			dq.pop_front();
		}
		dq.push_back(A[i]);
		cout << dq.front().first << " ";
	}
}

