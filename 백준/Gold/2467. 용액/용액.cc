#include <iostream>
#include <vector>
using namespace std;

int N;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;

    int l = 0, r = N - 1;
    pair<int, int> ans;

    vector<int> arr(N);
    for (int i = 0; i < N; i++) cin >> arr[i];
    ans = {arr[l], arr[r]};
    long long MIN = 2e10;
    while (l < r) {
        int S = abs(arr[l] + arr[r]);
        if (S <= MIN) {
            MIN = S;
            ans = {arr[l], arr[r]};
        }
        // 어느 방향으로 이동할 지 결정
        int L = arr[l + 1];
        int R = arr[r - 1];
        int l_sum = abs(arr[r] + L);
        int r_sum = abs(arr[l] + R);
        if (l_sum >= r_sum) {
            r--;
        } else {
            l++;
        }
    }

    cout << ans.first << " " << ans.second;
}