#include <iostream>
#include <vector>

using namespace std;

int N;
vector<string> area;

void recur(const int &volume, const int &sx, const int &sy) {
    // cout << "vol :" << volume << " " << sy << " " << sx << '\n';
    if (volume == 1) {
        cout << area[sy][sx];
        return;
    }
    // 전체가 1 혹은 0이라면
    char start = area[sy][sx];
    bool mixed = false;
    for (int dy = 0; dy < volume; dy++) {
        for (int dx = 0; dx < volume; dx++) {
            int x = sx + dx, y = sy + dy;
            if (start != area[y][x]) { // 섞여 있는 경우
                mixed = true;
                cout << '(';
                int n_volume = volume / 2;
                recur(n_volume, sx, sy);
                recur(n_volume, sx + n_volume, sy);
                recur(n_volume, sx, sy + n_volume);
                recur(n_volume, sx + n_volume, sy + n_volume);
                cout << ')';
                break;
            }
        }
        if (mixed)
            break;
    }
    if (!mixed) {
        cout << start;
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;
    area.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> area[i];
    }

    recur(N, 0, 0);
}
