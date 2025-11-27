#include <iostream>
#include <vector>

#define N 4

using namespace std;

typedef struct {
	int d;
}Fish;

typedef struct {
	int x;
	int y;
}Shark;

int fishCnt;

int M, S;
vector<Fish> fishMap[N][N];
vector<Fish> tempMap[N][N]; //물고기 복제 임시 공간
int smellMap[N][N]; // 0=냄새 없음, n > 0 => 냄새가 사라지기까지 남은 시간
Shark shark;

int f_dx[] = { 0, -1, -1, -1, 0, 1, 1, 1 };
int f_dy[] = { -1, -1, 0, 1, 1, 1, 0, -1 };

void input() {

	cin >> M >> S;
	int f_x, f_y, f_d;
	for (int i = 0; i < M; ++i) {
		cin >> f_x >> f_y >> f_d;
		f_x -= 1;
		f_y -= 1;
		f_d -= 1;
		fishMap[f_x][f_y].push_back(Fish{f_d});
	}

	fishCnt = M;

	cin >> shark.x >> shark.y;
	shark.x -= 1;
	shark.y -= 1;
}

/*
* 현재 물고기들을 임시맵에 복사
*/
void copyFish() {
	for (int x = 0; x < N; ++x) {
		for (int y = 0; y < N; ++y) {
			tempMap[x][y].assign(fishMap[x][y].begin(), fishMap[x][y].end());
		}
	}
}

/*
* 1. 물고기들을 이동(지역 임시맵에 저장)
* 2. 임시맵에 있는 물고기들을 실제 맵에 적용
*/
void moveFish() {

	vector<Fish> l_tempMap[N][N];


	for (int x = 0; x < N; ++x) {
		for (int y = 0; y < N; ++y) {
			
			if (fishMap[x][y].size() == 0) continue;

			bool flag = false;
			for (Fish& f : fishMap[x][y]) {
				
				for (int offset = 0; offset < 8; ++offset) {
					int new_d = (f.d + 8 - offset) % 8;

					int n_x = x + f_dx[new_d];
					int n_y = y + f_dy[new_d];
					if (n_x < 0 || n_x >= N || n_y < 0 || n_y >= N) continue;
					if (smellMap[n_x][n_y] > 0) continue;
					if (shark.x == n_x && shark.y == n_y) continue;

					//갈 수 있음 -> 방향 갱신 + 임시 공간으로 이동
					f.d = new_d;
					l_tempMap[n_x][n_y].push_back(f);
					flag = true;
					break;
				}
			}

			if (not flag) {
				l_tempMap[x][y].insert(l_tempMap[x][y].end(),
					fishMap[x][y].begin(), fishMap[x][y].end());
			}
		}
	}

	for (int x = 0; x < N; ++x) {
		for (int y = 0; y < N; ++y) {
			fishMap[x][y].clear();
			fishMap[x][y].assign(l_tempMap[x][y].begin(), l_tempMap[x][y].end());
		}
	}
}


int s_dx[] = { -1, 0, 1, 0 };
int s_dy[] = { 0, -1, 0, 1 };

int visit[N][N];

int maxEatCnt;
vector<int> realSharkPath;

void dfs(int x, int y, int k, int fishCnt, vector<int>& path) {
	if (k == 3) {

		if (maxEatCnt < fishCnt) {
			maxEatCnt = fishCnt;
			realSharkPath.clear();
			realSharkPath.assign(path.begin(), path.end());
		}

		return;
	}

	for (int d = 0; d < 4; ++d) {
		int n_x = x + s_dx[d];
		int n_y = y + s_dy[d];
		if (n_x < 0 || n_x >= N || n_y < 0 || n_y >= N) continue;

		if (visit[n_x][n_y]) {
			path.push_back(d);
			dfs(n_x, n_y, k + 1, fishCnt, path);
			path.pop_back();
		}
		else {
			visit[n_x][n_y] = true;
			path.push_back(d);
			dfs(n_x, n_y, k + 1, fishCnt + fishMap[n_x][n_y].size(), path);
			path.pop_back();
			visit[n_x][n_y] = false;
		}
	}
}


/*
* 상어를 이동 시킴
*/
void moveShark() {
	
	maxEatCnt = -1;
	realSharkPath.clear();

	//현재 상어 위치에 대해서 dfs
	vector<int> path;
	dfs(shark.x, shark.y, 0, 0, path);

	
	for (int d : realSharkPath) {
		shark.x += s_dx[d];
		shark.y += s_dy[d];

		if (fishMap[shark.x][shark.y].size() > 0) {
			smellMap[shark.x][shark.y] = 3;
			fishCnt -= fishMap[shark.x][shark.y].size();
			fishMap[shark.x][shark.y].clear();
		}
	}

}

/*
* 냄새 카운트 -1
*/
void renewSmell() {

	for (int x = 0; x < N; ++x) {
		for (int y = 0; y < N; ++y) {
			if (smellMap[x][y] > 0) smellMap[x][y] -= 1;
		}
	}
}

/*
* 임시맵에 복제해뒀던 물고기들을 실제맵에 반영
*/
void copyMap() {
	for (int x = 0; x < N; ++x) {
		for (int y = 0; y < N; ++y) {
			fishMap[x][y].insert(fishMap[x][y].end(),
				tempMap[x][y].begin(), tempMap[x][y].end());

			fishCnt += tempMap[x][y].size();
			tempMap[x][y].clear();
		}
	}
}


int main() {

	input();

	for (int r = 0; r < S; ++r) {
		copyFish();
		moveFish();
		moveShark();
		renewSmell();
		copyMap();
	}

	cout << fishCnt << endl;
	return 0;
}