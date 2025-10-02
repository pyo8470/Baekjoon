#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

long long A, B;
void init() {
	cin >> A >> B;
}

int solve() {
	queue<pll> q;
	q.push({A,1});

	while (!q.empty()) {
		pll cur = q.front(); q.pop();
		ll num = cur.first, count = cur.second;
		//cout << num << " -> " << count << '\n';
		
		ll n_double = num * 2;
		if (n_double == B) return count;

		if (n_double <= B) {
			q.push({ n_double,count + 1 });
		}

		ll n_add1 = num * 10 + 1;
		if (n_add1 == B) return count;
		if (n_add1 <= B) {
			q.push({ n_add1,count + 1 });
		}
	}
	return -1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	init();
	int ans = solve();
	(ans == -1) ? cout << -1 : cout << ans + 1;
}
