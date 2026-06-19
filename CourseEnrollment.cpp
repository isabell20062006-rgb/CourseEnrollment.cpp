// Name: Angelle Sumrall
// Date: 6/18/2026
// Course: COSC 1437 C++ Programming Fundamentals II
// Desc: Chapter 7 Lab - Student Course Enrollment System

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

//Part 4: Namespace Definition
namespace EnrollmentSystem {

    // Part 1: Enumeration Type: courseType
    enum courseType {
        ENGLISH,
        MATH,
        HISTORY,
        CPP,
        BIOLOGY,
        ART
    } currentCourse;

    //Part 2: Typedef Statment
    typedef int StudentID;
    typedef double CreditHours;

    void printCourse(courseType c);
    courseType readCourse();
    double calcTuition(CreditHours credits);
    void printStudentInfo(string fullName, string email, courseType course, StudentID id, CreditHours credits);
}

using namespace EnrollmentSystem;

// Part 1b: printCourse Function Definition
void EnrollmentSystem::printCourse(courseType c) {
    switch (c) {
    case ENGLISH:  cout << "English Composition"; break;
    case MATH:     cout << "College Algebra";     break;
    case HISTORY:  cout << "U.S. History";        break;
    case CPP:      cout << "C++ Programming";     break;
    case BIOLOGY:  cout << "General Biology";     break; 
    case ART:      cout << "Art Appreciation";    break;
    default:       cout << "Unknown Course";      break;
    }
}

// Part 1c: ReadCourse Function Definition
EnrollmentSystem::courseType EnrollmentSystem::readCourse() {
    string input;
    cout << "Enter course (english/math/history/cpp/biology/art): ";
    cin >> input;

    if (input == "english") return ENGLISH;
    else if (input == "math") return MATH;
    else if (input == "history") return HISTORY;
    else if (input == "cpp") return CPP;
    else if (input == "biology") return BIOLOGY;
    else if (input == "art") return ART;
    else {
        cout << "Invalid entry. Defaulting to English Composition.";
        return ENGLISH;
    }
}
// Part 2: CalcTuition Function Definition
double EnrollmentSystem::calcTuition(CreditHours credits) {
    return credits * 150.0;
}

// Part 3b: PrintStudentInfo Function Definition
void EnrollmentSystem::printStudentInfo(string fullName, string email, courseType course, StudentID id, CreditHours credits) {
    cout << endl << "--- Enrollment Summary ---" << endl;
    cout << "Student Full Name: " << fullName << endl;
    cout << "Student ID:        " << id << endl;
    cout << "Student Email:     " << email << endl;
    cout << "Enrolled Course:   ";
    printCourse(course);
    cout << endl;
    cout << "Credit Hours:      " << credits << endl;