#include <iostream>

using namespace std;


// 주 로직
void solve() {
    int arr[9][9];

    int MAX = 0;
    int x = 0, y = 0;
    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            cin >> arr[i][j];
            if( MAX <= arr[i][j] ){
                MAX = arr[i][j];
                y = i, x = j;
            }
        }
    }

    cout << MAX << '\n' << y + 1 << " " << x + 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}