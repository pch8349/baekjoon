#include <iostream>
#include <vector>

using namespace std;

int n;
vector<vector<int> > v;

void floyd() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= n; k++) {
				if (v[j][k] > v[j][i] + v[i][k]) {
					v[j][k] = v[j][i] + v[i][k];
				}
			}
		}
	}
}

int main() {
	int m;
	cin >> n >> m;
	v.resize(n + 1, vector<int>(n + 1, 9999));
	int a, b;
	for (int i = 1; i <= n; i++) v[i][i] = 0;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		v[a][b] = 1;
		v[b][a] = 1;
	}

	floyd();

	int min = INT32_MAX, sum, num;
	for (int i = n; i > 0; i--) {
		sum = 0;
		for (int j = 1; j <= n; j++) sum += v[i][j];
		if (sum <= min) {
			min = sum;
			num = i;
		}
	}
	cout << num;
