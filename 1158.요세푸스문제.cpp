#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, k, m = 0;
	cin >> n >> k;
	vector<int> dap;
	queue<int> q;
	for (int i = 1; i <= n; i++) q.push(i);
	cout << "<";
	while (!q.empty()) {
		m++;
		if (m % k != 0) {
			q.push(q.front());
			q.pop();
		}
		else {
			cout << q.front();
			if (q.size() != 1) cout << ", ";
			q.pop();
		}
	}
	cout << ">";
}