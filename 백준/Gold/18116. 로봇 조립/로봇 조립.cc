#include<iostream>
#define MAX 1000001
using namespace std;
int parent[MAX];
int u_size[MAX];

int find(int x) {
	if (parent[x] == x) return x;

	return parent[x] = find(parent[x]);
}

void merge(int a, int b) {
	a = find(a);
	b = find(b);

	if (a != b) {
		if (u_size[a] >= u_size[b])
			swap(a, b);
		parent[a] = b;
		u_size[b] += u_size[a];
	}
}
int main() {
	ios_base::sync_with_stdio(NULL);
	cin.tie(0);
	cout.tie(0);
	for (int i = 0; i < MAX; i++) {
		parent[i] = i;
		u_size[i] = 1;
	}
	int N; cin >> N;
	for (int i = 0; i < N; i++) {
		char command; 
		cin >> command;
		if (command == 'I') {
			int a, b; cin >> a >> b;
			merge(a, b);
		}
		else {
			int x; cin >> x;
			cout << u_size[find(x)] << '\n';
		}
	}
}