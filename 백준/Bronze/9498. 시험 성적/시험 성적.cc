#include<iostream>

using namespace std;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	int n; cin >> n;

	if (90 <= n && n <= 100) cout << "A";
	else if (80 <= n && n <= 89) cout << "B";
	else if (70 <= n && n <=79) cout << "C";
	else if (60 <= n && n <=69) cout << "D";
	else cout << "F";
}