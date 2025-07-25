#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    vector<int> countingArr(8001, 0); // -4000~4000

    int sum = 0;
    int minVal = 4001, maxVal = -4001;
    int maxFreq = 0;

    // 입력 및 카운트 + 통계용 준비
    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        sum += x;
        int idx = x + 4000;
        countingArr[idx]++;

        maxFreq = max(maxFreq, countingArr[idx]);
        minVal = min(minVal, x);
        maxVal = max(maxVal, x);
    }

    // 산술 평균

    int avg = round((double)sum / N);
    if (avg == -0) avg = 0; // -0 처리
    cout << avg << '\n';

    // 중앙값: 누적합만으로 해결
    int midCount = (N + 1) / 2;
    int median = 0;
    int cnt = 0;
    for (int i = 0; i < 8001; i++) {
        cnt += countingArr[i];
        if (cnt >= midCount) {
            median = i - 4000;
            break;
        }
    }
    cout << median << '\n';

    // 최빈값
    vector<int> modeList;
    for (int i = 0; i < 8001; i++) {
        if (countingArr[i] == maxFreq) {
            modeList.push_back(i - 4000);
        }
    }
    cout << (modeList.size() > 1 ? modeList[1] : modeList[0]) << '\n';

    // 범위
    cout << maxVal - minVal << '\n';
}
