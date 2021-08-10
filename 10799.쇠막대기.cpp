#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n = 0, m;
	string s;
	cin >> s;
	vector<int> v;
	stack<int> st;

	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '(') v.push_back(0);
		else if (s[i] == ')') {
			if (s[i - 1] == '(') {
				v.pop_back();
				v.push_back(1);
			}
			else v.push_back(-1);
		}
	}

	for (int i = 0; i < v.size(); i++) {
		if (v[i] != -1) st.push(v[i]);
		else {
			n++;
			m = 0;
			while (st.top() != 0) {
				m += st.top();
				st.pop();
			}
			st.pop();
			st.push(m);
			n += m;
		}
	}
	cout << n;
}