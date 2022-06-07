#include <exception>
#include <string>
#ifndef EXCEPTIONS_HPP
#define EXCEPTIONS_HPP
class invalid_student_data : std::exception {
    public:
       std::string what(void);
};
class invalid_subject_data : std::exception {
    public:
       std::string what(void);
};
class subject_mismatch : std::exception {
    public:
       std::string what(void);
};
#endif
