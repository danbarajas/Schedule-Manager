#include <iostream>
#include <string>
#include <map>
#include "Course.hpp"
#include "Schedule.hpp"
#include "functions.hpp"
using namespace std;

int main() {
    map<string, Schedule> schedules;

    Schedule testSchedule;
    Course testCourse;
    NonLecture testNL;
    testSchedule.setSemester("fall");
    testSchedule.setYear(2023);
    testCourse.setSemester("fall");
    testCourse.setYear(2023);
    testCourse.setSubject("computer science");
    testCourse.setCourseNum(361);
    testCourse.setName("systems programming");
    testCourse.setProfFirstName("george");
    testCourse.setProfLastName("maratos");
    testCourse.setBuilding("academic&residentialcomplex");
    testCourse.setRoom("137");
    testCourse.setTime("15:30-16:45");
    testCourse.appendDays("TR");
    testCourse.setNonLecture(&testNL);
    testNL.setType('L');
    testNL.appendTAName("first", "last");
    testNL.appendTAName("first2", "last2");
    testSchedule.updateCourses(&testCourse);

    cout << "Schedule Dump:" << endl;
    testSchedule.printScheduleDump();
    cout << endl;

    return 0;
}