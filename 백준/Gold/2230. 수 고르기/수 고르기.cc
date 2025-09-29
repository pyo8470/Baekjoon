#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int N, M;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M;
	set<int> s;
	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		s.insert(num);
	}

	vector<int> arr(s.begin(), s.end());
	int ans = 2e9;

	int l = 0, r = 0;
	while (r < arr.size()) {
		int diff = arr[r] - arr[l];
		if (diff >= M) {
			ans = min(ans, diff);
			if (l + 1 < r)
				l++; // 왼쪽 포인터 이동
			else
				r++;
		} else {
			r++; // 차이가 작으면 오른쪽 포인터 이동
		}
	}

	cout << ans;
}
