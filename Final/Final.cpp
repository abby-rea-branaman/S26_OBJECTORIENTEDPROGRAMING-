#include <iostream>
using namespace std;

class List {
private:
	char* arr;
	int size;

public:
	List(int n) {
		size = n;
		arr = new char[size];
	}

	void InputValues() {
		for (int i = 0; i < size; i++) {
			cout << "Enter value " << i + 1 << ": ";
			cin >> arr[i];
		}
	}

	void DisplayValues() {
		cout << "Values in the list: ";
		for (int i = 0; i < size; i++) {
			cout << arr[i] << " ";
		}
		cout << endl;
	}

	~List() {
		delete[] arr;
	}

	int main() {
		int n;
		cout << "Enter the number of elements: ";
		cin >> n;
		
		List myList(n);
		myList.InputValues();
		myList.DisplayValues();
		
		return 0;
	
	}
};