#ifndef STUDENTH
#define STUDENTH

#include "degree.h"
#include <string>

using namespace std;

class Student {
   
public:

    Student();
    
    Student(string studentID, string firstName, string lastName, string emailAddress, int ageYears, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram);

    ~Student();
    
    void SetStudentID(string studentID);
    
    void SetFirstName(string firstName);
    
    void SetLastName(string lastName);
    
    void SetEmailAddress(string emailAddress);
    
    void SetAge(int ageYears);
    
    void SetNumDaysToComplete(int daysInCourse1, int daysInCourse2, int daysInCourse3);
    
    void SetDegreeProgram(DegreeProgram program);

    string GetStudentID();
    
    string GetFirstName();
    
    string GetLastName();
    
    string GetEmailAddress();
    
    int GetAge();
    
    int GetNumDaysToComplete(int courseID);
    
    DegreeProgram GetDegreeProgram();
    
    void PrintInfo();

protected:

    string studentID;
    string firstName;
    string lastName;
    string emailAddress;
    int age;
    int numDaysToComplete[3];
    DegreeProgram degreeProgram;
};
#endif