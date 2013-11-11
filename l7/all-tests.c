#include "CuTest.h"
#include <stdio.h>
    
CuSuite* StrUtilGetSuite();
    
void RunAllTests(void) {
  CuString *output = CuStringNew();
  CuSuite* suite = CuSuiteNew();
     
  //CuSuiteAddSuite(suite, (CuSuite*)daysInMonthGetSuite());  // Adding our test suite
  CuSuiteAddSuite(suite, (CuSuite*)quadraticSuite());  // Adding our test suite
 
  CuSuiteRun(suite);
  CuSuiteSummary(suite, output);
  CuSuiteDetails(suite, output);
  printf("%s\n", output->buffer);
}
    
int main(void) {
    RunAllTests();
}