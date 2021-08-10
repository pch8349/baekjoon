#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, m;
	cin >> n;
	deque<int> dq, num;

	for (int i = 0; i < n; i++) {
		cin >> m;
		dq.push_back(m);
		num.push_back(i + 1);
	}
	while (!dq.empty()) {
		m = dq.front();
		cout << num.front() << " ";
		dq.pop_front();
		num.pop_front();
		if (dq.empty()) break;
		if (m > 0) {
			for (int i = 0; i < m - 1; i++) {
				dq.push_back(dq.front());
				num.push_back(num.front());
				dq.pop_front();
				num.pop_front();
			}
		}
		else {
			m = -m;
			for (int i = 0; i < m; i++) {
				dq.push_front(dq.back());
				num.push_front(num.back());
				dq.pop_back();
				num.pop_back();
			}
		}
	}
}