#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

int w[21][21][21] = {
    0,
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    memset(w, 1, sizeof(w));
    for (int a = 0; a <= 20; a++) {
        for (int b = 0; b <= 20; b++) {
            for (int c = 0; c <= 20; c++) {
                if (a == 0 || b == 0 || c == 0) {
                    w[a][b][c] = 1;
                } else if (a < b && b < c) {
                    w[a][b][c] = w[a][b][c - 1] + w[a][b - 1][c - 1] - w[a][b - 1][c];
                } else {
                    w[a][b][c] = w[a - 1][b][c] + w[a - 1][b - 1][c] + w[a - 1][b][c - 1] - w[a - 1][b - 1][c - 1];
                }
            }
        }
    }
    while (1) {
        int a, b, c;
        cin >> a >> b >> c;
        if (a == -1 && b == -1 && c == -1)
            break;
        int t_a = a, t_b = b, t_c = c;
        if (a <= 0 || b <= 0 || c <= 0) {
            t_a = 0, t_b = 0, t_c = 0;
        } else if (a > 20 || b > 20 || c > 20) {
            t_a = 20, t_b = 20, t_c = 20;
        }

        cout << "w(" << a << ", " << b << ", " << c << ") = " << w[t_a][t_b][t_c] << '\n';
    }
}
