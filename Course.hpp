#ifndef COURSE_HPP
#define COURSE_HPP
#include <string>
#include <map>
#include <set>
using namespace std;

class Course {
    private:
        string name = "--";
        string subject = "--";
        string subAbbrev = "--";
        int courseNum = 0;
        int CRN = 0;
        int credits = 0;
        string profFirstName = "--";
        string profLastName = "--";
        string building = "--";
        string buiAbbrev = "--";
        string room = "--";
        int startHr = 0;
        int startMin = 0;
        int endHr = 0;
        int endMin = 0;
        set<char> days;
        string semester = "--";
        int year = 0;
        Course* nonlecture;

    public:
        void setName(string);
        void setSubject(string);
        void setCourseNum(int);
        void setCRN(int);
        void setCredits(int);
        void setProfFirstName(string);
        void setProfLastName(string);
        void setBuilding(string);
        void setRoom(string);
        void setTime(string);
        void appendDays(string);
        void removeDays(string);
        void setSemester(string);
        void setYear(int);
        void setNonLecture(Course*);

        string getName();
        string getSubject();
        int getCourseNum();
        string getCourseShort();
        int getCRN();
        int getCredits();
        string getProfFirstName();
        string getProfLastName();
        string getRoom();
        int getStartHr();
        int getStartMin();
        int getEndHr();
        int getEndMin();
        set<char> getDays();
        string getSemester();
        int getYear();
        Course* getNonLecture();
        virtual void setType(char);
        virtual void appendTAName(string, string);
        virtual void removeTAName(string);
        virtual char getType();
        virtual map<string, string> getTANames();
        virtual void printType();
        virtual void printTANames();

        void printCourseShort();
        void printCourseBrief();
        void printCourseFull();
        void printProfFullName();
        void printProfFormalName();
        void printLocationShort();
        void printFullTime();
        void printDaysShort();
        void printDaysFull();
        void printSemesterFull();
};

class NonLecture : public Course {
    private:
        char type = '-';
        map<string, string> TANames;

    public:
        void setType(char);
        void appendTAName(string, string);
        void removeTAName(string);

        char getType();
        map<string, string> getTANames();

        void printType();
        void printTANames();
};
#endif