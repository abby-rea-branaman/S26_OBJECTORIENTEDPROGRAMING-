#include <iostream>
using namespace std;

template <typename T>
class List {
private:
	T* arr;
	int size;
	int count;		

public:
	List(int n) {
		size = n;
		count = 0;
		arr = new T[size];
	}

	List& operator+(const T& value) {
		if (count < size) {
			arr[count++] = value;
		} else {
			cout << "List is full. Cannot add more values." << endl;
		}
		return *this;
	}

	friend ostream& operator<<(ostream& os, const List& list) {
		os << "Values in the list: ";
		for (int i = 0; i < list.count; i++) {
			os << list.arr[i] << " ";
		}
		return os;
	}

	void InputValues() {
		T value{};
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
};

int main() {
	int choice = 0, n = 0;

	cout << "What is the Data Type?" << endl;
	cout << "1. Integer" << endl;
	cout << "2. Float" << endl;
	cout << "3. Double" << endl;
	cout << "Enter your choice: " << endl;
	cin >> choice;

	cout << "Enter size of array" << endl;
	cin >> n;

	if(choice == 1) {
		List<int> intList(n);
		intList.InputValues();
		intList.DisplayValues();
	} else if(choice == 2) {
		List<float> floatList(n);
		floatList.InputValues();
		floatList.DisplayValues();
	} else if(choice == 3) {
		List<double> doubleList(n);
		doubleList.InputValues();
		doubleList.DisplayValues();
	} else {
		cout << "Invalid choice." << endl;
	}

	return 0; 


}