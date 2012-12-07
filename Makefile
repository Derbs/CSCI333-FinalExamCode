CPP = g++
FLAGS = -Wall -Wextra -Werror

test: NaughtyNice.cpp
	$(CPP) $^ -o $@

clean:
	rm -f *.o
	rm -f test
