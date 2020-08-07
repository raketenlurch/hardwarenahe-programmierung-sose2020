
tests:
	checkmk caesar_minus2_gross_tests.ts > caesar_minus2_gross_tests.c

gcc: tests
	gcc caesar_minus2_gross.c caesar_minus2_gross_tests.c -o tests -Wall -std=c99 -g `pkg-config --cflags --libs check`

run: gcc
	./tests

clean:
	rm -f caesar_minus2_gross_tests.c tests
