#include <iostream>
#include <string>
#include "NetworkStudent.h"
#include "SecurityStudent.h"
#include "softwarestudent.h"
#include "roster.h"
#include "degree.h"
#include "student.h"

using namespace std;

Roster::Roster()//empty
{
	this->capacity = 0;
	this->lastIndex = -1;
	this->classRosterArray = nullptr;
}

Roster::Roster(int capacity)
{
	this->capacity = capacity;
	this->lastIndex = -1;
	this->classRosterArray = new Student*[capacity];
}


void Roster::add(string row)
{
	if (lastIndex < capacity) {
		lastIndex++;
		int daysInCourseArray[Student::daysInCourseArraySize];

		if (row.substr(row.length()-8, 8) == "SOFTWARE") {
			this->classRosterArray[lastIndex] = new SoftwareStudent();
			classRosterArray[lastIndex]->setDegree(SOFTWARE);
		}

		else if (row.substr(row.length()-7, 7) == "NETWORK") {
			this->classRosterArray[lastIndex] = new NetworkStudent();
			classRosterArray[lastIndex]->setDegree(NETWORK);
		}

		else if (row.substr(row.length()-8, 8) == "SECURITY") {
			this->classRosterArray[lastIndex] = new SecurityStudent();
			classRosterArray[lastIndex]->setDegree(SECURITY);
		}

		//set SID
		int rhs = studentData[lastIndex].find(",");
		classRosterArray[lastIndex]->setStudentId(studentData[lastIndex].substr(0, rhs));

		//set fname
		int lhs = rhs + 1;
		rhs = studentData[lastIndex].find(",", lhs);
		classRosterArray[lastIndex]->setFirstName(studentData[lastIndex].substr(lhs, rhs - lhs));

		lhs = rhs + 1;
		rhs = studentData[lastIndex].find(",", lhs);
		classRosterArray[lastIndex]->setLastName(studentData[lastIndex].substr(lhs, rhs - lhs));

		lhs = rhs + 1;
		rhs = studentData[lastIndex].find(",", lhs);
		classRosterArray[lastIndex]->setEmailAddress(studentData[lastIndex].substr(lhs, rhs - lhs));

		lhs = rhs + 1;
		rhs = studentData[lastIndex].find(",", lhs);
		classRosterArray[lastIndex]->setAge(stoi(studentData[lastIndex].substr(lhs, rhs - lhs)));

		//numdays0
		lhs = rhs + 1;
		rhs = studentData[lastIndex].find(",", lhs);
		daysInCourseArray[0] = stoi(studentData[lastIndex].substr(lhs, rhs - lhs));

		//numdays1
		lhs = rhs + 1;
		rhs = studentData[lastIndex].find(",", lhs);
		daysInCourseArray[1] = stoi(studentData[lastIndex].substr(lhs, rhs - lhs));

		//numdays2
		lhs = rhs + 1;
		rhs = studentData[lastIndex].find(",", lhs);
		daysInCourseArray[2] = stoi(studentData[lastIndex].substr(lhs, rhs - lhs));

		classRosterArray[lastIndex]->setDaysInCourse(daysInCourseArray);
	}
}

void Roster::remove(string studentID)
{
	for (int i = 0; i <= lastIndex; ++i) {
		if (classRosterArray[i] == nullptr) {
			cout << "Error: Student with ID: " << studentID << " not found" << endl;
			break;
		}
		else if (studentID == classRosterArray[i]->getStudentId()) {
			classRosterArray[i] = nullptr;
			cout << "Student removed" << endl;
		}
	}
}
void Roster::printAll()
{
	for (int i = 0; i <= this->lastIndex; i++) {
		(this->classRosterArray)[i]->print();
	}
}

void Roster::printAverageDaysInCourse(string studentId)
{
	bool found = false;
	for (int i = 0; i <= lastIndex; ++i) {
		if (this->classRosterArray[i]->getStudentId() == studentId) {
			found = true;
			int* daysInCourse = classRosterArray[i]->getDaysInCourse();
			cout << "Average number of days per course for student ID: " << studentId << " is " << (daysInCourse[0] + daysInCourse[1] + daysInCourse[3]) / 3 << endl;

		}
	}
}

void Roster::printInvalidEmails()
{
	for (int i = 0; i <= lastIndex; ++i) {
		string emailAddress = classRosterArray[i]->getEmailAddress();
		if ((eaddress.find("@") == string::npos) || (eaddress.find(" ") != string::npos) || (email.find(".") == string::npos)){
			cout << "This email for student: " << classRosterArray[i]->getFirstName() << " " << classRosterArray[i]->getLastName() << " is not valid: " << emailAddress << endl;
	}
	}
}

void Roster::printdegree(Degree degree)
{
	cout << "Student Roster by Degree: "  << degreeTypeString[degree] << "\n";
		for (int i = 0; i <= lastIndex; ++i) {
			if (this->classRosterArray[i]->getDegree() == degree) this->classRosterArray->print();

		}
}

Roster::~Roster()
{
	for (int i = 0; i < numStudents; i++)
	{
		delete this->classRosterArray[i];
	}
	delete this;
}

int main()
{

	const int numStudents = 5;

	string studentData[numStudents] = {
"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",

	"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",

	"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",

	"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",

	"A5,Cynthia,Pottin,cpotti2@my.wgu.edu,38,20,35,58,SOFTWARE",
	};

cout << "Scripting and Programming - Applications C867" << endl;
cout << "Student ID # 001075237" << endl;
cout << "Cynthia Pottn" << endl;
cout << endl;

	Roster* classroster = new Roster(numStudents);
	for (int i = 0; i < numStudents; ++i) {
		classRoster->add(studentData[i]);
	}
	
	cout << "Displaying all Students:\n";
	roster->printAll();
	cout << endl;

	cout << "Invalid Emails" << endl;
	roster->printInvalidEmails();
	cout << endl;

	cout << "Average days in class for student" << endl;
	for (int i = 0; i < numStudents; ++i) {
		roster->printAverageDaysInCourse(Roster->classRosterArray[i]->getStudentId());
	}

	roster->printDegree(SOFTWARE);
	cout << endl;

	Roster.remove("A3");
	cout << endl;

	Roster.remove("A3");
	cout << endl;

	}

Roster::~Roster() {}
