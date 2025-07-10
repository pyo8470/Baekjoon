#include <bits/stdc++.h>
#include <climits>
#include <math.h>
using namespace std;

int N,M;
int result = 0;
int main() {
   
   cin >> N >> M;

   int nums[N];

   for(int i=0; i<N; i++){
    cin >> nums[i];
   }

   for(int i=0; i<N-2; i++){
    for(int j=i+1; j<N-1;j++){
        for(int k = j+1; k<N;k++){
            int sum = nums[i] + nums[j] + nums[k];
            result = (sum <= M && abs(M-sum) < abs(M-result)) ? sum : result;
        }
    }
   }
   printf("%d", result);
}


