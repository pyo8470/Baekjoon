#include <bits/stdc++.h>
#include <climits>
using namespace std;

int main() {
    int N; cin >> N;
    int numbers[N];
    for(int i=0; i<N; i++) cin >> numbers[i];

    set<int> sorted;
    for(int i=0; i<N; i++) sorted.insert(numbers[i]);

    map<int,int> result;
    int count =0;
    for(int k : sorted){
        result[k] = count;
        count++;
    }
    for(int i=0; i<N; i++){
        printf("%d ", result[numbers[i]]);
    }

}