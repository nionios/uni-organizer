#include <student.hpp>
#include <iostream>

STUDENT::STUDENT
(const char * input_AM,
 std::string  input_name,
 unsigned int input_semester)
{
    AM       = input_AM;
    name     = input_name;
    semester = input_semester;
}

// Constructor (overloaded) to duplicate another STUDENT object.
//(delegate constructor)
STUDENT::STUDENT
(const STUDENT &source) : STUDENT (source.AM,
                                   source.name,
                                   source.semester) {}

// Function to print all attributes to ostream
void
STUDENT::print_all
(std::ostream &input_stream)
{
    input_stream  << "> AM: "       << AM
                  << " - Name: "    << name
                  << " - Semester: "<< semester
                  << std::endl;
}

/* Helper Functions */
// Function to increment semester by +1
void STUDENT::inc_semester (void) { semester++; }
// Add a subject to the vector of declared subjects of student
void STUDENT::add_subject (SUBJECT * input_subj) {
    this->declared_subjects.push_back(input_subj);
}

/* Setters And Getters */
const char * STUDENT::get_AM (void)       {return AM;}
std::string  STUDENT::get_name (void)     {return name;}
unsigned int STUDENT::get_semester (void) {return semester;}

void STUDENT::set_passing_grade (SUBJECT* input_subj, float input_grade) {
    passing_grade_list.first.push_back(input_subj);
    passing_grade_list.second.push_back(input_grade);
}
void STUDENT::set_name (std::string input_name) {name = input_name;}
void STUDENT::set_semester (unsigned int input_semester) {
    semester = input_semester;
}
std::vector<SUBJECT *> STUDENT::get_decl_subj (void) {
    return declared_subjects;
}
