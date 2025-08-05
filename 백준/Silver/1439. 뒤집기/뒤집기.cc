#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	string input; cin >> input;
	vector<bool> arr;
	for (char ch : input) {
		arr.push_back(int(ch - '0'));
	}


	bool start = arr[0];

	int result = 0;
	bool mode = false;
	for (int i = 1; i < arr.size(); i++) {
		if (start != arr[i]) {
			if (mode) continue;
			else result++;
			mode = true;
		}
		else {
			mode = false;
		}
	}
	cout << result;
}