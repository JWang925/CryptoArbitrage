LDLIBS= -lboost_system -lcrypto -lssl -lcpprest
CPPFLAGS= -std=c++11

all: test

test:
	g++ test.cpp api.cpp $(CPPFLAGS) -o test $(LDLIBS)

clean:
	rm -rf test
