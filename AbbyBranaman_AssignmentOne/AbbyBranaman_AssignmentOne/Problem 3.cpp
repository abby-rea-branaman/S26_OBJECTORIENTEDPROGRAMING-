#include <iostream>
#include <string>
using namespace std;

// Problem Three: Finding the smallest index 

int smallestIndex(int arr[], int size) {
	int smallNum = arr[0];
	int smallIndex = 0;

	for (int i = 1; i < size; i++) {
		if (arr[i] < smallNum) {
			smallNum = arr[i];
			smallIndex = i;
		}
	}

	return smallIndex;
}

int main() {
	int arr[] = {5, 2, 9, 1, 5, 6};
	int size = sizeof(arr) / sizeof(arr[0]);
	int index = smallestIndex(arr, size);
	cout << "The smallest index is: " << index << endl;
	return 0;
}