#include <string>
#include <sstream>
#include <iostream>
#include <student.hpp>
#include <subject.hpp>

SUBJECT *
search_subject_list
(std::string input_word,
 std::vector<SUBJECT> initialized_subject_list) {
    for (auto & index : initialized_subject_list) {
        // If the archived code matches an initialized subject (from
        // our main function, passed through the
        // initialized_subject_list) then return the pointer to subject
        if (index.get_code() == input_word)
            return &index;
    }
    // If subject is not found, return null pointer
    return NULL;
}

// This function does not just decode the data, it interprets it into objects
// too.
STUDENT
interpret_student
(std::string input_data_block,
 std::vector<SUBJECT> initialized_subject_list) {
    std::string line_of_data;
    int step = 0;
    const char * AM;
    std::string name;
    unsigned int semester;
    std::vector <std::pair <SUBJECT *, float>> passing_grade_list;
    std::vector<SUBJECT *> declared_subjects;

    std::istringstream scanned(input_data_block);
    while (std::getline(scanned, line_of_data)) {
        switch (step) {
            case 0:
                //Here we should have "* STUDENT ENTRY", skip this line
                break;
            case 1:
                AM = line_of_data.c_str();
                break;
            case 2:
                name = line_of_data;
                break;
            case 3:
                // We are converiting String to unsigned int, so we need 64 bits
                // not 32, so we use atoll() instead of atoi.
                semester = atoll(line_of_data.c_str());
                break;
            case 4:
                { // Braces to limit scope within this case
                int substep = 0;
                // Split the line of data into multiple words (separator is
                // whitespace)
                std::istringstream scanned_grade_words(line_of_data);
                std::string word;
                std::pair<SUBJECT *,float> inserted_pair;
                while (scanned_grade_words >> word) {
                    // In odd steps we should be looking at subject codes.
                    if (substep%2 == 1) {
                        SUBJECT * retrieved_subj = search_subject_list(word,
                                                    initialized_subject_list);
                        if (retrieved_subj) inserted_pair.first =
                            retrieved_subj;
                        // If res == NULL then subject was not initialized.
                        // the data is formatted wrongly. Stop trying to
                        // interpret
                        else return NULL;
                    // In even steps we should be looking at subject grades
                    } else {
                        try {
                            // Convert grade in string to float and put into
                            // inserted pai
                            inserted_pair.second = std::stof(line_of_data);
                            // If an exception has not occured, we have a
                            // number, but we check the grade one more time to
                            // make sure it is in 0-10 range
                            if (inserted_pair.second <= 10 &&
                                inserted_pair.second >= 0) {
                                // All is well, insert pair into list
                                passing_grade_list.push_back(inserted_pair);
                            }
                        } catch (const std::invalid_argument ex) {
                            std::cerr << "Invalid grade on student_data.txt"
                                      << std::endl;
                            return NULL;
                        }
                    }
                    substep++;
                }
                break;
                }
            case 5:
                // Split the line of data into multiple words (separator is
                // whitespace)
                std::istringstream scanned_subj_words(line_of_data);
                std::string word;
                while (scanned_subj_words >> word) {
                    SUBJECT * retrieved_subj = search_subject_list(word,
                                                 initialized_subject_list);
                    if (retrieved_subj)
                        declared_subjects.push_back(retrieved_subj);
                    // If res == NULL then subject was not initialized.
                    // the data is formatted wrongly. Stop trying to
                    // interpret
                    else return NULL;
                }
                break;
        }
        step++;
    }
    // If this whole process ends without errors, create the student object and
    // return it
    STUDENT interpreted_student
        (AM, name, semester, passing_grade_list, declared_subjects);
    return interpreted_student;
}

SUBJECT
interpret_subject
(std::string input_data_block) {
    std::string line_of_data;
    int step = 0;
    std::string code;
    std::string name;
    unsigned int semester;
    std::istringstream scanned(input_data_block);
    while (std::getline(scanned, line_of_data)) {
        switch (step) {
            case 0:
                break;
            case 1:
                code = line_of_data;
                break;
            case 2:
                name = line_of_data;
                break;
            case 3:
                // We are converiting String to unsigned int, so we need 64 bits
                // not 32, so we use atoll() instead of atoi.
                semester = atoll(line_of_data.c_str());
                break;
        }
    }
    // If no errors have occured up until now, create and return subject object
    SUBJECT interpreted_subject(code,name,semester);
    return interpreted_subject;
}
