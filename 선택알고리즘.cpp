#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> v;
vector<int> lower;
vector<int> high;

int select(int st, int end, int n) {
	int piv = v[end];
	int pivn;
	if (st + 1 == end) return v[st];
	lower.clear();
	high.clear();

	for (int i = st; i < end; i++) {
		if (v[i] < piv) lower.push_back(v[i]);
		else if (v[i] > piv) high.push_back(v[i]);
	}
	for (int j = st; j <= end; j++) {
		if (j - st < lower.size()) {
			v[j] = lower[j - st];
		}
		else if (j - st == lower.size()) {
			v[j] = piv;
			pivn = j;
		}
		else {
			v[j] = high[high.size() - end + j - 1];
		}
	}

	if (lower.size() + 1 == n) return piv;
	else if (lower.size() >= n)select(st, st + lower.size() - 1, n);
	else select(st + lower.size() + 1, end, n - lower.size() - 1);
}

int main() {
	int s, n; // s크기의 배열 v에서 n번째 작은 원소 찾기. 선택알고리즘
	cin >> s >> n;
	v.resize(s);
	for (int i = 0; i < s; i++) cin >> v[i];
	cout << endl << select(0, s - 1, n) << endl;
}