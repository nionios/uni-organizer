#include <create_subject.hpp>
#include <subject.hpp>
#include <iostream>
#include <string>

SUBJECT create_subject (void) {
    int semester;
    std::string code;
    std::string name;
    std::cout << "* Creating subject\n Please input subject code: ";
    std::cin  >> code;
    std::cout << " Please input subject name: ";
    std::cin  >> name;
    std::cout << " Please input subject semester number: ";
    std::cin  >> semester;
    return SUBJECT(code,name,semester);
}
