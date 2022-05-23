make:
	g++\
 ./src/main.cpp\
 ./src/student/student.cpp\
 ./src/student/operators.cpp\
 ./src/subject/subject.cpp\
 -o $(ONAME) -I ./include/student/ -I ./include/subject/
	mv $(ONAME) ./bin/
run:
	make
	./bin/$(ONAME)

ONAME=uni_organizer_ex_3
