#include <iostream>
#include <queue>
#include <stack>
#include <vector>

using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;
    int turn = 1;

    queue<int> line;
    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;
        line.push(num);
    }
    stack<int> waiting;

    //
    while (!line.empty()) {
        int target = line.front();
        line.pop();

        if (turn != target) {
            // 일단 대기열에 기다리는 사람과 안 맞을 때,
            // wating stack에 넣어야 한다.
            // 올바른지
            while (!waiting.empty()) {
                if (waiting.top() == turn) {
                    waiting.pop();
                    turn++;
                    continue;
                }
                break;
            }
            if (!waiting.empty() && waiting.top() < target) {
                cout << "Sad";
                return 0;
            }
            waiting.push(target);
            continue;
        }

        turn++;
    }
    cout << "Nice";
}
