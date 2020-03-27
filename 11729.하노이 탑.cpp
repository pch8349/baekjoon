#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

void hannoi(int, int, int, int);

int main() {
	int n, a = 1, b = 2, c = 3, t;
	scanf("%d", &n);
	t = pow(2, n) - 1;
	printf("%d\n", t);
	hannoi(n, a, b, c);
}

void hannoi(int n, int a, int b, int c) {
	if (n == 1) {
		printf("%d %d\n", a, c);
	}
	else {
		hannoi(n - 1, a, c, b);
		printf("%d %d\n", a, c);
		hannoi(n - 1, b, a, c);
	}
}