#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<int> sourFood;
vector<int> bitterFood;
int MIN_DIFF = 2e9;

void dfs(const int& index, const int& sour, const int& bitter, const int& count) {
    if (index == N) {
        if (count >= 1) {
            MIN_DIFF = min(MIN_DIFF, abs(sour - bitter));
        }
        return;
    }

    // 현재 음식 선택
    dfs(index + 1, sour * sourFood[index], bitter + bitterFood[index], count + 1);

    // 현재 음식 선택 안함
    dfs(index + 1, sour, bitter, count);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    sourFood.resize(N);
    bitterFood.resize(N);

    for (int i = 0; i < N; i++) {
        cin >> sourFood[i] >> bitterFood[i];
    }

    dfs(0, 1, 0, 0);
    cout << MIN_DIFF;
}
