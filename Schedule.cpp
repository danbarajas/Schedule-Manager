/**
 * Schedule Class Implementations [Schedule.cpp]
 * Schedule Manager
 * Includes implementations for the Schedule class which holds all 
 * Courses for a specific semester. Defines getters, accessors, print 
 * functions and other utility functions to help manage the Course list.
 * @author Daniel Barajas
*/

#include "Schedule.hpp"
#include "functions.hpp"
#include <iostream>
#include <set>

// *** SCHEDULE IMPLEMENTATIONS ***

// * Schedule Setters [Condensed] *

void Schedule::updateCourses(Course* C) { courses[C->getCourseShort()] = *C; }
void Schedule::removeCourse(string str) { courses.erase(str); }

// * Schedule Setters Continued [Longer Implementations] *

void Schedule::setSemester(string str) {
    str = toTitleCase(str);
    semester = str;
    for (auto C : courses)
        C.second.setSemester(str);
}

void Schedule::setYear(int num) {
    year = num;
    for (auto C : courses)
        C.second.setYear(num);
}

// * Schedule Accessors *

string Schedule::getSemester() { return semester; };
int Schedule::getYear() { return year; }
map<string, Course> Schedule::getCourses() { return courses; }
int Schedule::getCourseCount() { return courses.size(); }

// * Schedule Print Functions *

void Schedule::printSemesterFull() { cout << semester << " " << year; }

void Schedule::printCoursesShort() {
    cout << "All Courses for ";
    printSemesterFull();
    cout << ": " << endl;
    for (auto C : courses) {
        C.second.printCourseFull();
        cout << endl;
    }
}

void Schedule::printCoursesFull() {
    cout << "All Courses for ";
    printSemesterFull();
    cout << ": " << endl;
    for (auto C : courses) {
        C.second.printCourseBrief();
        cout << endl;
    }
}

void Schedule::printScheduleDump() {
    printCoursesFull();
}

// * Schedule Utility Functions *
// Help to manage and manipulate the Course list

Course* Schedule::findCourse(string str) {
    map<string, Course>::iterator itr = courses.find(str);
    if (itr != courses.end())
        return &(itr->second);
    else
        return nullptr;
}