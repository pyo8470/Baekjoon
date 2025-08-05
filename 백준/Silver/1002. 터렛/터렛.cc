#include <vector>
#include <algorithm>
#include <iostream>
#include <math.h>
using namespace std;
typedef long long ll;



int main() {
	int T; cin >> T;
	for (int t = 0; t < T; t++) {
		int x1, x2, y1, y2, r1, r2;
		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
		

		int distance = abs(x2 - x1) * abs(x2 - x1) + abs(y2 - y1) * abs(y2 - y1);
		
		
		int Rd = (r1 + r2) * (r1 + r2);
		int Rm = (r1 - r2) * (r1 - r2);
		int result = -1;
		if (Rd > distance) {
			// 두 점에서 만나는 경우
			if (Rm < distance) {
				result = 2;
			}
			// 내부에서 접하는 경우
			else if(Rm == distance) {
				result = 1;
			}
			else {
				// 5,6 번 케이스
				result = 0;
			}
		}
		// 외부에서 접하는 경우
		else if (Rd == distance) {
			result = 1;
		}
		else {
			result = 0;
		}

		if (x1 == x2 && y1 == y2 && r1 == r2) {
			result = -1;
		}
		cout << result << '\n';
	}
}
