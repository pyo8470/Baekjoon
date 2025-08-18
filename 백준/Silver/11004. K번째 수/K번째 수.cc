#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, K;
vector<int> list;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        int n; cin >> n;
        list.push_back(n);
    }

    sort(list.begin(), list.end());
    cout << list[K-1];
}
