#include "roster.h"
#include "student.h"
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;


Roster::Roster() {
}


void Roster::Add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram) {

	int studentIndex = 0;

	while (classRosterArray[studentIndex] != nullptr) {
		studentIndex++;
	}
	
	classRosterArray[studentIndex] = new Student(studentID, firstName, lastName, emailAddress, age, daysInCourse1, daysInCourse2, daysInCourse3, degreeProgram);
	
}

void Roster::Remove(string studentID) {

	for (int i = 0; i < classRosterLength; i++) {
		if (classRosterArray[i] != nullptr && classRosterArray[i]->GetStudentID() == studentID) {
			classRosterArray[i] = nullptr;
		}
		else if (classRosterArray[i] == nullptr) {
			cout << "ERROR: Student not found." << endl;
		}
	}
}


void Roster::PrintAll() {

	for (int i = 0; i < classRosterLength; i++) {
		if (classRosterArray[i] != nullptr) {
			classRosterArray[i]->PrintInfo();
		}
	}
}


void Roster::PrintAverageDaysInCourse(string studentID) {

	for (int i = 0; i < classRosterLength; i++) {
		if (classRosterArray[i] != nullptr && classRosterArray[i]->GetStudentID() == studentID) {
			double average = (double) classRosterArray[i]->GetNumDaysToComplete(0) + (double) classRosterArray[i]->GetNumDaysToComplete(1) + (double) classRosterArray[i]->GetNumDaysToComplete(2) / 3.0;
			cout << fixed << setprecision(1);
			cout << average << endl;
		}
	}
}


void Roster::PrintInvalidEmails() {
	string email;

	for (int i = 0; i < classRosterLength; i++) {
		if (classRosterArray[i] != nullptr) {
			email = classRosterArray[i]->GetEmailAddress();
		}
	
		if (email.find('@') == string::npos) {
			cout << "Invalid email address, no '@' found in: " << email << endl;
		} 

		if (email.find('.') == string::npos) {
			cout << "Invalid email address, no '.' found in: " << email << endl;
		}

		if (email.find(' ') != string::npos) {
			cout << "Invalid email address, found whitespace in: " << email << endl;
		}
	}
}


void Roster::PrintByDegreeProgram(DegreeProgram degreeProgram) {

	for (int i = 0; i < classRosterLength; i++) {
		if (classRosterArray[i] != nullptr && classRosterArray[i]->GetDegreeProgram() == degreeProgram) {
			classRosterArray[i]->PrintInfo();
		}
	}
}


Roster::~Roster() {
	delete[] classRosterArray;
}