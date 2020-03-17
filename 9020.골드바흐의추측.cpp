#include <iostream>
#include <vector>
using namespace std;
int main() {
	vector<int>v;
	vector<bool>check(10001, false);
	check[0] = true;
	check[1] = true;
	for (int i = 2; i <= 5000; i++) {
		if (check[i] == false) {
			v.push_back(i);
			for (int j = 2; j * i <= 10000; j++) {
				check[j * i] = true;
			}
		}
	}
	for (int i = 5001; i < 10001; i++) {
		if (check[i] == false) v.push_back(i);
	}
	
	vector<vector<int> > sum(10001, vector<int>(4, 0));
	int x = 0, a, b, c = 0;
	sum[4][0] = v[x];
	sum[4][1] = x;
	sum[4][2] = v[x];
	sum[4][3] = x;;
	for (int i = 6; i <= 10000; i += 2) {
		if (i == v[x + 1] * 2) {
			x++;
			sum[i][0] = v[x];
			sum[i][1] = x;
			sum[i][2] = v[x];
			sum[i][3] = x;
		}
		else {
			a = x;
			while (true) {
				b = x;
				while (true) {
					b++;
					if (v[a] + v[b] == i) {
						sum[i][0] = v[a];
						sum[i][1] = a;
						sum[i][2] = v[b];
						sum[i][3] = b;
						c = 1;
						break;
					}
					else if (v[a] + v[b] > i) {
						b = x;
						break;
					}
				}
				if (c == 1) {
					c = 0;
					break;
				}
				a--;
			}
		}
	}

	int t, n;
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> n;
		cout << sum[n][0] << " " << sum[n][2] << endl;
	}
}