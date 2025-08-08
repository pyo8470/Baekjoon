#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

//최소 공배수 == a/gcd * b/gcd *gcd
int LCM(int a,int b, int gcd) {
	return (a / gcd) * (b / gcd) * gcd;
}
//최대 공약수
int GCD(int a, int b) {
	int gcd = 0;
	for (int i = 1; i <= max(b, a); i++) {
		if (a % i == 0 && b % i == 0) gcd = i;
	}
	return gcd;
}
int main() {
	int N,M; cin >> N >> M;
	
	int gcd = GCD(N, M);
	cout << gcd << '\n';

	cout << LCM(N, M, gcd);
}