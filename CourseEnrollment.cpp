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
    cout << fixed << setprecision(2);
    cout << "Tuition Balance:   $" << calcTuition(credits) << endl;
}

int main () {
    cout << fixed << setprecision(2);

// Part 3: Welcome Banner Concatenation
    string line = "=====================================";
    string welcomeBanner = line + "STUDENT ENROLLMENT APPLICATION" + line;
    cout << welcomeBanner << endl << endl;

 // Part 3: string Type Operations
    string firstName, lastName, fullName;
    string emailUser, email;

    cout << "Enter first name: ";
    cin >> firstName;
    cout << "Enter last name: ";
    cin >> lastName;
    fullName = firstName + " " + lastName;
    cout << "Full Name Length: " << fullName.length() << " characters" << endl;

    size_t spaceLocation = fullName.find(' ');
    string extractedFirst = fullName.substr(0, spaceLocation);
    cout << "Extracted First Name: " << extractedFirst << endl;

    cout << "First Initial: " << fullName.at(0) << endl;
    cout << "Space Character Position: Index " << fullName.find(' ') << endl;

    cout << "Enter email username (e.g. jsmith): ";
    cin >> emailUser;

    if (!emailUser.empty()) {
        email = emailUser;
        email.insert(email.length(), "@sanjac.edu");
        cout << "Generated Base Email: " << email << endl;

        size_t typoPos = email.find("sanjac");
        if (typoPos != string::npos) {
            email.replace(typoPos, 6, "SanJack");
            cout << "Corrected Email Profile: " << email << endl;
        }

        if (email.back() == '.' || email.back() == '!') {
            email.erase(email.length() - 1, 1);
            cout << "Sanitized Email Profile: " << email << endl;
        }
    }

    string lastName2 = "Smith";
    int comparison = lastName.compare(lastName2);
    cout << "Comparing user last name (" << lastName << ") with benchmark (" << lastName2 << "):" << endl;
    if (comparison < 0) {
        cout << " -> " << lastName << " comes before " << lastName2 << " alphabetically." << endl;
    } else if (comparison > 0) {
        cout << " -> " << lastName << " comes after " << lastName2 << " alphabetically." << endl;
    } else {
        cout << " -> Both last names are an identical match." << endl;
    }
    cout << endl;

    // Part 1: Enum operations
    currentCourse = readCourse();
    cout << "You selected: ";
    printCourse(currentCourse);
    cout << endl;

    if (currentCourse < ART) {
        currentCourse = static_cast<courseType>(currentCourse + 1);
        cout << "Advanced course tracking status to next offering: ";
        printCourse(currentCourse);
        cout << endl;
    } else {
        cout << "Already at maximum threshold (ART). Cannot advance further." << endl;        
    }

    cout << "Listing all catalog track offerings: " << endl;
    for (int i = ENGLISH; i <= ART; i++) {
        cout << " - ";
        printCourse(static_cast<courseType>(i));
        cout << endl;
    }

    courseType trackOne = HISTORY;
    courseType trackTwo = BIOLOGY;
    cout << "Comparing course placements: " << endl;
    if (trackOne < trackTwo) {
        printCourse(trackTwo);
        cout << " comes later in the curriculum sequence than ";
        printCourse(trackOne);
        cout << "." << endl;
    } else if (trackTwo < trackOne) {
        printCourse(trackOne);
        cout << " comes later in the curriculum sequence than ";
        printCourse(trackTwo);
        cout << "." << endl;
    }

    // Part 2: Tuition
    CreditHours hours;
    StudentID sid = 10045;
    cout << "Enter credit hours: ";
    cin >> hours;

    cout << "Calculated Course Tuition: $" << calcTuition(hours) << endl;

    // Part 3: Summary Display
    printStudentInfo(fullName, email, currentCourse, sid, hours);

    // Part 4: Namespace Scope Resolution Demo
    cout << "[Namespace Scope Resolution Verification]:" << endl;
    cout << "Global initial application tracking node enum id code target value: " << EnrollmentSystem::currentCourse << endl;

    return 0;
}