#include<iostream>
#include<queue>
#include<vector>
using namespace std;
#define MAX_N 100000
int N, M;
long long INF = 2e18;

struct Node {
	long long MIN;
	long long MAX;
};

Node Tree[4 * MAX_N];
long long arr[MAX_N];

Node getMinMAX(Node& a, Node& b) {
	return { min(a.MIN,b.MIN), max(a.MAX,b.MAX) };
}

void build(const int& node, const int& start, const int& end) {
	if (start == end) {
		Tree[node] = { arr[start],arr[start] };
		return;
	}

	int mid = (start + end) / 2;
	build(node * 2, start, mid);
	build(node * 2 + 1, mid + 1, end);
	Tree[node] = getMinMAX(Tree[node * 2], Tree[node * 2 + 1]);
}

Node query(const int& node, const int& start, const int& end, const int& l, const int& r) {
	if (r < start || l > end) return { INF,-INF }; // 범위 out
	if (l <= start && end <= r) return Tree[node];
	int mid = (start + end) / 2;
	Node left = query(node * 2, start, mid, l, r);
	Node right = query(node * 2+1, mid+1, end, l, r);
	return getMinMAX(left, right);
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	cin >> N >> M;
	for (int i = 0; i < N; i++) cin >> arr[i];

	build(1, 0, N - 1);

	for (int i = 0; i < M; i++) {
		int l, r;
		cin >> l >> r;
		Node result = query(1, 0, N - 1, l-1, r-1);
		cout << result.MIN << " " << result.MAX << '\n';
	}
}
