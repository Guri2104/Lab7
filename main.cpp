#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <fstream>
#include <string>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <set>
#include "Course.hpp"

using namespace std;

/*
 * print schedule - outputs course schedule to the screen
 * @param - add any new parameters you need
 */
void printSchedule()
{
    //TODO implement your print using the copy algorithm, 2 iterators, and an ostream_iterator
}

int main () {
    //TODO read from courses.txt
    ifstream course_txt{"../courses.txt"};
    string line;
    string title;
    char day_char;
    Course::dayOfWeek day;
    unsigned int start;
    unsigned int finished;
    multiset<Course> courseSet;

    while (getline(course_txt, line)){
        istringstream iss{line};
        iss >> title >> day_char >> start >> finished;
        switch (day_char) {
            case 'M':
                day = Course::MON;
                break;

            case 'T':
                day = Course::TUE;
                break;

            case 'W':
                day = Course::WED;
                break;

            case 'R':
                day = Course::THUR;
                break;

            case 'F':
                day = Course::FRI;
                break;
        }
        Course course{title, day, start, finished};
        courseSet.insert(course);
    }

    multiset<Course>::iterator it1;
    multiset<Course>::iterator it2;
    int it_tracker;
    for(it1 = courseSet.begin(); it1 != courseSet.end(); it1++){
        it2 = it1;
        it2++;
        for (; it2 != courseSet.end(); it2++) {
            if (it1->conflict(const_cast<Course &>(*it2))) {
                cout << "CONFLICT:" << endl;
                cout << *it1;
                cout << *it2 << endl;
            }
        }
    }

    for(it1 = courseSet.begin(); it1 != courseSet.end(); it1++) {
        cout << *it1;
    }

    return 0;
}