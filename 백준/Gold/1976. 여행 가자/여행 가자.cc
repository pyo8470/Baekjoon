#define _CRT_SECURE_NO_WARNINGS

#include<iostream>

#define MAX_LEN 200
using namespace std;

int parent[MAX_LEN];
/*
	여행가자 : 유니온 파인드
*/
int N, M;
int find(const int &x) {
	if (x == parent[x]) return x;
	return parent[x] = find(parent[x]);
}

void merge(const int&a, const int&b) {
	int A = find(a);
	int B = find(b);

	if (A == B) return;
	
	parent[A] = B;
}
int main()
{

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; i++) parent[i] = i;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int connected; cin >> connected;
			if (connected) merge(i, j);
		}
	}

	int prev; cin >> prev;
	int next;
	for (int i = 1; i < M; i++) {
		cin >> next;
		if (find(prev-1) != find(next-1)) {
			cout << "NO"; return 0;
		}
		prev = next;
	}
	cout << "YES";
	return 0;
}

