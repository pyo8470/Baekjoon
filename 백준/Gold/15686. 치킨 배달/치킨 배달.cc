
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

#define MAX 1000
int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };

int N, M;
struct cord {
	int x, y;
};
int result = 2e9;
vector<vector<int>> MAP;
vector<cord> candidates;
vector<cord> living;


int dist(const cord& a, const cord& b) {
	return abs(a.x - b.x) + abs(a.y - b.y);
}
int getDistance(vector<cord>& comb) {
	int sum = 0;
	for (const cord& people : living) { // 각 거주지 당 역으로부터 떨어진 최소거리
		int distance = 2e9;
		for (const cord& station : comb) {
			distance = min(dist(people, station), distance); // 갱신
		}
		sum += distance;
	}
	return sum;
}
void combination(const int& depth, const int& idx, vector<cord>& comb) { // 모든 역에 대한 조합 생성
	if (depth == M) {
		/*cout << "조합 : " << '\n';
		for (int i = 0; i < comb.size(); i++) {
			cout << comb[i].x << " " << comb[i].y << " | ";
		}cout << '\n';*/
		result = min(getDistance(comb), result); // 조합에 대한 최소 거리
		return;
	}

	for (int i = idx; i < candidates.size(); i++) {
		comb.push_back(candidates[i]);
		combination(depth + 1, i + 1, comb);
		comb.pop_back();
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M;

	// 조합 + bfs
	MAP.assign(N, vector<int>(N));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> MAP[i][j];
			if (MAP[i][j] == 2) {
				candidates.push_back({ j,i });
			}
			else if (MAP[i][j] == 1) {
				living.push_back({ j,i });
			}
		}
	}

	vector<bool> visited;
	visited.assign(candidates.size(), false);
	vector<cord> comb;
	combination(0, 0, comb);
	cout << result;
}

