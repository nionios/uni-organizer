#include <create_subject.hpp>
#include <subject.hpp>
#include <iostream>
#include <sstream>
#include <string>

//TODO: make this work
SUBJECT create_subject () {
    std::string code;
    std::string name;
    std::string choice;
    std::cout << "* Creating subject\n Please input subject code:";
    std::cin  >> code;
    std::cout << " Please input subject name:";
    std::cin  >> name;
    while (1) {
        std::cout << " Please input subject semester number:"
                  << std::endl;
        std::string line;
        if(std::getline(std::cin, line)) {
            std::istringstream iss(line);
            int semester;
            if(iss >> semester) {
                SUBJECT created_subject(code, name,semester);
                return created_subject;
            } else {
                while (1) {
                    std::cout << " No semester number provided!"
                        << "\n  Do you want to try to input the semester"
                        << "number again (or default to 1 with 'n')? (y/n): ";
                    std::cin >> choice;
                    if (choice == "y") break;
                    else if (choice == "n") {
                        // In this case go ahead with creation of subject
                        SUBJECT created_subject(code, name);
                        return created_subject;
                    } else {
                        std::cout << " Please input 'y' or 'n'" << std::endl;
                    }
                }
            }
        }
    }
}
