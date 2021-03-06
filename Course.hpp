// Course.h
#include <iostream>

using namespace std;
struct Course {

enum dayOfWeek {MON, TUE, WED, THUR, FRI};

Course (string title, dayOfWeek day, unsigned int start_time, unsigned int finish_time);
Course (const Course & m);

// overloaded operators
Course & operator = (Course m);
bool operator < (const Course & m) const;
bool operator == (const Course & m) const;

string title; // Name of Course
dayOfWeek day; // Day of Course
unsigned int start_time; // Course start time in HHMM format
unsigned int finish_time; // Course finish time in HHMM format

// swap function for overloading '=' operator
void mySwap(Course &course1, Course &course2);

// function to check conflicts between 2 courses
bool conflict(Course &m) const;
};

// Helper operator for output
ostream &operator << (ostream &os, const Course & m);