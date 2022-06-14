#include <subject.hpp>
#include <student.hpp>
#include <iostream>

int view_subjects (std::vector<SUBJECT *> subject_pointer_list) {
    int step = 1;
    std::cout << "* Subject list *" << std::endl;
    for (auto & subject : subject_pointer_list) {
        std::cout << "Subject " << step << " : "
                  << subject->get_name()
                  << "- Subject Code: "
                  << subject->get_code()
                  << std::endl;
        step++;
    }
    return step;
}
