#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

// 열, 행 ,3x3 박스에 들어 있는 수들
vector<unordered_set<int>> cols;
vector<unordered_set<int>> rows;
vector<unordered_set<int>> boxes;

vector<vector<int>> sudoku;

vector<pair<int, int>> zeros;
bool found = false;
int N = 9;
void print_sudoku(vector<vector<int>> &sudoku) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << sudoku[i][j] << " ";
        }
        cout << '\n';
    }
}

void dfs(const int &depth, vector<vector<int>> &sudoku, vector<unordered_set<int>> &cols,
         vector<unordered_set<int>> &rows, vector<unordered_set<int>> &boxes) {
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
        if (cols[x].find(i) != cols[x].end())
            continue;
        if (rows[y].find(i) != rows[x].end())
            continue;
        if (boxes[box_idx].find(i) != boxes[box_idx].end())
            continue;

        sudoku[y][x] = i;
        cols[x].insert(i);
        rows[y].insert(i);
        boxes[box_idx].insert(i);
        dfs(depth + 1, sudoku, cols, rows, boxes);
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

    sudoku.resize(N, vector<int>(N));

    cols.resize(N, {});
    rows.resize(N, {});
    boxes.resize(N, {});
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> sudoku[i][j];

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

    dfs(0, sudoku, cols, rows, boxes);
}