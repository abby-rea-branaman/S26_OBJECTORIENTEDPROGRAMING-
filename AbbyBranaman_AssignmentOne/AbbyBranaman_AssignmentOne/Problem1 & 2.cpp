#include <iostream>
#include <string>
using namespace std;

// Problem One: Checks for the vowels in a string
bool isVowel(char c) {
	char lowerC = tolower(c);
	return lowerC == 'a' || lowerC == 'e' || lowerC == 'i' || lowerC == 'o' || lowerC == 'u';
}

// Problem Two: Removes the vowels from a string
string removeVowels(string str) {
	string result = "";
	for (char c : str) {
		if (!isVowel(c)) {
			result += c; 
		}
	}
	return result;
}

int main() {
	// User Input of a word
	cout << "Enter a set of words: ";
	string input;
	getline(cin, input);

	// Counts the number of vowels in the string
	int vowelCount = 0;

	for (char c : input) {
		if (isVowel(c)) {
			vowelCount++;
		}
	}

	// Prints the number of vowels in the string
	cout << "Number of vowels: " << vowelCount << endl;

	// After counting the vowels, removes the vowels from the string and prints the new string
	string str = removeVowels(input);
	cout << "String without vowels: " << str << endl;
	
	return 0;

}