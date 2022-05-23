#include <student.hpp>
#include <subject.hpp>
#ifndef OPERATOR_H
#define OPERATOR_H
inline bool operator == (STUDENT stud_left, STUDENT stud_right);
inline bool operator <  (STUDENT stud_left, STUDENT stud_right);
inline bool operator != (STUDENT stud_left, STUDENT stud_right);
inline bool operator >  (STUDENT stud_left, STUDENT stud_right);
inline bool operator <= (STUDENT stud_left, STUDENT stud_right);
inline bool operator >= (STUDENT stud_left, STUDENT stud_right);
#endif
