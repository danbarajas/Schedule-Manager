#include "functions.hpp"
#include <algorithm>
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

// Text Formatting

string toLowerCase(string str) {
    transform(str.begin(), str.end(), str.begin(), ::tolower);
    return str;
}

string toUpperCase(string str) {
    transform(str.begin(), str.end(), str.begin(), ::toupper);
    return str;
}

string toTitleCase(string str) {
    transform(str.begin(), str.end(), str.begin(), ::tolower);
    transform(str.begin(), str.begin() + 1, str.begin(), ::toupper);
    int i = str.find(' ');
    while (i != string::npos) {
        transform(str.begin() + i + 1, str.begin() + i + 2, str.begin() + i + 1, ::toupper);
        i = str.find(' ', i + 1);
    }
    return str;
}

string removeWhitespace(string str) {
    int i = str.find(' ');
    while (i != string::npos) {
        str.erase(i, 1);
        i = str.find(' ', i);
    }
    return str;
}

string trim(string str) {
    while(str[0] == ' ')
        str.erase(0, 1);

    while(str[str.length() - 1] == ' ')
        str.erase(str.length() - 1, 1);
    
    int i = str.find(' ');
    while (i != string::npos) {
        if (str[i + 1] == ' ') {
            str.erase(i + 1, 1);
            i = str.find(' ', i);
        } else
            i = str.find(' ', i + 1);
    }
    return str;
}

// Misc

bool isNumber(string str) {
    int length = str.length();
    for (int i = 0; i < length; i++) {
        if (!isdigit(str[i]))
            return false;
    }
    return true;
}

// Menu Functions

void splitKey(string &s, string &key, string &value) {
    // first word or possibly the only word
    key = s.substr(0,s.find("="));
 
    // skip all whitespace and get everything after the first word
    if (s.size() != key.size())
    {
        value = removeWhitespace(s.substr(s.find(" ")));
    }
    else
    {
        value = "";
        // wait for 1000 milliseconds
        
    }
}

bool keyLoad(map<string, Schedule>* schedules, string key, string value) {

}

bool loadSchedules(map<string, Schedule>* schedules) {
    string file = "schedules.txt";
    ifstream sFile(file);
    string line, key, value, schHeader, courseHeader, TAHeader;

    if (sFile.is_open()) {
        getline(sFile, schHeader);
        while (!sFile.eof()) {
            // album.artists.clear();
            // album.songs.clear();

            getline(sFile, line);
            splitKey(line, key, value);
            if (!keyLoad(schedules, key, value))
                cout << "Error loading key: " << key << " with value " << value << endl;

            // Record artist names until the first song is found (indicated by the 01 song number)
            while (num != "01") {
                album.artists.insert(line);
                getline(sFile, line);
                splitFirstWord(line, num, soTitle);
            }

            album.songs[num] = soTitle;
            getline(sFile, line);

            // Continue to record song numbers and names until the ending album name is found
            while (line != alTitle) {
                splitFirstWord(line, num, soTitle);
                album.songs[num] = soTitle;
                getline(sFile, line);
            }

            library[alTitle] = album;
            getline(sFile, alTitle);
        }
        sFile.close();
    } else
        cout << "Error: Could not open schedules file - " << sFile << endl;

    return library;
}

// Course Functions

pair<string, string> formatSubject(string str) {
    pair<string, string> formatted;
    str = toLowerCase(removeWhitespace(str));
    if (str == "computerscience" || str == "cs") {
        formatted.first = "Computer Science";
        formatted.second = "CS";
    } else if (str == "english" || str == "engl") {
        formatted.first = "English";
        formatted.second = "ENGL";
    } else if (str == "mathematics" || str == "math") {
        formatted.first = "Mathematics";
        formatted.second = "MATH";
    } else {
        formatted.first = "";
        formatted.second = "";
    }
    return formatted;
}

int createCourse(Schedule* schedule) {
    string input;
    string name;
    pair<string, string> courseShort;

    while (true) {
        name = "";
        cout << "What is the name of the course you'd like to create?" << endl
            << "Enter the subject followed by the course number of the course you want to create (Ex. CS 251 or Computer Science 261): ";
        cin >> input;

        while (!isNumber(input)) {
            name += input;
            cin >> input;
        }
        
        if (name.empty())
            cout << "Please enter the subject name first." << endl << endl;

        courseShort = formatSubject(name);
        if (courseShort.second.empty())
            cout << "No valid subject was found. Please try again." << endl << endl;
        else
            break;
    }
    
    courseShort.second += " " + input;
    if (schedule->findCourse(courseShort.second) != nullptr) {
        cout << "The specified course already exists in this schedule." << endl
            << "Would you like to update it instead? (press y for yes): ";
        cin >> input;

        if (toLowerCase(input) != "y") {
            // * Call update course function here *
            // return;
        }
    }
    return 0;

}