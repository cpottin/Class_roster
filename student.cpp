
//  student.cpp
//  C867 Roster Project
//
//  Created by Cynthia Pottin on 2/22/22.
//

#include <stdio.h>
#include "student.h"
#include<iostream>
#include <iomanip>
#include "degree.h"
using namespace std;

//empty string student record with default values 0 for int and undecided for degree program
Student::Student()
{
    this->student_id = "";
    this->first_name = "";
    this->last_name = "";
    this->email_address = "";
    this-> age = 0;
    for (int i =0; i < daysInCourseArray; i++) this->days_in_course[i] = 0;
    this->degree = DegreeProgram::SECURITY;
}

//constructor
Student::Student(string student_id, string first_name, string last_name, string email_address, int age, int days_in_course[], DegreeProgram degree)
{
    this->student_id = student_id;
    this->first_name = first_name;
    this->last_name = last_name;
    this->email_address = email_address;
    this->age = age;
    for (int i = 0; i < daysInCourseArray; i++) this-> days_in_course[i] = days_in_course[i];
    this->degree = degree;
}

Student::~Student() {} //destructor

//getters
string Student::getStudentId() {
    return this->student_id;
}

string Student::getFirstName() {
    return this->first_name;
}

string Student::getLastName() {
    return this-> last_name;
}

string Student::getEmailAddress() {
    return this->email_address;
}

int Student::getAge() {
    return this->age;
}

int* Student::getDaysInCourse() {
    return this->days_in_course;
}

DegreeProgram Student::getDegree() {
    return this->degree;
}

//setters
void Student::setStudentId(string student_id) {
        this->student_id = student_id;
}

void Student::setFirstName(string first_name) {
        this->first_name = first_name;
}

void Student::setLastName(string last_name) {
        this->last_name = last_name;
}

void Student::setEmailAddress(string email_address){
        this->email_address = email_address;
}

void Student::setAge(int age){
        this->age = age;
}

void Student::setDaysInCourse(int days_in_course[]){
        for (int i = 0; i < daysInCourseArray; i++) {
            this->days_in_course[i] = days_in_course[i];
        }
}

void Student::setDegree(DegreeProgram degree){
    this->degree = degree;
}

//print student record
void Student::printHeader()//use print headers
{
    cout<< "Output format: Student ID|First Name|Last Name|Email|Age|Days In Course|Degree\n";
}

void Student::print()
{
    cout << student_id<< "\t"; //tab at the end
    cout << first_name << "\t";
    cout << last_name<< "\t";
    cout << email_address << "\t";
    cout << age << "\t";
    cout << days_in_course[0] << ",";
    cout << days_in_course[1] << ",";
    cout << days_in_course[2] << "\t";
    cout << degreeProgramStrings[degree]<<"\n"; //degree to string
    
}
