#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std; 

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, r = 0, b = 0;
	cin >> n;
	string s;
	cin >> s;
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		if (s[i] == 'B') v[i] = 0;
		else v[i] = 1;
	}
	if (v[0] == 0) b++;
	else r++;
	for (int i = 1; i < n; i++) {
		if (v[i - 1] == v[i]) continue;
		else {
			if (v[i] == 0) b++;
			else r++;
		}
	}
	cout << min(r, b) + 1;
}