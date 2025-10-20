#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<int> cards;
int ans = 0;
void init() {
    cin >> N >> M;
    cards.resize(N);
    for (int i = 0; i < N; i++) cin >> cards[i];
}

void bruteForce(const int &depth, const int &idx, const int &sum) {
    if (sum > M)
        return;
    if (depth == 3) {
        ans = max(ans, sum);
        return;
    }

    for (int i = idx; i < N; i++) {
        bruteForce(depth + 1, i + 1, sum + cards[i]);
    }
}
void solve() {
    bruteForce(0, 0, 0);
    cout << ans;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    init();
    solve();
}