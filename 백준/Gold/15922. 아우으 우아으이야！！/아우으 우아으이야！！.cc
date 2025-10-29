#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<pair<int, int>> cord(N);

    // 이미 정렬된 상태이다.
    for (int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;
        cord[i] = {x, y};
    }

    int l = cord[0].first;   // 최고 왼쪽
    int r = cord[0].second;  // 최고 오른쪽

    int ans = 0;
    int sub = 0;  // 빈 공간들 길이 모으기
    for (int i = 1; i < N; i++) {
        // 겹치는 상태 (1. 한 쪽만 | 2. 포함 관계)
        int n_l = cord[i].first;
        int n_r = cord[i].second;

        if (n_l <= r) {
            // 1번 상태
            if (n_r > r) {
                r = n_r;
            } else  // 2번상태 -> 포함 관계이므로 아무런 동작도 취하지 않는다.
                continue;
        } else {  // 겹치지 않는 상태
            // 빈 공간을 모으자
            sub += (n_l)-r;
            r = n_r;
        }
    }

    ans = (r - l) - sub;
    cout << ans;
}