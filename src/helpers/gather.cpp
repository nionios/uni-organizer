#include <load.hpp>
#include <interpret.hpp>
#include <subject.hpp>
#include <student.hpp>
#include <sstream>
#include <iostream>
#include <exceptions.hpp>
// Helper function to split the loaded data into blocks and feed into interpret
// function.

std::vector<STUDENT>
gather_students
(std::vector<SUBJECT> initialized_subject_list) {
    std::string loaded_data = load("student_data.txt");
    std::istringstream scanned_loaded_data(loaded_data);
    std::string loaded_data_block;
    std::vector<STUDENT> loaded_student_list;
    // Split scanned loaded data into blocks, delimiter is '*'
    try {
        while (std::getline(scanned_loaded_data, loaded_data_block, '*')) {
            // Skip first scan of "*" (will return empty string)
            if (loaded_data_block == "") continue;
            STUDENT loaded_stud(interpret_student(loaded_data_block,
                    initialized_subject_list));
            loaded_stud.print_all(std::cout);
            loaded_student_list.push_back(loaded_stud);
        }
    } catch (invalid_student_data ex) {
        std::cout << ex.what() << std::endl;
    } catch (subject_mismatch ex) {
        std::cout << ex.what() << std::endl;
    }
    return loaded_student_list;
}

std::vector<SUBJECT>
gather_subjects
(void) {
    std::string loaded_data = load("subject_data.txt");
    std::istringstream scanned_loaded_data(loaded_data);
    std::string loaded_data_block;
    std::vector<SUBJECT> loaded_subject_list;
    // Split scanned loaded data into blocks, delimiter is '*'
    try {
        while (std::getline(scanned_loaded_data, loaded_data_block, '*')) {
            // Skip first scan of "*" (will return empty string)
            if (loaded_data_block == "") continue;
            SUBJECT loaded_subj = interpret_subject(loaded_data_block);
            loaded_subject_list.push_back(loaded_subj);
        }
    } catch (invalid_subject_data ex) {
        std::cout << ex.what() << std::endl;
    }
    return loaded_subject_list;
}
