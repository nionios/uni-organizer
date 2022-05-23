#include <subject.hpp>
#include <student.hpp>
#include <iostream>
#include <vector>

SUBJECT::SUBJECT ( const char * input_code,
        std::string input_name,
        unsigned int input_semester) {
    code     = input_code;
    name     = input_name;
    semester = input_semester;
}
// Constructor (overloaded) to duplicate another SUBJECT object.
SUBJECT::SUBJECT (const SUBJECT& source) {
    code     = source.code;
    name     = source.name;
    semester = source.semester;
}
// Function to print all attributes to ostream
void SUBJECT::print_all (std::ostream &input_stream) {
    input_stream  << "> Code: "      << code
                  << " - Name: "     << name
                  << " - Semester: " << semester
                  << std::endl;
}

// Function to increment semester by +1
void SUBJECT::inc_semester (void) { semester++; }
// Setters and getters
const char * SUBJECT::get_code (void) {return code;}
std::string SUBJECT::get_name (void) {return name;}
unsigned int SUBJECT::get_semester (void) {return semester;}
void SUBJECT::set_code (const char * input_code) {code = input_code;}
void SUBJECT::set_name (std::string input_name) {name = input_name;}
void SUBJECT::set_semester (unsigned int input_semester) {
    semester = input_semester;
}
