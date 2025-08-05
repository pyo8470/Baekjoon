#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
typedef long long ll;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;
	priority_queue<ll, vector<ll>, greater<ll>> pq;

	for (int i = 0; i < n; i++) {
		int num; cin >> num;
		pq.push(num);
	}

	for (int i = 0; i < m; i++) {
		ll a, b;
		a = pq.top(); pq.pop();
		b = pq.top(); pq.pop();
		
		pq.push(a + b);
		pq.push(a + b);
	}

	ll result = 0;
	while (!pq.empty()) {
		result += pq.top(); pq.pop();
	}
	cout << result;
}