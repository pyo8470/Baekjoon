#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<math.h>
using namespace std;

int solution() {
	long long x, y;
	cin >> x >> y;

	long long MAX = x + y;
	long long start_n = (long long)sqrt((x + y) * 4);
	long long n;
	for (n = start_n; n >= 1; n--) {
		if (n * (n + 1) / 2 == MAX) break;
	}

	if (n < 1) return -1;
	// 이제 찾아봅시다.

	// 윤호 : x 동혁이 : y
	// 윤호의 횟수가 최소가 되려면 그냥 위에서부터 나눠주면 된다.
	int answer = 0;
	for (int round = n; round >= 1; round--) {
		if (x - round >= 0) {
			x -= round;
			answer++;
		}
		else y -= round;
	}
	return answer;

}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cout << solution();
	
}