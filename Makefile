CC = g++
CFLAGS = -Iincludes -Wall -fprofile-arcs -ftest-coverage
LDFLAGS = -lgtest -lgtest_main -pthread

check:
	@mkdir -p bin
	\ \ src/logic.cpp tests/test_main.cpp \ -o bin/tests
	./bin/tests

clean:
	rm -rf bin *.gcda *.gcno coverage.info