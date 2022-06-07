#include <exceptions.hpp>
#include <exception>
#include <string>
std::string invalid_student_data::what(void) {
    return "Exception: Invalid student data in student_data.txt";
}
std::string invalid_subject_data::what(void) {
    return "Exception: Invalid subject data in subject_data.txt";
};
std::string subject_mismatch::what(void) {
    return "Exception: Some subjects in student_data.txt are not initialized";
};
