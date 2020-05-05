#include<iostream>
#include<map>
#include<cstdio>
#include<string>
#include<vector>
#include<algorithm>
#include<cstdlib>
using namespace std;

vector<int> v;
map<string, int> m;
vector<int>counter;
int a, b;

int find(int s) {
	if (v[s] == s) return s;
	return v[s] = find(v[s]);
}

int main() {
	int t, f;
	char s_1[21], s_2[21];
	cin >> t;
	v.reserve(200001);
	for (int i = 0; i < t; i++) {
		scanf("%d", &f);
		m.clear();
		counter.clear();
		counter.resize(f * 2 + 1, 1);
		v.resize(1, 0);
		for (int j = 0; j < f; j++) {
			scanf("%s %s", s_1, s_2);
			if (m.find(s_1) == m.end()) {
				v.push_back(v.size());
				m.insert(pair<string, int>(s_1, v.size() - 1));
			}
			if (m.find(s_2) == m.end()) {
				v.push_back(v.size());
				m.insert(pair<string, int>(s_2, v.size() - 1));
			}

			a = find(m[s_1]);
			b = find(m[s_2]);
			v[b] = a;
			if(a != b) counter[a] += counter[b];
			printf("%d\n", counter[a]);
		}
	}
}