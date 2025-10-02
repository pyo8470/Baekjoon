#include <iostream>
#include <iostream>
#include <vector>

using namespace std;

int N;
int MAX = 0;
vector<int> arr;
int budget;
int cal(const int &mid) {
	int sum = 0;
	for (int &d : arr) {
		if (d <= mid)
			sum += d;
		else
			sum += mid;
	}
	return sum;
}
int solve(const int &sum) {

	if (sum <= budget) {
		return MAX;
	}
	int l = 0;
	int r = MAX;
	int ans;
	while (l <= r) {
		int mid = (l + r) / 2;

		int t_sum = cal(mid);

		if (t_sum <= budget) {
			ans = mid;
			l = mid + 1;
		} else {
			r = mid - 1;
		}
	}

//	cout << l << " " << r << '\n';
	return ans;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;

	arr.assign(N, 0);
	int sum = 0;

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		sum += arr[i];
		MAX = max(MAX, arr[i]);
	}
	cin >> budget;
	cout << solve(sum);
}
