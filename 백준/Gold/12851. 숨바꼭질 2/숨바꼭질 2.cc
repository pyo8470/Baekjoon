#include <iostream>
#include <vector>
#include <deque>

int MAX;
using namespace std;
typedef pair<int, int> pii;
int N, M;
int ans_count = 0;
vector<int> dist;
vector<int> visit;
int bfs(int start) {
	int answer = 2e9;
	deque<int> dq;
	dq.push_back(start);

	dist[start] = 0;
	visit[start] = 1;
	ans_count = 0;

	while (!dq.empty()) {
		int num = dq.front();
		dq.pop_front();
		/*cout << num << " " << dist[num] << " " << visit[num] << '\n';
		cout << '\n';*/
		if (num == M) {
			answer = dist[num];
			ans_count = visit[num];
			break;
		}
		int dx[3] = { num + 1, num - 1, num * 2 };

		for (int i = 0; i < 3; i++) {
			int next = dx[i];
			if (next < 0 || next >= (MAX + 1) * 2) continue;
			//cout << next << " ";
			//cout << dist[next] << " " << visit[next] << '\n';
			if (dist[next] == -1) {
				dist[next] = dist[num] + 1;
				visit[next] = visit[num];
				dq.push_back(next);
			}
			/*cout << dist[next] << " " << visit[next] << '\n' << '\n';*/
			else if (dist[next] == dist[num] + 1) {
				visit[next] += visit[num];
			}
		}
		//cout << '\n';
	}
	return answer;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M;

	MAX = max(N, M);
	dist.assign((MAX + 1) * 2, -1);
	visit.assign((MAX + 1) * 2, 0);
	if (M <= N) {
		cout << N - M << '\n' << 1;
		return 0;
	}
	cout << bfs(N) << '\n';
	cout << ans_count;
}
