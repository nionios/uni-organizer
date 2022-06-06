#include <fstream>
#include <iostream>
#include <string>
// Code by Dennis Nikolopoulos
// AM: 18390126
// Description: function to load selected data file from disk

std::string
load(std::string filename) {
    std::fstream data(filename, std::fstream::in);
    std::string loaded_data;
    //data.open(filename, std::ios::in);
    if (!data) {
        std::cout << "* Data load from file " << filename << " failed."
                  << std::endl;
    } else {
        getline(data, loaded_data, '\0');
        std::cout << "* Data load from file " << filename << " completed!"
                  << std::endl;
    }
    data.close();
    return loaded_data;
}
