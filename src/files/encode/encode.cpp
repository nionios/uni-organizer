#include <iostream>
#include <string>
#include <student.hpp>
#include <subject.hpp>
// Code by Dennis Nikolopoulos
// AM: 18390126
// Description: function to encode student and subject data
std::string
encode(STUDENT * input_student) {
    std::string encoded_student_info =
     "*" + std::string(input_student->get_AM()) +
     "/" + input_student->get_name() +
     "/" + std::to_string(input_student->get_semester()) +
     "/" + input_student->get_all_passing_grades() +
     "/" + input_student->get_all_declared_subjects() + "\n";
    return encoded_student_info;
}
// Overload for subject too
std::string
encode(SUBJECT * input_subject) {
    std::string encoded_subject_info =
        "*" + input_subject->get_code() +
        "/" + input_subject->get_name() +
        "/" + std::to_string(input_subject->get_semester()) + "\n";
    return encoded_subject_info;
}
