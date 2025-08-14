#include <iostream>
#include <vector>
using namespace std;

int T, N;
vector<int> parent;
int find(int x) {
    if (parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}

void merge(int a, int b) {
    a = find(a);
    b = find(b);
    if (a != b) {
        parent[a] = b; return;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> T >> N;
    parent.resize(T + 1);
    for (int i = 1; i < T + 1; i++) parent[i] = i;
    int answer = 0;
    for (int i = 0; i < N; i++) {
        int version; cin >> version;
        
        //현재 해당 version에 맞는게 남으면
        int next = find(version);
        if (next == 0) break;
        merge(version, next -1);
    
        answer++;
   }

    cout << answer;
}