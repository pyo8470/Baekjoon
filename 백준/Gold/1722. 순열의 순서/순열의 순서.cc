#include <bits/stdc++.h>
using namespace std;

int N;
int problem_number;
vector<long long> arr;
vector<long long> factorial;
unordered_set<long long> num_set;
long long K;

void p1(){
    cin >> K;
    int idx = 0;
    int turn = 1;
    while(idx < N){
        long long fact = factorial[N-idx-1];
        if(num_set.count(turn)){
            turn++;
            continue;;
        }
        if(K <= fact){
            cout << turn << " ";
            num_set.insert(turn);
            idx++;
            turn = 1;
        }else{
            K -= fact;
            turn++;
        }
    }
}
void p2(){
    long long answer = 1;
    arr.resize(N);
    for(int i=0; i<N; i++){
        cin >> arr[i];
    }
    int idx = 0;
    int turn = 1;
    while(idx < N){
        int num = arr[idx];
        if(num_set.count(turn)){
            turn++;
            continue;
        }
        if(turn == num){
            num_set.insert(num);
            idx++;
            turn = 1;
            continue;
        }
        answer+=factorial[N-idx-1];
        turn++;
    }
    cout << answer;
}
void solve(){
    
    if(problem_number == 1){
        // 길이 N 수열의 k번째 순열
        p1();
    }else{
        // 몇 번 쨰인가
        p2();   
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    factorial.assign(21,1);
    factorial[1] = 1;
    for(int i=2; i<21; i++){
        factorial[i] = factorial[i-1]*i;
    }

    cin >> N >> problem_number;
    solve();
}