#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<math.h>
#include<algorithm>
#include<vector>
#define MAX_N 20
using namespace std;
typedef long long ll;


int N;
struct cord {
	int x, y;
};

cord points[MAX_N];
bool visited[MAX_N];
double MIN;
double calculation() {
	cord vector = { 0,0 };

	for (int i = 0; i < N; i++) {
		if (visited[i]) {
			vector.x += points[i].x;
			vector.y += points[i].y;
		}
		else {
			vector.x -= points[i].x;
			vector.y -= points[i].y;
		}
	}
	ll dx = vector.x;
	ll dy = vector.y;
	//cout << dx << " | " << dy << '\n';
	double ret = sqrt(double(dx * dx) + double(dy * dy));
	//cout << "반환 -> " << ret << '\n';
	return ret;
}

void Combination(const int& depth,const int& idx) {
	if (depth == N / 2) {
		MIN = min(MIN,calculation());
		return;
	}

	for (int i = idx; i < N; i++) {
		if (visited[i]) continue;
		visited[i] = true;
		Combination(depth + 1, i + 1);
		visited[i] = false;
	}
}

int main()
{

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int T; cin >> T;
	for (int t = 0; t < T; t++) {
		cin >> N;
		MIN = 2e9;
		for (int i = 0; i < N; i++) {
			int x, y; cin >> x >> y;
			points[i] = { x,y };
		}

		Combination(0, 0);

		cout << fixed;
		cout << MIN << '\n';
	}
	
	return 0;
}

