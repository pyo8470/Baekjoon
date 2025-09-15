#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<algorithm>
#include<deque>
#include<vector>
#define MAX_LEN 100000
using namespace std;


int N, K;
int ans = 0;

struct State{
	bool robot = false;
	int dur;
};
deque<State> belt;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> K;
	
	for (int i = 0; i < 2 * N; i++) {
		int dur; cin >> dur;
		belt.push_back({false,dur});
	}

	while (true) {
		// 벨트 회전
		ans++;

		belt.push_front(belt.back());
		belt.pop_back();
		// 내리는 위치
		if (belt[N - 1].robot) belt[N - 1].robot = false;


		// 로봇 움직임
		for (int i = 2 * N - 1; i >= 0; i--) {
			if (!belt[i].robot) continue;
			int next_idx = (i + 1) % (2 * N);

			if (belt[next_idx].dur < 1 || belt[next_idx].robot) continue;

			belt[next_idx].dur = max(0,belt[next_idx].dur-1);
			belt[next_idx].robot = true;
			// 내리는 위치
			if(next_idx == N-1) belt[next_idx].robot = false;
			belt[i].robot = false;
		}

		if (belt[0].dur != 0) {
			belt[0].robot = true;
			belt[0].dur = max(0, belt[0].dur - 1);
		}

		int broken = 0;
		for (int i = 0; i < 2 * N; i++) {
			if (belt[i].dur <= 0) broken++;
			if (broken >= K) {
				cout << ans << '\n';
				return 0;
			}
		}
	}
}

