#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int MAX = 0, idx = 0;

	for (int i = 0; i < 9; i++) {
		int num; cin >> num;
		if (MAX < num) {
			MAX = num;
			idx = i;
		}
	}

	cout << MAX << '\n' << idx + 1;
}
