#include <iostream>

using namespace std;

void swapp(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

int main() {
	int a[9] = { 3,5,32,53,2,4,2,45,12 };

	int* ptr = a;

	for (int i = 0; i < 9; i++) {
		for (int j = i + 1; j < 9; j++) {
			if (a[i] > a[j])
				swapp(&a[i], &a[j]);
		}
	}

	for (int i = 0; i < 9; i++) {
		cout << *(ptr + i) << " ";
	}

	return 0;
}
