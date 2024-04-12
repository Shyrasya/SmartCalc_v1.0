CC=gcc
CFLAGS= -Wall -Werror -Wextra -std=c11
OS = $(shell uname)
SOURCES = s21_validator.c s21_parser.c s21_rpn.c s21_calculation.c tests.c
MAT = -lm

ifeq ($(OS),Linux)
    det_OS = -lcheck -lm -lrt -lpthread -lsubunit
		project = SmartCalc
		inst = cd SmartCalc && qmake && make && make clean && rm Makefile && mkdir -p ../build && mv $(project) ../build/
else
    det_OS = -lcheck -lm -lpthread
		project = SmartCalc.app
		inst = cd SmartCalc && qmake && make && make clean && rm Makefile && mkdir -p ../build && mv $(project)/$(UI_BIN) ../build/
endif


all: clean dist gcov_report dvi

dvi:
	open ./documentation.md

install: clean uninstall
	$(inst)

dist: clean_all install
	mkdir -p dist
	cp  -R ./build/$(project) ./dist/$(project)
	cp ./documentation.md ./dist/documentation.md
	cd ./dist && tar cvzf calculator.tgz *
	cd ./dist && rm -R $(project) documentation.md
	make clean

uninstall:
	rm -rf build ./SmartCalc/.qmake.stash

test: clean
	$(CC) $(CFLAGS) --coverage $(SOURCES) -o test $(det_OS)
	./test


gcov_report: test
	lcov -t "result" -o res.info -c -d .
	genhtml -o report res.info
	open report/index.html

check:
	cp ../materials/linters/.clang-format ./
	clang-format -style=Google -n *.c *.h
	clang-format -style=Google -i *.c *.h
	rm .clang-format

	cp ../materials/linters/.clang-format ./SmartCalc
	clang-format -style=Google -n ./SmartCalc/*.cpp ./SmartCalc/*.h
	clang-format -style=Google -i ./SmartCalc/*.cpp ./SmartCalc/*.h
	rm ./SmartCalc/.clang-format


valgrind: test
	CK_FORK=no valgrind --vgdb=no --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose -s ./test

clean:
	rm -rf report build *.gc* *.o *.info *.a test.dSYM test gch ./SmartCalc/.qmake.stash compose-dev.yaml

clean_dist:
	rm -rf dist

clean_all: clean clean_dist

rebuild: clean clean_dist all