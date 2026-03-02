#include <iostream>
#include <string>
using namespace std;

const int NUM_STUDENTS = 5;

struct studentType {
	string firstName;
	string lastName;
	int testScore;
	char grade;
};

void getStudentInfo(studentType students[]);
void assignGrades(studentType students[]);
int findHighestScore(studentType students[]);
void printStudents(studentType students[]);
void printHighestScorers(studentType students[], int highestScore);

int main() {
	studentType students[NUM_STUDENTS];
	int highestScore;
	
	getStudentInfo(students);
	highestScore = findHighestScore(students);
	assignGrades(students);
	printStudents(students);
	printHighestScorers(students, highestScore);
	
	return 0;
}

void getStudentInfo(studentType students[]) {
	for (int i = 0; i < NUM_STUDENTS; i++) {
		cout << "Enter first name for student " << (i + 1) << ": ";
		cin >> students[i].firstName;
		cout << "Enter last name for student " << (i + 1) << ": ";
		cin >> students[i].lastName;
		cout << "Enter test score for student " << (i + 1) << ": ";
		cin >> students[i].testScore;
	}
}

void assignGrades(studentType students[]) {
	for (int i = 0; i < NUM_STUDENTS; i++) {
		if (students[i].testScore >= 90) {
			students[i].grade = 'A';
		} else if (students[i].testScore >= 80) {
			students[i].grade = 'B';
		} else if (students[i].testScore >= 70) {
			students[i].grade = 'C';
		} else if (students[i].testScore >= 60) {
			students[i].grade = 'D';
		} else {
			students[i].grade = 'F';
		}
	}
}

int findHighestScore(studentType students[]) {
	int highestScore = students[0].testScore;
	for (int i = 1; i < NUM_STUDENTS; i++) {
		if (students[i].testScore > highestScore) {
			highestScore = students[i].testScore;
		}
	}
	return highestScore;
}

void printStudents(studentType students[]) {
	cout << "Student Information:\n";
	for (int i = 0; i < NUM_STUDENTS; i++) {
		cout << students[i].firstName << " " << students[i].lastName 
			 << " - Score: " << students[i].testScore 
			 << ", Grade: " << students[i].grade << endl;
	}
}

void printHighestScorers(studentType students[], int highestScore) {
	cout << "Highest Scorers:\n";
	for (int i = 0; i < NUM_STUDENTS; i++) {
		if (students[i].testScore == highestScore) {
			cout << students[i].lastName << " " << students[i].firstName 
				 << " - Score: " << students[i].testScore 
				 << ", Grade: " << students[i].grade << endl;
		}
	}
}
