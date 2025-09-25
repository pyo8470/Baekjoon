//#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

#define MAX 200001

bool visited[MAX];
int N, K;

int cal(const int &x, const int &i) {
	switch (i) {
	case 0:
		return x + 1;
	case 1:
		return x - 1;
	case 2:
		return 2 * x;
	}
}
void init() {
	cin >> N >> K;
}

struct State {
	int x, count;
};
int bfs(int s) {
	queue<State> q;
	q.push( { s, 0 });

	while (!q.empty()) {
		State cur = q.front();
		q.pop();

		int x = cur.x, count = cur.count;
		visited[x] = true;
		if (x == K)
			return count;
		for (int i = 0; i < 3; i++) {
			int nx = cal(x, i);
			if (nx < 0 || nx > MAX || visited[nx])
				continue;
			q.push( { nx, count + 1 });
			visited[nx] = true;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	init();
	cout << bfs(N);
}
