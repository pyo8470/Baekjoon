#include <iostream>

using namespace std;


// 주 로직
void solve() {
   int N; cin >> N;

   for(int i=0; i<2*N - 1; i++){
       int indent = i;
       if (indent > N - 1) indent = 2*N-1 - i - 1;
       for(int blank = N - indent - 1; blank > 0; blank--){
           cout << " ";
       }
       for(int star = 0; star < 2 * indent + 1; star++){
           cout << "*";
       }
       cout << '\n';
   }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}
