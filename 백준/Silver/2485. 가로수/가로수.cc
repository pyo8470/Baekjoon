#include <iostream>
#include <numeric>
#include <utility>
#include <vector>

using namespace std;

int GCD(int A, int B) {
    if (B == 0)
        return A;
    return gcd(B, A % B);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    // 모든 수의 최대 공약수를 구한다.
    int N;
    cin >> N;
    vector<int> trees(N);
    while (N--) cin >> trees[trees.size() - N - 1];
    N = trees.size();

    vector<int> dist(N - 1);
    for (int i = 0; i < N - 1; i++) {
        dist[i] = trees[i + 1] - trees[i];
    }

    int gcd = dist[0];
    for (int i = 1; i < N - 1; i++) {
        gcd = GCD(max(gcd, dist[i]), min(gcd, dist[i]));
    }

    int ans = 0;
    for (int d : dist) {
        ans += (d / gcd) - 1;
    }
    cout << ans;
}