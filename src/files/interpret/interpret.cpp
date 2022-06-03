#include <string>
#include <sstream>
#include <student.hpp>
#include <subject.hpp>

// This function does not just decode the data, it interprets it into objects
// too.
STUDENT interpret_student(std::string input_data) {
    std::string line_of_data;
    int step = 0;
    const char * AM;
    std::string name;
    unsigned int semester;
    std::vector <std::pair <SUBJECT *, float>> passing_grade_list;
    std::vector<SUBJECT *> declared_subjects;

    std::istringstream scanned(input_data);
    while (std::getline(scanned, line_of_data)) {
        switch (step) {
            case 0:
                AM = line_of_data.c_str();
                break;
            case 1:
                name = line_of_data;
            case 2:
                // We are converiting String to unsigned int, so we need 64 bits
                // not 32, so we use atoll() instead of atoi.
                semester = atoll(line_of_data.c_str());
        }
        step++;
    }
}
SUBJECT interpret_subject(std::string input_data) {
}
