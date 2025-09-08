
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <cstring>
#define MAX_N 125
using namespace std;

int N;
int board[MAX_N][MAX_N];
int dijk[MAX_N][MAX_N];
int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};
struct State {
    int x, y, dist;
    bool operator<(const State& other) const{
        return dist > other.dist;
    }
};
inline int bfs() {
    priority_queue<State> pq;
    pq.push({ 0,0,board[0][0]});

    while (!pq.empty()) {
        State cur = pq.top(); pq.pop();
        int x = cur.x, y = cur.y, d = cur.dist;
        //cout << x << "|" << y << "|" << d << '\n';


        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            
            if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;

            if (board[ny][nx] + d >= dijk[ny][nx]) continue;
            dijk[ny][nx] = board[ny][nx] + d;
            pq.push({ nx,ny,board[ny][nx] + d });
        }
    }
    return dijk[N - 1][N - 1];
}
int main()
{
    // 코드를 작성해주세요
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int problem = 1;
    while (true) {
        cin >> N;
        if (N == 0) break;
        memset(board, 0, sizeof(board));
        memset(dijk, 0, sizeof(dijk));

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cin >> board[i][j];
                dijk[i][j] = 2e9;
            }
        }
        dijk[0][0] = board[0][0];
        cout << "Problem " << problem++ << ": " << bfs() << '\n';

    }
    return 0;
}

