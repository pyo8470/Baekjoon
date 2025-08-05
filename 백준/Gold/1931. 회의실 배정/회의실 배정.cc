#include <iostream>
#include <vector>
#include <algorithm>
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

	sort(timetable.begin(), timetable.end(), [](pair<int, int> a, pair<int, int> b) {
		return a.second < b.second ||
			(a.second == b.second && a.first < b.first);
		});

	//for (int i = 0; i < N; i++) {
	//	cout << timetable[i].first << " " << timetable[i].second << '\n';
	//}
	int result = 1;
	int end = timetable[0].second;
	for (int i = 1; i < N; i++) {
		if (end <= timetable[i].first) {
			result++;
			end = timetable[i].second;
		}
	}

	cout << result;
}