#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;
    unordered_map<int, int> cards;
    cards.reserve(N + 5);

    for (int i = 0; i < N; i++) {
        int card;
        cin >> card;
        cards[card] += 1;
    }

    int M;
    cin >> M;
    for (int i = 0; i < M; i++) {
        int target;
        cin >> target;
        cout << cards[target] << " ";
    }
}