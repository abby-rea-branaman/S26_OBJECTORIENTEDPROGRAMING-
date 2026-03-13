#include <iostream>
#include <string>
using namespace std;

class studentType
{
private:
	string fName;
	string lName;
	int id;
	double gpa;

public:
	studentType()
	{
		fName = "";
		lName = "";
		id = 0;
		gpa = 0.0;
	}

	studentType(string firstName, string lastName, int studentID, double studentGPA)
	{
		fName = firstName;
		lName = lastName;
		id = studentID;
		gpa = studentGPA;
	}

	void setStudentInfo(string firstName, string lastName, int studentID, double studentGPA)
	{
		fName = firstName;
		lName = lastName;
		id = studentID;
		gpa = studentGPA;
	}

	string getFirstName()
	{
		return fName;
	}
	string getLastName()
	{
		return lName;
	}
	int getID()
	{
		return id;
	}
	double getGPA()
	{
		return gpa;
	}

	void displayStudentInfo()
	{
		cout << "Student Information:" << endl;
		cout << "Name: " << fName << " " << lName << endl;
		cout << "ID: " << id << endl;
		cout << "GPA: " << gpa << endl;
	}
};

int main()
{
	studentType student1("Kay", "Dahkla", 1111, 2.5);
	student1.displayStudentInfo();

	cout << endl;

	studentType student2("Aubrey", "Lemon", 12222, 4.0);
	student2.displayStudentInfo();
	return 0;
}