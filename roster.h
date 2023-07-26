#ifndef ROSTERH
#define ROSTERH

#include "degree.h"
#include "student.h"
#include <array>
#include <string>
using namespace std;

class Roster {

public:

	Roster();

	void Add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int DaysInCourse2, int daysInCourse3, DegreeProgram degreeProgram);

	void Remove(string studentID);

	void PrintAll();

	void PrintAverageDaysInCourse(string studentID);

	void PrintInvalidEmails();

	void PrintByDegreeProgram(DegreeProgram degreeProgram);

	~Roster();

	int classRosterLength = 5;	

	Student* classRosterArray[5] = { nullptr };
};
#endif
		