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
        std::string("* STUDENT ENTRY START\n") +
        std::string(input_student->get_AM()) + "\n" +
        input_student->get_name() + "\n" +
        std::to_string(input_student->get_semester()) + "\n" +
        // FIXME: these 2 lines do not work properly
        input_student->get_all_passing_grades() + "\n" +
        input_student->get_all_declared_subjects() + "\n" +
        "* STUDENT ENTRY END";
    return encoded_student_info;
}
// Overload for subject too
std::string
encode(SUBJECT * input_subject) {
    std::string encoded_subject_info =
        "* SUBJECT ENTRY START\n" +
        input_subject->get_code() + "\n" +
        input_subject->get_name() + "\n" +
        std::to_string(input_subject->get_semester()) + "\n" +
        "* SUBJECT ENTRY END";
    return encoded_subject_info;
}
