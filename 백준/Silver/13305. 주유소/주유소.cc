#include <cstring>
#include <iostream>
#include <iterator>
#include <vector>
using namespace std;
int N;
vector<int> road;
vector<int> cost;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;
    road.resize(N - 1);
    cost.resize(N - 1);

    int dist = 0;
    for (int i = 0; i < N - 1; i++) {
        cin >> road[i];
    }
    for (int i = 0; i < N - 1; i++) {
        cin >> cost[i];
    }

    long long rslt = 0;
    int MIN = 2e9;
    for (int i = 0; i < N - 1; i++) {
        // 현재 Cost가 이전 Cost보다 비싸다면 이전 주유소에서 더 충전
        MIN = min(cost[i], MIN);
        rslt += (long long)road[i] * MIN;
    }
    cout << rslt;
}
