#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };

int N;
vector<vector<int>> board;

struct Shark {
    int x, y;
    int size;
    int eat;
};
Shark shark;

struct Fish {
    int x, y;
    int size;
    int dist;
};
vector<Fish> fishes;

struct State {
    int x, y, dist;
};

int bfs(int sx, int sy, int tx, int ty) {
    vector<vector<int>> dist(N, vector<int>(N, -1));
    queue<State> q;
    q.push({ sx, sy, 0 });
    dist[sy][sx] = 0;

    while (!q.empty()) {
        auto cur = q.front(); q.pop();
        int x = cur.x, y = cur.y, d = cur.dist;

        if (x == tx && y == ty) return d;

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
            if (dist[ny][nx] != -1) continue;
            if (board[ny][nx] > shark.size) continue;

            dist[ny][nx] = d + 1;
            q.push({ nx, ny, d + 1 });
        }
    }

    return 2e9; // 도달 불가
}

bool cmp(const Fish& a, const Fish& b) {
    if (a.dist != b.dist) return a.dist < b.dist;
    if (a.y != b.y) return a.y < b.y;
    return a.x < b.x;
}

void init() {
    cin >> N;
    board.assign(N, vector<int>(N));
    shark.size = 2;
    shark.eat = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> board[i][j];
            if (board[i][j] == 9) {
                shark.x = j;
                shark.y = i;
                board[i][j] = 0;
            }
            else if (board[i][j] != 0) {
                fishes.push_back({ j, i, board[i][j], 0 });
            }
        }
    }
}

int solve() {
    int result = 0;

    while (1) {
        vector<Fish> candi;
        for (auto& f : fishes) {
            if (f.size < shark.size) { // 먹을 수 있는 물고기만
                f.dist = bfs(shark.x, shark.y, f.x, f.y);
                if (f.dist != 2e9) candi.push_back(f);
            }
        }

        if (candi.empty()) break;

        sort(candi.begin(), candi.end(), cmp);
        Fish target = candi[0];
       
        // 상어 이동 및 먹기 처리
        result += target.dist;
        shark.x = target.x;
        shark.y = target.y;
        shark.eat++;
        if (shark.eat == shark.size) {
            shark.size++;
            shark.eat = 0;
        }
        board[target.y][target.x] = 0;

        // fishes 배열에서 제거
        for (int i = 0; i < (int)fishes.size(); i++) {
            if (fishes[i].x == target.x && fishes[i].y == target.y) {
                fishes.erase(fishes.begin() + i);
                break;
            }
        }

    }

    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    init();
    cout << solve();
}
