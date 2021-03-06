make:
	g++\
 ./src/main.cpp\
 ./src/student/student.cpp\
 ./src/student/operators.cpp\
 ./src/subject/subject.cpp\
 ./src/helpers/vector_printer.cpp\
 ./src/helpers/create_student.cpp\
 ./src/helpers/create_subject.cpp\
 ./src/helpers/view_subjects.cpp\
 ./src/helpers/archive.cpp\
 ./src/helpers/gather.cpp\
 ./src/files/load/load.cpp\
 ./src/files/save/save.cpp\
 ./src/files/encode/encode.cpp\
 ./src/files/interpret/interpret.cpp\
 ./src/exceptions/exceptions.cpp\
 -I./include/student/\
 -I./include/subject/\
 -I./include/helpers/\
 -I./include/files/load/\
 -I./include/files/save/\
 -I./include/files/encode/\
 -I./include/files/interpret/\
 -I./include/exceptions/\
 -o $(ONAME)
	mv $(ONAME) ./bin/
run:
	make
	./bin/$(ONAME)

ONAME=uni_organizer_ex_3
