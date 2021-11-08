#include <iostream>
#include <fstream>
#include <string>
#include <cppunit/TestRunner.h>
#include <cppunit/TestResult.h>
#include <cppunit/TestResultCollector.h>
#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/BriefTestProgressListener.h>
#include <cppunit/extensions/TestFactoryRegistry.h>
#include "func.h"

class Test : public CPPUNIT_NS::TestCase
{
  CPPUNIT_TEST_SUITE(Test);
  CPPUNIT_TEST(testHelloWorld);
  CPPUNIT_TEST(testAdd);
  CPPUNIT_TEST(testMult);
  CPPUNIT_TEST_SUITE_END();

public:
  void setUp(void) {}
  void tearDown(void) {}

protected:
  void testHelloWorld(void) {
    system("./hello >nul 2>nul");
    std::string line;
    std::ifstream myfile ("nul");
    if (myfile.is_open()){
	    getline(myfile,line);
	    CPPUNIT_ASSERT(line.compare("Hello World!") == 0);
    }
    else{
	    CPPUNIT_ASSERT(false);
    }
  }

  void testAdd(void){
	  MyFunctions func;
  	CPPUNIT_ASSERT(func.addsTwo(3,4) == 7);
  }

  void testMult(void){
	  MyFunctions func;
	CPPUNIT_ASSERT(func.multiply(3,4) == 12);
  }
};


CPPUNIT_TEST_SUITE_REGISTRATION(Test);

int main()

{
  CPPUNIT_NS::TestResult controller;

  CPPUNIT_NS::TestResultCollector result;
  controller.addListener(&result);

  CPPUNIT_NS::BriefTestProgressListener progress;
  controller.addListener(&progress);

  CPPUNIT_NS::TestRunner runner;
  runner.addTest(CPPUNIT_NS::TestFactoryRegistry::getRegistry().makeTest());
  runner.run(controller);

  return result.wasSuccessful() ? 0 : 1;
}
