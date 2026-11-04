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

int* binarysearchIt(int* begin, int* end, int target) {
	while (begin < end) {
		int* mid = begin + (end - begin) / 2;
		if (*mid == target) return mid;
		if (*mid < target) begin = mid + 1;
		else  end = mid;
	}
	return NULL;
}

int* binarysearchRe(int* begin, int* end, int target) {
	if (begin >= end) return NULL;

	int* mid = begin + (end - begin) / 2;
	if (*mid == target) return mid;
	if (*mid < target) return binarysearchRe(mid + 1, end, target);

	return binarysearchRe(begin, mid, target);
}


int main() {
	int a[9] = { 3,5,32,53,2,4,2,45,12 };

	int* ptr = a;

	bubble_sort(a, 9);

	int* found = binarysearchIt(a, a+9, 74);
	int* foundre = binarysearchRe(a, a + 9, 24);

	if (found)  cout << "postoi";
	if (foundre) cout << "postoi (rekurzivno)";


	for (int i = 0; i < 9; i++) {
		cout << *(ptr + i) << " ";
	}

	return 0;
}
