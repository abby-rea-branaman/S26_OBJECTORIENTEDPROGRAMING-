#include <iostream>
#include <cassert>
#include <exception>
#include <string>
#include <limits>
using namespace std;

// Custom exception class for invalid data type selection
class InvalidTypeException : public exception {
private:
    string message;
public:
    InvalidTypeException(int choice) {
        message = "Error: '" + to_string(choice) + "' is not a valid data type selection. Please choose 1 (int), 2 (float), or 3 (double).";
    }
    const char* what() const noexcept override {
        return message.c_str();
    }
};

template <typename T>
class List {
private:
    T* arr;
    int size;
    int count;

public:
    // Constructor: allocates dynamic array of given size
    List(int n) {
        size = n;
        count = 0;
        arr = new T[size];
    }

    // Destructor: frees allocated memory
    ~List() {
        delete[] arr;
    }

    // Overloaded + operator: adds an element to the array
    List& operator+(const T& value) {
        if (count < size) {
            arr[count++] = value;
        }
        else {
            cout << "Array is full. Cannot add more elements." << endl;
        }
        return *this;
    }

    // Overloaded << operator: prints all elements of the List object
    friend ostream& operator<<(ostream& os, const List<T>& list) {
        os << "Array values: ";
        for (int i = 0; i < list.count; i++) {
            os << list.arr[i];
            if (i < list.count - 1)
                os << " ";
        }
        os << endl;
        return os;
    }

    // Prompts user to enter a value for each element, with try/catch validation
    void inputValues() {
        T value;
        for (int i = 0; i < size; i++) {
            while (true) {
                try {
                    cout << "Enter value " << (i + 1) << ": ";
                    cin >> value;

                    // If cin fails, input was the wrong type (e.g. a string/char)
                    if (cin.fail()) {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        throw invalid_argument("Invalid input: please enter a numeric value.");
                    }

                    *this + value;
                    break; // Valid input received, exit retry loop

                }
                catch (const invalid_argument& e) {
                    cout << "Error: " << e.what() << endl;
                }
            }
        }
    }
};

// Prompts for and validates the type choice, throws InvalidTypeException if invalid
int getTypeChoice() {
    int choice;
    cout << "\nSelect data type:" << endl;
    cout << "1. Integer" << endl;
    cout << "2. Float" << endl;
    cout << "3. Double" << endl;

    while (true) {
        cout << "Enter choice (1-3): ";
        cin >> choice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Error: Invalid selection. Please enter 1, 2, or 3." << endl;
            continue;
        }

        if (choice < 1 || choice > 3) {
            throw InvalidTypeException(choice);
        }

        return choice;
    }
}

// Prompts for and validates the array size, asserts it is a positive integer
int getArraySize() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    if (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Assertion failed: array size must be a positive integer. Terminating." << endl;
        assert(false);
    }

    // Assert size is a positive integer; terminates program with message if not
    if (n <= 0) {
        cout << "Assertion failed: array size must be greater than 0. Terminating." << endl;
        assert(n > 0);
    }

    return n;
}

int main() {
    int choice, n;

    // Validate type selection — catch invalid type exception
    try {
        choice = getTypeChoice();
    }
    catch (const InvalidTypeException& e) {
        cout << e.what() << endl;
        return 1;
    }

    // Validate array size — assert terminates if invalid
    n = getArraySize();

    // Instantiate the correct template type and run
    if (choice == 1) {
        List<int> list(n);
        list.inputValues();
        cout << list;
    }
    else if (choice == 2) {
        List<float> list(n);
        list.inputValues();
        cout << list;
    }
    else {
        List<double> list(n);
        list.inputValues();
        cout << list;
    }

    return 0;
}