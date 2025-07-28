#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>
using namespace std;


int cal(int num, int div) {
	int count = 0;
	while (num % div == 0 && num != 0) {
		num /= div;
		count++;
	}
	return count;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(0);
	int N;
	cin >> N;
	
	int countFive = 0;
	for (int i = 1; i <= N; i++) {
		if (i % 5 == 0) {
			countFive += cal(i, 5);
		}
	}
	cout << countFive;
}
