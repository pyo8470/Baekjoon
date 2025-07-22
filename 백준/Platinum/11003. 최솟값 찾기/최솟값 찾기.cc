#include <iostream>
using namespace std;
#include <string>
#include <vector>
#include <stack>
#include <climits>
#include <queue>
#include <set>
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N, L;
	cin >> N >> L;


	
	// {값, 인덱스}
	deque<pair<int,int>> dq;
	vector<pair<int, int>> v;
	for (int i = 0; i < N; i++) {
		int k; cin >> k;
		v.push_back(make_pair(k, i));
	}

	for (int i = 0; i < N; i++) {
		// 새로 들어오는 수보다 back보다 작다는 것은 해당 back은 최소값의 여지가 없으므로 퇴출
		while (!dq.empty()&& dq.back().first > v[i].first) {
			dq.pop_back();
		}
		// 슬라이딩 윈도우/범위에 벗어나는 값은 버린다.
		while (!dq.empty() && dq.front().second <= i - L)
			dq.pop_front();
		dq.push_back(v[i]);
		cout << dq.front().first << " ";
	}
}