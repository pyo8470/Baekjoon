#include <iostream>
using namespace std;
#include <algorithm>
#include <vector>

void solve() {
  while (1) {

    int a, b, c;
    cin >> a >> b >> c;
    if (a == 0 && b == 0 || c == 0)
      break;
    vector<int> k = {a, b, c};
    sort(k.begin(), k.end());
    if (k[2] < k[0] + k[1]) {
      if (a == b && b == c) {
        // 정삼각형
        cout << "Equilateral";
      } else if (a != b && b != c && a != c) {
        // 같은게 없음
        cout << "Scalene";
      } else {
        cout << "Isosceles";
      }
    } else {
      cout << "Invalid";
    }
    cout << '\n';
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  solve();
}