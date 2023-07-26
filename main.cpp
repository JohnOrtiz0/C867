#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include "degree.h"
#include "student.h"
#include "roster.h"

using namespace std;

int main() {

	Roster* classRoster = new Roster();
	DegreeProgram degreeProgram;
	int i;

	cout << "Scripting and Programming - Applications – C867" << endl;
	cout << "Programming language : C++" << endl;
	cout << "WGU studentID: 008152142" << endl;
	cout << "John Ortiz" << endl;
	cout << endl;

	const string studentData[] = {
		"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
		"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
		"A3,Jock,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
		"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
		"A5,John,Ortiz,Jort252@wgu.edu,26,10,3,8,SOFTWARE"
	};


	for (i = 0; i < classRoster->classRosterLength; i++) {
		stringstream stream(studentData[i]);

		vector<string> studentInfo;

		while (stream.good()) {
			string substring;
			getline(stream, substring, ',');
			studentInfo.push_back(substring);
		}

		if (studentInfo.at(8) == "SOFTWARE") {
			degreeProgram = SOFTWARE;
		}

		if (studentInfo.at(8) == "NETWORK") {
			degreeProgram = NETWORK;
		}

		if (studentInfo.at(8) == "SECURITY") {
			degreeProgram = SECURITY;
		}

		classRoster->Add(studentInfo.at(0), studentInfo.at(1), studentInfo.at(2), studentInfo.at(3), stoi(studentInfo.at(4)), stoi(studentInfo.at(5)), stoi(studentInfo.at(6)), stoi(studentInfo.at(7)), degreeProgram);
	}
	
	
	classRoster->PrintAll();
	cout << endl;
	
	classRoster->PrintInvalidEmails();
	cout << endl;


	//AVERAGE TIME TO COMPLETE CLASSES
	for (i = 0; i < classRoster->classRosterLength; i++) {
		string studentID = "A" + to_string(i + 1);
		classRoster->PrintAverageDaysInCourse(studentID);
	}

	cout << endl;


	//PRINT BY DEGREE PROGRAM
	classRoster->PrintByDegreeProgram(SOFTWARE);

	cout << endl;

	//REMOVE STUDENT WITH ID A3
	classRoster->Remove("A3");

	//PRINT ALL FUNCTION
	classRoster->PrintAll();

	cout << endl;

	//TRY TO REMOVE A3 AGAIN
	classRoster->Remove("A3");

	return 0;
}
