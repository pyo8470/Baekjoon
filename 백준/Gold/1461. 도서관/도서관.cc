
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#define MAX_N 125
using namespace std;

int N, M;
vector<int> pos;
vector<int> neg;
int main()
 {
    // 그리디였네;;

    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin >> N >> M;

    int MAX = 0;
    for (int i = 0; i < N; i++) {
        int num; cin >> num;
        (num < 0) ? neg.push_back(-num) : pos.push_back(num);
        MAX = max(MAX, abs(num));
    }
    
    sort(pos.begin(), pos.end(), [](const int& a, const int& b) {
        return a > b;
        });
    sort(neg.begin(), neg.end(), [](const int& a, const int& b) {
        return a > b;
        });
    
    int answer = 0;
    for (int i = 0; i < pos.size(); i += M) {
        answer += pos[i]*2;
    }
    for (int i = 0; i < neg.size(); i += M) {
        answer += neg[i] * 2;

    }

    cout << answer-MAX << '\n';
    return 0;
}

