#include <iostream>

using namespace std;

void bubble_sort(int* a, int b) {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9 - i - 1; j++) {
			if (*(a + j) > *(a + j + 1)) {
				int temp = *(a + j);
				*(a + j) = *(a + j + 1);
				*(a + j + 1) = temp;
			}
		}
	}
}

int main() {
	int a[9] = { 3,5,32,53,2,4,2,45,12 };

	int* ptr = a;

	bubble_sort(a, 9);


	for (int i = 0; i < 9; i++) {
		cout << *(ptr + i) << " ";
	}

	return 0;
}
