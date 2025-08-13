#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
typedef pair<int, string> pis;
int N;
vector<bool> visited(10000);
string k = "DSLR";
string bfs(int A , int B) {
	queue<pis> q;
	q.push({ A,"" });

	while (!q.empty()) {
		pis current = q.front(); q.pop();
		int num = current.first;
		string st = current.second;
		//cout << num << " " << st << '\n';
		int dx[4] = { num * 2, num - 1,
			(num % 1000)*10 + num / 1000,
			(num % 10) * 1000 + num / 10 };
		visited[num] = true;
		if (num == B) {
			return st;
		}
		for (int i=0; i<4; i++) {
			int next = dx[i];
			if (next < 0) next = 9999;
			if (next > 9999) next = next % 10000;

			//cout << next << " ";
			if (visited[next]) continue;

			visited[next] = true;
			q.push({ next,st + k[i] });
		}
		//cout << '\n';

	}
	return "";
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		int A, B; 
		fill(visited.begin(), visited.end(), false);
		cin >> A >> B;
		//cout << " A B " << A << " " << B << '\n';
		cout << bfs(A,B) << '\n';
	}
}