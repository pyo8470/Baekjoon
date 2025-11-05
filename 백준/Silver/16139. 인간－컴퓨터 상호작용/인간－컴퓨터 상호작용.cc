#include <bits/stdc++.h>
using namespace std;

string S;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> S;
    int q;
    cin >> q;
    vector<vector<int>> sums;
    sums.assign(26, vector<int>(S.size() + 1, 0));

    for (int i = 1; i <= (int)S.size(); i++) {
        char c = S[i - 1];
        int idx = int(c - 'a');

        for (int alphabet = 0; alphabet < 26; alphabet++) {
            if (idx == alphabet) {
                sums[alphabet][i] = sums[alphabet][i - 1] + 1;
            } else {
                sums[alphabet][i] = sums[alphabet][i - 1];
            }
        }
    }
    while (q--) {
        char target;
        int s, e;
        cin >> target >> s >> e;
        s++;
        e++;

        int t_idx = int(target - 'a');
        cout << sums[t_idx][e] - sums[t_idx][s - 1] << '\n';
    }
    return 0;
}
