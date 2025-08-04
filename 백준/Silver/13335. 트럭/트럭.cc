#include <iostream>
#include <queue>
#include <tuple>
#include <algorithm>;
using namespace std;



int N, W, L;
deque<int> trucks;
deque<pair<int, int>> bridge;
int main() {
	
	// 트럭 수/ 길이/ 하중
	cin >> N >> L >> W;
	for (int i = 0; i < N; i++) {
		int t; cin >> t;
		trucks.push_back(t);
	}

	// 무게, 간 거리
	int cap = 0;
	int time = 0;
	while (!bridge.empty() || !trucks.empty()) {
		time++;
		for (int i = 0; i < bridge.size(); i++) {
			bridge[i].second++;
		}

		if (!bridge.empty() && bridge.front().second >= L) {
			cap -= bridge.front().first;
			bridge.pop_front();
		}

		if (!trucks.empty() && cap + trucks.front() <= W) {
			cap += trucks.front();
			bridge.push_back({ trucks.front(),0});
			trucks.pop_front();
		}
		
	}
	cout << time;
}