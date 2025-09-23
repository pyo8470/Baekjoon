#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int N, target;
int parent[51];
vector<unordered_set<int>> child;

int answer = 0;

void countLeaf(int node) {
    if (child[node].empty()) {
        answer++;
        return;
    }
    for (int nxt : child[node]) {
        countLeaf(nxt);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> N;
    child.assign(N + 1, {});

    for (int i = 1; i <= N; i++) {
        cin >> parent[i];
        parent[i]++;
    }
    cin >> target;
    target++;

    int root = -1;
    for (int i = 1; i <= N; i++) {
        if (parent[i] == 0) root = i;
        else child[parent[i]].insert(i);
    }

    // target 제거
    if (parent[target] != 0) {
        child[parent[target]].erase(target);
    }
    else {
        // target이 root라면 트리 전체 삭제됨
        cout << 0;
        return 0;
    }

    // 남은 트리에서 리프 개수 세기
    countLeaf(root);
    cout << answer;
}
