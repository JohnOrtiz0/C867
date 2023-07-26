 #include "student.h"
#include <iostream>
using namespace std;


Student::Student() {
    studentID = "None";
    firstName = "None";
    lastName = "None";
    emailAddress = "None";
    age = 0;
    numDaysToComplete[0] = 0;
    numDaysToComplete[1] = 0;
    numDaysToComplete[2] = 0;
    degreeProgram = SOFTWARE;
}


Student::Student(string studentID, string firstName, string lastName, string emailAddress, int ageYears, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram) {
    this->studentID = studentID;
    this->firstName = firstName;
    this->lastName = lastName;
    this->emailAddress = emailAddress;
    age = ageYears;
    numDaysToComplete[0] = daysInCourse1;
    numDaysToComplete[1] = daysInCourse2;
    numDaysToComplete[2] = daysInCourse3;
    this->degreeProgram = degreeProgram;
}


void Student::SetStudentID(string studentID) {
    this->studentID = studentID;
}


void Student::SetFirstName(string firstName) {
    this->firstName = firstName;
} 


void Student::SetLastName(string lastName) {
    this->lastName = lastName;
}


void Student::SetEmailAddress(string emailAddress) {
    this->emailAddress = emailAddress;
}


void Student::SetAge(int ageYears) {
    age = ageYears;
}


void Student::SetNumDaysToComplete(int daysInCourse1, int daysInCourse2, int daysInCourse3) {
    numDaysToComplete[0] = daysInCourse1;
    numDaysToComplete[1] = daysInCourse2;
    numDaysToComplete[2] = daysInCourse3;
}


void Student::SetDegreeProgram( DegreeProgram program) {
    degreeProgram = program;
}


string Student::GetStudentID() {
    return studentID;
}


string Student::GetFirstName() {
    return firstName;
}


string Student::GetLastName() {
    return lastName;
}


string Student::GetEmailAddress() {
    return emailAddress;
}


int Student::GetAge() {
    return age;
}


int Student::GetNumDaysToComplete(int courseID) {
    return numDaysToComplete[courseID];
}


DegreeProgram Student::GetDegreeProgram() {
    return degreeProgram;
}


void Student::PrintInfo() {
    cout << "StudentID: " << studentID << "    ";
    cout << "First Name: " << firstName << "    ";
    cout << "Last Name: " << lastName << "    ";
    cout << "Age: " << age << "    ";
    cout << "Days in course: {" << numDaysToComplete[0] << ", " << numDaysToComplete[1] << ", " << numDaysToComplete[2] << "}" << "    ";
    cout << "Degree Program: " << degreeProgram << endl;
}


Student::~Student() {

}