#include <save.hpp>
#include <encode.hpp>
// Helper function to decode and save with one function call

void archive (STUDENT * input_stud) {
    save(encode(input_stud), "student_data.txt");
}

void archive (SUBJECT * input_subj) {
    save(encode(input_subj), "subject_data.txt");
}
