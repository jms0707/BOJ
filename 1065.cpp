#include <iostream>

using namespace std;

int countNum(int n);

int main() {

	int n;
	int result;
	cin >> n;
	if (n / 100 == 0) {
		cout << n;
	}
	else {
		result = countNum(n);
		cout << result;
	}
}

int countNum(int n) {
	int res = 99;
	int a, b, c;
	for (int i = 100; i <= n; i++) {
		if (i == 1000) {
			return res;
		}
		a = i % 10;
		b = (i / 10) % 10;
		c = (i / 100) % 10;
		if (b - a == c - b) {
			res++;
		}
	}
	return res;
}