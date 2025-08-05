#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N; cin >> N;
	// 시작, 끝
	vector<pair<int, int>> timetable;
	for (int i = 0; i < N; i++) {
		int start, end;
		cin >> start >> end;
		timetable.push_back({ start,end });
	}

	// 시작 시간 기준으로 정렬
	// 시작 시간이 되면 일단 넣어야 함.
	sort(timetable.begin(), timetable.end(), [](pair<int, int> a, pair<int, int> b) {
		return a.first < b.first ||
			(a.first == b.first && a.second < b.second);
		});

    // 강의실
	priority_queue<int, vector<int>, greater<int>> pq;

	int result = 1;
	pq.push(timetable[0].second);
	for (int i = 1; i < N; i++) {
		if (pq.top() <= timetable[i].first) {
			pq.pop();
		}
		pq.push(timetable[i].second);
		result = max(pq.size(), (size_t)result);
	}
	cout << result;
}