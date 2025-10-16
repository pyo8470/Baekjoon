#include <iostream>
#include <vector>

using namespace std;


// 주 로직
void solve() {
   int N, M; cin >> N >> M;

    vector<vector<int>> mat[2];
    
    for(int i=0; i<2; i++){
        mat[i].resize(N,vector<int>(M));
        for(int j=0; j<N; j++){
            for(int k=0; k<M; k++){
                cin >> mat[i][j][k];
            }   
        }
    }

    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cout << mat[0][i][j] + mat[1][i][j] << " ";
        }
        cout << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}