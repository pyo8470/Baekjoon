#include <iostream>
#include <vector>
using namespace std;

int N, L;

int main() {
    cin >> N >> L;

    vector<int> result;
    for (int len = L; len <= 100; len++) {
        double val = (double(N) / len) + 0.5 - (double(len) / 2);
        int a = (int)val;

        if (val == a && a >= 0) {
            for (int i = 0; i < len; i++) {
                result.push_back(a + i);
            }
            break;
        }
    }

    if (result.empty()) {
        cout << -1 << "\n";
    }
    else {
        for (int x : result) cout << x << " ";
    }
}
