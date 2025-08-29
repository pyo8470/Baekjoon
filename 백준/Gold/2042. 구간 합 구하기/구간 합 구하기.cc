#include<iostream>
#include<queue>
#include<vector>
using namespace std;
#define MAX_N 1000000
int N, M, K;

long long tree[4 * MAX_N];
long long arr[MAX_N];
void build(int node, int start, int end, long long arr[]) {
	if (start == end) {
		tree[node] = arr[start];
		return;
	}
	int mid = (start + end) / 2;
	build(2 * node, start, mid, arr);
	build(2 * node + 1, mid + 1, end, arr);
	tree[node] = tree[2 * node] + tree[2 * node + 1];
}

long long query(int node, int start, int end, int l, int r) {
	if (r < start || end < l) return 0;
	if (l <= start && end <= r) return tree[node];
	int mid = (start + end) / 2;
	return query(2 * node, start, mid, l, r) + query(2 * node + 1, mid + 1, end, l, r);
}

void update(int node, int start, int end, int idx, long long val) {
	if (idx < start || idx > end) return;
	if (start == end) {
		tree[node] = val;
		return;
	}
	int mid = (start + end) / 2;
	update(node * 2, start, mid, idx, val);
	update(node * 2 + 1, mid + 1, end, idx, val);
	tree[node] = tree[node * 2] + tree[node * 2 + 1];
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N >> M >> K;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	build(1, 0, N - 1, arr);
	for (int i = 0; i < M + K; i++) {
		int a, b; long long c; cin >> a >> b >> c;
		if (a == 1) { // 변경
			update(1, 0, N - 1, b - 1, c);
		}
		else { // 구간합
			cout << query(1, 0, N - 1, b - 1, c - 1) << '\n';
		}
	}
}
