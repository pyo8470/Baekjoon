#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
vector<vector<int>> board;

int getSum(int x, int y,vector<vector<pair<int, int>>> &shape) {
    
    int ret = 0;
    for (int i = 0; i < shape.size(); i++) {
        int sum = 0;
        for (pair<int, int> direction : shape[i]) {
            int dx, dy;
            dx = direction.second;
            dy = direction.first;
            
            int nx, ny;
            nx = x + dx;
            ny = y + dy;

            if (0 > nx || nx >= M || 0 > ny || ny >= N) continue;
            
            sum += board[ny][nx];
        }
        ret = max(sum, ret);
    }
    return ret;
    
}
int main() {
    cin >> N >> M;
    board.assign(N, vector<int>(M));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> board[i][j];
        }
    }

    
    // 모양에 따른 벡터

    vector<vector<pair<int, int>>> line = {
        {{0,0},{0,1},{0,2},{0,3}},
        {{0,0},{1,0},{2,0},{3,0}}
    };
    vector<vector<pair<int, int>>> square = {
        {{0,0},{0,1},{1,0},{1,1}}
    };
    vector<vector<pair<int, int>>> Lshape = {
        {{0,0},{1,0},{2,0},{2,1}}, // L
        {{0,0},{0,1},{0,2},{-1,2}}, // 우측 90도
        {{0,0},{-1,0},{-2,0},{-2,-1}}, // 180도
        {{0,0},{0,-1},{0,-2},{1,-2}}, // 270도

        // 대칭
        {{0,0},{1,0},{2,0},{2,-1}}, // 
        {{0,0},{0,1},{0,2},{1,2}}, // 우측 90도
        {{0,0},{-1,0},{-2,0},{-2,1}}, // 180도
        {{0,0},{0,-1},{0,-2},{-1,-2}} // 270도
    };
    vector<vector<pair<int, int>>> legShape = {
        {{-1,0},{0,0},{0,1},{1,1}},
        {{0,-1},{0,0},{-1,0},{-1,1}},

        {{1,0},{0,0},{0,1},{-1,1}},
        {{0,-1},{0,0},{1,0},{1,1}}
    };
    vector<vector<pair<int, int>>> fuckyouShape = {
        {{0,0},{0,-1},{0,1},{1,0}}, // ㅜ
        {{0,0},{-1,0},{1,0},{0,1}}, // ㅏ
        {{0,0},{0,-1},{0,1},{-1,0}}, // ㅗ
        {{0,0},{-1,0},{1,0},{0,-1}}, // ㅓ
    };

    int result = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            result = max(getSum(j, i, line),result);
            result = max(getSum(j, i, square),result);
            result = max(getSum(j, i, Lshape),result);
            result = max(getSum(j, i, legShape),result);
            result = max(getSum(j, i, fuckyouShape),result);
        }
    }
    cout << result;
}
