#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <string>
#include <iostream>
#include <climits>
using namespace std;
typedef long long ll;


int N;
vector<int> arr;
vector<int> oper(4); // + - x %
int MIN, MAX;
void solution(int index, int depth,int cal) {
	if (depth == N - 1) {
		MIN = min(cal, MIN);
		MAX = max(cal, MAX);
		return;
	}

	for (int i = 0; i < 4; i++) {
		if (oper[i]) {
			oper[i]--;
			//cout << "연산자 : " << i << "\n";
			switch (i) {
			case 0:
				solution(index + 1, depth + 1, cal + arr[index]); break;
			case 1:
				solution(index + 1, depth + 1, cal - arr[index]); break;
			case 2:
				solution(index + 1, depth + 1, cal * arr[index]); break;
			case 3:
				solution(index + 1, depth + 1, cal / arr[index]); break;
			default:break;
			}
			oper[i]++;
		}
	}
}
int main() {
	cin >> N; arr.assign(N, 0);
	for (int i = 0; i < N; i++) cin >> arr[i];
	for (int i = 0; i < 4; i++) cin >> oper[i];


	MIN = INT_MAX, MAX = INT_MIN;

	solution(1, 0, arr[0]);
	cout << MAX << '\n' << MIN;
}
