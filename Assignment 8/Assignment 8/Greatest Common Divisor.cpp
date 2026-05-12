#include <iostream>
using namespace std;

int gcd(int a, int b) {
	if (b == 0) {
		return a;
	}
	return gcd(b, a % b);
}

int main() {
	int num1, num2;
	
	cout << "Enter two numbers: ";
	cout << endl;
	
	cout << "Number 1: ";
	cin >> num1;
	cout << "Number 2: ";
	cin >> num2;

	int result = gcd(num1, num2);

	cout << "The greatest common divisor of " << num1 << " and " << num2 << " is: " << result << endl;
}