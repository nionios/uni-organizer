#include <fstream>
#include <iostream>
#include <string>
// Code by Dennis Nikolopoulos
// AM: 18390126
// Description: function to save all student data to disk

std::string
load(void) {
    std::fstream student_data;
    std::string loaded_student_data;
    student_data.open("student_data.txt", std::ios::in);
    if (!student_data) {
        std::cout << "* Student data load failure.";
    } else {
        while (1) {
            student_data >> loaded_student_data;
            if (student_data.eof())
                break;
        }
        std::cout << "* Student data loaded successfully!";
        student_data.close();
    }
    return loaded_student_data;
}
