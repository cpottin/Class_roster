

//  main.cpp
//  C867 Roster Project
//
//  Created by Cynthia Pottin on 2/22/22.
//

#include <iostream>
#include "roster.h"
#include <iostream>
#include <string>
using namespace std;




int main() {
    cout << "Application: Xcode" << endl;
    cout << "C867 - Scripting & Programming: Applications" << endl;
    cout << "Programing Language: C++" << endl;
    cout << "Student ID: 001075237 " << endl;
    cout << "Name: Cynthia Pottin" << endl;
    
    const string studentData[] =
    {
        "A1, John, Smith, John1989@gm ail.com, 20, 30, 35, 40, SECURITY",
        "A2, Suzan, Erickson, Erickson_1990@gmailcom, 19, 50, 30, 40, NETWORK",
        "A3, Jack, Napoli, The_lawyer99yahoo.com, 19, 20, 40, 33, SOFTWARE",
        "A4, Erin, Black, Erin.black@comcast.net, 22, 50, 58, 40, SECURITY",
        "A5, Cynthia, Pottin, cpotti2@my.wgu.edu, 46, 30, 45, 60, SOFTWARE"
        
    };
    const int numStudents = 5;
    
    Roster roster; //creates roster
    
    for (int i=0; i < numStudents; i++) roster.parse(studentData[i]);
    cout << "Displaying all students: " << std::endl;
    roster.printAll();
    cout << std::endl;
    
    for (int i = 0; i < 3; i++)
    {
        cout << "Display Students by Degree Program:" << degreeProgramStrings[i] << std::endl;
        roster.printByDegreeProgram((DegreeProgram)i);
    }
    
    cout << "Display Students with email address:" << std::endl;
    roster.printInvalidEmails();
    cout << std::endl;
    
    cout << "Displaying average days in course: " << std::endl;
    roster.printAverageDaysInCourse();
    
    cout << "Removing studnet with ID A3: " << std::endl;
    roster.removeStudentByID("A3");
    cout << std::endl;
    
    return 0;
}
