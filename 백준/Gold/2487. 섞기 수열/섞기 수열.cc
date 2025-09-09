#define _CRT_SECURE_NO_WARNINGS

#include <vector>
#include <iostream>
#include <unordered_set>
#include <math.h>
using namespace std;
int N;
vector<vector<int>> cycles;
vector<int> arr;

int gcd(int a, int b) {
	while (b != 0) {
		int t = a % b;
		a = b;
		b = t;
	}
	return a;
}
int lcm(int a, int b) {
	return a / gcd(a, b) * b;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	arr.assign(N, 0);
	for (int i = 0; i < N; i++) cin >> arr[i];
	vector<bool> visited(N, false);
	int cn = 0;
	for (int i = 0; i < N; i++) {
		if (arr[i] == i + 1 || visited[i]) continue;
		int start = arr[i];
		vector<int> t;
		while (true) {
			t.push_back(start);
			visited[start - 1] = true;
			int next = arr[start - 1];
			start = next;
			if (start == arr[i]) break;
		}
		cycles.push_back(t);
	}


	int answer = 0;
	if (!cycles.empty()) {
		answer = cycles[0].size();
		for (int i = 1; i < cycles.size(); i++) {
			answer = lcm(answer, cycles[i].size());
		}
	}
	cout << answer;
	return 0;
}

