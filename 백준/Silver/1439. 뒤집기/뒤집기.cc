#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	string input; cin >> input;
	int count0 = 0, count1 = 0;

	if (input[0] == '0') count0++;
	else count1++;

	for (int i = 1; i < input.size(); i++) {
		if (input[i] != input[i - 1]) {
			if (input[i] == '0') count0++;
			else count1++;
		}
	}

	cout << min(count0, count1);
}