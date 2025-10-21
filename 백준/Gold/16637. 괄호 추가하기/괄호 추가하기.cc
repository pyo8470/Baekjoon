#include <cctype>
#include <cstdio>
#include <ios>
#include <iostream>
#include <vector>

using namespace std;
// 16637 괄호 추가하기

int N;
string query;
long long ans = -2e15;

int s_n;
vector<int> nums;  // 피연산자
vector<char> opt;  // 연산자

inline int calc(const int& a, const int& b, char op) {
    if (op == '+')
        return a + b;
    if (op == '-')
        return a - b;
    if (op == '*')
        return a * b;
    return 0;
}

void solve(const int& depth, const int& now) {
    if (depth == nums.size() - 1) {
        ans = max(ans, (long long)now);
        return;
    }

    // 현재 연산 진행
    solve(depth + 1, calc(now, nums[depth + 1], opt[depth]));

    // 진행 안함
    // ex )
    // depth : 0      1     2
    //         3  +  (8  *  7)
    if (depth + 2 <= (int)nums.size() - 1) {
        int temp = calc(nums[depth + 1], nums[depth + 2], opt[depth + 1]);  // 괄호연산 진행
        solve(depth + 2, calc(now, temp, opt[depth]));
    }
}

// 풀이를 어떻게 할까유...

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> query;

    for (int i = 0; i < N; i++) {
        if (i % 2 == 0)
            nums.push_back(int(query[i] - '0'));
        else
            opt.push_back(query[i]);
    }
    solve(0, nums[0]);

    cout << ans;
}