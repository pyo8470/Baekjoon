#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int N;
vector<char> oper = { '-','+',' ' };
vector<string> answers;
void evaluate(const vector<char>& operators) {
    string expr = "1";
    for (int i = 2; i <= N; i++) {
        expr += operators[i - 2];
        expr += to_string(i);
    }

    // 수식 계산
    int sum = 0;
    int num = 0;
    char sign = '+';

    for (int i = 0; i < expr.size(); i++) {
        if (expr[i] == ' ') continue;

        string tmp = "";
        tmp += expr[i];

        // 숫자일 경우 연속된 숫자 처리
        if (isdigit(expr[i])) {
            while (i + 1 < expr.size() && expr[i + 1] == ' ') {
                i += 2;
                tmp += expr[i];
            }
            num = stoi(tmp);

            if (sign == '+') sum += num;
            else sum -= num;
        }
        else { // 연산자일 때
            sign = expr[i];
        }
    }

    if (sum == 0) {
        answers.push_back(expr);
    }
}

void print(const vector<char>& operators) {
    cout << 1;
    for (int i = 2; i <= N; i++) {
        cout << operators[i - 2];
        cout << i;
    }
    cout << '\n';
}

void backtracking(int depth, vector<char>& operators) {
    if (depth == N) {
        evaluate(operators);
        return;
    }

    for (char op : oper) {
        operators.push_back(op);
        backtracking(depth + 1, operators);
        operators.pop_back();
    }
}

void solve() {
    cin >> N;
    vector<char> operators;
    backtracking(1, operators);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; cin >> T;
    for (int t = 0; t < T; t++) {
        solve();
        sort(answers.begin(), answers.end());
        for (string& ans : answers) {
            cout << ans << '\n';
        }
        answers.clear();
        cout << '\n';
    }
}
