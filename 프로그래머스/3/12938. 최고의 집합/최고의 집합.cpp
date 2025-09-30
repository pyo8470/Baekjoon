#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, int s) {
    vector<int> answer;
    
    if(n > s) return {-1};
    
    int count = n;
    for(int i=0; i<count; i++){
        int k = s/n;
        
        answer.push_back(k);
        n--;
        s-=k;
    }
    return answer;
}