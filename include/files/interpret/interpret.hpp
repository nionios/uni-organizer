#include <string>
#include <student.hpp>
#include <subject.hpp>
#ifndef interpret_HPP
#define interpret_HPP
STUDENT
interpret_student
(std::string input_data_block,
 std::vector<SUBJECT> initialized_subject_list);

SUBJECT
interpret_subject
(std::string input_data_block);
#endif
