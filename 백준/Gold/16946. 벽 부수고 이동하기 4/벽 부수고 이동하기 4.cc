#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include <unordered_set>
#include <vector>
using namespace std;
// 16946번 벽부수고 이동하기4
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
int N, M;

vector<string> MAP;
vector<int> zero_count;
int zero_idx;
bool visited[1000][1000];
vector<vector<int>> num_MAP;
// 서로 연결되있는 0끼리..
void bfs(int sx, int sy) {
    queue<pair<int, int>> q;
    q.push({sx, sy});

    visited[sy][sx] = 0;
    num_MAP[sy][sx] = zero_idx;

    int cnt = 0;
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        visited[sy][sx] = 1;
        cnt++;

        num_MAP[y][x] = zero_idx;
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 0 || ny < 0 || nx >= M || ny >= N)
                continue;
            if (visited[ny][nx] || MAP[ny][nx] == '1')
                continue;
            visited[ny][nx] = true;
            q.push({nx, ny});
        }
    }

    zero_count.push_back(cnt);
}
int solve(const int& x, const int& y) {
    unordered_set<int> a_num_set;
    int ret = 1;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        if (nx < 0 || ny < 0 || nx >= M || ny >= N)
            continue;
        if (MAP[ny][nx] == '1')
            continue;

        int num = num_MAP[ny][nx];
        if (a_num_set.find(num) != a_num_set.end())
            continue;
        a_num_set.insert(num);
        ret += zero_count[num];
    }
    return ret;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> N >> M;
    MAP.resize(N);
    memset(visited, 0, sizeof(visited));
    zero_idx = 0;
    num_MAP.assign(N, vector<int>(M, -1));
    for (int i = 0; i < N; i++) {
        cin >> MAP[i];
    }

    // 0 군집 찾기
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < M; x++) {
            if (MAP[y][x] == '1' || visited[y][x])
                continue;
            bfs(x, y);
            zero_idx++;
        }
    }

    
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < M; x++) {
            if (MAP[y][x] == '1') {
                cout << solve(x, y) % 10;
            } else {
                cout << 0;
            }
        }
        cout << '\n';
    }
}
