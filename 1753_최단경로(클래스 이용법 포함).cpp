#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Edge {
public:
	int vertex, dist;

	Edge() { // �⺻ ������

	}

	Edge(int vertex, int dist) : vertex(vertex), dist(dist) {
		// Edge�� ������ �� �� ����
	}

	bool operator>(const Edge& other) const {
		return dist > other.dist; // �������� ����
	}
};


int main() {
	int n, e, start, a, b, c;
	cin >> n >> e >> start;
	vector<vector<Edge> > v(n + 1);
	vector<int> distance(n + 1, INT32_MAX);
	priority_queue<Edge, vector<Edge>, greater<> > q;
	distance[start] = 0;
	while (e--) {
		cin >> a >> b >> c;
		v[a].push_back(Edge(b, c));
	}
	q.push(Edge(start, 0));
	while (!q.empty()) {
		for (Edge next : v[q.top().vertex]) { // for�� ���� ������ ���
			if (distance[next.vertex] > distance[q.top().vertex] + next.dist) {
				next.dist += distance[q.top().vertex];
				distance[next.vertex] = next.dist;
				q.push(next);
			}
		}
		q.pop();
	}
	for (int i = 1; i <= n; i++) {
		if (distance[i] == INT32_MAX) cout << "INF\n";
		else cout << distance[i] << "\n";
	}
}