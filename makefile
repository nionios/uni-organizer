make:
	g++\
 ./src/main.cpp\
 ./src/student/student.cpp\
 ./src/student/operators.cpp\
 ./src/subject/subject.cpp\
 ./src/helpers/vector_printer.cpp\
 ./src/files/load/load.cpp\
 ./src/files/save/save.cpp\
 ./src/files/encode/encode.cpp\
 -I./include/student/\
 -I./include/subject/\
 -I./include/helpers/\
 -I./include/files/load/\
 -I./include/files/save/\
 -I./include/files/encode/\
 -I./include/files/decode/\
 -o $(ONAME)
	mv $(ONAME) ./bin/
run:
	make
	./bin/$(ONAME)

ONAME=uni_organizer_ex_3
