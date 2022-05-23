make:
	g++ ./src/main.cpp\
 ./src/student/student.cpp ./src/student/operators.cpp\
 ./src/subject/subject.cpp\
 -o ex_3 -I ./include/student/ -I ./include/subject/
	mv ex_3 ./bin/
run:
	make
	./bin/ex_3
