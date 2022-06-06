#include <string>
#include <vector>
#include <subject.hpp>
#ifndef STUDENT_HPP
#define STUDENT_HPP
class STUDENT
{
    private:
        const char * AM;
        std::string name;
        unsigned int semester;
        std::vector <std::pair <SUBJECT *, float>> passing_grade_list;
        std::vector<SUBJECT *> declared_subjects;
    public:
        // Constructor with a default values.
        STUDENT ( const char * input_AM        = "Unknown Student Code",
                  std::string  input_name      = "Unnamed Student",
                  unsigned int input_semester  = 1,
                  SUBJECT     *input_decl_subj = NULL,
                  SUBJECT     *input_subj      = NULL,
                  float        input_grade     = -1);
        // Constructor (overloaded) to input the lists too (for ex. in case of
        // loading from disk, this constructor is called)
        STUDENT (const char  *input_AM,
                std::string  input_name,
                unsigned int input_semester,
                std::vector <std::pair <SUBJECT *, float>> input_passing_grade_list,
                std::vector<SUBJECT *> input_declared_subjects);
        // Constructor (overloaded) to duplicate another STUDENT object.
        STUDENT (const STUDENT& source);
        /* Operators */
        void operator += (SUBJECT * input_subj);
        void operator = (STUDENT &source_stud);
        /* Helper Functions */
        // Function to print all attributes to ostream
        void print_all(std::ostream &input_stream);
        // Function to increment semester by +1
        void inc_semester(void);
        /* Setters and getters */
        void set_AM (const char * input_AM);
        void set_name (std::string input_name);
        void set_semester (unsigned int input_semester);
        void set_passing_grade (SUBJECT* input_subj, float input_grade);
        void set_passing_grade_list
            (std::vector<std::pair<SUBJECT *, float>> input_passing_grade_list);
        void set_declared_subjects_list
            (std::vector<SUBJECT *> input_declared_subjects);
        std::string get_all_passing_grades(void);
        std::string get_all_declared_subjects(void);
        std::vector<std::pair<SUBJECT *, float>> get_passing_grade_list(void);
        std::vector<SUBJECT *> get_declared_subjects_list(void);
        float get_passing_grade (std::string search_term);
        const char * get_AM (void);
        std::string get_name (void);
        unsigned int get_semester (void);
        std::vector<SUBJECT *> get_decl_subj (void);
        void add_subject (SUBJECT * inpu_subj);
        void operator = (STUDENT stud_right);
};
#endif
