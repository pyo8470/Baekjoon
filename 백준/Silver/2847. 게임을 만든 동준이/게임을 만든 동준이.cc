#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
int N;
vector<int> arr;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> N;

	for (int i = 0; i < N; i++) {
		int n; cin >> n;
		arr.push_back(n);
	}

	int result = 0;
	for (int i = N-2; i >= 0 ; i--) {
		if (arr[i] >= arr[i + 1]) {
			result += (arr[i] - (arr[i + 1] - 1));
			arr[i] = arr[i + 1] - 1;
		}
	}
	cout << result;
}