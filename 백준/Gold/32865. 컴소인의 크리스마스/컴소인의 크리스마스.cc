#include <bits/stdc++.h>
using namespace std;

// 맞기 전 상태를 관리하는 구조체
struct Candidate {
    int id, remain;

    // remain이 큰 순, 같다면 id가 큰 순 (Greedy 조건)
    bool operator<(const Candidate& other) const {
        if (remain != other.remain) return remain < other.remain; // priority_queue는 기본이 Max-Heap이므로 < 사용
        return id < other.id;
    }
};

int N;
priority_queue<Candidate> wrong_pq; // 아직 더 틀려야 하는 그룹
queue<int> ready_q;                 // 이제 맞을 준비가 된(remain=0) 그룹
vector<int> answer;

bool solve() {
    for (int i = 1; i <= 2 * N - 1; i++) {
        if (i % 2 == 1) { // 홀수 번째: 'O' (맞아야 함)
            if (ready_q.empty()) return false;
            
            answer.push_back(ready_q.front());
            ready_q.pop();
        } 
        else { // 짝수 번째: 'X' (틀려야 함)
            if (wrong_pq.empty()) return false;

            Candidate target = wrong_pq.top();
            wrong_pq.pop();

            answer.push_back(target.id);
            target.remain--;

            if (target.remain == 0) {
                ready_q.push(target.id);
            } else {
                wrong_pq.push(target);
            }
        }
    }
    return true;
}

int main() {
    // 입출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    if (!(cin >> N)) return 0;

    answer.reserve(2 * N - 1);

    for (int i = 1; i <= N; i++) {
        int cnt;
        cin >> cnt;
        if (cnt == 0) {
            ready_q.push(i);
        } else {
            wrong_pq.push({i, cnt});
        }
    }

    if (solve()) {
        for (const int& id : answer) {
            cout << id << "\n";
        }
    } else {
        cout << -1;
    }

    return 0;
}