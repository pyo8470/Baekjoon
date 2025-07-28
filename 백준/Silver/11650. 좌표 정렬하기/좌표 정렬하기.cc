#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);
    int N;
    cin >> N;
    
    vector<pair<int, int>> coord(N);
    for (int i = 0; i < N; i++) {
        cin >> coord[i].first;
        cin >> coord[i].second;
    }

    sort(coord.begin(), coord.end());

    for (int i = 0; i < N; i++) {
        cout << coord[i].first << " " << coord[i].second << '\n';
    }
}
