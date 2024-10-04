#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP
#include "Schedule.hpp"
#include <string>
using namespace std;

// Text Formatting
string toLowerCase(string);
string toUpperCase(string);
string toTitleCase(string);
string removeWhitespace(string);
string trim(string);

// Misc
bool isNumber(string);

// Menu Functions
void splitKey(string*, string*, string*);
bool keyLoad(map<string, Schedule>*, string, string);
bool loadSchedules(map<string, Schedule>*);

// Course Functions
pair<string, string> formatSubject(string);
int createCourse(Schedule*);
#endif