all:
	g++ -std=c++17 hello.cpp -o hello
	g++ -std=c++17 helloTest.cpp func.cpp -lcppunit -o helloTest
	#g++ -std=c++17 testf.cpp FirstTestCase.cpp  -lcppunit -o testf
	#g++ -std=c++17 FirstTestCase.cpp -lcppunit -o FirstTestCase

test:
	chmod +x hello
	./helloTest

clean:
	$(RM) hello helloTest '#helloTest.cpp#' nul helloTest.cpp~ testf FirstTestCase


