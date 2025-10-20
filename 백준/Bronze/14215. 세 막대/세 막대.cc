#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

void solve() {
  vector<int> bars;
  bars.resize(3);

  for (int i = 0; i < 3; i++) {
    cin >> bars[i];
  }

  sort(bars.begin(), bars.end());

  if (bars[0] + bars[1] <= bars[2]) {
    bars[2] = bars[0] + bars[1] - 1;
  }
  cout << accumulate(bars.begin(), bars.end(), 0);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  solve();
}