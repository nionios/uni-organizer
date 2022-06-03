#include <fstream>
#include <iostream>
#include <string>
// Code by Dennis Nikolopoulos
// AM: 18390126
// Description: function to load selected data file from disk

std::string
load(std::string filename) {
    std::fstream data;
    std::string loaded_data;
    data.open(filename, std::ios::in);
    if (!data) {
        std::cout << "* Data load from file " << filename << " failed.";
    } else {
        while (1) {
            data >> loaded_data;
            if (data.eof()) break;
        }
        std::cout << "* Data load from file " << filename << " completed!";
        data.close();
    }
    return loaded_data;
}
