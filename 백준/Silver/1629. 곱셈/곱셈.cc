#include <iostream>
#include <math.h>
using namespace std;
long long int A, B, C;
long long int solution(long long int A, long long int B) {
	long long int  mult = 1;
	//cout << B << endl;
	if (B == 0) return 1;
	if (B == 1) return A%C;

	long long half = solution(A, B / 2);
	long long result = (half * half)%C;
	
	//cout << half << endl;
	if (B % 2 == 1) result = result * A%C;
	return result;
}
int main() {
	
	cin >> A >> B >> C;
	cout << solution(A, B);
}