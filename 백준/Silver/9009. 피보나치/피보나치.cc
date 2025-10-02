#include <iostream>
#include <algorithm>
#include <vector>

#define MAX 1000000000

using namespace std;

vector<int> fibo;

void init() {
	fibo.push_back(0);
	fibo.push_back(1);

	int i = 2;
	while (true) {
		fibo.push_back(fibo[i - 1] + fibo[i - 2]);
		if (fibo[i] >= MAX) break;
		i++;
	}
}

vector<int> solve(int num) {

	vector<int> ret;
	for (int i = fibo.size() - 1; i >= 1; i--) {
		if (fibo[i] > num) continue;
		ret.push_back(fibo[i]);
		num -= fibo[i];
	}
	return ret;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	init();

	int T; cin >> T;
	for (int t = 0; t < T; t++) {
		int num; cin >> num;
		vector<int> answer = solve(num);
		reverse(answer.begin(), answer.end());
		for (int& d : answer) {
			cout << d << ' ';
		}cout << '\n';
	}

}
