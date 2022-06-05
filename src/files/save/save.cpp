#include <fstream>
#include <iostream>
#include <string>
// Code by Dennis Nikolopoulos
// AM: 18390126
// Description: Function to save all data to disk

void
save(std::string input_data, std::string filename) {
    std::fstream to_be_saved_data;
    // Save subject and student data in different files
    to_be_saved_data.open(filename, std::ios::app);
    if (!to_be_saved_data) {
        std::cout << filename + " data save failure." << std::endl;
    } else {
        std::cout << filename + " data saved successfully!" << std::endl;
        to_be_saved_data << input_data;
        to_be_saved_data.close();
    }
}
