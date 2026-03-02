#include <iostream>
#include <string>
using namespace std;

// Struct to hold user information
struct Person {
	string name;
	int age;
	string gender;
	int heightFeet;
	int heightInches;
	int weightPounds;
	int totalInches;
	double bmi;
	string bmiCategory;
};

void getUserInfo(Person& user);
void calculateBMI(Person& user);
void determineBMICategory(Person& user);
void displayResults(const Person& user);

int main() {
	Person user;
	getUserInfo(user);
	calculateBMI(user);
	determineBMICategory(user);
	displayResults(user);
}

// Asks for User Info
void getUserInfo(Person& user) {
	cout << "What is your name? ";
	getline(cin, user.name);
	cout << "What is your age? ";
	cin >> user.age;
	cout << "What is your gender";
	cin >> user.gender;
	cout << "What is your height in feet? ";
	cin >> user.heightFeet;
	cout << "What is your height in inches? ";
	cin >> user.heightInches;
	cout << "What is your weight in pounds? ";
	cin >> user.weightPounds;
}

// Converts height to inches and calculates BMI
void calculateBMI(Person& user) {
	user.totalInches = (user.heightFeet * 12) + user.heightInches;
	user.bmi = (user.weightPounds / (user.totalInches * user.totalInches)) * 703;
}

// Determines BMI category based on calculated BMI
void determineBMICategory(Person& user) {
	if (user.bmi < 16) {
		user.bmiCategory = "Severely Underweight";
	}
	else if (user.bmi >= 16 && user.bmi < 17) {
		user.bmiCategory = "Moderate Underweight";
	}
	else if (user.bmi >= 17 && user.bmi < 18.5) {
		user.bmiCategory = "Mild Underweight";
	}
	else if (user.bmi >= 18.5 && user.bmi < 25) {
		user.bmiCategory = "Normal weight";
	}
	else if (user.bmi >= 25 && user.bmi < 30) {
		user.bmiCategory = "Overweight";
	}
	else if (user.bmi >= 30 && user.bmi < 35) {
		user.bmiCategory = "Obese Class I";
	}
	else if (user.bmi >= 35 && user.bmi < 40) {
		user.bmiCategory = "Obese Class II";
	}
	else {
		user.bmiCategory = "Obese Class III";
	}
}

// Displays the results to the user
void displayResults(const Person& user) {
	cout << "Name: " << user.name << endl;
	cout << "Age: " << user.age << endl;
	cout << "Gender: " << user.gender << endl;
	cout << "Height: " << user.heightFeet << " feet " << user.heightInches << " inches" << endl;
	cout << "Weight: " << user.weightPounds << " pounds" << endl;
	cout << "" << endl;
	cout << "BMI: " << user.bmi << endl;
	cout << "BMI Category: " << user.bmiCategory << endl;
}