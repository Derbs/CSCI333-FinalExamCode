CPP = g++
FLAGS = -Wall -Wextra -Werror

tweet_test: TweetTracker.cpp
	$(CPP) $^ -o $@

naughty_test: NaughtyNice.cpp
	$(CPP) $^ -o $@

clean:
	rm -f *.o
	rm -f test
