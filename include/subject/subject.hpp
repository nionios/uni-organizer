#include <string>
#ifndef SUBJECT_HPP
#define SUBJECT_HPP
class SUBJECT
{
    private:
        const char * code;
        std::string name;
        unsigned int semester;
    public:
        // Constructor with a default value in the semester number (1).
        SUBJECT ( const char * input_code,
                  std::string input_name,
                  unsigned int input_semester = 1);
        // Constructor (overloaded) to duplicate another STUDENT object.
        SUBJECT (const SUBJECT& source);
        // Function to print all attributes to ostream
        void print_all(std::ostream &input_stream);
        // Function to increment semester by +1
        void inc_semester(void);
        // Setters and getters
        void set_code (const char * input_code);
        void set_name (std::string input_name);
        void set_semester (unsigned int input_semester);
        const char * get_code (void);
        std::string get_name (void);
        unsigned int get_semester (void);
};
#endif
