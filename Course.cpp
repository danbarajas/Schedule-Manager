/**
 * Course Class Implementations [Course.cpp]
 * Schedule Manager
 * Includes implementations for both classes, Course and NonLecture. 
 * Defines getters, accessors, print functions, and other useful member 
 * functions for each class.
 * @author Daniel Barajas
*/

#include "Course.hpp"
#include "functions.hpp"
#include <iostream>


// *** COURSE IMPLEMENTATIONS ***

// * Course Setters [Condensed] *

void Course::setName(string str) { name = toTitleCase(trim(str)); }
void Course::setCourseNum(int num) { courseNum = num;}
void Course::setCRN(int num) { CRN = num; }
void Course::setCredits(int num) { credits = num; }
void Course::setRoom(string str) { room = toUpperCase(str); }
void Course::setProfFirstName(string str) { profFirstName = toTitleCase(str); }
void Course::setProfLastName(string str) { profLastName = toTitleCase(str); }
void Course::setSemester(string str) { semester = toTitleCase(str); }
void Course::setYear(int num) { year = num; }
void Course::setNonLecture(Course* NL) { nonlecture = NL; }

// * Course Setters Continued [Longer Implementations] *

void Course::setSubject(string str) {
    str = toLowerCase(removeWhitespace(str));
    if (str == "computerscience" || str == "cs") {
        subject = "Computer Science";
        subAbbrev = "CS";
    } else if (str == "english" || str == "engl") {
        subject = "English";
        subAbbrev = "ENGL";
    } else if (str == "mathematics" || str == "math") {
        subject = "Mathematics";
        subAbbrev = "MATH";
    } else
        subject = str;                                                                                                     
}

void Course::setBuilding(string str) {
    string tstr = toLowerCase(removeWhitespace(str));
    if (tstr == "academicandresidentialcomplex" || tstr == "academic&residentialcomplex" || tstr == "arc") {
        building = "Academic & Residential Complex";
        buiAbbrev = "ARC";
    } else if (tstr == "behavioralsciences" || tstr == "behavioralsciencesbuilding" || tstr == "behaviouralsciences" || tstr == "behaviouralsciencesbuilding" || tstr == "bsb") {
        building = "Behavioral Sciences Building";
        buiAbbrev = "BSB";
    } else if (tstr == "lecturecentera" || tstr == "lecturecenterbuildinga" || tstr == "lca") {
        building = "Lecture Center Building A";
        buiAbbrev = "LCA";
    } else if (tstr == "lecturecenterb" || tstr == "lecturecenterbuildingb" || tstr == "lcb") {
        building = "Lecture Center Building B";
        buiAbbrev = "LCB";
    } else if (tstr == "lecturecenterc" || tstr == "lecturecenterbuildingc" || tstr == "lcc") {
        building = "Lecture Center Building C";
        buiAbbrev = "LCC";
    } else if (tstr == "lecturecenterd" || tstr == "lecturecenterbuildingd" || tstr == "lcd") {
        building = "Lecture Center Building D";
        buiAbbrev = "LCD";
    } else if (tstr == "lecturecentere" || tstr == "lecturecenterbuildinge" || tstr == "lce") {
        building = "Lecture Center Building E";
        buiAbbrev = "LCE";
    } else if (tstr == "lecturecenterf" || tstr == "lecturecenterbuildingf" || tstr == "lcf") {
        building = "Lecture Center Building F";
        buiAbbrev = "LCF";
    } else if (tstr == "lincolnhall" || tstr == "lh") {
        building = "Lincoln Hall";
        buiAbbrev = "LH";
    } else if (tstr == "science&engineeringeast" || tstr == "scienceandengineeringeast" || tstr == "science&engineeringlaboratoryeast" || tstr == "scienceandengineeringlaboratoryeast" || tstr == "sele") {
        building = "Science & Engineering Laboratory East";
        buiAbbrev = "SELE";
    } else if (tstr == "science&engineeringsouth" || tstr == "scienceandengineeringsouth" || tstr == "ses") {
        building = "Science & Engineering South";
        buiAbbrev = "SES";
    } else if (tstr == "stevensonhall" || tstr == "sh") {
        building = "Stevenson Hall";
        buiAbbrev = "SH";
    } else
        building = toTitleCase(trim(str));
}

void Course::setTime(string str) {
    str = removeWhitespace(str);
    int dash = str.find('-');
    int startColon = str.find(':');
    int endColon = str.find(':', dash);
    
    if (startColon != string::npos && startColon < dash) {
        startHr = stoi(str.substr(0, startColon));
        startMin = stoi(str.substr(startColon + 1, dash - (startColon + 1)));
    } else {
        startHr = stoi(str.substr(0, dash));
        startMin = 0;
    }

    if (endColon != string::npos) {
        endHr = stoi(str.substr(dash + 1, endColon - (dash + 1)));
        endMin = stoi(str.substr(endColon + 1));
    } else {
        endHr = stoi(str.substr(dash + 1));
        endMin = 0;
    }
}

