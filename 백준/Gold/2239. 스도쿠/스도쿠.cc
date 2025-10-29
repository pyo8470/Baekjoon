#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

// 열, 행 ,3x3 박스에 들어 있는 수들

bool found = false;
int N = 9;
void print(vector<unordered_set<int>> &sub) {
    for (auto &s : sub) {
        for (auto it = s.begin(); it != s.end(); it++) {
            cout << *it;
        }
        cout << '\n';
    }
    cout << '\n';
}
void print_sudoku(vector<vector<int>> &sudoku) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << sudoku[i][j] << "";
        }
        cout << '\n';
    }
}

void dfs(const int &depth, vector<vector<int>> &sudoku, vector<unordered_set<int>> &cols,
         vector<unordered_set<int>> &rows, vector<unordered_set<int>> &boxes, vector<pair<int, int>> &zeros) {
    if (found)
        return;
    if (depth == zeros.size()) {
        print_sudoku(sudoku);
        found = true;
        return;
    }

    pair<int, int> &cord = zeros[depth];
    int x = cord.first, y = cord.second;
    int box_idx = (y / 3) * 3 + x / 3;
    for (int i = 1; i <= 9; i++) {
        if (rows[y].count(i) || cols[x].count(i) || boxes[box_idx].count(i))
            continue;

        sudoku[y][x] = i;
        cols[x].insert(i);
        rows[y].insert(i);
        boxes[box_idx].insert(i);
        dfs(depth + 1, sudoku, cols, rows, boxes, zeros);
        boxes[box_idx].erase(i);
        rows[y].erase(i);
        cols[x].erase(i);
        sudoku[y][x] = 0;
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    vector<unordered_set<int>> cols;
    vector<unordered_set<int>> rows;
    vector<unordered_set<int>> boxes;

    vector<vector<int>> sudoku;

    vector<pair<int, int>> zeros;

    sudoku.resize(N, vector<int>(N));

    cols.resize(N, {});
    rows.resize(N, {});
    boxes.resize(N, {});
    string s;
    for (int i = 0; i < N; i++) {
        cin >> s;
        // cout << "읽은 문자열: [" << s << "] 길이: " << s.size() << '\n';

        for (int j = 0; j < N; j++) {
            sudoku[i][j] = int(s[j] - '0');

            if (sudoku[i][j] == 0) {
                // x ,y
                zeros.push_back({j, i});
                continue;
            }
            int idx = (i / 3) * 3 + j / 3;
            cols[j].insert(sudoku[i][j]);
            rows[i].insert(sudoku[i][j]);

            boxes[idx].insert(sudoku[i][j]);
        }
    }

    dfs(0, sudoku, cols, rows, boxes, zeros);
}