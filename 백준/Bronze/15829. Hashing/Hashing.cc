#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <climits>
#include <queue>
#include <set>
#include <algorithm>
#include <math.h>
using namespace std;

int main(){
	int L; cin >> L;
	string input; cin >> input;
	
	int result = 0;
	int MOD = 1234567891;
	for (int i = 0; i < L; i++) {
		int k = (input[i] - 'a' + 1) * (int)pow(31, i) % MOD;
		result += k;
	}
	cout << result;
}