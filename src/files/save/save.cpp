#include <fstream>
#include <iostream>
#include <string>
// Code by Dennis Nikolopoulos
// AM: 18390126
// Description: Function to save all data to disk

void
save(std::string input_data) {
    std::fstream to_be_saved_data;
    std::string filename;
    /* Search contents of the input data to determine if it is student or
     * subject data that is being saved. */
    if (input_data.find("* STUDENT ENTRY") != std::string::npos)
        filename = "student";
    else if (input_data.find("* SUBJECT ENTRY") != std::string::npos)
        filename = "subject";
    else {
        std::cout << "Incorrectly formatted data received!";
        return;
    }
    // Save subject and student data in different files
    to_be_saved_data.open(filename + "_data.txt", std::ios::app);
    if (!to_be_saved_data) {
        std::cout << filename + " data save failure." << std::endl;
    } else {
        std::cout << filename + " data saved successfully!" << std::endl;
        to_be_saved_data << input_data;
        to_be_saved_data.close();
    }
}
