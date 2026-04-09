CC = g++
CFLAGS = -Iincludes -Wall -fprofile-arcs -ftest-coverage
LDFLAGS = -lsqlite3 -lgtest -lgtest_main -pthread --coverage
check:
	@mkdir -p bin
	$(CC) $(CFLAGS) src/logic.cpp tests/test_main.cpp $(LDFLAGS) -o bin/tests
	./bin/tests

clean:
	rm -rf bin *.gcda *.gcno coverage.info