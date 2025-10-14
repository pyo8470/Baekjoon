#include <cstdio>
#include <ios>
#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int H,M; cin >> H >> M;

    int time = H*60 + M;

    time-=45;
    if(time < 0) time += 1440;
    cout << time / 60 << " " << time % 60;
}