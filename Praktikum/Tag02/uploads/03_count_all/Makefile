
tests:
	checkmk count_all_tests.ts > count_all_tests.c

gcc: tests
	gcc count_all.c count_all_tests.c -o tests -Wall -std=c99 -g `pkg-config --cflags --libs check`

run: gcc
	./tests

clean:
	rm -f count_all_tests.c tests

