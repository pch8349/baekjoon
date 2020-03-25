#include <iostream>
#include <vector>
using namespace std;
int main() {
	vector<int> x(5, 0);
	vector<int> y(5, 0);
	int n, a, p;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a;
		for (int j = 0; j < a; j++) {
			cin >> p;
			x[p]++;
		}
		cin >> a;
		for (int j = 0; j < a; j++) {
			cin >> p;
			y[p]++;
		}
		for (int j = 4; j > 0; j--) {
			if (x[j] > y[j]) {
				cout << "A\n";
				break;
			}
			else if (x[j] < y[j]) {
				cout << "B\n";
				break;
			}
			else if (j == 1) cout << "D\n";
		}
		x.clear();
		y.clear();
		x.resize(5);
		y.resize(5);
	}
}