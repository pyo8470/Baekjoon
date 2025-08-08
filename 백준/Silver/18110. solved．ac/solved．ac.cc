#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
using namespace std;


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int N; cin >> N;
	if (N == 0) { cout << 0; return 0; }
	vector<int> Levels(N);

	for (int i = 0; i < N; i++) {
		cin >> Levels[i];
	}

	sort(Levels.begin(), Levels.end());
	int except = round(((double)N * 3 / 10) / 2) ;
	
	int len = Levels.size();
	int sum = 0;
	for (int i = except; i < len - except; i++) {
		sum += Levels[i];
	}

	int avg = round((double)sum/(N-except*2));

	cout << avg;
}