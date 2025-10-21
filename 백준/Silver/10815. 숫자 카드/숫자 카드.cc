#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;
    unordered_map<int, int> cards;
    cards.reserve(500005);
    for (int i = 0; i < N; i++) {
        int c;
        cin >> c;
        cards[c] = 1;
    }

    int M;
    cin >> M;
    for (int i = 0; i < M; i++) {
        int target;
        cin >> target;
        if (cards.find(target) == cards.end())
            cout << 0 << " ";
        else
            cout << 1 << " ";
    }
}