#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <math.h>

//#include <bits/stdc++.h>
using namespace std;
int N, M;
vector<bool> visited;
vector<int> arr;
void NM(vector<int> answer,int depth) {
	if (depth == M) {
		for (int k : answer) {
			cout << k << " ";
		}
		cout << '\n';
		return;
	}

	for (int i = 0; i < N; i++) {



		answer.push_back(arr[i]);
		NM(answer, depth + 1);
		answer.pop_back();

	}
}
int main() {
	cin >> N >> M;
	arr.assign(N,0);
	for (int i = 0; i < N; i++) cin >> arr[i];
	
	
	sort(arr.begin(), arr.end());
	//visited.assign(N, false);

	NM({}, 0);
}