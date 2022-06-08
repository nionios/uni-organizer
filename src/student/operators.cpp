#include <operators.hpp>
#include <student.hpp>
#include <iostream>
#include <subject.hpp>
// Overloading operator for easy adding declared classes to student
void
STUDENT::operator +=
(SUBJECT * input_subj) {
    this->add_subject(input_subj);
}

// Overloading operator for easy adding declared classes to student
void
STUDENT::operator =
(STUDENT stud_right) {
    this->set_AM(stud_right.get_AM());
    this->set_name(stud_right.get_name());
    this->set_semester(stud_right.get_semester());
    this->set_passing_grade_list(stud_right.get_passing_grade_list());
    this->set_declared_subjects_list(stud_right.get_declared_subjects_list());
}

std::ostream& operator<<(std::ostream& os, STUDENT &stud) {
    stud.print_all(os);
    return os;
}

bool
operator ==
(STUDENT stud_left, STUDENT stud_right) {
    if (stud_left.get_semester() == stud_right.get_semester())
        return true;
    else return false;
}

bool
operator <
(STUDENT stud_left, STUDENT stud_right) {
    if (stud_left.get_semester() < stud_right.get_semester())
        return true;
    else return false;
}

bool
operator !=
(STUDENT stud_left, STUDENT stud_right) {
    return !operator==(stud_left,stud_right);
}

bool
operator >
(STUDENT stud_left, STUDENT stud_right) {
    return  operator< (stud_right,stud_left);
}

bool
operator <=
(STUDENT stud_left, STUDENT stud_right) {
    return !operator> (stud_left,stud_right);
}

bool
operator >=
(STUDENT stud_left, STUDENT stud_right) {
    return !operator< (stud_left,stud_right);
}
