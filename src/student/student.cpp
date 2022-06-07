#include <student.hpp>
#include <iostream>

STUDENT::STUDENT
(std::string  input_AM,
 std::string  input_name,
 unsigned int input_semester,
 SUBJECT     *input_decl_subj,
 SUBJECT     *input_subj,
 float        input_grade)
{
    AM       = input_AM;
    name     = input_name;
    semester = input_semester;
    // if input_subj is NULL then do not set
    if (input_decl_subj) this->add_subject(input_decl_subj);
    // Don't throw exception, these are warnings
    if (input_subj) {
        // Grade cannot be smaller than 0
        if (input_grade > 0) {
            this->set_passing_grade(input_subj, input_grade);
        } else {
            std::cerr << "Warning: Input a grade number > 0, "
                      << "passing grade for student "
                      << input_name
                      << " currently not set."
                      << std::endl;
        }
    //input_grade = -1 is the default value of grade (in place of empty)
    } else if (!input_subj && input_grade != -1) {
        std::cerr << "Warning: Cannot input grade without subject,"
                  << " ignoring grade..."
                  << std::endl;
    }
}

// Overloaded to input whole lists (for ex. in case of loading from disk)
STUDENT::STUDENT
(std::string  input_AM,
 std::string  input_name,
 unsigned int input_semester,
 std::vector <std::pair <SUBJECT *, float>> input_passing_grade_list,
 std::vector<SUBJECT *> input_declared_subjects) {
    AM       = input_AM;
    name     = input_name;
    semester = input_semester;
    passing_grade_list = input_passing_grade_list;
    declared_subjects = input_declared_subjects;
}

// Constructor (overloaded) to duplicate another STUDENT object.
//(delegate constructor)
STUDENT::STUDENT
(const STUDENT &source) : STUDENT (source.AM,
                                   source.name,
                                   source.semester,
                                   source.passing_grade_list,
                                   source.declared_subjects) {}

// Function to print all attributes to ostream
void
STUDENT::print_all
(std::ostream &input_stream)
{
    input_stream  << "> AM: "                << AM
                  << " - Name: "             << name
                  << " - Semester: "         << semester
                  << " - Passing Grades: "   << get_all_passing_grades()
                  << " - Declared Subjects: "<< get_all_declared_subjects()
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
std::string  STUDENT::get_AM (void)       {return AM;}
std::string  STUDENT::get_name (void)     {return name;}
unsigned int STUDENT::get_semester (void) {return semester;}
std::vector<std::pair<SUBJECT *, float>> STUDENT::get_passing_grade_list (void) {
    return passing_grade_list;
}
std::vector<SUBJECT *> STUDENT::get_declared_subjects_list (void) {
    return declared_subjects;
}

void STUDENT::set_passing_grade_list
(std::vector<std::pair<SUBJECT *, float>> input_passing_grade_list) {
    passing_grade_list = input_passing_grade_list;
}
void STUDENT::set_declared_subjects_list
(std::vector<SUBJECT *> input_declared_subjects) {
    declared_subjects = input_declared_subjects;
}
/* Function that seaches for subject code or name * and returns the passing
 * grade if the subject is passed by student*/
float
STUDENT::get_passing_grade
(std::string search_term) {
    if (passing_grade_list.empty())  {
        std::cout << "Warning: Student "
                  << this->get_name()
                  << " has not passed any subjects."
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
                  << " has not passed this subject."
                  << std::endl;
        return 0;
    }
}

std::string STUDENT::get_all_passing_grades(void) {
    std::string grades_string= "";
    // Just to avoid space before first word on grades_string
    bool first = true;
    // Check if grade list is empty, if not, fill it with the info
    if (!passing_grade_list.empty())  {
        for (auto & index : passing_grade_list) {
            // Avoid space on first word but input before every other one
            if (!first) grades_string += " ";
            first = false;
            grades_string += index.first->get_code() + " " +
                             std::to_string(index.second);
        }
    } else grades_string = "No_subjects_passed";
    return grades_string;
}

std::string STUDENT::get_all_declared_subjects(void) {
    std::string subjects_string = "";
    // Just to avoid space before first word on grades_string
    bool first = true;
    // Check if grade list is empty, if not, fill it with info
    if (!declared_subjects.empty())  {
        for (auto & index : declared_subjects) {
            // Avoid space on first word but input before every other one
            if (!first) subjects_string += " ";
            first = false;
            subjects_string += index->get_code();
        }
    } else subjects_string = "No_subjects_declared";
    return subjects_string;
}

void STUDENT::set_passing_grade (SUBJECT* input_subj, float input_grade) {
    // Create the pair and insert it into the list
    std::pair <SUBJECT *, float>input_pair = {input_subj, input_grade};
    passing_grade_list.push_back(input_pair);
}
void STUDENT::set_AM (std::string input_AM) {AM = input_AM;}
void STUDENT::set_name (std::string input_name) {name = input_name;}
void STUDENT::set_semester (unsigned int input_semester) {
    semester = input_semester;
}
std::vector<SUBJECT *> STUDENT::get_decl_subj (void) {
    return declared_subjects;
}
