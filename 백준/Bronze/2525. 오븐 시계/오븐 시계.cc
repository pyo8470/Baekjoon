#include <cstdio>
#include <ios>
#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int H,M; cin >> H >> M;
    int add; cin >> add;
    int time = H*60 + M;

    time += add;
    if(time >= 1440) time -= 1440;
    cout << time / 60 << " " << time % 60;
}