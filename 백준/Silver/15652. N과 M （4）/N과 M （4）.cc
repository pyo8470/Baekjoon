#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <math.h>

//#include <bits/stdc++.h>
using namespace std;
int N, M;
vector<bool> visited;

void NM(int cur, vector<int> answer,int depth) {
	if (depth == M) {
		for (int k : answer) {
			cout << k << " ";
		}
		cout << '\n';
		return;
	}

	for (int i = cur; i <= N; i++) {
		answer.push_back(i);
		NM(i, answer, depth + 1);
		answer.pop_back();
	}
}
int main() {
	cin >> N >> M;

	visited.assign(N, false);
	NM(1,{}, 0);
}