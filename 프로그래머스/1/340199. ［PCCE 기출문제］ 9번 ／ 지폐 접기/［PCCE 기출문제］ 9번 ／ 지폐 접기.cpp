#include <string>
#include <vector>

using namespace std;

int solution(vector<int> wallet, vector<int> bill) {
    int answer = 0;

   
    int bMin = min(bill[0],bill[1]);
    int bMax = max(bill[0],bill[1]);
    
    int wMin = min(wallet[0],wallet[1]);
    int wMax = max(wallet[0],wallet[1]);
    while(bMin > wMin || bMax > wMax){
        if(bill[0] > bill[1]){
            bill[0] /=2;
        }else{
            bill[1] /=2;
        }
        bMin = min(bill[0],bill[1]);
        bMax = max(bill[0],bill[1]);
        
        answer++;
    }
    return answer;
}