
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#define MAX_H 1000
#define MAX_W 1000
using namespace std;
int H, W;

int dx[8] = { 0,1,1,1,0,-1,-1,-1 };
int dy[8] = { -1,-1,0,1,1,1,0,-1 };
vector<string> beach;
void print() {
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cout << beach[i][j];
        }cout << '\n';
    }cout << '\n';
}

struct State {
    int x, y;
};
int main()
 {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin >> H >> W;

    deque<State> q;
    beach.assign(H,"");
    for (int i = 0; i < H; i++) {
        cin >> beach[i];
    }
    
    for (int y = 0; y < H; y++) {
        for (int x = 0; x < W; x++) {

            if (beach[y][x] == '.' || beach[y][x] == '9') continue;
            int b_count = 0;
            for (int i = 0; i < 8; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (nx < 0 || ny < 0 || nx >= W || ny >= H) continue;
                if (beach[ny][nx] != '.') continue;
                b_count++;
            }
            int depth = int(beach[y][x] - '0');
            if (depth <= b_count) {
                q.push_back({ x,y });
            }
        }
    }
    vector<vector<bool>> inq(H, vector<bool>(W, false));
    int answer = 0;
    if (q.empty()) {
        cout << answer;
        return 0;
    }
    while (!q.empty()) {
        int qs = q.size();
        deque<State> next;
        //print();
        deque<State> change;
        while (qs--) {
            State cur = q.front(); q.pop_front();
            int x = cur.x, y = cur.y;

            if (beach[y][x] == '.') continue; // 이미 무너진 칸은 스킵
            int blank = 0;
            for (int d = 0; d < 8; d++) {
                int nx = x + dx[d];
                int ny = y + dy[d];
                if (nx < 0 || ny < 0 || nx >= W || ny >= H) continue;
                if (beach[ny][nx] == '.') blank++;
            }

            if (blank >= int(beach[y][x] - '0')) {
                change.push_back({ x,y });
                // 무너진 모래 주변 모래를 다시 후보에 넣음
                for (int d = 0; d < 8; d++) {
                    int nx = x + dx[d];
                    int ny = y + dy[d];
                    if (nx < 0 || ny < 0 || nx >= W || ny >= H) continue;
                    if (beach[ny][nx] != '.' && beach[ny][nx] != '9' && !inq[ny][nx]) {
                        next.push_back({ nx, ny });
                        inq[ny][nx] = true;
                    }
                }
            }
        }
        if (change.empty())break;
        for (const State& cur : change) {
            beach[cur.y][cur.x] = '.';
        }
        change.clear();
        q = next;
        for (auto& n : q) {
            inq[n.y][n.x] = false;
        }
        answer++;
        
    }
    cout << answer;
    return 0;
}

