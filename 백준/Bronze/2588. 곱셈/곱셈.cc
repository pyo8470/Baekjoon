#include <iostream>
#include <string>
#include <math.h>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int a; string b;
    cin >> a >> b;
    int result = 0;
    for (int i = 2; i >= 0; i--) {
        int k = b[i] - '0';
        cout << k * a << '\n';
        result += pow(10, 2 - i)*(k*a);
    }

    cout << result << '\n';
}
