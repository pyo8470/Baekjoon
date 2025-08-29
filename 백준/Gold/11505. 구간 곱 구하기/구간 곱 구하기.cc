#include<iostream>
#include<queue>
#include<vector>
using namespace std;
#define MAX_N 1000000
#define MOD 1000000007
int N, M, K;

long long tree[MAX_N * 4];
int arr[MAX_N];

void build(const int& node, const int& start, const int& end) {
	if (start == end) {
		tree[node] = arr[start] % MOD; return;
	}
	int mid = (start + end) / 2;
	build(node * 2, start, mid);
	build(node * 2 + 1, mid + 1, end);
	tree[node] = tree[node * 2] * tree[node * 2 + 1] %MOD;
}

long long query(const int& node, const int& start, const int& end, const int& l, const int& r) {
	if (l > end || r < start) return 1;
	if (l <= start && end <= r) return tree[node] % MOD;
	int mid = (start + end) / 2;
	long long p1 = query(node * 2, start, mid, l, r) % MOD;
	long long p2 = query(node * 2 + 1, mid + 1, end, l, r) % MOD;
	return p1 * p2 % MOD;
}

void update(const int& node, const int& start, const int& end, const int& idx, const int& val) {
	if (idx < start || idx > end) return;
	if (start == end) {
		arr[idx] = val;
		tree[node] = val;
		return;
	}
	int mid = (start + end) / 2;
	update(node * 2, start, mid, idx, val);
	update(node * 2 + 1, mid + 1, end, idx, val);
	tree[node] = tree[node * 2] * tree[node * 2 + 1] % MOD;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N >> M >> K;

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	build(1, 0, N - 1);
	for (int i = 0; i < M + K; i++) {
		int a, b, c; cin >> a >> b >> c;
		if (a == 1) { // update
			update(1, 0, N - 1, b-1, c);
		}
		else { // query
			cout << query(1, 0, N - 1, b - 1, c - 1) % MOD << '\n';
		}
	}
}
