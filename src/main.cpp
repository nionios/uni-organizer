// Code by Dennis Nikolopoulos
// AM: 18390126
// Description: Program answering all questions of Exercise 3 in the Object
//              Oriented Programming class in the University of West Attica.
// Compilation command : Running "make" command in root dir of the
//                       exercise to make, "make run" to make the
//                       executables and run. It should run if g++
//                       is installed on the host machine.
// My machine specs: Arch Linux, kernel: 5.17.5-arch1-1, g++ (GCC) 11.2.0
#include <iostream>
#include <string>
#include <student.hpp>
#include <subject.hpp>
#include <operators.hpp>
#include <vector_printer.hpp>
#include <encode.hpp>
#include <save.hpp>

int
main (int argc, char **argv)
{
    std::cout << "====== Exercise 3 =======" << std::endl;
    STUDENT stud_1("18390126","Dionisis Nikolopoulos",8);
    STUDENT stud_2("12601839","Nionios Dionisopoulos");

    SUBJECT dop("ICE-1001","Programming");
    SUBJECT oop("ICE-2001","Object Oriented Programming");
    STUDENT stud_3("10101010","Binary Code Man",2000,&oop,&dop,10);
    stud_1 += &dop;
    stud_1 += &oop;
    std::vector<SUBJECT *> subjp = stud_1.get_decl_subj();
    std::cout << subjp[0]->get_name() << std::endl;
    std::cout << subjp[1]->get_name() << std::endl;

    stud_1.set_passing_grade(&dop, 9.89);
    stud_1.set_passing_grade(&oop, 8.5);
    stud_2.set_passing_grade(&dop, 5.1);
    stud_2.set_passing_grade(&oop, 5.04);

    STUDENT stud_duplicate(stud_1);
    std::cout << "Printing duplicated STUDENT object" << std::endl;
    stud_duplicate.print_all(std::cout);

    STUDENT stud_duplicate_2;
    std::cout << "Printing empty STUDENT object" << std::endl;
    stud_duplicate_2.print_all(std::cout);
    stud_duplicate = stud_2;
    std::cout << "Printing duplicated STUDENT object" << std::endl;
    stud_duplicate_2.print_all(std::cout);

    stud_1.print_all(std::cout);
    stud_2.print_all(std::cout);
    stud_duplicate.print_all(std::cout);
    stud_duplicate.inc_semester();
    stud_duplicate.print_all(std::cout);
    stud_duplicate_2.print_all(std::cout);

    std::cout << "Comparing stud_1 and stud_2:" << std::endl;
    std::cout << "stud_1 == stud_2:" << std::endl;
    if (stud_1 == stud_2) std::cout << " True" << std::endl;
    else std::cout << " False" << std::endl;

    std::cout << "stud_1 != stud_2:" << std::endl;
    if (stud_1 != stud_2) std::cout << " True" << std::endl;
    else std::cout << " False" << std::endl;

    std::cout << "stud_1 > stud_2:"  << std::endl;
    if (stud_1 > stud_2) std::cout << " True" << std::endl;
    else std::cout << " False" << std::endl;

    std::cout << "stud_1 < stud_2:"  << std::endl;
    if (stud_1 < stud_2) std::cout << " True" << std::endl;
    else std::cout << " False" << std::endl;

    std::cout << "stud_1 >= stud_2:" << std::endl;
    if (stud_1 >= stud_2) std::cout << " True" << std::endl;
    else std::cout << " False" << std::endl;

    std::cout << "stud_1 <= stud_2:" << std::endl;
    if (stud_1 <= stud_2) std::cout << " True" << std::endl;
    else std::cout << " False" << std::endl;

    float searched_grade_1 = stud_1.get_passing_grade("ICE-2001");
    std::cout << "Seached grade 1 is " << searched_grade_1 << std::endl;
    float searched_grade_2 =
        stud_1.get_passing_grade("Object Oriented Programming");
    std::cout << "Seached grade 2 is " << searched_grade_2 << std::endl;

    std::string encoded_stud_data = encode(&stud_1);
    std::string encoded_subj_data = encode(&oop);
    save(encoded_stud_data);
    save(encoded_subj_data);

    std::cout << "====End of Exercise 3====" << std::endl;
    return 0;
}
