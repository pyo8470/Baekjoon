#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <math.h>

//#include <bits/stdc++.h>
using namespace std;
int N;
int recursion_n = 0;
vector<int> answer = { 0,0,0 };
bool isValid(int n, vector<vector<int>> paper,int target) {

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (target != paper[i][j]) return false;
		}
	}
	return true;
}

void print(vector<vector<int>> arr) {
	for (int i = 0; i < arr.size(); i++) {
		for (int j = 0; j < arr.size(); j++) {
			cout << arr[i][j] << " ";
		}
		cout << '\n';
	}
	cout << '\n';
}
void getSlice(int sX,int sY, vector<vector<int>> &slice, vector<vector<int>> &paper) {

	int k = slice.size();
	for (int i = 0; i < slice.size(); i++) {
		for (int j = 0; j < slice.size(); j++) {
			slice[i][j] = paper[i + sY* k][j + sX* k];
		}
	}
}
void recursion(vector<vector<int>> &paper) {
	int n = paper.size();
	recursion_n++;
	//print(paper);
	int count = 0;
	int target = paper[0][0];
	if (isValid(n, paper, target)) {
		answer[target + 1] += 1;
		return;
	}

	// 9개의 영역으로 나누기
	int sN = n / 3;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			vector<vector<int>> slice(sN, vector<int>(sN));
			getSlice(j, i, slice, paper);
			recursion(slice);
		}
	}
	
}
int main() {
	cin >> N;
	vector<vector<int>> paper(N, vector<int>(N));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> paper[i][j];
		}
	}

	/*vector<vector<int>> slice(1, vector<int>(1));
	getSlice(0, 0, slice, paper);*/

	recursion(paper);

	//cout << "재귀 횟수 : " << recursion_n << '\n';
	for (int ans : answer) {
		cout << ans << '\n';
	}
}