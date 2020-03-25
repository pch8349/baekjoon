#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n, m, ch = 0, a, b;
	cin >> n >> m;
	vector<int> answer(n + 1, 0);
	vector<int> check(n + 1, 0);
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		answer[a]++;
		answer[b]--;
	}
	for (int i = 1; i <= n; i++) {
		answer[i] += i;
		check[answer[i]]++;
	}
	for (int i = 1; i <= n; i++) {
		if (check[i] == 0) {
			ch++;
		}
	}
	if (ch == 0) {
		for (int i = 1; i <= n; i++) {
			cout << answer[i] << " ";
		}
	}
	else {
		cout << "-1" << endl;
	}
}