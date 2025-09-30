#include <string>
#include <vector>
#include <math.h>
#include <iostream>
#include <unordered_map>
using namespace std;

int solution(int n, int w, int num) {
    int answer = 0;
    
    vector<vector<int>> arr;
    int h = ceil((double)n/w);
    arr.assign(h,vector<int>(w));
    
    // num -> cord
    unordered_map<int,pair<int,int>> num_map;
    int W = 0,H = 0;
    for(int i=1; i<=n; i++){
        arr[H][W] = i;
        num_map[i] = {W,H};
        if(W == w-1 && H%2 == 0){
            H++;
        }else if(W == 0 && H%2 == 1){
            H++;
        }else if(H%2 == 0){
            W++;
        }else if(H%2 == 1){
            W--;
        }
    }
    
    pair<int,int> target_location = num_map[num];
    
    int tW = target_location.first;
    int tH = target_location.second;
    while(true){
        if(tH >= h || arr[tH][tW] == 0) break;
        if(arr[tH][tW] !=0) answer++;
        tH++;
    }
    return answer;
}