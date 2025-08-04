#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <math.h>

//#include <bits/stdc++.h>
using namespace std;
int N, M;

bool isValid(int i, vector<int>& answer) {
	for (int k : answer) {
		if (i == k) return  false;
	}
	return true;
}
void solution(int depth, vector<int> answer) {
	if (depth == M) {
		for (int i : answer) {
			cout << i << ' ';
		}
		cout << '\n';
		return;
	}
	for (int i = 1; i <= N; i++) {
		if (!isValid(i, answer)) continue;
		answer.push_back(i);
		solution(depth + 1,answer);
		answer.pop_back();
	}
}
int main() {
	
	cin >> N >> M;

	solution(0, {});
}