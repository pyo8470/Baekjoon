#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<algorithm>
#include<queue>
#define MAX_LEN 100000
using namespace std;


int N;
int SCV[3];
int answer = 1000;
int visited[61][61][61];
void solve(const int& depth, int scv1, int scv2, int scv3) {
	if (depth >= answer) return;

	if (scv1 <= 0 && scv2 <= 0 && scv3 <= 0) {
		answer = min(answer, depth); return;
	}


	if (scv1 < 0) scv1 = 0;
	if (scv2 < 0) scv2 = 0;
	if (scv3 < 0) scv3 = 0;
	if (visited[scv1][scv2][scv3] <= depth && 
		visited[scv1][scv2][scv3] != 0) return;


	visited[scv1][scv2][scv3] = depth;
	solve(depth + 1, scv1 - 9, scv2 - 3, scv3 - 1);
	solve(depth + 1, scv1 - 9, scv2 - 1, scv3 - 3);
	solve(depth + 1, scv1 - 3, scv2 - 9, scv3 - 1);
	solve(depth + 1, scv1 - 3, scv2 - 1, scv3 - 9);
	solve(depth + 1, scv1 - 1, scv2 - 3, scv3 - 9);
	solve(depth + 1, scv1 - 1, scv2 - 9, scv3 - 3);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	// 시작점을 잡아야하는데
	for (int i = 0; i < N; i++) {
		cin >> SCV[i];
	}

	solve(0, SCV[0], SCV[1], SCV[2]);
	cout << answer;
	return 0;
}

