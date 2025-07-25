#include<iostream>

using namespace std;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	int a; cin >> a;
	string stars;
	for (int i = 0; i < a; i++) {
		stars += "*";
		cout << stars << endl;
	}

}