#include <string>
#include <iostream>
#include <subject.hpp>
#include <student.hpp>
#include <create_student.hpp>
#include <uni_organizer_helpers.hpp>

STUDENT create_student (std::vector<SUBJECT *> subject_pointer_list) {
    try {
        std::cout << "At any time, type 0 to exit." << std::endl;
        std::string input_name;
        std::string input_AM;
        int input_semester;
        int input_index;
        float input_grade;
        std::vector<SUBJECT *> input_subject_list;
        std::pair<SUBJECT *, float> input_pair;
        std::vector<std::pair<SUBJECT *, float>> input_passing_grade_list;

        std::cout << "Add student code: ";
        std::cin >> input_AM;
        if (input_name == "0") return STUDENT(input_AM);
        std::cout << "Add student name: ";
        // Collect the stray "\n" that is left into garbage string
        std::string garbage;
        std::getline(std::cin, garbage);
        std::getline(std::cin, input_name);
        if (input_AM == "0") return STUDENT(input_AM, input_name);
        std::cout << "Add student semester: ";
        std::cin >> input_semester;
        if (input_semester == 0) { return STUDENT(input_AM,
                                                  input_name,
                                                  input_semester); }

        while (1) {
            std::cout << "Type number to select subject to input student grade"
                      << "(passed subject, so grade should be 5 to 10): "
                      << std::endl;
            int subj_number = view_subjects(subject_pointer_list);
            std::cout << "Input here (0 to continue): ";
            std::cin >> input_index;
            // Input index is offset by +1, reset.
            input_index--;
            // ...So -1 is 0
            if (input_index == -1) break;
            else if (input_index < 0 || input_index > subj_number - 1) {
                std::cout << "Please input a number from 1 to "
                          << subj_number - 1
                          << std::endl;
            } else {
                while (1) {
                    std::cout << "\nAdd passed subject grade:";
                    std::cin  >> input_grade;
                    if (input_grade < 5 || input_grade > 10) {
                        std::cout << "Please input a number from 5 to 10"
                                  << std::endl;
                    } else {
                        input_pair = {subject_pointer_list[input_index],
                                      input_grade};
                        input_passing_grade_list.push_back(input_pair);
                        break;
                    }
                }
            }
        }

        // If user pressed "0" but has not passed any classes return...
        if (input_passing_grade_list.empty()) { return STUDENT(input_AM,
                                                               input_name,
                                                               input_semester);
        }

        while (1) {
            int subj_number = view_subjects(subject_pointer_list);
            std::cout << "Add declared subject to student "
                      << "(type number, 0 to continue): "
                      << std::endl;
            std::cin >> input_index;
            if (input_index == 0) break;
            else if (input_index < 1 || input_index > subj_number) {
                std::cout << "Please input a number from 1 to " << subj_number
                          << std::endl;
            } else {
                // Correlate the subject to the appropriate pointer from
                // initialized subjects
                input_subject_list.push_back(subject_pointer_list[input_index]);
            }
        }

        // If user pressed "0" but has not passed any classes return...
        if (input_subject_list.empty()) {
            return STUDENT(input_AM,
                           input_name,
                           input_semester,
                           input_passing_grade_list);
        } else {
            return STUDENT(input_AM,
                           input_name,
                           input_semester,
                           input_passing_grade_list,
                           input_subject_list);
        }
    } catch (std::invalid_argument ex) {
        std::cout << "Exception: " << ex.what() << std::endl;
    }
    // if exception accurs, return default student config
    return STUDENT();
}
