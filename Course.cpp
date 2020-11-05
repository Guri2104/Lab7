#include "Course.hpp"

using namespace std;

Course::Course (string title, dayOfWeek day, unsigned int start_time, unsigned int finish_time) : title (title), day (day), start_time (start_time), finish_time (finish_time)
{
}
Course::Course (const Course & m) : title (m.title), day (m.day), start_time (m.start_time), finish_time (m.finish_time)
{
}

Course & Course::operator =(Course m) {
    mySwap(*this, m);
    return *this;
}
bool Course::operator == (const Course & m) const {
    if (title != m.title || day != m.day ||
        start_time != m.start_time || finish_time != m.finish_time){
        return false;
    }
    return true;
}

bool Course::operator < (const Course & m) const
{
    if (day < m.day)
        return true;
    if (day > m.day)
        return false;
    if (start_time < m.start_time)
        return true;
    if (start_time > m.start_time)
        return false;
    if (finish_time <= m.finish_time)
        return true;
    return false;
}

void Course::mySwap(Course &course1, Course &course2) {
    swap(course1.title, course2.title);
    swap(course1.day, course2.day);
    swap(course1.start_time, course2.start_time);
    swap(course1.finish_time, course2.finish_time);
}

ostream & operator << (ostream &os, const Course & m)
{
    char day;
    switch (m.day) {
        case Course::MON:
            day = 'M';
            break;

        case Course::TUE:
            day = 'T';
            break;

        case Course::WED:
            day = 'W';
            break;

        case Course::THUR:
            day = 'R';
            break;

        case Course::FRI:
            day = 'F';
            break;
    }
    os << m.title << " " << day << " " << m.start_time << " " << m.finish_time << endl;
    return os;
}

bool Course::conflict(Course& m) const
{
    if (day != m.day)
        return false;
    if (start_time > m.finish_time || finish_time < m.start_time)
        return false;
    return true;
}