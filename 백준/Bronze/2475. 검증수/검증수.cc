#include<iostream>

using namespace std;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	
	int sum = 0;
	int k; 
	cin >> k;
	sum += (k*k);
	cin >> k;
	sum += (k * k);
	cin >> k;
	sum += (k * k);
	cin >> k;
	sum += (k * k);
	cin >> k;
	sum += (k * k);

	cout << sum % 10;

}