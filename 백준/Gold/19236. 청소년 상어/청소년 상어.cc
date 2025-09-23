#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cstring>
using namespace std;

#define N 4

int dx[8] = { 0,-1,-1,-1,0,1,1,1 };
int dy[8] = { -1,-1,0,1,1,1,0,-1 };

struct Fish {
    int id, x, y, dir;
};
struct Shark {
    int x, y, dir;
};

int answer = 0;

// 물고기 이동
void fishMove(int Board[N][N], map<int, Fish>& fish_map, Shark s) {
    for (int i = 1; i <= 16; i++) {
        if (fish_map.find(i) == fish_map.end()) continue;
        Fish& moving = fish_map[i];
        int x = moving.x, y = moving.y, d = moving.dir;

        for (int rot = 0; rot < 8; rot++) {
            int nd = (d + rot) % 8;
            int nx = x + dx[nd];
            int ny = y + dy[nd];

            if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
            if (s.x == nx && s.y == ny) continue; // 상어 자리

            // 빈칸인 경우
            if (Board[ny][nx] == 0) {
                Board[ny][nx] = moving.id;
                Board[y][x] = 0;
                moving = { moving.id, nx, ny, nd };
            }
            else { // 다른 물고기와 swap
                int tid = Board[ny][nx];
                Fish& target = fish_map[tid];

                swap(Board[y][x], Board[ny][nx]);
                swap(moving.x, target.x);
                swap(moving.y, target.y);

                moving.dir = nd;
            }
            break;
        }
    }
}

// 백트래킹
void backtracking(int Board[N][N], map<int, Fish> fish_map, Shark s, int sum) {
    answer = max(answer, sum);

    // 물고기 이동
    fishMove(Board, fish_map, s);

    // 상어 이동
    int x = s.x, y = s.y, d = s.dir;
    for (int step = 1; step < N; step++) {
        int nx = x + dx[d] * step;
        int ny = y + dy[d] * step;

        if (nx < 0 || ny < 0 || nx >= N || ny >= N) break;
        if (Board[ny][nx] == 0) continue; // 빈칸이면 패스

        int tid = Board[ny][nx];
        Fish target = fish_map[tid];

        // 복사본 만들기
        int newBoard[N][N];
        memcpy(newBoard, Board, sizeof(newBoard));
        map<int, Fish> newFish = fish_map;

        newBoard[y][x] = 0;
        newBoard[ny][nx] = -1;
        newFish.erase(tid);

        Shark ns = { nx, ny, target.dir };
        backtracking(newBoard, newFish, ns, sum + tid);
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int Board[N][N];
    map<int, Fish> fish_map;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int id, d;
            cin >> id >> d;
            Board[i][j] = id;
            fish_map[id] = { id, j, i, d - 1 };
        }
    }

    // 상어 첫 먹이
    int firstID = Board[0][0];
    Shark shark = { 0, 0, fish_map[firstID].dir };
    int sum = firstID;
    fish_map.erase(firstID);
    Board[0][0] = -1;

    backtracking(Board, fish_map, shark, sum);

    cout << answer << "\n";
}
