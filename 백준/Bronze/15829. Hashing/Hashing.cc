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


int main() {
	int L; cin >> L;
	string input; cin >> input;

	long long result = 0;
	int MOD = 1234567891;
	long long pow = 1;
	for (int i = 0; i < L; i++) {
		long long k = (long long)(input[i] - 'a' + 1);
		result = (result + k * pow) % MOD;
		pow = (pow * 31) % MOD;
		
	}
	cout << result;
}

