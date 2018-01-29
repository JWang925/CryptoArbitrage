LDLIBS = -lboost_system -lcrypto -lssl -lcpprest
CPPFLAGS = -std=c++11
CC = g++

RunMe: main.o aux.o quadriga.o kraken.o
	$(CC) $(CPPFLAGS) -o RunMe main.o aux.o quadriga.o kraken.o $(LDLIBS)

main.o: main.cpp
	$(CC) $(CPPFLAGS) -c main.cpp 

aux.o: aux.cpp 
	$(CC) $(CPPFLAGS) -c aux.cpp

quadriga.o: quadriga.cpp
	$(CC) $(CPPFLAGS) -c quadriga.cpp

kraken.o: kraken.cpp
	$(CC) $(CPPFLAGS) -c kraken.cpp

clean:
	rm -rf RunMe *.o
