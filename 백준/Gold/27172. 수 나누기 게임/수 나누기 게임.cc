#include <bits/stdc++.h>
using namespace std;

const int MAX = 1'000'000;

int N;
vector<int> nums;
bool che[MAX + 1];

void make_che() {
    fill(che, che + MAX + 1, true);
    che[0] = che[1] = false;
    for (int i = 2; i * i <= MAX; i++) {
        if (che[i]) {
            for (int j = i * i; j <= MAX; j += i)
                che[j] = false;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    nums.resize(N);
    for (int i = 0; i < N; i++) cin >> nums[i];

    make_che();

    vector<int> freq(MAX + 1, 0);
    for (int x : nums) freq[x]++;

    vector<int> score(MAX + 1, 0);

    for (int i = 1; i <= MAX; i++) {
        if (freq[i] == 0) continue;
        for (int mul = 2 * i; mul <= MAX; mul += i) {
            if (freq[mul] == 0) continue;
            if (che[i] && che[mul]) continue; // 둘 다 소수면 스킵
            score[i] += freq[mul];
            score[mul] -= freq[i];
        }
    }

    for (int x : nums)
        cout << score[x] << " ";
}
