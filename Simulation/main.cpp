#include <iostream>

struct a {
	int b = 1;
};

int main() {

	a** f;

	f = new a* [10];
	for (int i{ 0 }; i < 10; i++) {
		f[i] = new a[10];
	}

	return 0;
}