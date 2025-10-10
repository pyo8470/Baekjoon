#include <iostream>
#include <vector>

using namespace std;
typedef pair<int, int> pii;

// 시계 방향 - 반 시계 방향 / 2
// 신발끈 공식

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    double sum1 = 0;
     double sum2 = 0;

    int N; cin >> N;

    vector<pii> cords;
    for (int i = 0; i < N; i++) {
        int x, y; cin >> x >> y;
        cords.push_back({ x,y });
    }
    for (int i = 0; i < N; i++) {
        double cx, nx;
        double cy, ny;
        cx = cords[i].first, cy = cords[i].second;
        if (i == N - 1) {
            nx = cords[0].first;
            ny = cords[0].second;
        }
        else {
            nx = cords[i + 1].first;
            ny = cords[i + 1].second;
        }
        sum1 += (cx * ny);
        sum2 += (cy * nx);
    }
    
    cout << fixed;
    cout.precision(1);
    cout << abs(sum1 - sum2) / 2;
}
