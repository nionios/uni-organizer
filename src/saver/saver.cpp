#include <fstream>
#include <iostream>
// Code by Dennis Nikolopoulos
// AM: 18390126
// Description: function to save all student data to disk

void saver() {
    fstream student_data;
    my_file.open("student_data.txt", ios::out);
    if (!my_file) {
        cout << "File not created!";
    }
    else {
        cout << "File created successfully!";
        my_file << "DATA";
        my_file.close();
    }
}
