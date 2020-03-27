#include <iostream>
using namespace std;

int main() {
	int a, b, c, n, x = 0, y = 0, z = 0, t = 0;
	cin >> a >> b >> c >> n;
	while (t == 0) {
		while (t == 0) {
			while (t == 0) {
				if (x + y + z > n) {
					z = 0;
					break;
				}
				else if (x + y + z == n) {
					cout << "1" << endl;
					t = 1;
				}
				z += c;
			}
			if (y > n) {
				y = 0;
				break;
			}
			y += b;
		}
		if (x > n) {
			cout << "0" << endl;
			break;
		}
		x += a;
	}
}