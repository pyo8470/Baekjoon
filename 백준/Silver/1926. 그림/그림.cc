#include <iostream>
#include <unordered_map>
#include <string>
#include <stack>
#include <vector>
#include <deque>
using namespace std;
int n, m;
int COUNT = 0;
int MAX = 0;
vector<vector<int>> board;
vector<vector<bool>> visited;

int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };
void BFS(int x, int y) {
    
    // 좌표, 넓이
    deque<tuple<int,int>> dq = { {x,y} };
    visited[y][x] = true;
    int nx, ny;
    int area = 1;
    while (!dq.empty()) {
        auto [cx, cy] = dq.front();
        dq.pop_front();

        visited[cy][cx] = true;
        for (int dir = 0; dir < 4; dir++) {
            nx = cx + dx[dir];
            ny = cy + dy[dir];
            if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
            if (visited[ny][nx] || board[ny][nx] == 0) continue;
            // 넓이 체크 해야함
            // 찾는 도중에도 중복 체크를 해야함
            visited[ny][nx] = true;
            dq.push_back(tuple(nx, ny));
            area++;
        }
    }
    MAX = max(area, MAX);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    board.assign(n, vector<int>(m));
    visited.assign(n, vector<bool>(m, false));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }

    for (int y = 0; y < n; y++) {
        for (int x = 0; x < m; x++) {
            if (!visited[y][x] && board[y][x] != 0) {
                BFS(x, y); 
                COUNT++;
            }
        }
    }
    cout << COUNT << endl;
    cout << MAX << endl;
}
