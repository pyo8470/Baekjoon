#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<vector>
#include<queue>
#define MAX_LEN 1000000
using namespace std;
int visited[MAX_LEN + 1];
struct state {
	int stair, count;
};
int main()
{

	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int F, S, G, U, D;
	cin >> F >> S >> G >> U >> D;

	queue<state> q;
	q.push({ S,0 });
	
	while (!q.empty()) {
		state cur = q.front(); q.pop();
		int st = cur.stair, count = cur.count;
		//cout << st << '\n';
		if (st == G) {
			cout << count;
			return 0;
		}
		visited[st] = true;
		
		int next_up = st + U;
		int next_down = st - D;

		if (next_up <= F && !visited[next_up]) {
			visited[next_up] = true;
			q.push({ next_up, count + 1 });
		}
		if (next_down >= 1 && !visited[next_down]) {
			visited[next_down] = true;
			q.push({ next_down, count + 1 });

		}
	}
	cout << "use the stairs";
	return 0;
}

