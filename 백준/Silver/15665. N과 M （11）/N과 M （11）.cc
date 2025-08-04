#include <bits/stdc++.h>

using namespace std;
int N, M;
vector<int> arr;
set<vector<int>> result;
void NM(vector<int> answer, int depth) {
	if (depth == M) {
		result.insert(answer);
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
	arr.resize(N, 0);
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	
	sort(arr.begin(), arr.end());
	NM({}, 0);

	for (auto vec : result) {
		for (int num : vec) {
			cout << num << " ";
		}
		cout << '\n';
	}
}