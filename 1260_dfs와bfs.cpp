#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n, m, start;
int vertex[1001][1001];
vector<bool> point(1001);

void dfs(int);
void bfs(int);

int main() {
	cin >> n >> m >> start;
	int a, b;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		vertex[a][b] = vertex[b][a] = 1;
	}
	dfs(start);
	cout << endl;
	bfs(start);
}

void dfs(int start) {
	cout << start << " ";
	point[start] = true;
	for (int i = 1; i <= n; i++) {
		if (point[i] == false && vertex[start][i] == 1) {
			dfs(i);
		}
	}
}

void bfs(int start) {
	queue <int> q;
	q.push(start);
	point[start] = false;
	while (!q.empty()) {
		cout << q.front() << " ";
		start = q.front();
		q.pop();
		for (int i = 1; i <= n; i++) {
			if (vertex[start][i] == 1 && point[i] == true) {
				q.push(i);
				point[i] = false;
			}
		}
	}
}