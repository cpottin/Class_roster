#pragma once
#include <iostream>
#include <list>
#include "student.h"
#include <string>

using namespace std;


const int numStudents = 5;

string studentData[numStudents] = {"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
"A5,Cynthia,Pottin,cpotti2@my.wgu.edu,38,20,35,58,SOFTWARE",
};

class Roster {

public:
	int lastIndex;
	int capacity;
	Student** classRosterArray; //students is an array of pointers to classRosterArray; so **
	Roster();
	Roster(int capacity);
	void add(string datarow);
	void printAll();
	void remove(string sId);
	void printAverageDaysInCourse(string id);
	void printInvalidEmails();
	void printByDegree(Degree d);
	~Roster(); //destructor

};