void Course::appendDays(string str) {
    str = toUpperCase(removeWhitespace(str));
    for (char c : str) {
        if (c == 'M' || c == 'T' || c == 'W' || c == 'R' || c == 'F')
            days.insert(c);
    }
}

void Course::removeDays(string str) {
    str = toUpperCase(removeWhitespace(str));
    for (char c : str) {
        if (c == 'M' || c == 'T' || c == 'W' || c == 'R' || c == 'F')
            days.erase(c);
    }
}

// * Course Accessors *

string Course::getName() { return name; }
string Course::getSubject() { return subject; }
int Course::getCourseNum() { return courseNum; }
string Course::getCourseShort() { return subAbbrev + " " + to_string(courseNum); }
int Course::getCRN() { return CRN; }
int Course::getCredits() { return credits; }
string Course::getProfFirstName() { return profFirstName; }
string Course::getProfLastName() { return profLastName; }
string Course::getRoom() { return room; }
int Course::getStartHr() { return startHr; }
int Course::getStartMin() { return startMin; }
int Course::getEndHr() { return endHr; }
int Course::getEndMin() { return endMin; }
string Course::getSemester() { return semester; };
int Course::getYear() { return year; }
Course* Course::getNonLecture() { return nonlecture; }

// * Course Print Functions [Condensed] *

void Course::printCourseShort() { cout << subAbbrev << " " << courseNum; }
void Course::printCourseFull() { cout << subAbbrev << " " << courseNum << " " << name; }
void Course::printProfFullName() { cout << profFirstName << " " << profLastName; }
void Course::printProfFormalName() { cout << profLastName << ", " << profFirstName; }
void Course::printLocationShort() { cout << buiAbbrev << " " << room; }
void Course::printSemesterFull() { cout << semester << " " << year; }

// * Course Print Functions Contiuned [Longer Implmentation] *

void Course::printCourseBrief() {
    printCourseFull();
    cout << endl;
    printLocationShort();
    cout << " - ";
    printDaysShort();
    cout << " ";
    printFullTime();
    cout << endl;
    printProfFullName();
    cout << endl;
    printSemesterFull();
}

void Course::printFullTime() {
    if (startHr > 12)
        cout << startHr - 12;
    else
        cout << startHr;

    if (startMin >= 10)
        cout << ':' << startMin;
    else
        cout << ":0" << startMin;

    if (startHr < 12)
        cout << "am - ";
    else
        cout << "pm - ";

    if (endHr > 12)
        cout << endHr - 12;
    else
        cout << endHr;

    if (endMin >= 10)
        cout << ':' << endMin;
    else
        cout << ":0" << endMin;

    if (endHr < 12)
        cout << "am";
    else
        cout << "pm";
}

void Course::printDaysShort() {
    if (!days.empty()) {
        if (days.find('M') != days.end())
            cout << 'M';
        if (days.find('T') != days.end())
            cout << 'T';
        if (days.find('W') != days.end())
            cout << 'W';
        if (days.find('R') != days.end())
            cout << "Th";
        if (days.find('F') != days.end())
            cout << 'F';
    } else
        cout << "--";
}

void Course::printDaysFull() {
    if (!days.empty()) {
        int count = 0;
        if (days.find('M') != days.end()) {
            cout << "Monday";
            count++;
            if (count < days.size())
                cout << ", ";
            else
                return;
        }

        if (days.find('T') != days.end()) {
            cout << "Tuesday";
            count++;
            if (count < days.size())
                cout << ", ";
            else
                return;
        }

        if (days.find('W') != days.end()) {
            cout << "Wednesday";
            count++;
            if (count < days.size())
                cout << ", ";
            else
                return;
        }

        if (days.find('R') != days.end()) {
            cout << "Thursday";
            count++;
            if (count < days.size())
                cout << ", ";
            else
                return;
        }

        if (days.find('F') != days.end())
            cout << "Friday";
    } else
        cout << "--";
}

// * Course Virtual Functions *
// For use of NonLecture functions.
// Empty implementation so calling these functions on a Course object
// instead of NonLecture object does nothing.

void Course::setType(char) {}
void Course::appendTAName(string, string) {}
void Course::removeTAName(string) {}
char Course::getType() {}
map<string, string> Course::getTANames() {}
void Course::printType() {}
void Course::printTANames() {}

// *** NONLECTURE IMPLEMENTATIONS ***

// * NonLecture Setters *

void NonLecture::setType(char c) { type = c; };
void NonLecture::appendTAName(string f, string l) { TANames[l] = f; }
void NonLecture::removeTAName(string l) { TANames.erase(l); }

// * NonLecture Accessors *

char NonLecture::getType() { return type; }
map<string, string> NonLecture::getTANames() { return TANames; }

// * NonLecture Print Functions *

void NonLecture::printType() {
    if (type == 'D')
        cout << "Discussion";
    else if (type == 'L')
        cout << "Laboratory";
    else if (type == 'Q')
        cout << "Quiz";
    else
        cout << type;
}

void NonLecture::printTANames() {
    for (auto n : TANames )
        cout << n.first << " " << n.second << ", ";
    cout << endl;
}