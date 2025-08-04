#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <math.h>

//#include <bits/stdc++.h>
using namespace std;
int N, S;
vector<int> arr;
int answer = 0;

void findSum(int n, int sum,int cur,int depth) {
	if (depth == n){
		if(sum == S) answer++;
		return;
	}

	for (int i = cur; i < N; i++) {
		//cout << sum << " ";
		findSum(n,sum+arr[i],i+1, depth + 1);
	}
}
int main() {
	cin >> N >> S;
	arr.resize(N);
	for (int i = 0; i < N; i++) cin >> arr[i];

	for (int i = 1; i <= N; i++) {
		findSum(i,0, 0, 0);
	}
	
	cout << answer;
}