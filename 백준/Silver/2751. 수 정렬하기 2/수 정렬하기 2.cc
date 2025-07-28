#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>
using namespace std;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(0);
	int N; cin >> N;
	vector<int> num(N);

	for (int i = 0; i < N; i++) cin >> num[i];
	sort(num.begin(), num.end());

	for (int i = 0; i < N; i++) {
		cout << num[i] << '\n';
	}
}
