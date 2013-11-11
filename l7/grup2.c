#include <stdio.h>
#include <math.h>
#include <assert.h>
#include "CuTest.h"



/* Find roots in the quadratic equation a * x*x + b * x + c = 0.
   Assume as a precondition that a is not zero                    */
void solveQuadraticEquation(double a, double b, double c, 
                            int *numberOfRoots, double *root1, double *root2){
  double discriminant;

  discriminant = b * b - 4 * a * c;

  if (discriminant < 0){
    *numberOfRoots = 0;
  }
  else if (discriminant == 0){
    *numberOfRoots = 1;
    *root1 = -b/(2*a);
  }
  else{
    *numberOfRoots = 2;
    *root1 = (-b + sqrt(discriminant))/(2*a);
    *root2 = (-b - sqrt(discriminant))/(2*a);
  }
}
 
void test1(CuTest *tc) {
  double a = 1, b = 0, c = 0;
  int numberOfRoots;
  double root1, root2;

  solveQuadraticEquation(a,b,c,&numberOfRoots,&root1,&root2);
  CuAssertIntEquals(tc, numberOfRoots, 1);


  //assert(numberOfRoots == 1);
  //assert(root1 == 0);
} 

void test2(CuTest *tc) {
  double a = 1, b = 0, c = 1;
  int numberOfRoots;
  double root1, root2;

  solveQuadraticEquation(a,b,c,&numberOfRoots,&root1,&root2);
  assert(numberOfRoots == 0);
} 

void test3(CuTest *tc) {
  double a = 1, b = 0, c = -1;
  int numberOfRoots;
  double root1, root2;

  solveQuadraticEquation(a,b,c,&numberOfRoots,&root1,&root2);
  assert(numberOfRoots == 2);
  assert(root1 == 1);
  assert(root2 == -1);
} 

/* Test case management: Adding the test case to a test suite */
CuSuite* quadraticSuite() {
  CuSuite* suite = CuSuiteNew();
  SUITE_ADD_TEST(suite, test1);
  SUITE_ADD_TEST(suite, test2);
  SUITE_ADD_TEST(suite, test3);
  return suite;
}