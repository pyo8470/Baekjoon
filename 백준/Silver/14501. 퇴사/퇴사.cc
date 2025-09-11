#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<vector>
using namespace std;

struct TimeTable {
	int Time; int Price;
};
int N;
vector<TimeTable> table;
int result = 0;
void solve(const int& date, const int& price) {

	// 해당 날짜에 한다(날짜에 적혀있는 날로)
	// 만약에 넘어가면? 안 한다
	//cout << date << " | " << price << '\n';
	if (date > N) {
		return;
	}
	if (date == N) {
		result = max(result, price);
		return;
	}
	int nextDate = date + table[date].Time;
	if (nextDate <= N) {
		solve(nextDate, price + table[date].Price);
	}
	solve(date + 1, price);
	// 안 한다(다음날로)
}
int main()
{
	
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> N; table.assign(N, {});

	for (int i = 0; i < N; i++) {
		int t, p; cin >> t >> p;
		table[i] = { t,p };
	}

	solve(0, 0);
	cout << result;
		
	return 0;
}

