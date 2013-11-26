all: at2
at2 : at2.o
	g++ -o at2 at2.o -lboost_date_time -lboost_thread

at2.o : at2.cpp
	g++ -O0 -g3 -Wall -c at2.cpp

clean:
	rm -f at2 at2.o
