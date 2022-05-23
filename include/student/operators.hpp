#include <student.hpp>
#include <subject.hpp>
#ifndef OPERATORS_HPP
#define OPERATORS_HPP
bool operator == (STUDENT stud_left, STUDENT stud_right);
bool operator <  (STUDENT stud_left, STUDENT stud_right);
bool operator != (STUDENT stud_left, STUDENT stud_right);
bool operator >  (STUDENT stud_left, STUDENT stud_right);
bool operator <= (STUDENT stud_left, STUDENT stud_right);
bool operator >= (STUDENT stud_left, STUDENT stud_right);
#endif
