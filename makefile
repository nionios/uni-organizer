make:
	g++\
 ./src/main.cpp\
 ./src/student/student.cpp\
 ./src/student/operators.cpp\
 ./src/subject/subject.cpp\
 ./src/helpers/vector_printer.cpp\
 -o $(ONAME) -I ./include/student/ -I ./include/subject/ -I ./include/helpers/
	mv $(ONAME) ./bin/
run:
	make
	./bin/$(ONAME)

ONAME=uni_organizer_ex_3
