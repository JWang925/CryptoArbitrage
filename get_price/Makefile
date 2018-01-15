LDLIBS= -lboost_system -lcrypto -lssl -lcpprest
CPPFLAGS= -std=c++11

all: main

main:
	g++ main.cpp api.cpp $(CPPFLAGS) -o test $(LDLIBS)

clean:
	rm -rf test
