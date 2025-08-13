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
	queue<int> q;
	vector<int> parent(10000, -1);
	vector<char> result(10000,0);
	q.push(A);

	while (!q.empty()) {
		int num = q.front(); q.pop();
		//cout << num << " " << st << '\n';
		int dx[4] = { num * 2 % 10000, 
			num == 0 ? 9999 : num-1,
			(num % 1000)*10 + num / 1000,
			(num % 10) * 1000 + num / 10 };

		visited[num] = true;
		if (num == B) {
			break;
		}
		for (int i=0; i<4; i++) {
			int next = dx[i];
			if (next < 0) next = 9999;
			if (next > 9999) next = next % 10000;

			//cout << next << " ";
			if (visited[next]) continue;

			visited[next] = true;
			parent[next] = num;
			result[next] = k[i];
			q.push(next);
		}
		//cout << '\n';

	}
	
	string ret;
	for (int cur = B; cur != A; cur = parent[cur]) {
		ret.push_back(result[cur]);
	}
	reverse(ret.begin(), ret.end());
	return ret;
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