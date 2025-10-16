#include <iostream>
#include <vector>

using namespace std;


// 주 로직
//

int plane[101][101] = {0,};
void solve() {
    int n; cin >> n;
    int answer = 0;
    for(int i=0; i<n; i++){
        int sx,sy; cin >> sx >> sy;

        for(int x = sx; x < sx+10; x++){
            for(int y = sy; y < sy +10; y++){
                if(plane[y][x]) continue;
                plane[y][x] = 1;
                answer++;
            }
        }
    }

    cout << answer;

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}
