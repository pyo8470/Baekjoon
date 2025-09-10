#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<math.h>
#include<algorithm>
#include<vector>
#define MAX_N 20
using namespace std;
typedef long long ll;


int N, r, c;
int result;

/*
	재귀적으로 파고 들어간다
	// 어떻게?
	-> N=1될 때까지 파고 들어감


	// 예시
	// N == 2 3 1
	// 3,1 -> 왼쪽 아래

*/
int ret;
void div(int N, int r, int c, int num) {
	if (N == 1) {
		ret = num;
		ret += (r % 2) * 2 + c;
		return;
	}

	int next_r = r % (int)pow(2, N - 1); // 다음 조각의 위치
	int next_c = c % (int)pow(2, N - 1);
	int volume = (int)pow(2, 2 * (N - 1));

	int next_num = (volume * 2) * (r / (int)pow(2, N - 1)) +
		volume * (c / (int)pow(2, N - 1));
	div(N - 1, next_r, next_c, num + next_num);

}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> r >> c;
	div(N, r, c, 0);
	cout << ret;
	return 0;
}

