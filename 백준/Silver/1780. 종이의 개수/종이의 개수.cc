#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <math.h>

//#include <bits/stdc++.h>
using namespace std;
int N;
vector<vector<int>> paper;
int recursion_n = 0;
vector<int> answer = { 0,0,0 };
bool isValid(int x,int y, int size) {
	int target = paper[y][x];
	for (int i = y; i < y+size; i++) {
		for (int j = x; j < x+size; j++) {
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
void countPaper(int x,int y, int size) {

	//print(paper);
	int count = 0;
	if (isValid(x,y,size)) {
		answer[paper[y][x] + 1] += 1;
		return;
	}

	// 9개의 영역으로 나누기
	int sN = size / 3;
	for (int dy = 0; dy < 3; dy++) {
		for (int dx = 0; dx < 3; dx++) {
			countPaper(x + dx*sN, y + dy*sN, sN);
		}
	}
}
int main() {
	cin >> N;
	
	paper.assign(N, vector<int>(N));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> paper[i][j];
		}
	}

	countPaper(0,0,N);

	//cout << "재귀 횟수 : " << recursion_n << '\n';
	for (int ans : answer) {
		cout << ans << '\n';
	}
}