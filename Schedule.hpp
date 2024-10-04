#ifndef SCHEDULE_HPP
#define SCHEDULE_HPP
#include "Course.hpp"
#include <string>
#include <map>
using namespace std;

class Schedule {
    private:
        map<string, Course> courses;
        string semester = "--";
        int year = 0;
    
    public:
        void setSemester(string);
        void setYear(int);
        void updateCourses(Course*);
        void removeCourse(string);
        
        string getSemester();
        int getYear();
        map<string, Course> getCourses();
        int getCourseCount();

        void printSemesterFull();
        void printCoursesShort();
        void printCoursesFull();
        void printScheduleDump();

        Course* findCourse(string);
};
#endif