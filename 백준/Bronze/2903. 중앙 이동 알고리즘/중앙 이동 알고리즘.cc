#include <cctype>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;


void solve() {
    int N; cin >> N;

    int power = pow(2,N);
    cout << (1+power) * (1+power);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}

