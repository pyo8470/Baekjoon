#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M;
    cin >> N >> M;
    set<int> A, B;
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        A.insert(a);
    }
    for (int i = 0; i < M; i++) {
        int b;
        cin >> b;
        B.insert(b);
    }

    vector<int> O;
    set_symmetric_difference(A.begin(), A.end(), B.begin(), B.end(), back_inserter(O));
    cout << O.size();
}