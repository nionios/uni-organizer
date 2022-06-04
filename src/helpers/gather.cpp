#include <load.hpp>
#include <interpret.hpp>
#include <subject.hpp>
#include <student.hpp>
#include <sstream>
// Helper function to split the loaded data into blocks and feed into interpret
// function.

//TODO: make changes in header file too
std::vector<STUDENT> gather_students (void) {
    std::string loaded_data = load("student_data.txt");
    std::istringstream scanned_loaded_data(loaded_data);
    std::string loaded_data_block;
    std::vector<STUDENT> loaded_student_list;
    // Split scanned loaded data into blocks, the delimiter is "STUDENT ENTRY"
    while (std::getline(scanned_loaded_data, loaded_data_block, "* STUDENT ENTRY")) {
        STUDENT loaded_stud = interpret(loaded_data_block);
        loaded_student_list.push_back(loaded_stud);
    }
    return loaded_student_list;
}

std::vector<SUBJECT> gather_subjects (void) {
    std::string loaded_data = load("subject_data.txt");
    std::istringstream scanned_loaded_data(loaded_data);
    std::string loaded_data_block;
    std::vector<SUBJECT> loaded_subject_list;
    // Split scanned loaded data into blocks, the delimiter is "STUDENT ENTRY"
    while (std::getline(scanned_loaded_data, loaded_data_block, "* SUBJECT ENTRY")) {
        SUBJECT loaded_subj = interpret(loaded_data_block);
        loaded_subject_list.push_back(loaded_subj);
    }
    return loaded_subject_list;
}
