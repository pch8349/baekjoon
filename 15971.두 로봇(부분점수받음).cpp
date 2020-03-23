#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<bool> check(100001);
long int v[10001][10001];
vector<long int> range;

int n, a, b, collect = 0;
void dfs(int start);
int main() {
	cin >> n >> a >> b;
	int x, y, z, sum = 0;
	long int ma = 0;
	for (int i = 0; i < n - 1; i++) {
		cin >> x >> y >> z;
		v[x][y] = z;
		v[y][x] = z;
	}
	dfs(a);
	range.push_back(a);
	for (int i = 0; i < range.size() - 1; i++) {
		sum = sum + v[range[i]][range[i + 1]];
		ma = max(ma, v[range[i]][range[i + 1]]);
	}
	cout << sum - ma << endl;
}
void dfs(int start) {
	check[start] = true;
	for (int i = 1; i <= n; i++) {
		if (check[i] == false && v[start][i] != 0) {
			if (i != b) dfs(i);
			else {
				collect = 1;
				range.push_back(i);
				break;
			}
		}
		if (collect == 1) {
			range.push_back(i);
			break;
		}
	}
}