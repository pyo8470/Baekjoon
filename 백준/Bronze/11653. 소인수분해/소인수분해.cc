#include <cmath>
#include <cstddef>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;


void solve(){
    int N; cin >> N;

    for(int div = 2; ;){
        if(N == 1) break;
        if(N%div == 0) {
            cout << div << '\n';
            N /= div;
        }
        else{
            div++;
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve(); 
}

