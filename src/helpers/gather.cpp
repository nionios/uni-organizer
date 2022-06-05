#include <load.hpp>
#include <interpret.hpp>
#include <subject.hpp>
#include <student.hpp>
#include <sstream>
#include <iostream>
// Helper function to split the loaded data into blocks and feed into interpret
// function.

std::vector<STUDENT>
gather_students
(std::vector<SUBJECT> initialized_subject_list) {
    std::string loaded_data = load("student_data.txt");
    std::istringstream scanned_loaded_data(loaded_data);
    std::string loaded_data_block;
    std::vector<STUDENT> loaded_student_list;
    // Split scanned loaded data into blocks, delimiter is '*' in
    // "* STUDENT ENTRY"
    while (std::getline(scanned_loaded_data, loaded_data_block, '*')) {
        STUDENT loaded_stud = interpret_student(loaded_data_block,
                                                initialized_subject_list);
        loaded_student_list.push_back(loaded_stud);
    }
    return loaded_student_list;
}

std::vector<SUBJECT>
gather_subjects
(void) {
    std::string loaded_data = load("student_data.txt");
    std::istringstream scanned_loaded_data(loaded_data);
    std::string loaded_data_block;
    std::vector<SUBJECT> loaded_subject_list;
    // Split scanned loaded data into blocks, delimiter is '*' in
    // "* SUBJECT ENTRY"
    while (std::getline(scanned_loaded_data, loaded_data_block, '*')) {
        SUBJECT loaded_subj = interpret_subject(loaded_data_block);
        loaded_subject_list.push_back(loaded_subj);
    }
    return loaded_subject_list;
}
