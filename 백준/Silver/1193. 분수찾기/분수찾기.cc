#include <cctype>
#include <cmath>
#include <iostream>

using namespace std;


void solve() {
    int N; cin >> N;
    
    int step = 0;
    int sub = 1;
    while(N > 0){
        N -= sub;
        step++;
        sub++;
    }

    int sum = step+1; //각 분자의 분모 분자 값

    
    N = abs(N);
    int up,down;
    if(step % 2 == 0){

        up = sum - 1;
        down = 1;

        up -= N;
        down += N;
    }else{
        up = 1;
        down = sum - 1;
        
        up += N;
        down -= N;
    }
    
    cout << up << "/" << down;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}

