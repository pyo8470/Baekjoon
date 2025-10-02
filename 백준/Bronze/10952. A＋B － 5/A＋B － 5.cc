#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;





int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	while (true) {
		int A, B; cin >> A >> B;
		if (A || B) cout << A + B << '\n';
		else break;
	}
}
