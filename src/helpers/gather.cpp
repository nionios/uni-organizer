#include <load.hpp>
#include <interpret.hpp>
// Helper function to decode and save with one function call

void gather (STUDENT * input_stud) {
    save(encode(input_stud));
}

void gather (SUBJECT * input_subj) {
    save(encode(input_subj));
}
