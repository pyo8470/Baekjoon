#include <iostream>
#include <vector>
#include <climits>
using namespace std;
#define MAX 100000
int N;
int M;
int arr[MAX];


struct Node {
	int val, index;

	bool operator<(const Node& other) const {
		if(val != other.val) return val < other.val;
		return index < other.index;
		
	}
}; Node tree[MAX * 4];


Node my_min(const Node& a, const Node& b) {
	return (a < b) ? a : b;
}
void build(int node, int left, int right) {

	if (left == right) {
		tree[node] = { arr[left],left }; return;
	}
	int mid = (left + right) / 2;
	build(node * 2, left, mid);
	build(node * 2 + 1, mid + 1, right);
	tree[node] = my_min(tree[node * 2], tree[node * 2 + 1]);
}

Node query(int node, int start, int end, int left, int right) {
	if (right < start || end < left) return { INT_MAX,INT_MAX};
	if (left <= start && end <= right) return tree[node];
	int mid = (start + end) / 2;
	Node p1 = query(node * 2, start, mid, left, right);
	Node p2 = query(node * 2 + 1, mid + 1, end, left, right);
	return my_min(p1, p2);
}

void update(int node, int start, int end, int idx, int val) {
	if (idx < start || idx > end) return;
	if (start == end) {
		tree[node] = { val,idx };
		return;
	}
	int mid = (start + end) / 2;
	update(node * 2, start, mid, idx, val);
	update(node * 2 + 1, mid + 1, end, idx, val);
	tree[node] = my_min(tree[node * 2], tree[node * 2 + 1]);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) cin >> arr[i];
	build(1, 0, N - 1);
	cin >> M;
	for (int i = 0; i < M; i++) {
		int c, a, b; cin >> c >> a >> b;
		if (c == 1) {
			update(1, 0, N - 1, a - 1, b);
		}
		else if (c == 2) {
			cout << query(1, 0, N - 1, a - 1, b - 1).index + 1 << '\n';
		}
	}

}
