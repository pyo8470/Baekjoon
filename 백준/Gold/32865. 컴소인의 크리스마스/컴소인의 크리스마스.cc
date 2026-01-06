#include <bits/stdc++.h>
using namespace std;

vector<int> try_count;
// 맞기 전 카운트 세보기?
// 테케는 현재 가능한 X나 O카운트가 큰 것 중에 번호가 큰걸 기준으로 한듯
// 이제 맞을 차례의 vector들과 아직 맞지 않은 집합들(X의 카운트가 크고, 같다면 번호가 같아야함)
struct wrong{
    int id, remain;
    const bool operator<(const wrong& other) const{
        if(remain != other.remain) return remain > other.remain;
        return id > other.remain;
    }
};


int N;
set<wrong> wrong_set;
queue<int> correct;
vector<int> answer;
bool solution(){
    for(int i=1; i<=2*N-1; i++){
        if(i%2 == 1){
            // 없다면 실패
            if(correct.empty()){
                return false;
            }
            // 있다면
            answer.push_back(correct.front());
            correct.pop();
        }else{
            if(wrong_set.empty()){
                return false;
            }
            auto target_it = wrong_set.begin();
            int tid = target_it->id;
            int remain = target_it->remain - 1;
            wrong_set.erase(target_it);
            answer.push_back(tid);
            if(remain !=0) wrong_set.insert({tid,remain});
            else{correct.push(tid);}
        }
    }
    return true;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);  

    cin >> N;
    try_count.assign(N,0);
    for(int i=0; i<N; i++){
        cin >> try_count[i];
        if(try_count[i] == 0) correct.push(i+1);
        else wrong_set.insert({i+1,try_count[i]});
    }

    // 홀수 -> O
    // 짝수 -> X
    
    if(solution()){
        for(auto &id : answer){
            cout << id << '\n';
        }
    }else{
        cout << -1;
    }

    return 0;
}