#include <student.hpp>
#include <iostream>

STUDENT::STUDENT
(const char  *input_AM,
 std::string  input_name,
 unsigned int input_semester,
 SUBJECT     *input_decl_subj,
 SUBJECT     *input_subj,
 float        input_grade)
{
    AM       = input_AM;
    name     = input_name;
    semester = input_semester;
    if (input_decl_subj) this->add_subject(input_decl_subj);
    // if input_subj is NULL then do not set
    if (input_subj) {
        // Grade cannot be smaller than 0
        if (input_grade > 0) {
            this->set_passing_grade(input_subj, input_grade);
        } else {
            // Don't throw exception, this is a warning
            std::cerr << "Warning: Input a grade number > 0, "
                      << "passing grade for student "
                      << input_name
                      << " currently not set."
                      << std::endl;
        }
    } else {
        // Don't throw exception, this is a warning
        std::cerr << "Warning: Input a valid subject pointer, "
                  << "passing grade for student "
                  << input_name
                  << " currently not set."
                  << std::endl;
    }
}

//TODO: lists update this too (passing grades)
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

/* Function that seaches for subject code or name * and returns the passing
 * grade if the subject is passed by student*/
float
STUDENT::get_passing_grade
(std::string search_term) {
    if (passing_grade_list.empty())  {
        std::cout << "Warning: Student "
                  << this->get_name()
                  << " has not passed any classes."
                  << std::endl;
        return 0;
    } else {
        for (auto & index : passing_grade_list) {
            if (index.first->get_code() == search_term ||
                index.first->get_name() == search_term)
                return index.second;
        }
        std::cout << "Warning: Student "
                  << this->get_name()
                  << " has not passed this class."
                  << std::endl;
        return 0;
    }
}

// TODO: dont return empty string, return "no classes" or smth
std::string STUDENT::get_all_passing_grades(void) {
    std::string grades_string = "";
    // Check if grade list is empty, if yes, return empty string
    if (!passing_grade_list.empty())  {
        for (auto & index : passing_grade_list) {
            grades_string += index.first->get_code() + " " +
                             std::to_string(index.second) + " ";
        }
    }
    return grades_string;
}

std::string STUDENT::get_all_declared_subjects(void) {
    std::string subjects_string = "";
    // Check if grade list is empty, if yes, return empty string
    if (!declared_subjects.empty())  {
        for (auto & index : declared_subjects) {
            subjects_string += index->get_code();
        }
    }
    return subjects_string;
}

void STUDENT::set_passing_grade (SUBJECT* input_subj, float input_grade) {
    // Create the pair and insert it into the list
    std::pair <SUBJECT *, float>input_pair = {input_subj, input_grade};
    passing_grade_list.push_back(input_pair);
}
void STUDENT::set_name (std::string input_name) {name = input_name;}
void STUDENT::set_semester (unsigned int input_semester) {
    semester = input_semester;
}
std::vector<SUBJECT *> STUDENT::get_decl_subj (void) {
    return declared_subjects;
}
