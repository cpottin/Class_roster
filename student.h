
//  student.h
//  C867 Roster Project
//
//  Created by Cynthia Pottin on 2/22/22.
//

#ifndef student_h
#define student_h

#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#include "degree.h"
using std::string;
using std::cout;
using namespace std;

class Student{
public:
    const static int daysInCourseArray = 3;
private:
    string student_id;
    string first_name;
    string last_name;
    string email_address;
    int age;
    int days_in_course[daysInCourseArray];
    DegreeProgram degree;
    
public:
    Student();
    Student(string student_id, string first_name, string last_name, string email_address, int age, int days_in_course[], DegreeProgram degree);
    
    ~Student(); //destructor


    /*getters aka accessors*/

    string getStudentId();
    string getFirstName();
    string getLastName();
    string getEmailAddress();
    int getAge();
    int* getDaysInCourse();
    DegreeProgram getDegree();
    

    //setters aka mutator
    void setStudentId (string student_id);
    void setFirstName (string first_name);
    void setLastName (string last_name);
    void setEmailAddress (string email_address);
    void setAge (int age);
    void setDaysInCourse (int days_in_course[]);
    void setDegree (DegreeProgram degree);

    
    static void printHeader();//prints header
    
    void print();//prints student data

};
#endif /* student_h */
